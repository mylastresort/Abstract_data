#ifndef ELEMENT_ACCESS_VECTOR_TPP
#define ELEMENT_ACCESS_VECTOR_TPP

#pragma once
#include "vector.hpp"

namespace ft
{

template < class T, class Alloc >
typename vector< T, Alloc >::const_reference vector< T, Alloc >::at(size_type pos) const
{
	if (pos >= size())
		throw "Fatal: cannot index vector at out of range position.";
	return begin_ptr[pos];
}

template < class T, class Alloc >
typename vector< T, Alloc >::const_reference vector< T, Alloc >::back() const
{
	return empty() ? *iterator() : begin_ptr[size() - 1];
}

template < class T, class Alloc >
typename vector< T, Alloc >::const_reference vector< T, Alloc >::front() const
{
	return empty() ? *iterator() : *begin_ptr;
}

template < class T, class Alloc >
typename vector< T, Alloc >::const_reference
vector< T, Alloc >::operator[](size_type pos) const
{
	return begin_ptr[pos];
}

template < class T, class Alloc >
typename vector< T, Alloc >::reference vector< T, Alloc >::at(size_type pos)
{
	if (pos >= size())
		throw "Fatal: cannot index vector at out of range position.";
	return begin_ptr[pos];
}

template < class T, class Alloc >
typename vector< T, Alloc >::reference vector< T, Alloc >::back()
{
	return empty() ? *iterator() : begin_ptr[size() - 1];
}

template < class T, class Alloc >
typename vector< T, Alloc >::reference vector< T, Alloc >::front()
{
	return empty() ? *iterator() : *begin_ptr;
}

template < class T, class Alloc >
typename vector< T, Alloc >::reference vector< T, Alloc >::operator[](size_type pos)
{
	return begin_ptr[pos];
}

} // namespace ft

#endif