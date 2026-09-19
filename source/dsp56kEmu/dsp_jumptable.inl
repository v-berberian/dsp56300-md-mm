#pragma once

#include "dsp.h"
#include "opcodetypes.h"

namespace dsp56k
{
	constexpr TInstructionFunc g_opcodeFuncs[] =
	{
		&DSP::op_Abs,							// Abs
		&DSP::op_ADC,							// ADC 
		&DSP::op_Add_SD,						// Add_SD
		&DSP::op_Add_xx,						// Add_xx
		&DSP::op_Add_xxxx,						// Add_xxxx 
		&DSP::op_Addl,							// Addl 
		&DSP::op_Addr,							// Addr 
		&DSP::op_And_SD,						// And_SD 
		&DSP::op_And_xx,						// And_xx 
		&DSP::op_And_xxxx,						// And_xxxx 
		&DSP::op_Andi,							// Andi 
		&DSP::op_Asl_D,							// Asl_D 
		&DSP::op_Asl_ii,						// Asl_ii 
		&DSP::op_Asl_S1S2D,						// Asl_S1S2D 
		&DSP::op_Asr_D,							// Asr_D 
		&DSP::op_Asr_ii,						// Asr_ii 
		&DSP::op_Asr_S1S2D,						// Asr_S1S2D 
		&DSP::op_Bcc_xxxx,						// Bcc_xxxx 
		&DSP::op_Bcc_xxx,						// Bcc_xxx 
		&DSP::op_Bcc_Rn,						// Bcc_Rn 
		&DSP::op_Bchg_ea,						// Bchg_ea 
		&DSP::op_Bchg_aa,						// Bchg_aa 
		&DSP::op_Bchg_pp,						// Bchg_pp 
		&DSP::op_Bchg_qq,						// Bchg_qq 
		&DSP::op_Bchg_D,						// Bchg_D 
		&DSP::op_Bclr_ea,						// Bclr_ea 
		&DSP::op_Bclr_aa,						// Bclr_aa 
		&DSP::op_Bclr_pp,						// Bclr_pp 
		&DSP::op_Bclr_qq,						// Bclr_qq 
		&DSP::op_Bclr_D,						// Bclr_D 
		&DSP::op_Bra_xxxx,						// Bra_xxxx 
		&DSP::op_Bra_xxx,						// Bra_xxx 
		&DSP::op_Bra_Rn,						// Bra_Rn 
		&DSP::op_Brclr_ea,						// Brclr_ea 
		&DSP::op_Brclr_aa,						// Brclr_aa 
		&DSP::op_Brclr_pp,						// Brclr_pp 
		&DSP::op_Brclr_qq,						// Brclr_qq 
		&DSP::op_Brclr_S,						// Brclr_S 
		&DSP::op_BRKcc,							// BRKcc 
		&DSP::op_Brset_ea,						// Brset_ea 
		&DSP::op_Brset_aa,						// Brset_aa 
		&DSP::op_Brset_pp,						// Brset_pp 
		&DSP::op_Brset_qq,						// Brset_qq 
		&DSP::op_Brset_S,						// Brset_S 
		&DSP::op_BScc_xxxx,						// BScc_xxxx 
		&DSP::op_BScc_xxx,						// BScc_xxx 
		&DSP::op_BScc_Rn,						// BScc_Rn 
		&DSP::op_Bsclr_ea,						// Bsclr_ea 
		&DSP::op_Bsclr_aa,						// Bsclr_aa 
		&DSP::op_Bsclr_pp,						// Bsclr_pp 
		&DSP::op_Bsclr_qq,						// Bsclr_qq 
		&DSP::op_Bsclr_S,						// Bsclr_S 
		&DSP::op_Bset_ea,						// Bset_ea 
		&DSP::op_Bset_aa,						// Bset_aa 
		&DSP::op_Bset_pp,						// Bset_pp 
		&DSP::op_Bset_qq,						// Bset_qq 
		&DSP::op_Bset_D,						// Bset_D 
		&DSP::op_Bsr_xxxx,						// Bsr_xxxx 
		&DSP::op_Bsr_xxx,						// Bsr_xxx 
		&DSP::op_Bsr_Rn,						// Bsr_Rn 
		&DSP::op_Bsset_ea,						// Bsset_ea 
		&DSP::op_Bsset_aa,						// Bsset_aa 
		&DSP::op_Bsset_pp,						// Bsset_pp 
		&DSP::op_Bsset_qq,						// Bsset_qq 
		&DSP::op_Bsset_S,						// Bsset_S 
		&DSP::op_Btst_ea,						// Btst_ea 
		&DSP::op_Btst_aa,						// Btst_aa 
		&DSP::op_Btst_pp,						// Btst_pp 
		&DSP::op_Btst_qq,						// Btst_qq 
		&DSP::op_Btst_D,						// Btst_D 
		&DSP::op_Clb,							// Clb 
		&DSP::op_Clr,							// Clr 
		&DSP::op_Cmp_S1S2,						// Cmp_S1S2 
		&DSP::op_Cmp_xxS2,						// Cmp_xxS2 
		&DSP::op_Cmp_xxxxS2,					// Cmp_xxxxS2 
		&DSP::op_Cmpm_S1S2,						// Cmpm_S1S2 
		&DSP::op_Cmpu_S1S2,						// Cmpu_S1S2 
		&DSP::op_Debug,							// Debug 
		&DSP::op_Debugcc,						// Debugcc 
		&DSP::op_Dec,							// Dec 
		&DSP::op_Div,							// Div 
		&DSP::op_Dmac,							// Dmac 
		&DSP::op_Do_ea,							// Do_ea 
		&DSP::op_Do_aa,							// Do_aa 
		&DSP::op_Do_xxx,						// Do_xxx 
		&DSP::op_Do_S,							// Do_S 
		&DSP::op_DoForever,						// DoForever 
		&DSP::op_Dor_ea,						// Dor_ea 
		&DSP::op_Dor_aa,						// Dor_aa 
		&DSP::op_Dor_xxx,						// Dor_xxx 
		&DSP::op_Dor_S,							// Dor_S 
		&DSP::op_DorForever,					// DorForever 
		&DSP::op_Enddo,							// Enddo 
		&DSP::op_Eor_SD,						// Eor_SD 
		&DSP::op_Eor_xx,						// Eor_xx 
		&DSP::op_Eor_xxxx,						// Eor_xxxx 
		&DSP::op_Extract_S1S2,					// Extract_S1S2 
		&DSP::op_Extract_CoS2,					// Extract_CoS2 
		&DSP::op_Extractu_S1S2,					// Extractu_S1S2 
		&DSP::op_Extractu_CoS2,					// Extractu_CoS2 
		&DSP::op_Ifcc,							// Ifcc 
		&DSP::op_Ifcc_U,						// Ifcc_U 
		&DSP::op_Illegal,						// Illegal 
		&DSP::op_Inc,							// Inc 
		&DSP::op_Insert_S1S2,					// Insert_S1S2 
		&DSP::op_Insert_CoS2,					// Insert_CoS2 
		&DSP::op_Jcc_xxx,						// Jcc_xxx 
		&DSP::op_Jcc_ea,						// Jcc_ea 
		&DSP::op_Jclr_ea,						// Jclr_ea 
		&DSP::op_Jclr_aa,						// Jclr_aa 
		&DSP::op_Jclr_pp,						// Jclr_pp 
		&DSP::op_Jclr_qq,						// Jclr_qq 
		&DSP::op_Jclr_S,						// Jclr_S 
		&DSP::op_Jmp_ea,						// Jmp_ea 
		&DSP::op_Jmp_xxx,						// Jmp_xxx 
		&DSP::op_Jscc_xxx,						// Jscc_xxx 
		&DSP::op_Jscc_ea,						// Jscc_ea 
		&DSP::op_Jsclr_ea,						// Jsclr_ea 
		&DSP::op_Jsclr_aa,						// Jsclr_aa 
		&DSP::op_Jsclr_pp,						// Jsclr_pp 
		&DSP::op_Jsclr_qq,						// Jsclr_qq 
		&DSP::op_Jsclr_S,						// Jsclr_S 
		&DSP::op_Jset_ea,						// Jset_ea 
		&DSP::op_Jset_aa,						// Jset_aa 
		&DSP::op_Jset_pp,						// Jset_pp 
		&DSP::op_Jset_qq,						// Jset_qq 
		&DSP::op_Jset_S,						// Jset_S 
		&DSP::op_Jsr_ea,						// Jsr_ea 
		&DSP::op_Jsr_xxx,						// Jsr_xxx 
		&DSP::op_Jsset_ea,						// Jsset_ea 
		&DSP::op_Jsset_aa,						// Jsset_aa 
		&DSP::op_Jsset_pp,						// Jsset_pp 
		&DSP::op_Jsset_qq,						// Jsset_qq 
		&DSP::op_Jsset_S,						// Jsset_S 
		&DSP::op_Lra_Rn,						// Lra_Rn 
		&DSP::op_Lra_xxxx,						// Lra_xxxx 
		&DSP::op_Lsl_D,							// Lsl_D 
		&DSP::op_Lsl_ii,						// Lsl_ii 
		&DSP::op_Lsl_SD,						// Lsl_SD 
		&DSP::op_Lsr_D,							// Lsr_D 
		&DSP::op_Lsr_ii,						// Lsr_ii 
		&DSP::op_Lsr_SD,						// Lsr_SD 
		&DSP::op_Lua_ea,						// Lua_ea 
		&DSP::op_Lua_Rn,						// Lua_Rn 
		&DSP::op_Mac_S1S2,						// Mac_S1S2 
		&DSP::op_Mac_S,							// Mac_S 
		&DSP::op_Maci_xxxx,						// Maci_xxxx 
		&DSP::op_Macsu,							// Macsu 
		&DSP::op_Macr_S1S2,						// Macr_S1S2 
		&DSP::op_Macr_S,						// Macr_S 
		&DSP::op_Macri_xxxx,					// Macri_xxxx 
		&DSP::op_Max,							// Max 
		&DSP::op_Maxm,							// Maxm 
		&DSP::op_Merge,							// Merge 
		&DSP::op_Move_Nop,						// Move_Nop 
		&DSP::op_Move_xx,						// Move_xx 
		&DSP::op_Mover,							// Mover 
		&DSP::op_Move_ea,						// Move_ea 
		nullptr,								// Movex_ea 
		nullptr,								// Movex_aa 
		&DSP::op_Movex_Rnxxxx,					// Movex_Rnxxxx 
		&DSP::op_Movex_Rnxxx,					// Movex_Rnxxx 
		&DSP::op_Movexr_ea,						// Movexr_ea 
		&DSP::op_Movexr_A,						// Movexr_A 
		nullptr,								// Movey_ea 
		nullptr,								// Movey_aa 
		&DSP::op_Movey_Rnxxxx,					// Movey_Rnxxxx 
		&DSP::op_Movey_Rnxxx,					// Movey_Rnxxx 
		&DSP::op_Moveyr_ea,						// Moveyr_ea 
		&DSP::op_Moveyr_A,						// Moveyr_A 
		&DSP::op_Movel_ea,						// Movel_ea 
		&DSP::op_Movel_aa,						// Movel_aa 
		&DSP::op_Movexy,						// Movexy 
		&DSP::op_Movec_ea,						// Movec_ea 
		&DSP::op_Movec_aa,						// Movec_aa 
		&DSP::op_Movec_S1D2,					// Movec_S1D2 
		&DSP::op_Movec_xx,						// Movec_xx 
		&DSP::op_Movem_ea,						// Movem_ea 
		&DSP::op_Movem_aa,						// Movem_aa 
		&DSP::op_Movep_ppea,					// Movep_ppea 
		&DSP::op_Movep_Xqqea,					// Movep_Xqqea 
		&DSP::op_Movep_Yqqea,					// Movep_Yqqea 
		&DSP::op_Movep_eapp,					// Movep_eapp 
		&DSP::op_Movep_eaqq,					// Movep_eaqq 
		&DSP::op_Movep_Spp,						// Movep_Spp 
		&DSP::op_Movep_SXqq,					// Movep_SXqq 
		&DSP::op_Movep_SYqq,					// Movep_SYqq 
		&DSP::op_Mpy_S1S2D,						// Mpy_S1S2D 
		&DSP::op_Mpy_SD,						// Mpy_SD 
		&DSP::op_Mpy_su,						// Mpy_su 
		&DSP::op_Mpyi,							// Mpyi 
		&DSP::op_Mpyr_S1S2D,					// Mpyr_S1S2D 
		&DSP::op_Mpyr_SD,						// Mpyr_SD 
		&DSP::op_Mpyri,							// Mpyri 
		&DSP::op_Neg,							// Neg 
		&DSP::op_Nop,							// Nop 
		&DSP::op_Norm,							// Norm 
		&DSP::op_Normf,							// Normf 
		&DSP::op_Not,							// Not 
		&DSP::op_Or_SD,							// Or_SD 
		&DSP::op_Or_xx,							// Or_xx 
		&DSP::op_Or_xxxx,						// Or_xxxx 
		&DSP::op_Ori,							// Ori 
		&DSP::op_Pflush,						// Pflush 
		&DSP::op_Pflushun,						// Pflushun 
		&DSP::op_Pfree,							// Pfree 
		&DSP::op_Plock,							// Plock 
		&DSP::op_Plockr,						// Plockr 
		&DSP::op_Punlock,						// Punlock 
		&DSP::op_Punlockr,						// Punlockr 
		&DSP::op_Rep_ea,						// Rep_ea 
		&DSP::op_Rep_aa,						// Rep_aa 
		&DSP::op_Rep_xxx,						// Rep_xxx 
		&DSP::op_Rep_S,							// Rep_S 
		&DSP::op_Reset,							// Reset 
		&DSP::op_Rnd,							// Rnd 
		&DSP::op_Rol,							// Rol 
		&DSP::op_Ror,							// Ror 
		&DSP::op_Rti,							// Rti 
		&DSP::op_Rts,							// Rts 
		&DSP::op_Sbc,							// Sbc 
		&DSP::op_Stop,							// Stop 
		&DSP::op_Sub_SD,						// Sub_SD 
		&DSP::op_Sub_xx,						// Sub_xx 
		&DSP::op_Sub_xxxx,						// Sub_xxxx 
		&DSP::op_Subl,							// Subl 
		&DSP::op_Subr,							// subr 
		&DSP::op_Tcc_S1D1,						// Tcc_S1D1 
		&DSP::op_Tcc_S1D1S2D2,					// Tcc_S1D1S2D2 
		&DSP::op_Tcc_S2D2,						// Tcc_S2D2 
		&DSP::op_Tfr,							// Tfr 
		&DSP::op_Trap,							// Trap 
		&DSP::op_Trapcc,						// Trapcc 
		&DSP::op_Tst,							// Tst 
		&DSP::op_Vsl,							// Vsl 
		&DSP::op_Wait,							// Wait 
		&DSP::op_ResolveCache,					// ResolveCache
		&DSP::op_Parallel,						// Parallel
	};

