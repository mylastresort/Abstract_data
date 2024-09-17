#ifndef __CONSTRUCTOR__VECTOR_TPP
#define __CONSTRUCTOR__VECTOR_TPP
// IWYU pragma: private, include "vector.hpp"

#include "type_traits.hpp"
#pragma once
#include "vector.hpp"

namespace ft
{

template < class T, class Alloc >
vector< T, Alloc >::vector(const allocator_type& alloc)
	: alloc(alloc), begin_ptr(), cap_ptr(begin_ptr), end_ptr(begin_ptr)
{
}

template < class T, class Alloc >
vector< T, Alloc >::vector(size_type n,
						   const value_type& value,
						   const allocator_type& alloc)
	: alloc(alloc), begin_ptr(), cap_ptr(begin_ptr), end_ptr(begin_ptr)
{
	assign(n, value);
}

template < class T, class Alloc >
template < class InputIterator >
vector< T, Alloc >::vector(
	InputIterator first,
	InputIterator last,
	const allocator_type& alloc,
	typename enable_if< !numeric_limits< InputIterator >::is_integer >::type* /*unused*/)
	: alloc(alloc), begin_ptr(), cap_ptr(begin_ptr), end_ptr(begin_ptr)
{
	assign(first, last);
}

template < class T, class Alloc >
vector< T, Alloc >::vector(const vector& cpy)
	: alloc(cpy.get_allocator()), begin_ptr(), cap_ptr(begin_ptr),
	  end_ptr(begin_ptr)
{
	assign(cpy.begin(), cpy.end());
}

template < class T, class Alloc >
vector< T, Alloc >& vector< T, Alloc >::operator=(const vector& cpy)
{
	if (this != &cpy)
	{
		assign(cpy.begin(), cpy.end());
	}
	return *this;
}

} // namespace ft
#endif