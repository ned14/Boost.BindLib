/* 128 bit integer support
(C) 2016 Niall Douglas http://www.nedprod.com/
File Created: Sept 2016


Boost Software License - Version 1.0 - August 17th, 2003

Permission is hereby granted, free of charge, to any person or organization
obtaining a copy of the software and accompanying documentation covered by
this license (the "Software") to use, reproduce, display, distribute,
execute, and transmit the Software, and to prepare derivative works of the
Software, and to permit third-parties to whom the Software is furnished to
do so, all subject to the following:

The copyright notices in the Software and this entire statement, including
the above license grant, this restriction and the following disclaimer,
must be included in all copies of the Software, in whole or in part, and
all derivative works of the Software, unless such copies or derivative
works are solely in the form of machine-executable object code generated by
a source language processor.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/

#ifndef BOOSTLITE_UINT128_HPP
#define BOOSTLITE_UINT128_HPP

#include "config.hpp"

BOOSTLITE_NAMESPACE_BEGIN

namespace integers128
{
  /*! \union uint128
  \brief An unsigned 128 bit value
  */
  union alignas(16) uint128 {
    unsigned char as_bytes[16];
    unsigned short as_shorts[8];
    unsigned int as_ints[4];
    unsigned long long as_longlongs[2];
#if defined(__i386__) || defined(_M_IX86) || defined(__x86_64__) || defined(_M_X64)
#if defined(__x86_64__) || defined(_M_X64) || defined(__SSE2__) || (defined(_M_IX86_FP) && _M_IX86_FP >= 2)
    // Strongly hint to the compiler what to do here
    __m128i as_m128i;
#endif
#endif
    //! Default constructor, no bits set
    uint128() noexcept {}
    //! All bits zero constructor
    constexpr uint128(std::nullptr_t) noexcept : as_longlongs{0, 0} {}
  private:
    static const uint128 &_allbitszero()
    {
      static uint128 v(nullptr);
      return v;
    }

  public:
    explicit operator bool() const noexcept { return (*this) != _allbitszero(); }
    bool operator!() const noexcept { return (*this) == _allbitszero(); }
    bool operator==(const uint128 &o) const noexcept { return as_longlongs[1] == o.as_longlongs[1] && as_longlongs[0] == o.as_longlongs[0]; }
    bool operator!=(const uint128 &o) const noexcept { return as_longlongs[1] != o.as_longlongs[1] || as_longlongs[0] != o.as_longlongs[0]; }
    bool operator<(const uint128 &o) const noexcept { return as_longlongs[0] < o.as_longlongs[0] || (as_longlongs[0] == o.as_longlongs[0] && as_longlongs[1] < o.as_longlongs[1]); }
    bool operator<=(const uint128 &o) const noexcept { return as_longlongs[0] < o.as_longlongs[0] || (as_longlongs[0] == o.as_longlongs[0] && as_longlongs[1] <= o.as_longlongs[1]); }
    bool operator>(const uint128 &o) const noexcept { return as_longlongs[0] > o.as_longlongs[0] || (as_longlongs[0] == o.as_longlongs[0] && as_longlongs[1] > o.as_longlongs[1]); }
    bool operator>=(const uint128 &o) const noexcept { return as_longlongs[0] > o.as_longlongs[0] || (as_longlongs[0] == o.as_longlongs[0] && as_longlongs[1] >= o.as_longlongs[1]); }
  };
  static_assert(sizeof(uint128) == 16, "uint128 is not 16 bytes long!");
  static_assert(alignof(uint128) == 16, "uint128 is not aligned to 16 byte multiples!");
}

BOOSTLITE_NAMESPACE_END

#endif