    // The low byte fully specifies a parallel ALU operation. Compile these
    // 256 small handlers once, allowing constant operands and a direct ALU
    // call while retaining the existing move and accumulator-latch rules.
    constexpr Instruction parallelAluType(TWord byte) {
        for(const auto& info : g_opcodes)
            if(info.m_opcode[0] == '?'
                && (byte & (info.m_mask0 | info.m_mask1)) == info.m_mask1)
                return info.m_instruction;
        return Invalid;
    }
    template<TWord Alu> ASMJIT_FORCE_INLINE void DSP::op_ParallelCached(TWord op) {
        constexpr auto type = parallelAluType(Alu);
        if constexpr(type == Invalid || g_opcodeFuncs[type] == nullptr) {
            op_Parallel(op);
        } else {
            const auto preA = reg.a;
            const auto preB = reg.b;
            (this->*g_opcodeFuncs[type])(Alu);
            const auto postA = reg.a;
            const auto postB = reg.b;
            reg.a = preA;
            reg.b = preB;
            (this->*m_opcodeCache[pcCurrentInstruction].opMove)(op);
            if(postA != preA) reg.a = postA;
            if(postB != preB) reg.b = postB;
        }
    }
    template<size_t... I> constexpr auto parallelAluHandlers(std::index_sequence<I...>) {
        return std::array<TInstructionFunc, sizeof...(I)>{&DSP::op_ParallelCached<I>...};
    }
    TInstructionFunc DSP::resolveParallelAlu(TWord op, Instruction alu) {
        static constexpr auto handlers = parallelAluHandlers(std::make_index_sequence<256>{});
        // The ordinary decoder enforces operand restrictions. Keep its handler
        // for any ambiguous encoding instead of changing decoding precedence.
        return parallelAluType(op & 255) == alu ? handlers[op & 255] : &DSP::op_Parallel;
    }


