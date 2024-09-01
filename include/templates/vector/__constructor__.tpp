#ifndef __CONSTRUCTOR__VECTOR_TPP
#define __CONSTRUCTOR__VECTOR_TPP

#pragma once
#include "vector.hpp"

namespace ft
{

template < class T, class Alloc >
vector< T, Alloc >::vector(const typename vector::allocator_type& alloc)
	: alc(alloc), length(0)
{
	list = alc.allocate(0);
}

template < class T, class Alloc >
vector< T, Alloc >::vector(typename vector::size_type size,
						   const typename vector::value_type& value,
						   const typename vector::allocator_type& alloc)
	: alc(alloc), length(size)
{
	list = alc.allocate(size);
	for (typename vector::size_type i = 0; i < size; i++)
	{
		alc.construct(list[i], value);
	}
}

template < class T, class Alloc >
template < class InputIterator >
vector< T, Alloc >::vector(InputIterator first,
						   InputIterator last,
						   const typename vector::allocator_type& alloc)
	: alc(alloc), length(last - first)
{
	list = alloc.allocate(length);
	for (InputIterator i = first; i != last; i++)
	{
		alc.construct(list[i], *i);
	}
}

} // namespace ft
#endif