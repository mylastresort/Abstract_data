#ifndef INSERTIONS_VECTOR_TPP
#define INSERTIONS_VECTOR_TPP

#pragma once
#include "type_traits.hpp"
#include "vector.hpp"

namespace ft
{

template < class T, class Alloc >
template < class InputIterator >
void vector< T, Alloc >::assign(
	InputIterator first,
	InputIterator last,
	typename enable_if< !numeric_limits< InputIterator >::is_integer >::type*
	/*unused*/)
{
	clear();
	reserve(last - first);
	for (InputIterator i = first; i != last; i++)
	{
		alloc.construct(begin_ptr + (i - first), *i);
	}
	end_ptr = begin_ptr + (last - first);
}

template < class T, class Alloc >
void vector< T, Alloc >::assign(size_type n, const value_type& val)
{
	clear();
	reserve(n);
	for (size_type i = 0; i < n; i++)
	{
		alloc.construct(begin_ptr + i, val);
	}
	end_ptr = begin_ptr + n;
}

} // namespace ft

#endif