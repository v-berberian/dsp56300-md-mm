#pragma once

#include "error.h"
#include "types.h"
#include "utils.h"

namespace dsp56k
{
	class AGU
	{
	public:
		static TWord calcModuloMask(TWord m)
		{
//			const auto zeroBits = countZeroBitsReversed(m);
//			const int testRes = (1<<((sizeof(m)*CHAR_BIT)-zeroBits))-1;

			m |= m >> 1;
			m |= m >> 2;
			m |= m >> 4;
			m |= m >> 8;

//			assert(m == testRes);
			return m;
		}

		template<bool add>
		static void updateAddressRegister( TWord& r, TWord n, TWord m, TWord moduloMask, int32_t modulo )
		{
			// modulo or linear addressing
			if (moduloMask)
			{
				// Linear (modulo == 0) and multiple-wrap-around (modulo == -1) leave through one
				// test: modulo + 1 is 1 or 0 for exactly these two. Linear is the common case and
				// the modes alternate per register, so a second data-dependent branch here would
				// cost more than the modulo arithmetic it skips. Unsigned add, no overflow UB.
				if (static_cast<uint32_t>(modulo) + 1u <= 1u)
				{
					if (modulo == 0)	// Linear addressing.
					{
						// Identical to the modulo arm with modulo == 0: both fixups add zero and
						// only the low 24 bits survive the final mask, so n needs no sign extension.
						if constexpr (add)
							r += n;
						else
							r -= n;
						r &= 0x00ffffff;
						return;
					}

					// Multiple-wrap-around.
					auto temp = r & moduloMask;
					r ^= temp;
					if constexpr (add)
						temp += n;
					else
						temp -= n;
					temp &= moduloMask;
					r |= temp;
					return;
				}


				n = signextend<int, 24>(n);

				const auto lowerBound = r & ~moduloMask;
				const auto upperBound = lowerBound + m;

				if constexpr(add)
					r += n;
				else
					r -= n;

				modulo = n & moduloMask ? modulo : 0;

				if(r < lowerBound)
					r += modulo;
				if(r > upperBound)
					r -= modulo;
				/*
				if constexpr(add)
				{
					r += n;
					n &= moduloMask;
					r -= n;
				}
				else
				{
					r -= n;
					n &= moduloMask;
					r += n;
				}

				// If (rOffset<0) then bit 31 of rOffset is set. Shift it down 31 places to get -1. Otherwise you have 0.
				// and this value with modulo to get either modulo or zero. Add to rOffset.
				// If (moduloTest-rOffset<0) (rOffset>moduloTest) (i.e. rOffset exceeds moduloTest), do the same trick.
				if constexpr(add)
				{
					const int32_t p				= (r & moduloMask) + n;
					const int32_t mt			= static_cast<int32_t>(m) - p;
					r += n;
					r += (p>>31) & modulo;
					r -= (mt>>31) & modulo;
				}
				else
				{
					const int32_t p				= (r & moduloMask) - n;
					const int32_t mt			= static_cast<int32_t>(m) - p;
					r -= n;
					r += (p>>31) & modulo;
					r -= (mt>>31) & modulo;
				}
*/			}
			else	// bit-reverse mode
			{
//				const auto or = r;
//				const auto on = n;

				r = bitreverse24(r);
				n = bitreverse24(n);
//				LOG("BitReverse r=" << HEX(or) << ", n=" << HEX(on) << ", rr=" << HEX(r) << ", rn=" << HEX(n) << ", resRev=" << HEX(r+n) << ", res=" << HEX(bitreverse24(r+n)));
				if constexpr(add)
					r += n;
				else
					r -= n;
				r = bitreverse24(r);
			}

			r &= 0x00ffffff;
		}
	};
};
