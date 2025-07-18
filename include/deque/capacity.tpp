#ifndef CAPACITY_DEQUE_TPP
#define CAPACITY_DEQUE_TPP

#include "deque/__impl_data_.hpp"
#pragma once
#include "deque.hpp"

namespace ft
{

template <class T, class Alloc>
typename deque<T, Alloc>::size_type deque<T, Alloc>::size() const
{
  size_type count = this->map.size();
  if (count == 0)
    return count;
  return count - this->map.front()->head -
          (CHUNK_SIZE - 1 - this->map.back()->tail);
}

#ifdef TEST
// template class ft::deque< int >;
#endif

} // namespace ft

#endif