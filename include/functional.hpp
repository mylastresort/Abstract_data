#ifndef FUNCTIONAL_HPP
#define FUNCTIONAL_HPP

#include <climits>

namespace ft
{

template <class T> struct greater
{
  bool operator()(const T& first, const T& second) const
  {
    return first > second;
  }

  template <class U> bool operator()(const T& first, const U& second) const
  {
    return first > second;
  }

  static const int TEST_MIN = INT_MAX;
  static const int TEST_MAX = INT_MIN;
};

template <class T> struct less
{
  bool operator()(const T& first, const T& second) const
  {
    return first < second;
  }

  template <class U> bool operator()(const T& first, const U& second) const
  {
    return first < second;
  }

  static const int TEST_MIN = INT_MIN;
  static const int TEST_MAX = INT_MAX;
};

template <class c, class T> struct notCompare : public c
{
  bool operator()(const T& first, const T& second) const
  {
    return !c::operator()(first, second);
  }

  template <class U> bool operator()(const T& first, const U& second) const
  {
    return !c::operator()(first, second);
  }
};

} // namespace ft

#endif
