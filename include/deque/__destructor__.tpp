#ifndef __DESTRUCTOR_DEQUE_TPP
#define __DESTRUCTOR_DEQUE_TPP

#pragma once
#include "deque.hpp"

namespace ft
{

template <class T, class Alloc> deque<T, Alloc>::~deque<T, Alloc>()
{
	clear();
	for (size_type i = 0; i < this->_chunks_sz; i++)
	{
		this->_a.deallocate(this->_map_ptr[i], CHUNK_SIZE);
	}
	if (this->_map_ptr != 0)
	{
		this->_a_map.deallocate(this->_map_ptr, this->_chunks_sz);
	}
}

#ifdef TEST
// template class ft::deque< int >;
#endif

} // namespace ft

#endif
