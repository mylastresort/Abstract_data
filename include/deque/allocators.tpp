#ifndef ALLOCATORS_DEQUE_TPP
#define ALLOCATORS_DEQUE_TPP

#pragma once
#include "deque.hpp"

namespace ft
{

template <class T, class Alloc>
typename deque<T, Alloc>::allocator_type deque<T, Alloc>::get_allocator() const
{
  return this->_a;
}

#ifdef TEST
// template class ft::deque< int >;
#endif

} // namespace ft

#endif
