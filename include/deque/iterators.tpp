#ifndef ITERATORS_DEQUE_TPP
#define ITERATORS_DEQUE_TPP

#pragma once
#include "deque.hpp"

namespace ft
{

template <class T, class Alloc>
typename deque<T, Alloc>::const_iterator deque<T, Alloc>::begin() const
{
	return const_iterator(this, 0); // NOLINT
}

template <class T, class Alloc>
typename deque<T, Alloc>::const_iterator deque<T, Alloc>::end() const
{
	return const_iterator(this, size()); // NOLINT
}

template <class T, class Alloc>
typename deque<T, Alloc>::const_reverse_iterator deque<T, Alloc>::rbegin() const
{
	return const_reverse_iterator(end() - 1);
}

template <class T, class Alloc>
typename deque<T, Alloc>::const_reverse_iterator deque<T, Alloc>::rend() const
{
	return const_reverse_iterator(begin() - 1);
}

template <class T, class Alloc>
typename deque<T, Alloc>::iterator deque<T, Alloc>::begin()
{
	return iterator(this, 0);
}

template <class T, class Alloc>
typename deque<T, Alloc>::iterator deque<T, Alloc>::end()
{
	return iterator(this, size());
}

template <class T, class Alloc>
typename deque<T, Alloc>::reverse_iterator deque<T, Alloc>::rbegin()
{
	return reverse_iterator(end() - 1);
}

template <class T, class Alloc>
typename deque<T, Alloc>::reverse_iterator deque<T, Alloc>::rend()
{
	return reverse_iterator(begin() - 1);
}

#ifdef TEST
// template class ft::deque< int >;
#endif

} // namespace ft

#endif
