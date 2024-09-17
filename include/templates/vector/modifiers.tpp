#ifndef MODIFIERS_VECTOR_TPP
#define MODIFIERS_VECTOR_TPP

#pragma once
#include "vector.hpp"

namespace ft
{

template < class T, class Alloc > void vector< T, Alloc >::swap(vector& other)
{
	pointer tmp = begin_ptr;
	begin_ptr = other.begin_ptr;
	other.begin_ptr = tmp;
	tmp = end_ptr;
	end_ptr = other.end_ptr;
	other.end_ptr = tmp;
	tmp = cap_ptr;
	cap_ptr = other.cap_ptr;
	other.cap_ptr = tmp;
}

} // namespace ft

#endif