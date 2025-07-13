#ifndef __CONSTRUCTOR__DEQUE_TPP
#define __CONSTRUCTOR__DEQUE_TPP
// IWYU pragma: private, include "vector.hpp"

#pragma once
#include "deque.hpp"

namespace ft
{

template <class T, class Alloc>
deque<T, Alloc>::deque(const allocator_type& alloc)
	: _deque_impl_data<Alloc>(alloc)
{
}

template <class T, class Alloc>
deque<T, Alloc>::deque(const deque& cpy)
	: _deque_impl_data<Alloc>(cpy.get_allocator())
{
	assign(cpy.begin(), cpy.end());
}

template <class T, class Alloc>
deque<T, Alloc>::deque(size_type n,
					   const value_type& val,
					   const allocator_type& alloc)
	: _deque_impl_data<Alloc>(alloc)
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
	: _deque_impl_data<Alloc>(alloc)
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