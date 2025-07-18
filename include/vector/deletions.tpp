#ifndef DELETIONS_VECTOR_TPP
#define DELETIONS_VECTOR_TPP

#pragma once
#include "vector.hpp"

namespace ft
{

template <class T, class Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(
        iterator first, iterator last)
{
  if (last > end())
    last = end();
  if (first == last or first >= end())
    return last;
  difference_type distance = last - first;
  for (iterator i = first; i != last; i++)
  {
    this->alloc.destroy(&*i);
  }
  for (iterator i = first; i != end() - distance; i++)
  {
    *i = i[distance];
  }
  this->end_ptr -= distance;
  return iterator(first);
}

template <class T, class Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator position)
{
  return erase(position, position + 1);
}

template <class T, class Alloc> void vector<T, Alloc>::clear()
{
  for (iterator itr = begin(); itr != end(); itr++)
  {
    this->alloc.destroy(&*itr);
  }
  this->end_ptr = this->begin_ptr;
}

template <class T, class Alloc> void vector<T, Alloc>::pop_back()
{
  if (!empty())
  {
    this->alloc.destroy(this->end_ptr - 1);
    this->end_ptr--;
  }
}

} // namespace ft

#endif