	constexpr size_t g_opcodeFuncsSize = sizeof(g_opcodeFuncs) / sizeof(g_opcodeFuncs[0]);
	static_assert(g_opcodeFuncsSize <= 256, "jump table too large");

	using TField = std::pair<Field,TWord>;	// Field + Field Value

	struct FieldPermutationType
	{
		constexpr explicit FieldPermutationType(const Instruction _instruction, const TField _field) noexcept
		: instruction(_instruction)
		, field(_field)
		{
		}

		const Instruction instruction;
		const TField field;
	};

	constexpr FieldPermutationType g_permutationTypes[] =
	{
		FieldPermutationType(Abs, {Field_d, 0}),
		FieldPermutationType(Abs, {Field_d, 1}),

		FieldPermutationType(Asl_D, {Field_d, 0}),
		FieldPermutationType(Asl_D, {Field_d, 1}),
		
		FieldPermutationType(And_SD, {Field_d, 0}),
		FieldPermutationType(And_SD, {Field_d, 1}),
		FieldPermutationType(And_SD, {Field_JJ, 0}),
		FieldPermutationType(And_SD, {Field_JJ, 1}),
		FieldPermutationType(And_SD, {Field_JJ, 2}),
		FieldPermutationType(And_SD, {Field_JJ, 3}),
/*
		FieldPermutationType(Movexy, {Field_MM, 0}),
		FieldPermutationType(Movexy, {Field_MM, 1}),
		FieldPermutationType(Movexy, {Field_MM, 2}),
		FieldPermutationType(Movexy, {Field_MM, 3}),

		FieldPermutationType(Movexy, {Field_RRR, 0}),
		FieldPermutationType(Movexy, {Field_RRR, 1}),
		FieldPermutationType(Movexy, {Field_RRR, 2}),
		FieldPermutationType(Movexy, {Field_RRR, 3}),
		FieldPermutationType(Movexy, {Field_RRR, 4}),
		FieldPermutationType(Movexy, {Field_RRR, 5}),
		FieldPermutationType(Movexy, {Field_RRR, 6}),
		FieldPermutationType(Movexy, {Field_RRR, 7}),

		FieldPermutationType(Movexy, {Field_mm, 0}),
		FieldPermutationType(Movexy, {Field_mm, 1}),
		FieldPermutationType(Movexy, {Field_mm, 2}),
		FieldPermutationType(Movexy, {Field_mm, 3}),

		FieldPermutationType(Movexy, {Field_rr, 0}),
		FieldPermutationType(Movexy, {Field_rr, 1}),
		FieldPermutationType(Movexy, {Field_rr, 2}),
		FieldPermutationType(Movexy, {Field_rr, 3}),
*/
		FieldPermutationType(Movexy, {Field_W, 0}),
		FieldPermutationType(Movexy, {Field_W, 1}),

		FieldPermutationType(Movexy, {Field_w, 0}),
		FieldPermutationType(Movexy, {Field_w, 1}),

		FieldPermutationType(Movexy, {Field_ee, 0}),
		FieldPermutationType(Movexy, {Field_ee, 1}),
		FieldPermutationType(Movexy, {Field_ee, 2}),
		FieldPermutationType(Movexy, {Field_ee, 3}),

		FieldPermutationType(Movexy, {Field_ff, 0}),
		FieldPermutationType(Movexy, {Field_ff, 1}),
		FieldPermutationType(Movexy, {Field_ff, 2}),
		FieldPermutationType(Movexy, {Field_ff, 3}),

		FieldPermutationType(Movex_ea, {Field_W, 0}),
		FieldPermutationType(Movex_ea, {Field_W, 1}),

		FieldPermutationType(Movex_ea, {Field_MMM, 0}),
		FieldPermutationType(Movex_ea, {Field_MMM, 1}),
		FieldPermutationType(Movex_ea, {Field_MMM, 2}),
		FieldPermutationType(Movex_ea, {Field_MMM, 3}),
		FieldPermutationType(Movex_ea, {Field_MMM, 4}),
		FieldPermutationType(Movex_ea, {Field_MMM, 5}),
		FieldPermutationType(Movex_ea, {Field_MMM, 6}),
		FieldPermutationType(Movex_ea, {Field_MMM, 7}),

		FieldPermutationType(Movex_aa, {Field_W, 0}),
		FieldPermutationType(Movex_aa, {Field_W, 1}),

		FieldPermutationType(Movey_ea, {Field_W, 0}),
		FieldPermutationType(Movey_ea, {Field_W, 1}),
		FieldPermutationType(Movey_aa, {Field_W, 0}),
		FieldPermutationType(Movey_aa, {Field_W, 1}),
		
		FieldPermutationType(Movey_ea, {Field_MMM, 0}),
		FieldPermutationType(Movey_ea, {Field_MMM, 1}),
		FieldPermutationType(Movey_ea, {Field_MMM, 2}),
		FieldPermutationType(Movey_ea, {Field_MMM, 3}),
		FieldPermutationType(Movey_ea, {Field_MMM, 4}),
		FieldPermutationType(Movey_ea, {Field_MMM, 5}),
		FieldPermutationType(Movey_ea, {Field_MMM, 6}),
		FieldPermutationType(Movey_ea, {Field_MMM, 7}),
	};

