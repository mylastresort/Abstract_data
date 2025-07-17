#ifndef CAPACITY_DEQUE_TPP
#define CAPACITY_DEQUE_TPP

#pragma once
#include "deque.hpp"

namespace ft
{

template <class T, class Alloc>
typename deque<T, Alloc>::size_type deque<T, Alloc>::size() const
{
	return this->_past_end_offset - this->_begin_offset;
}

template <class T, class Alloc> bool deque<T, Alloc>::empty() const
{
	return size() == 0;
}

template <class T, class Alloc>
void deque<T, Alloc>::resize(size_type sz, value_type val)
{
	if (sz == size())
		return;
	if (sz < size())
	{
		erase(begin() + sz, end());
		return;
	}
	insert(end(), size() - sz, val);
}

#ifdef TEST
// template class ft::deque< int >;
#endif

} // namespace ft

#endif
