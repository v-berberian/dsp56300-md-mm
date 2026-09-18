#pragma once

#include "dsp56kBase/mmuhelper.h"
#include "types.h"

namespace dsp56k
{
	// DSP56K_NO_MMU: the iPad build never maps the DSP address space through
	// the host MMU (shm_open is denied on iOS). It shares the Android stub, and
	// Memory::hasMmuSupport() becomes a compile-time false.
#if defined(__ANDROID__) || defined(DSP56K_NO_MMU)
	class MemoryBuffer
	{
	public:
		MemoryBuffer(TWord _pSize, TWord _xySize, TWord _externalMemAddress) {}
		~MemoryBuffer() {}

		bool isValid() const { return false; }

		TWord* ptrX() const { return nullptr; }
		TWord* ptrY() const { return nullptr; }
		TWord* ptrP() const { return nullptr; }
	};
#else
	class MemoryBuffer
	{
	public:
		MemoryBuffer(TWord _pSize, TWord _xySize, TWord _externalMemAddress);
		~MemoryBuffer() = default;

		bool isValid() const { return m_isValid; }

		TWord* ptrX() const { return m_x; }
		TWord* ptrY() const { return m_y; }
		TWord* ptrP() const { return m_p; }

	private:
		MmuHelper m_mmu;

		TWord* m_x = nullptr;
		TWord* m_y = nullptr;
		TWord* m_p = nullptr;

		bool m_isValid = false;
	};
#endif
}