	constexpr size_t g_permutationTypeCount = sizeof(g_permutationTypes) / sizeof(g_permutationTypes[0]);

	struct FunctorAbs		{ template<TWord A>				constexpr TInstructionFunc get() const noexcept	{ return &DSP::opCE_Abs<A>;			} };
	struct FunctorAsl		{ template<TWord A>				constexpr TInstructionFunc get() const noexcept	{ return &DSP::opCE_Asl_D<A>;		} };
	struct FunctorAndSD		{ template<TWord A, TWord B>	constexpr TInstructionFunc get() const noexcept { return &DSP::opCE_And_SD<A,B>;	} };

	struct FunctorMovexy	{ template<TWord W, TWord w, TWord ee, TWord ff>	constexpr TInstructionFunc get() const noexcept { return &DSP::opCE_Movexy<W,w,ee,ff>;	} };

	struct FunctorMovex_ea	{ template<TWord W, TWord MMM>	constexpr TInstructionFunc get() const noexcept { return &DSP::opCE_Movex_ea<W, MMM>;	} };
	struct FunctorMovey_ea	{ template<TWord W, TWord MMM>	constexpr TInstructionFunc get() const noexcept { return &DSP::opCE_Movey_ea<W, MMM>;	} };

	struct FunctorMovex_aa	{ template<TWord W>	constexpr TInstructionFunc get() const noexcept { return &DSP::opCE_Movex_aa<W>;	} };
	struct FunctorMovey_aa	{ template<TWord W>	constexpr TInstructionFunc get() const noexcept { return &DSP::opCE_Movey_aa<W>;	} };

	constexpr TWord permutationCount(const Instruction _inst, const Field _field) noexcept
	{
		TWord result = 0;

		for (auto permutationType : g_permutationTypes)
		{
			if(permutationType.instruction == _inst && permutationType.field.first == _field)
				++result;
		}
		return result;
	}

	template<Instruction I, Field F>
	constexpr TWord permutationCount() noexcept
	{
		return permutationCount(I, F);
	}

	template<Instruction I>
	constexpr TWord permutationCount() noexcept
	{
		TWord result = 1;

		for(size_t f=0; f<Field_COUNT; ++f)
		{
			result *= std::max(static_cast<TWord>(1), permutationCount(I, static_cast<Field>(f)));
		}

		return result;
	}
	
	template<Instruction I, Field F, TWord _index>
	constexpr TWord permutationValue() noexcept
	{
		static_assert(getFieldInfoCE<I,F>().len > 0, "field not known for opcode");

		TWord index=0;

		for(size_t i=0; i<g_permutationTypeCount; ++i)
		{
			if(g_permutationTypes[i].instruction != I || g_permutationTypes[i].field.first != F)
				continue;

			if(index == _index)
			{
				return g_permutationTypes[i].field.second;
			}

			++index;
		}

		return 0;
	}

