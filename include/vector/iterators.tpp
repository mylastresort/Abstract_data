#ifndef ITERATORS_VECTORS_TPP
#define ITERATORS_VECTORS_TPP

#pragma once
#include "vector.hpp"

namespace ft
{

template <class T, class Alloc>
typename vector<T, Alloc>::const_iterator vector<T, Alloc>::begin() const
{
  return const_iterator(this->begin_ptr);
}

template <class T, class Alloc>
typename vector<T, Alloc>::const_iterator vector<T, Alloc>::end() const
{
  return const_iterator(this->end_ptr);
}

template <class T, class Alloc>
typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::rbegin() const
{
  return const_reverse_iterator(end() - 1);
}

template <class T, class Alloc>
typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::rend() const
{
  return const_reverse_iterator(begin() - 1);
}

template <class T, class Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::begin()
{
  return iterator(this->begin_ptr);
}

template <class T, class Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::end()
{
  return iterator(this->end_ptr);
}

template <class T, class Alloc>
typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rbegin()
{
  return reverse_iterator(end() - 1);
}

template <class T, class Alloc>
typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rend()
{
  return reverse_iterator(begin() - 1);
}

} // namespace ft

#endif