#ifndef __DESTRUCTOR__VECTOR_TPP
#define __DESTRUCTOR__VECTOR_TPP

#pragma once
#include "vector.hpp"

namespace ft
{

template < class T, class Alloc > vector< T, Alloc >::~vector()
{
	for (typename vector::size_type i = 0; i < length; i++)
	{
		alc.destroy(list + i);
	}
	alc.deallocate(list, length);
}

} // namespace ft

#endif