	template<Instruction I> constexpr TWord fieldCount()
	{
		TWord count = 0;
		auto lastField = Field_COUNT;

		for(auto p : g_permutationTypes)
		{
			if(p.instruction != I)
				continue;
			if(p.field.first != lastField)
			{
				++count;
				lastField = p.field.first;
			}
		}
		return count;
	}

	constexpr TWord totalPermutationCount()
	{
		TWord count = 0;
		auto lastField = Field_COUNT;

		for(auto p : g_permutationTypes)
		{
			if(p.field.first != lastField)
			{
				count += permutationCount(p.instruction, p.field.first);
				lastField = p.field.first;
			}
		}
		return count;
	}

	template<Instruction I>
	struct Permutation
	{
		Instruction inst;
		TInstructionFunc func;
		std::array<TField, fieldCount<I>()> fields;
	};

	template<Instruction I>
	using TPermutations = std::array<Permutation<I>,permutationCount<I>()>;

	template<Instruction I, TWord ...Fs> constexpr TWord permIndex(const Field FieldOfInterest, const TWord offset)
	{
		const TWord d[] = {Fs...};
		uint32_t mul = 1;
		for(size_t i=0; i<sizeof...(Fs); ++i)
		{
			if(d[i] == FieldOfInterest)
				return (offset / mul) % permutationCount(I,static_cast<Field>(d[i]));
			mul *= permutationCount(I,static_cast<Field>(d[i]));
		}
		return 0;
	}

	template<Field... Fields>
	struct FieldSequence
	{
		static constexpr size_t size() noexcept { return (sizeof...(Fields)); }
	};

	template<Instruction I, Field... Fs>
	auto constexpr permIndex(Field FieldOfInterest, TWord Offset, FieldSequence<Fs...>)
	{
	    return permIndex<I, Fs...>(FieldOfInterest, Offset);
	}

	using TPack = uint32_t;

	template<Instruction I, Field F, TWord Index> constexpr TPack packValues()
	{
		static_assert(F < 256, "field too large");
		static_assert(Index < 256, "index too large");
//		static_assert(permutationCount<I,F>() <= 256, "too many permutations");
		return (F) | (Index << 8);// | permutationCount<I,F>() << 16;
	}

	template<TPack Pack> constexpr Field unpackField()								{ return static_cast<Field>((Pack >> 0) & 0xff); }
	template<TPack Pack> constexpr TWord unpackIndex()								{ return static_cast<TWord>((Pack >> 8) & 0xff); }
//	template<Instruction I, TPack Pack> constexpr TWord unpackPermutationCount()	{ return static_cast<TWord>((Pack >> 16) & 0xffff); }	// Note: we can omit storing the permutationcount if we need more storage in the pack, will be more costly then but will work

	template<Instruction I, TPack Pack> constexpr TWord permutationValue()			{ return permutationValue<I, unpackField<Pack>(), unpackIndex<Pack>()>(); }

	template<typename Functor, Instruction I, TPack ...Pack> constexpr TInstructionFunc getPtr()
	{
		return Functor().template get< permutationValue<I, Pack>()...>();
	}

	template<Instruction I, TPack Pack> constexpr TField getTField()
	{
		return std::make_pair<Field,TWord>(unpackField<Pack>(), permutationValue<I, Pack>());
	}

	template<typename Functor, Instruction I, TPack ...Pack> constexpr Permutation<I> getPermutationFromPack()
	{
		return 
		{
			I,
			getPtr<Functor, I, Pack...>(),
			{getTField<I,Pack>()...},
		};
	}

	template<typename Functor, Instruction I, TWord Index, Field ...Fields> constexpr auto getPermutationFromPack(FieldSequence<Fields...> fields)
	{
		return getPermutationFromPack<Functor, I, packValues<I, Fields, permIndex<I>(Fields, Index, fields)>()...>();
	}

	template<typename Functor, Instruction I, TWord IdxLeft, TWord IdxRight, Field ...Fields>
	constexpr void getPermutationsRecursive(TPermutations<I>& _target)
	{
		if constexpr (IdxLeft == IdxRight)
		{
			_target[IdxLeft] = getPermutationFromPack<Functor, I, IdxLeft, Fields...>(FieldSequence<Fields...>());			
		}
		else if((IdxRight - IdxLeft) == 1)
		{
			_target[IdxLeft] = getPermutationFromPack<Functor, I, IdxLeft, Fields...>(FieldSequence<Fields...>());			
			_target[IdxRight] = getPermutationFromPack<Functor, I, IdxRight, Fields...>(FieldSequence<Fields...>());			
		}
		else
		{
			getPermutationsRecursive<Functor, I, IdxLeft, IdxLeft + (IdxRight-IdxLeft)/2, Fields...>(_target);
			getPermutationsRecursive<Functor, I, IdxLeft + (IdxRight-IdxLeft)/2, IdxRight, Fields...>(_target);
		}
	}

	template<typename Functor, Instruction I, Field ...Fields> constexpr TPermutations<I> getFuncs()
	{
		TPermutations<I> funcs{};
		static_assert((permutationCount<I>() & (permutationCount<I>()-1)) == 0, "permutation count needs to be a power of two");

		getPermutationsRecursive<Functor, I, 0, permutationCount<I>() - 1, Fields...>(funcs);

		return funcs;
	}
	/*
	static_assert(permutationCount(Abs, Field_d) == 2, "something wrong");
	static_assert(permutationCount(And_SD, Field_d) == 2, "something wrong");
	static_assert(permutationCount(And_SD, Field_JJ) == 4, "something wrong");
	static_assert(permutationCount<And_SD>() == 8, "something wrong");

	static_assert(permutationValue<Abs, Field_d,1>() == 1, "unexpected value for Field_d");
	static_assert(permutationValue<And_SD, Field_JJ,3>() == 3, "unexpected value for Field_JJ");
	*/

