#define _MYSTD_ALGORITHM_UNIQUE_COPY_WITH_COUNT_H
#ifndef _MYSTD_ALGORITHM_UNIQUE_COPY_WITH_COUNT_H

#include "adjacent_count.h"

namespace mystd
{
  /////////////////////////////////////////////////////////////////////////////
  /// Copies the elements, together with the number of consecutive copies,
  /// from the range [first, last), to another range beginning at d_first in
  /// such a way that there are no consecutive equal elements.
  /// Only the first element of each group of equal elements is copied.
  /////////////////////////////////////////////////////////////////////////////
  template<typename FwdItr, typename OutItr>
  OutItr unique_copy_with_count(FwdItr first, FwdItr last, OutItr d_first)
  {
    while (first != last)
    {
      auto result = mystd::adjacent_count(first, last);
      *d_first++ = { *result.second, result.first }; 
      first = result.second;
    }
    return d_first;
  }

} // End of mystd namespace.

#endif