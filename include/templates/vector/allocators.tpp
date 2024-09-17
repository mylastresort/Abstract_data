#ifndef ALLOCATORS_VECTOR_TPP
#define ALLOCATORS_VECTOR_TPP

#pragma once
#include "vector.hpp"

namespace ft
{

template < class T, class Alloc >
typename vector< T, Alloc >::allocator_type vector< T, Alloc >::get_allocator() const
{
	return allocator_type();
}

} // namespace ft

#endif