	class Jumptable
	{
	public:
		Jumptable()
		{
			m_jumpTable.reserve(g_opcodeFuncsSize);

			for(size_t i=0; i<g_opcodeFuncsSize; ++i)
				m_jumpTable.push_back(g_opcodeFuncs[i]);

			addPermutations(getFuncs<FunctorAbs, Abs, Field_d>());
			addPermutations(getFuncs<FunctorAndSD, And_SD, Field_d, Field_JJ>());
			addPermutations(getFuncs<FunctorMovexy, Movexy, Field_W, Field_w, Field_ee, Field_ff>());
			addPermutations(getFuncs<FunctorMovex_ea, Movex_ea, Field_W, Field_MMM>());
			addPermutations(getFuncs<FunctorMovex_aa, Movex_aa, Field_W>());
			addPermutations(getFuncs<FunctorMovey_ea, Movey_ea, Field_W, Field_MMM>());
			addPermutations(getFuncs<FunctorMovey_aa, Movey_aa, Field_W>());
		}

		const std::vector<TInstructionFunc>& jumptable() const { return m_jumpTable; }
		TWord resolve(const Instruction _inst, const TWord _op) const
		{
			const auto& perms = m_permutationInfo[_inst];

			if(perms.permutations.empty())
				return _inst;

			for(const auto& p : perms.permutations)
			{
				bool match = true;

				for(const auto& f : p.fields)
				{
					assert(hasField(_inst, f.first));

					const auto v = getFieldValue(_inst, f.first, _op);

					if(v != f.second)
					{
						match = false;
						break;
					}
				}
				if(match)
					return p.jumpTableIndex;
			}

			return _inst;
		}
	private:
		struct FieldValues
		{
			Field field;
			std::vector<TWord> values;
			std::vector<FieldValues> children;
		};

		struct PermutationInfo
		{
			TWord jumpTableIndex = 0;
			std::vector<TField> fields;
		};

		struct PermutationList
		{
			std::vector<PermutationInfo> permutations;
		};

		template<Instruction I>
		void addPermutations(const TPermutations<I>& _permutations)
		{
			auto& pl = m_permutationInfo[I];
			pl.permutations.clear();

			for (const Permutation<I>& p : _permutations)
			{
				PermutationInfo pi;

				pi.jumpTableIndex = (TWord)m_jumpTable.size();
				pi.fields.reserve(p.fields.size());

				for(const auto& f : p.fields)
					pi.fields.push_back(f);

				m_jumpTable.push_back(p.func);

				pl.permutations.emplace_back(pi);
			}
		}

		std::vector<TInstructionFunc> m_jumpTable;
		std::array<PermutationList, InstructionCount> m_permutationInfo;
	};

