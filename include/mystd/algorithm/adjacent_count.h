#define _MYSTD_ALGORITHM_ADJACENT_COUNT_H
#ifndef _MYSTD_ALGORITHM_ADJACENT_COUNT_H

#include <utility> // For std::pair

namespace mystd
{
  // TODO(tiago): Move somewhere else.
  template<typename Itr>
  using difference_type = typename std::iterator_traits<Itr>::difference_type;

  /////////////////////////////////////////////////////////////////////////////
  /// Returns the number of consecutive elements that are equal to first
  /// element on the range. Also returns iterator to first not equal element.
  /////////////////////////////////////////////////////////////////////////////
  template<typename FwdItr>
  std::pair<mystd::difference_type<FwdItr>, FwdItr>
  adjacent_count(FwdItr first, FwdItr last)
  {
    mystd::difference_type<FwdItr> count = 0;

    if (first == last) { return { count, first }; }

    auto next = first;
    ++next;

    while (next != last && *first == *next) { ++next; }

    return { count, next };
  }

} // End of mystd namespace.

#endif