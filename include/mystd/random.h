#ifndef _MYSTD_RANDOM
#define _MYSTD_RANDOM

#include <random>
#include <type_traits>

// A implementation of some ideas proposed on N3847.
namespace mystd
{
  using default_urbg_t = std::mt19937;

  inline default_urbg_t& global_urbg()
  {
    static default_urbg_t eng{ };
    return eng;
  }

  inline void randomize()
  {
    static std::random_device rd{ };
    global_urbg().seed(rd());
  }

  template<typename T>
  typename std::enable_if<std::is_integral<T>::value, T>::type
  pick_a_number(T from, T thru)
  {
    static std::uniform_int_distribution<T> dist{ };
    using parm_t = typename decltype(dist)::param_type;
    return dist(global_urbg(), parm_t{ from, thru });
  }

  template<typename T>
  typename std::enable_if<std::is_floating_point<T>::value, T>::type
  pick_a_number(T from, T upto)
  {
    static std::uniform_real_distribution<T> dist{ };
    using parm_t = typename decltype(dist)::param_type;
    return dist(global_urbg(), parm_t{ from, upto });
  }

} // End of mystd namespace.

#endif