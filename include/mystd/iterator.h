#ifndef _MYSTD_ITERATOR_H
#define _MYSTD_ITERATOR_H

#include <iterator> // For std::reverse_iterator

namespace mystd
{
  /////////////////////////////////////////////////////////////////////////////
  /// Construct an reverse_iterator from itr, deducing it's type.
  /////////////////////////////////////////////////////////////////////////////
  template<typename BiItr>
  std::reverse_iterator<BiItr> make_reverse_iterator(BiItr itr)
  {
    return std::reverse_iterator<BiItr>(itr);
  }

} // End of mystd namespace.

#endif