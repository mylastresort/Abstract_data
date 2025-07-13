#ifndef __DESTRUCTOR__VECTOR_TPP
#define __DESTRUCTOR__VECTOR_TPP
// IWYU pragma: private, include "vector.hpp"

#pragma once
#include "vector.hpp"

namespace ft
{

template <class T, class Alloc> vector<T, Alloc>::~vector()
{
	clear();
	this->alloc.deallocate(this->begin_ptr, capacity());
}

} // namespace ft

#endif