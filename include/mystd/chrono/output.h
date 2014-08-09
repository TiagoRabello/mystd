#ifndef _MYSTD_CHRONO_OUTPUT_H
#define _MYSTD_CHRONO_OUTPUT_H

#include "duration_traits.h"

#include <ostream> // For std::basic_ostream

namespace mystd
{
  namespace chrono
  {
    namespace output
    {
      template<class CharT, class CharTraits, class DurationT>
      std::basic_ostream<CharT, CharTraits>&
      operator<<(std::basic_ostream<CharT, CharTraits>& os, const DurationT& t)
      {
        using traits = mystd::chrono::duration_traits<DurationT>;
        auto count = t.count();
        os << count << " ";
        os << ((count != 1) ? traits::description_plural()
                            : traits::description_singular());
        return os;
      }

    } // End of output namespace.
  } // End of chrono namespace.
} // End of mystd namespace.

#endif