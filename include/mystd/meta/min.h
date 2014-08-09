#ifndef _MYSTD_META_MIN
#define _MYSTD_META_MIN

#include <type_traits> // for std::conditional and std::integral_constant

namespace mystd
{
  namespace meta
  {
    ///////////////////////////////////////////////////////////////////////////
    /// Obtains the minimum value among a list of compile-time numbers.
    ///
    /// Compile-time Complexity: O(N)
    ///////////////////////////////////////////////////////////////////////////
    template<int... numbers> struct min;

    ///////////////////////////////////////////////////////////////////////////
    // min implementation.
    ///////////////////////////////////////////////////////////////////////////
    template<int number>
    struct min<number> : std::integral_constant<int, number> { };

    template<int min_value, int head, int... tail>
    struct min<min_value, head, tail...>
    : conditional_t<(head < min_value), min<     head, tail...>
                                      , min<min_value, tail...>>
    {};

  } // End of meta namespace.
} // End of mystd namespace.

#endif