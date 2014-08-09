#ifndef _MYSTD_CHRONO_DURATION_TRAITS_H
#define _MYSTD_CHRONO_DURATION_TRAITS_H

#include <chrono>
#include <ratio>

namespace mystd
{
  namespace chrono
  {
    template<typename T>
    struct duration_traits
    {
      static const char * description_singular() { return ""; }
      static const char * description_plural() { return ""; }
    };

    template<typename NumberType>
    struct duration_traits<std::chrono::duration<NumberType, std::pico>>
    {
      static const char * description_singular() { return "picosecond"; }
      static const char * description_plural() { return "picoseconds"; }
    };

    template<typename NumberType>
    struct duration_traits<std::chrono::duration<NumberType, std::nano>>
    {
      static const char * description_singular() { return "nanosecond"; }
      static const char * description_plural() { return "nanoseconds"; }
    };

    template<typename NumberType>
    struct duration_traits<std::chrono::duration<NumberType, std::micro>>
    {
      static const char * description_singular() { return "microsecond"; }
      static const char * description_plural() { return "microseconds"; }
    };

    template<typename NumberType>
    struct duration_traits<std::chrono::duration<NumberType, std::milli>>
    {
      static const char * description_singular() { return "millisecond"; }
      static const char * description_plural() { return "milliseconds"; }
    };

    template<typename NumberType>
    struct duration_traits<std::chrono::duration<NumberType, std::ratio<1>>>
    {
      static const char * description_singular() { return "second"; }
      static const char * description_plural() { return "seconds"; }
    };

    template<typename NumberType>
    struct duration_traits<std::chrono::duration<NumberType, std::ratio<60>>>
    {
      static const char * description_singular() { return "minute"; }
      static const char * description_plural() { return "minutes"; }
    };

    template<typename NumberType>
    struct duration_traits<std::chrono::duration<NumberType, std::ratio<3600>>>
    {
      static const char * description_singular() { return "hour"; }
      static const char * description_plural() { return "hours"; }
    };

    template<typename NumberType>
    struct duration_traits<std::chrono::duration<NumberType, std::ratio<86400>>>
    {
      static const char * description_singular() { return "day"; }
      static const char * description_plural() { return "days"; }
    };

  } // End of chrono namespace.
} // End of mystd namespace.

#endif