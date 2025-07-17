#ifndef __CONSTRUCTOR__DEQUE_TPP
#define __CONSTRUCTOR__DEQUE_TPP

#pragma once
#include "deque.hpp"

namespace ft
{

template <class T, class Alloc>
deque<T, Alloc>::deque(const allocator_type& alloc) : _a(alloc)
{
	const size_t size = 1;
	this->_map_ptr = this->_a_map.allocate(size);
	this->_chunks_sz = size;
	this->_map_ptr[0] = this->_a.allocate(CHUNK_SIZE);
	this->_begin_offset = CHUNK_SIZE / 2;
	this->_past_end_offset = this->_begin_offset;
}

template <class T, class Alloc>
deque<T, Alloc>::deque(const deque& cpy)
	: _map_ptr(0), _begin_offset(0), _past_end_offset(0), _chunks_sz(0)
{
	assign(cpy.begin(), cpy.end());
}

template <class T, class Alloc>
deque<T, Alloc>::deque(size_type n,
					   const value_type& val,
					   const allocator_type& alloc)
	: _map_ptr(0), _begin_offset(0), _past_end_offset(0), _chunks_sz(0),
	  _a(alloc)
{
	assign(n, val);
}

template <class T, class Alloc>
template <class InputIterator>
deque<T, Alloc>::deque(
	InputIterator first,
	InputIterator last,
	const allocator_type& alloc,
	typename enable_if<!numeric_limits<InputIterator>::is_integer>::type* /*unused*/)
	: _map_ptr(0), _begin_offset(0), _past_end_offset(0), _chunks_sz(0),
	  _a(alloc)
{
	assign(first, last);
}

template <class T, class Alloc>
deque<T, Alloc>& deque<T, Alloc>::operator=(const deque& cpy)
{
	if (this != &cpy)
	{
		assign(cpy.begin(), cpy.end());
	}
	return *this;
}

#ifdef TEST
// template class ft::deque< int >;
#endif

} // namespace ft

#endif
