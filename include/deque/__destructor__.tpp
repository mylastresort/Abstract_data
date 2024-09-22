#ifndef __DESTRUCTOR_DEQUE_TPP
#define __DESTRUCTOR_DEQUE_TPP

#pragma once
#include "deque.hpp"

namespace ft
{

template < class T, class Alloc > deque< T, Alloc >::~deque< T, Alloc >()
{
	clear();
}

#ifdef TEST
// template class ft::deque< int >;
#endif

} // namespace ft

#endif