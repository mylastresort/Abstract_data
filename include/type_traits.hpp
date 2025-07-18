#ifndef TYPES_TRAITS_HPP
#define TYPES_TRAITS_HPP

#include "_phc.hpp"

namespace ft
{

template <bool B, class T = void> struct enable_if
{
};

template <class T> struct enable_if<true, T>
{
  typedef T type;
};

template <class T> struct remove_cv
{
  typedef T type;
};

template <class T> struct remove_cv<const T>
{
  typedef T type;
};

template <class T> struct remove_cv<volatile T>
{
  typedef T type;
};

template <class T> struct remove_cv<const volatile T>
{
  typedef T type;
};

template <class T> struct is_const
{
  static const bool value = false;
};

template <class T> struct is_const<const T>
{
  static const bool value = true;
};

template <bool B, class T, class F> struct conditional
{
  typedef T type;
};

template <class T, class F> struct conditional<false, T, F>
{
  typedef F type;
};

using std::numeric_limits;

} // namespace ft

#endif
