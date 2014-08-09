#ifndef _MYSTD_ALGORITHM_FIND_LAST_H
#define _MYSTD_ALGORITHM_FIND_LAST_H

#include <mystd/iterator.h> // For mystd::make_reverse_iterator

#include <algorithm> // For std::find
#include <iterator>  // For std::prev

namespace mystd
{
  /////////////////////////////////////////////////////////////////////////////
  /// Finds the last element in the range equal to value.
  /// Returns last if no element is equal to value.
  /////////////////////////////////////////////////////////////////////////////
  template<typename BiItr, typename T>
  BiItr find_last(BiItr first, BiItr last, const T& value)
  {
    auto r_first = mystd::make_reverse_iterator(last );
    auto r_last  = mystd::make_reverse_iterator(first);
    auto val_itr = std::find(r_first, r_last, value);

    return (val_itr != r_last) ? std::prev(val_itr.base()) : last;
  }
}

#endif