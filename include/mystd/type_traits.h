#ifndef _MYSTD_TYPE_TRAITS
#define _MYSTD_TYPE_TRAITS

#include <type_traits>

namespace mystd
{
  template<bool If, typename Then, typename Else>
  using conditional_t = typename std::conditional<If, Then, Else>::type;

  template<bool If, typename T = void>
  using enable_if_t = typename std::enable_if<If, T>::type;
  
  template<typename T>
  using remove_cv_t = typename std::remove_cv<T>::type;

  template<typename T>
  using remove_reference_t = typename std::remove_reference<T>::type;

  template<typename T>
  using unqualified_t = remove_cv_t<remove_reference_t<T>>;

  template<typename T>
  using decay_t = typename std::decay<T>::type;

  template<typename T>
  using storage_for_t = typename std::aligned_storage<sizeof(T), alignof(T)>::type;

} // End of mystd namespace.

#endif