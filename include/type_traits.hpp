#ifndef TYPES_TRAITS_HPP
#define TYPES_TRAITS_HPP

#pragma once
#include "_phc.hpp"

namespace ft
{

using std::numeric_limits;

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

} // namespace ft

#endif
