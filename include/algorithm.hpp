#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

namespace ft
{

template <class InputIterator1, class InputIterator2>
bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
{
  InputIterator1 itr1 = first1;
  InputIterator2 itr2 = first2;
  for (; itr1 != last1; itr1++, itr2++)
    if (*itr1 != *itr2)
      return false;
  return true;
}

template <class InputIterator1, class InputIterator2, class BinaryPredicate>
bool equal(InputIterator1 first1,
        InputIterator1    last1,
        InputIterator2    first2,
        BinaryPredicate   pred)
{
  InputIterator1 itr1 = first1;
  InputIterator2 itr2 = first2;
  for (; itr1 != last1; itr1++, itr2++)
    if (!pred(*itr1, *itr2))
      return false;
  return true;
}

template <class InputIterator1, class InputIterator2>
bool lexicographical_compare(InputIterator1 first1,
        InputIterator1                      last1,
        InputIterator2                      first2,
        InputIterator2                      last2)
{
  InputIterator1 itr1 = first1;
  InputIterator2 itr2 = first2;
  for (; itr1 != last1; itr1++, itr2++)
    if (*itr1 < *itr2)
      return true;
    else if (*itr2 < *itr1)
      return false;
  return first1 == last1 && first2 != last2;
}

template <class InputIterator1, class InputIterator2, class Compare>
bool lexicographical_compare(InputIterator1 first1,
        InputIterator1                      last1,
        InputIterator2                      first2,
        InputIterator2                      last2,
        Compare                             comp)
{
  InputIterator1 itr1 = first1;
  InputIterator2 itr2 = first2;
  for (; itr1 != last1; itr1++, itr2++)
    if (comp(*itr1, *itr2))
      return true;
    else if (comp(*itr2, *itr1))
      return false;
  return first1 == last1 && first2 != last2;
}

} // namespace ft

#endif