    inline DSP::OpcodeCacheEntry DSP::resolveCacheEntry() {
        return {&DSP::op_ResolveCache, nullptr, nullptr, 0, &DSP::threadedOp<&DSP::op_ResolveCache>};
    }
    template<TInstructionFunc Func> void DSP56K_INTERPRETER_CC DSP::threadedOp(DSP* dsp, uint64_t target, TWord op, uint32_t cycles) {
        const auto pc = dsp->pcCurrentInstruction;
        if constexpr(g_traceSupported) dsp->getASM(op, dsp->m_opWordB);
        if constexpr(Func == &DSP::op_ResolveCache)
            if(!dsp->usesJit()) cycles = dsp->getOpcodeCycles(pc);
        dsp->m_currentOpLen = 1;
        (dsp->*Func)(op);
        if(dsp->pcCurrentInstruction == pc) {
            ++dsp->m_instructions;
            if(!dsp->usesJit()) dsp->m_cycles += cycles;
            if constexpr(g_traceSupported) dsp->traceOp();
        }
        dsp->finishInterpreterLoops();
#if defined(DSP56K_COOPERATIVE_POLL_LOOPS)
        if constexpr(Func == &DSP::op_Bcc_xxx || Func == &DSP::op_Bcc_xxxx || Func == &DSP::op_Bra_xxx || Func == &DSP::op_Bra_xxxx) {
            if(!dsp->usesJit() && dsp->reg.pc.var <= pc && pc - dsp->reg.pc.var <= 24 && dsp->m_cycles < target)
                dsp->skipStablePollingLoop(pc, target);
        }
#endif
        if(dsp->m_cycles >= target) return;
#if defined(__clang__)
        const auto nextOp = dsp->prepareInterpreterInstruction();
        const auto& entry = dsp->m_opcodeCache[dsp->pcCurrentInstruction];
        // Every slot is seeded by resolveCacheEntry(), so this is never null.
        assert(entry.threaded);
        [[clang::musttail]] return entry.threaded(dsp, target, nextOp, entry.cycles);
#else
        // Non-Clang hosts use the ordinary loop; never grow the call stack.
        while(dsp->m_cycles < target) dsp->execInterpreter();
#endif
    }
#if defined(__clang__) && defined(DSP56K_COOPERATIVE_INTERPRETER)
    // A run of NOPs (opcode word 0) retires in one dispatch. Firmware paces itself
    // with delay loops of hundreds of NOPs, and each one cost a full threaded
    // dispatch (a fifth of the Machinedrum's whole budget on an iPad). This is
    // exact: the same instructions and cycles are charged, and a run stops at
    // the current DO loop's last address, at the next peripheral deadline and at
    // the scheduler's target, so nothing observable moves. A run that is a whole
    // DO body also charges the remaining iterations that fit the same bounds.
    // Only the threaded path uses it; REP and other direct callers of the cache
    // entry's op still see a plain single NOP.
    void DSP56K_INTERPRETER_CC DSP::threadedNopRun(DSP* dsp, uint64_t target, TWord op, uint32_t cycles) {
        const auto pc = dsp->pcCurrentInstruction;
        if constexpr(g_traceSupported) dsp->getASM(op, dsp->m_opWordB);
        dsp->m_currentOpLen = 1;
        const uint64_t perCycles = cycles ? cycles : 1;
        // Instructions that may retire before a deadline must be observed again.
        uint64_t budget = 1;
        if(dsp->m_checkInstr > dsp->m_instructions && dsp->m_checkCycle > dsp->m_cycles && target > dsp->m_cycles) {
            budget = std::min<uint64_t>(dsp->m_checkInstr - dsp->m_instructions, (dsp->m_checkCycle - dsp->m_cycles) / perCycles);
            budget = std::min<uint64_t>(budget, (target - dsp->m_cycles + perCycles - 1) / perCycles);
            if(!budget) budget = 1;
        }
        uint32_t limit = static_cast<uint32_t>(std::min<uint64_t>(budget, 64));
        const bool inLoop = dsp->sr_test_noCache(SR_LF) && dsp->reg.la.var >= pc;
        if(inLoop) limit = static_cast<uint32_t>(std::min<uint64_t>(limit, dsp->reg.la.var - pc + 1));
        const auto sizeP = dsp->mem.sizeP();
        if(pc + limit > sizeP) limit = pc < sizeP ? static_cast<uint32_t>(sizeP - pc) : 1;
        // Read the words the way the fetch does (memReadOpcode, the raw P array), not
        // through the checked data-read path: the scan repeats on every peripheral
        // tick, and the link ESSIs raise one every few dozen cycles.
        uint32_t n = 1;
        if constexpr(g_useAARTranslate) {
            for(TWord a, b; n < limit; ++n) { dsp->memReadOpcode(pc + n, a, b); if(a) break; }
        } else {
            const TWord* program = dsp->mem.getMemAreaPtr(MemArea_P);
            while(n < limit && program[pc + n] == 0) ++n;
        }
        uint64_t retired = n;
        if(inLoop && pc + n - 1 == dsp->reg.la.var && dsp->reg.lc.var > 1 && hiword(dsp->reg.ss[dsp->ssIndex()]).var == pc) {
            const uint64_t remaining = budget > n ? (budget - n) / n : 0;
            const uint64_t k = std::min<uint64_t>(remaining, dsp->reg.lc.var - 1);
            dsp->reg.lc.var -= static_cast<TWord>(k);
            retired += k * n;
        }
        dsp->reg.pc.var = pc + n;
        dsp->m_instructions += retired;
        dsp->m_cycles += retired * cycles;
        if constexpr(g_traceSupported) dsp->traceOp();
        dsp->finishInterpreterLoops();
        if(dsp->m_cycles >= target) return;
        const auto nextOp = dsp->prepareInterpreterInstruction();
        const auto& entry = dsp->m_opcodeCache[dsp->pcCurrentInstruction];
        assert(entry.threaded);
        [[clang::musttail]] return entry.threaded(dsp, target, nextOp, entry.cycles);
    }
#endif
    void DSP::execInterpreterThreaded(uint64_t targetCycles) noexcept {
#if !defined(__clang__)
        do { execInterpreter(); } while(m_cycles < targetCycles);
#else
        if(usesJit()) {
            if(m_opcodeCache.empty()) clearOpcodeCache();
            // Explicit interpreter diagnostics in JIT binaries do not charge
            // cycles. A single-step entry is still available for parity tests.
            targetCycles = 0;
        }
        // Other processors may have changed a polled register while this DSP
        // was yielded, even if it resumes midway through a polling iteration.
        ++m_peripheralEpoch;
        const auto op = prepareInterpreterInstruction();
        const auto& entry = m_opcodeCache[pcCurrentInstruction];
        assert(entry.threaded);
        entry.threaded(this, targetCycles, op, entry.cycles);
#endif
    }
    struct ThreadedHandlerPair { TInstructionFunc op; TThreadedInstructionFunc threaded; };
    template<TInstructionFunc Op> constexpr TThreadedInstructionFunc baseThreadedHandler() {
        if constexpr(Op == nullptr) return nullptr;
        else return &DSP::threadedOp<Op>;
    }
    template<size_t... I> constexpr auto baseThreadedHandlers(std::index_sequence<I...>) {
        return std::array<ThreadedHandlerPair, sizeof...(I)>{
            ThreadedHandlerPair{g_opcodeFuncs[I], baseThreadedHandler<g_opcodeFuncs[I]>()}...};
    }
    template<size_t... I> constexpr auto aluThreadedHandlers(std::index_sequence<I...>) {
        return std::array<ThreadedHandlerPair, sizeof...(I)>{
            ThreadedHandlerPair{&DSP::op_ParallelCached<I>, &DSP::threadedOp<&DSP::op_ParallelCached<I>>}...};
    }
    template<typename Functor, Instruction I, size_t N, Field... Fields>
    constexpr ThreadedHandlerPair threadedPermutation() {
        constexpr auto perm = getPermutationFromPack<Functor, I, N, Fields...>(FieldSequence<Fields...>{});
        return {perm.func, &DSP::threadedOp<perm.func>};
    }
    template<typename Functor, Instruction I, Field... Fields, size_t... N>
    constexpr auto permutationThreadedHandlers(std::index_sequence<N...>) {
        return std::array<ThreadedHandlerPair, sizeof...(N)>{threadedPermutation<Functor, I, N, Fields...>()...};
    }
    TThreadedInstructionFunc DSP::resolveThreaded(TInstructionFunc op) {
        static constexpr auto base = baseThreadedHandlers(std::make_index_sequence<g_opcodeFuncsSize>{});
        static constexpr auto alu = aluThreadedHandlers(std::make_index_sequence<256>{});
        const auto find = [op](const auto& handlers) -> TThreadedInstructionFunc {
            for(const auto& handler : handlers) if(handler.op == op) return handler.threaded;
            return nullptr;
        };
        if(auto f = find(base)) return f;
        if(auto f = find(alu)) return f;
#define DSP_THREADED_PERMS(Functor, Inst, ...) \
        { static constexpr auto table = permutationThreadedHandlers<Functor, Inst, __VA_ARGS__>(std::make_index_sequence<permutationCount<Inst>()>{}); \
          if(auto f = find(table)) return f; }
        DSP_THREADED_PERMS(FunctorAbs, Abs, Field_d)
        DSP_THREADED_PERMS(FunctorAndSD, And_SD, Field_d, Field_JJ)
        DSP_THREADED_PERMS(FunctorMovexy, Movexy, Field_W, Field_w, Field_ee, Field_ff)
        DSP_THREADED_PERMS(FunctorMovex_ea, Movex_ea, Field_W, Field_MMM)
        DSP_THREADED_PERMS(FunctorMovex_aa, Movex_aa, Field_W)
        DSP_THREADED_PERMS(FunctorMovey_ea, Movey_ea, Field_W, Field_MMM)
        DSP_THREADED_PERMS(FunctorMovey_aa, Movey_aa, Field_W)
#undef DSP_THREADED_PERMS
        if(op == &DSP::op_Parallel) return &DSP::threadedOp<&DSP::op_Parallel>;
        assert(false && "missing threaded opcode handler");
        return &DSP::threadedOp<&DSP::op_ResolveCache>;
    }

