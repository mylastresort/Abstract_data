#ifndef UTILITY_HPP
#define UTILITY_HPP

namespace ft
{

template <class T> T max(T a, T b)
{
  if (a > b)
    return a;
  return b;
};

template <class T> T max(T a, T b, T c)
{
  T m = max(a, b);
  if (m > c)
    return m;
  return c;
};

template <class T> struct hash
{
};

} // namespace ft

#endif
