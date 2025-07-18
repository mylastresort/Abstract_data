#ifndef ELEMENT_ACCESS_DEQUE_TPP
#define ELEMENT_ACCESS_DEQUE_TPP

#include <cstddef>
#pragma once
#include "deque.hpp"

namespace ft
{

template <class T, class Alloc>
typename deque<T, Alloc>::const_reference deque<T, Alloc>::at(size_type pos) const
{
  return (*this)[pos];
};

template <class T, class Alloc>
typename deque<T, Alloc>::reference deque<T, Alloc>::at(size_type pos)
{
  return (*this)[pos];
};

template <class T, class Alloc>
typename deque<T, Alloc>::const_reference deque<T, Alloc>::back() const
{
  const size_type pos = size() == 0 ? 0 : size() - 1;
  return (*this)[pos];
};

template <class T, class Alloc>
typename deque<T, Alloc>::reference deque<T, Alloc>::back()
{
  const size_type pos = size() == 0 ? 0 : size() - 1;
  return (*this)[pos];
};

template <class T, class Alloc>
typename deque<T, Alloc>::const_reference deque<T, Alloc>::front() const
{
  return (*this)[0];
};

template <class T, class Alloc>
typename deque<T, Alloc>::reference deque<T, Alloc>::front()
{
  return (*this)[0];
};

template <class T, class Alloc>
typename deque<T, Alloc>::const_reference deque<T, Alloc>::operator[](
        size_type pos) const
{
  pos += this->_begin_offset;
  return this->_map_ptr[pos / CHUNK_SIZE][pos % CHUNK_SIZE];
};

template <class T, class Alloc>
typename deque<T, Alloc>::reference deque<T, Alloc>::operator[](size_type pos)
{
  pos += this->_begin_offset;
  return this->_map_ptr[pos / CHUNK_SIZE][pos % CHUNK_SIZE];
};

} // namespace ft

#endif
