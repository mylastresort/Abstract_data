#ifndef INSERTIONS_DEQUE_TPP
#define INSERTIONS_DEQUE_TPP

#include "deque/__impl_data_.hpp"
#pragma once
#include "deque.hpp"

namespace ft
{

// template < class T, class Alloc >
// template < class InputIterator >
// void deque< T, Alloc >::assign(
// 	InputIterator first,
// 	InputIterator last,
// 	typename enable_if< !numeric_limits< InputIterator >::is_integer >::type* /*unused*/)
// {
// 	clear();
// 	typename _deque_impl_data< Alloc >::_chunk_iterator itr(first, last);
// 	this->map.assign(itr.first, itr.last);
// }

template <class T, class Alloc>
void deque<T, Alloc>::assign(size_type count, const value_type& val)
{
  clear();
  typename _deque_impl_data<Alloc>::_chunk_iterator itr(count, val);
  this->map.assign(itr.first, itr.last);
}

#ifdef TEST
template class ft::deque<int>;
#endif

} // namespace ft

#endif