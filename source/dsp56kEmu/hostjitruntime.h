#pragma once
#include "asmjit/core/jitruntime.h"
#include "asmjit/core/virtmem.h"
#include <set>

#ifdef DSP56K_EXTERNAL_JIT_MEMORY
// Host supplies a prepared executable arena. No executable mapping is created
// by the DSP runtime; both DSPs and their trampolines use the same bounded pool.
extern "C" bool dsp56kHostJitAllocate(size_t,void**,void**);
extern "C" bool dsp56kHostJitRelease(void*);
extern "C" void dsp56kHostJitFlush(void*,void*,size_t);
namespace dsp56k {
class HostJitRuntime final : public asmjit::JitRuntime {
public:
    ~HostJitRuntime() override { for(auto p:allocations) dsp56kHostJitRelease(p); }
    asmjit::Error _add(void** result,asmjit::CodeHolder* code) noexcept override {
        using namespace asmjit;
        *result=nullptr;
        auto error=code->flatten(); if(error) return error;
        error=code->resolveUnresolvedLinks(); if(error) return error;
        const auto size=code->codeSize();
        if(!size) return kErrorNoCodeGenerated;
        void* rx=nullptr; void* rw=nullptr;
        if(!dsp56kHostJitAllocate(size,&rx,&rw)) return kErrorOutOfMemory;
        error=code->relocateToBase(reinterpret_cast<uintptr_t>(rx));
        if(!error) {
            VirtMem::ProtectJitReadWriteScope write(rx,size);
            error=code->copyFlattenedData(rw,size,CopySectionFlags::kPadSectionBuffer);
            if(!error) dsp56kHostJitFlush(rx,rw,code->codeSize());
        }
        if(error) { dsp56kHostJitRelease(rx); return error; }
        allocations.insert(rx); *result=rx;
        return kErrorOk;
    }
    asmjit::Error _release(void* pointer) noexcept override {
        if(!allocations.erase(pointer)) return asmjit::kErrorInvalidArgument;
        return dsp56kHostJitRelease(pointer)?asmjit::kErrorOk:asmjit::kErrorInvalidArgument;
    }
private:
    std::set<void*> allocations;
};
}
#else
namespace dsp56k { using HostJitRuntime=asmjit::JitRuntime; }
#endif
