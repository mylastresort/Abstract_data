#ifndef DELETIONS_VECTOR_TPP
#define DELETIONS_VECTOR_TPP

#pragma once
#include "vector.hpp"

namespace ft
{

template < class T, class Alloc > void vector< T, Alloc >::clear()
{
	for (iterator itr = begin(); itr != end(); itr++)
	{
		alloc.destroy(&*itr);
	}
	end_ptr = begin_ptr;
}

} // namespace ft

#endif