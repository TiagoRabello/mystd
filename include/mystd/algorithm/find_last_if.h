#define _MYSTD_ALGORITHM_FIND_LAST_IF_H
#ifndef _MYSTD_ALGORITHM_FIND_LAST_IF_H

#include <mystd/iterator.h> // For mystd::make_reverse_iterator

#include <algorithm> // For std::find_if
#include <iterator>  // For std::prev

namespace mystd
{
  /////////////////////////////////////////////////////////////////////////////
  /// Finds the last element in the range that satisfies predicate.
  /// Returns last if no element satisfies the predicate.
  /////////////////////////////////////////////////////////////////////////////
  template< typename BiItr, typename Pred >
  BiItr find_last_if(BiItr first, BiItr last, Pred pred)
  {
    auto r_first = mystd::make_reverse_iterator(last);
    auto r_last  = mystd::make_reverse_iterator(first);
    auto val_itr = std::find_if(r_first, r_last, pred);

    return (val_itr != r_last) ? std::prev(val_itr.base()) : last;
  }
}

#endif