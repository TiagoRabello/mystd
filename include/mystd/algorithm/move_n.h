#define _MYSTD_ALGORITHM_MOVE_N_H
#ifndef _MYSTD_ALGORITHM_MOVE_N_H

#include <utility> // For std::pair

namespace mystd
{
  /////////////////////////////////////////////////////////////////////////////
  /// Move first n elements from input range to output iterator then returns
  /// resulting iterators.
  /// Both iterators are guaranteed to be incremented n times.
  /////////////////////////////////////////////////////////////////////////////
  template<typename InItr, typename Size, typename OutItr>
  std::pair<InItr, OutItr> move_n(InItr first, Size n, OutItr d_first)
  {
    while (n-- > 0) { *d_first++ = std::move( *first++ ); }
    return { first, d_first };
  }

} // End of mystd namespace.

#endif