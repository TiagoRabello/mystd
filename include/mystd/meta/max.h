#ifndef _MYSTD_META_MAX
#define _MYSTD_META_MAX

#include <type_traits> // for std::conditional and std::integral_constant

namespace mystd
{
  namespace meta
  {
    ///////////////////////////////////////////////////////////////////////////
    /// Obtains the maximum value among a list of compile-time numbers.
    ///
    /// Compile-time Complexity: O(N)
    ///////////////////////////////////////////////////////////////////////////
    template<int... numbers> struct max;

    ///////////////////////////////////////////////////////////////////////////
    // max implementation.
    ///////////////////////////////////////////////////////////////////////////
    template<int number>
    struct max<number> : std::integral_constant<int, number> { };

    template<int max_value, int head, int... tail>
    struct max<max_value, head, tail...>
    : conditional_t<(head > max_value), max<     head, tail...>
                                      , max<max_value, tail...>>
    {};

  } // End of meta namespace.
} // End of mystd namespace.

#endif