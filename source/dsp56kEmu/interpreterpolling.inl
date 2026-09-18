#pragma once

namespace dsp56k {
struct InterpreterPollingLoop {
    uint64_t revision=0, firstPage=0, lastPage=0, epoch=0, lastInstructions=0, lastCycles=0;
    TWord first=0;
    uint32_t instructions=0, cycles=0;
    bool valid=false, observed=false;
    uint8_t gpioPorts=0;
    // A validated body can only touch the accumulators, the status register and
    // the CCR cache, so the fixed point is proven on those instead of a whole
    // DspRegs snapshot. Debug builds keep the snapshot to check that proof.
    TReg56 a, b;
    TReg48 x, y;
    TReg24 sr;
    DSP::CCRCache flags{};
#ifdef _DEBUG	// the switch assert() uses, see dspassert.h
    DspRegs registers{};
#endif
};

void DSP::skipStablePollingLoop(TWord branchPC, uint64_t targetCycles) {
    // Opt-in for the app's single-thread, cycle-bounded hardware scheduler.
    // Parallel hosts must not skip reads of asynchronously changing hardware.
#if DSP56300_DEBUGGER
    if(m_debugger) return;
#endif
    const auto first=reg.pc.toWord();
    if(branchPC+1>=mem.sizeP()) return;
    if(m_interruptFunc != m_execPeripheralsFunc
        || (sr_test_noCache(SR_LF) && reg.la.var>=first && reg.la.var<=branchPC+1)
        || perif[0]->getType() != PeripheralType::Peripherals56303)
        return;
    auto& slot=m_pollingLoops.edit(branchPC);
    if(!slot) slot=std::make_shared<InterpreterPollingLoop>();
    auto& loop=*slot;
    const auto firstPage=m_programPageRevisions[first/256];
    const auto lastPage=m_programPageRevisions[(branchPC+1)/256];
    if(loop.revision != m_programRevision || loop.first != first
        || loop.firstPage != firstPage || loop.lastPage != lastPage) {
        loop={}; loop.revision=m_programRevision; loop.first=first;
        loop.firstPage=firstPage; loop.lastPage=lastPage;
        bool hasRead=false, valid=true;
        for(TWord pc=first; pc<=branchPC && valid;) {
            TWord op,extension; memReadOpcode(pc,op,extension);
            Instruction a,b; m_opcodes.getInstructionTypes(op,a,b);
            unsigned words=1;
            if(pc==branchPC) {
                valid=a==Bcc_xxx || a==Bcc_xxxx || a==Bra_xxx || a==Bra_xxxx;
                words=(a==Bcc_xxxx || a==Bra_xxxx)?2:1;
            } else if(a==Movep_Spp || a==Movep_SXqq) {
                // Read-only DMA addresses/counters and plain latched GPIO only.
                // Exclude host/audio data reads, timers and dynamic pin sources.
                const bool pp=a==Movep_Spp;
                const auto write=pp?getFieldValue<Movep_Spp,Field_W>(op):getFieldValue<Movep_SXqq,Field_W>(op);
                const auto area=pp?getFieldValue<Movep_Spp,Field_s>(op):0;
                const auto dest=pp?getFieldValue<Movep_Spp,Field_dddddd>(op):getFieldValue<Movep_SXqq,Field_dddddd>(op);
                const auto address=pp?(0xffffc0+getFieldValue<Movep_Spp,Field_pppppp>(op)):
                    (0xffff80+getFieldValue<Movep_SXqq,Field_q,Field_qqqqq>(op));
                valid=!write && !area && (dest==14 || dest==15);
                auto& periph=*static_cast<Peripherals56303*>(perif[0]);
                const bool dma=address>=XIO_DCR5 && address<=XIO_DSR0;
                const bool gpio=(address==Essi::ESSI_PDRC && !periph.getPortC().hasHostInputSource())
                    || (address==Essi::ESSI_PDRD && !periph.getPortD().hasHostInputSource());
                valid &= dma || gpio;
                if(gpio) loop.gpioPorts |= address==Essi::ESSI_PDRC ? 1 : 2;
                hasRead |= valid;
            } else if(a==Movex_ea || a==Movey_ea) {
                // A two-word absolute-address load into a data register: plain X/Y
                // memory (only DMA or another processor changes it, and both end the
                // fixed point through the epoch) or the same read-only DMA and latched
                // GPIO registers MOVEP may read. Never a store, never an address update.
                const bool x=a==Movex_ea;
                const auto load=x?getFieldValue<Movex_ea,Field_W>(op):getFieldValue<Movey_ea,Field_W>(op);
                const auto mmm=x?getFieldValue<Movex_ea,Field_MMM>(op):getFieldValue<Movey_ea,Field_MMM>(op);
                const auto rrr=x?getFieldValue<Movex_ea,Field_RRR>(op):getFieldValue<Movey_ea,Field_RRR>(op);
                const auto dest=x?getFieldValue<Movex_ea,Field_dd,Field_ddd>(op):getFieldValue<Movey_ea,Field_dd,Field_ddd>(op);
                words=2;
                valid=load && ((mmm<<3)|rrr)==MMMRRR_AbsAddr && ((dest>=4 && dest<=7) || dest==14 || dest==15);
                const TWord address=extension;
                if(valid && isPeripheralAddress(address)) {
                    auto& periph=*static_cast<Peripherals56303*>(perif[0]);
                    const bool dma=x && address>=XIO_DCR5 && address<=XIO_DSR0;
                    const bool gpio=x && ((address==Essi::ESSI_PDRC && (!periph.getPortC().hasHostInputSource() || periph.getPortC().hostInputStableWhileRunning()))
                        || (address==Essi::ESSI_PDRD && (!periph.getPortD().hasHostInputSource() || periph.getPortD().hostInputStableWhileRunning())));
                    valid=dma || gpio;
                    if(gpio) loop.gpioPorts |= address==Essi::ESSI_PDRC ? 1 : 2;
                }
                hasRead |= valid;
            } else if(a==Nop) {
            } else if(a==Cmp_xxxxS2 || a==And_xxxx) {
                words=2;
            } else if(a==And_xx || a==Cmp_xxS2) {
            } else {
                // Only accumulator arithmetic with no parallel data movement.
                // No address updates, stores, loop control or system registers.
                const bool pureMove=b==Move_Nop || b==Ifcc || b==Ifcc_U;
                const bool pureAlu=a==Add_SD || a==Sub_SD || a==Cmp_S1S2 || a==And_SD;
                valid=pureMove && pureAlu;
            }
            if(pc<branchPC && pc+words>branchPC) valid=false;
            ++loop.instructions; loop.cycles+=getOpcodeCycles(pc); pc+=words;
        }
        loop.valid=valid && hasRead;
    }
    if(!loop.valid) return;
    // A host can install a dynamic pin source without changing program memory.
    auto& periph=*static_cast<Peripherals56303*>(perif[0]);
    if(((loop.gpioPorts&1) && periph.getPortC().hasHostInputSource() && !periph.getPortC().hostInputStableWhileRunning())
        || ((loop.gpioPorts&2) && periph.getPortD().hasHostInputSource() && !periph.getPortD().hostInputStableWhileRunning())) return;
    // Require one complete, event-free iteration to leave every register the
    // proven pure body can write unchanged. This establishes its fixed point.
    const bool fixed=loop.observed && loop.epoch==m_peripheralEpoch
        && m_instructions-loop.lastInstructions==loop.instructions
        && m_cycles-loop.lastCycles==loop.cycles
        && reg.a==loop.a && reg.b==loop.b && reg.x==loop.x && reg.y==loop.y && reg.sr==loop.sr
        && ccrCache.ab==loop.flags.ab && ccrCache.alu==loop.flags.alu && ccrCache.dirty==loop.flags.dirty;
#ifdef _DEBUG
    // The narrowed compare is only as good as the whitelist above and the loop
    // handling in finishInterpreterLoops(): nothing else may change in between.
    assert(!fixed || std::memcmp(&reg,&loop.registers,sizeof(reg))==0);
#endif
    if(fixed && loop.cycles && loop.instructions) {
        const auto cycleEnd=std::min(targetCycles,perif[0]->getTargetCycle());
        const auto instructionEnd=perif[0]->getTargetClock();
        if(cycleEnd>m_cycles && instructionEnd>m_instructions) {
            const auto repeats=std::min((cycleEnd-m_cycles)/loop.cycles,
                (instructionEnd-m_instructions)/loop.instructions);
            m_cycles+=repeats*loop.cycles;
            m_instructions+=repeats*loop.instructions;
            m_skippedPollingInstructions+=repeats*loop.instructions;
        }
    }
    loop.observed=true; loop.epoch=m_peripheralEpoch;
    loop.lastInstructions=m_instructions; loop.lastCycles=m_cycles;
    loop.a=reg.a; loop.b=reg.b; loop.x=reg.x; loop.y=reg.y; loop.sr=reg.sr; loop.flags=ccrCache;
#ifdef _DEBUG
    loop.registers=reg;
#endif
}
}