    // Fuse common parallel move forms with their ALU byte at build time.
    // These are ordinary signed native functions; no runtime code generation.
    template<TInstructionFunc Move, TWord Alu> ASMJIT_FORCE_INLINE void DSP::op_ParallelFused(TWord op) {
        constexpr auto type=parallelAluType(Alu);
        if constexpr(type==Invalid || g_opcodeFuncs[type]==nullptr) {
            op_Parallel(op);
        } else {
            const auto preA=reg.a, preB=reg.b;
            (this->*g_opcodeFuncs[type])(Alu);
            const auto postA=reg.a, postB=reg.b;
            reg.a=preA; reg.b=preB;
            (this->*Move)(op);
            if(postA!=preA) reg.a=postA;
            if(postB!=preB) reg.b=postB;
        }
    }
    template<TInstructionFunc Move,size_t... Alu>
    constexpr auto fusedHandlers(std::index_sequence<Alu...>) {
        return std::array<InterpreterHandlers,sizeof...(Alu)>{
            InterpreterHandlers{&DSP::op_ParallelFused<Move,Alu>,&DSP::threadedOp<&DSP::op_ParallelFused<Move,Alu>>}...};
    }
    template<TInstructionFunc Move> const InterpreterHandlers* fusedHandlers() {
        static constexpr auto handlers=fusedHandlers<Move>(std::make_index_sequence<256>{});
        return handlers.data();
    }
    template<TWord Op, Instruction Move>
    ASMJIT_FORCE_INLINE void DSP::op_ParallelStatic(TWord op) {
        assert(op == Op);
        constexpr auto type=parallelAluType(Op & 255);
        static_assert(type!=Invalid && g_opcodeFuncs[type]!=nullptr);
        const auto preA=reg.a, preB=reg.b;
        (this->*g_opcodeFuncs[type])(Op & 255);
        const auto postA=reg.a, postB=reg.b;
        reg.a=preA; reg.b=preB;
        // Force only these few constant-operand call sites into the handler.
        // The generic move helpers retain their normal inlining policy.
#if defined(__clang__)
#define DSP_STATIC_INLINE [[clang::always_inline]]
#else
#define DSP_STATIC_INLINE
#endif
        if constexpr(Move==Movexr_ea) {
            DSP_STATIC_INLINE op_Movexr_ea(Op);
        } else if constexpr(Move==Movex_ea || Move==Movey_ea) {
            constexpr auto w=getFieldValue(getFieldInfoCE<Move,Field_W>(),Op);
            constexpr auto mmm=getFieldValue(getFieldInfoCE<Move,Field_MMM>(),Op);
            constexpr auto area=Move==Movex_ea?MemArea_X:MemArea_Y;
            DSP_STATIC_INLINE move_ddddd_MMMRRR<Move,area,w,mmm>(Op);
        } else if constexpr(Move==Movexy) {
            constexpr auto w=getFieldValue(getFieldInfoCE<Move,Field_W>(),Op);
            constexpr auto y=getFieldValue(getFieldInfoCE<Move,Field_w>(),Op);
            constexpr auto ee=getFieldValue(getFieldInfoCE<Move,Field_ee>(),Op);
            constexpr auto ff=getFieldValue(getFieldInfoCE<Move,Field_ff>(),Op);
            DSP_STATIC_INLINE opCE_Movexy<w,y,ee,ff>(Op);
        }
#undef DSP_STATIC_INLINE
        if(postA!=preA) reg.a=postA;
        if(postB!=preB) reg.b=postB;
    }
    InterpreterHandlers DSP::resolveStaticParallel(TWord op) {
#if defined(DSP56K_STATIC_PARALLEL_OPCODES)
        if constexpr(!g_traceSupported) {
            switch(op) {
#define DSP_STATIC_PARALLEL(Op, Move) \
                case Op: return {&DSP::op_ParallelStatic<Op,Move>, &DSP::threadedOp<&DSP::op_ParallelStatic<Op,Move>>};
#include "staticparallelops.inc"
#undef DSP_STATIC_PARALLEL
            }
        }
#endif
        return {};
    }

    InterpreterHandlers DSP::resolveParallelHandlers(TInstructionFunc move,TWord op,Instruction alu) {
        if(parallelAluType(op&255)==alu) {
#define DSP_FUSED_MOVE(...) \
            if(move==__VA_ARGS__) return fusedHandlers<__VA_ARGS__>()[op&255];
            DSP_FUSED_MOVE(&DSP::opCE_Movexy<1,1,1,0>)
            DSP_FUSED_MOVE(&DSP::opCE_Movexy<1,1,0,0>)
            DSP_FUSED_MOVE(&DSP::opCE_Movexy<0,1,2,0>)
            DSP_FUSED_MOVE(&DSP::opCE_Movexy<0,1,3,1>)
            DSP_FUSED_MOVE(&DSP::opCE_Movexy<1,0,0,2>)
            DSP_FUSED_MOVE(&DSP::opCE_Movexy<1,0,0,3>)
            DSP_FUSED_MOVE(&DSP::opCE_Movex_ea<1,1>)
            DSP_FUSED_MOVE(&DSP::opCE_Movex_ea<1,3>)
            DSP_FUSED_MOVE(&DSP::opCE_Movex_ea<1,4>)
            DSP_FUSED_MOVE(&DSP::opCE_Movex_ea<0,3>)
            DSP_FUSED_MOVE(&DSP::opCE_Movey_ea<1,3>)
            DSP_FUSED_MOVE(&DSP::opCE_Movey_ea<0,3>)
            DSP_FUSED_MOVE(&DSP::op_Movexr_ea)
            DSP_FUSED_MOVE(&DSP::op_Moveyr_ea)
            DSP_FUSED_MOVE(&DSP::op_Mover)
#undef DSP_FUSED_MOVE
        }
        const auto handler=resolveParallelAlu(op,alu);
        return {handler,resolveThreaded(handler)};
    }

}
