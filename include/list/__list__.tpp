#ifndef __LIST__TPP
#define __LIST__TPP

#pragma once
#include "list.hpp"

namespace ft
{

// Unique with binary predicate
template <class T, class Alloc>
template <class BinaryPredicate>
void list<T, Alloc>::unique(BinaryPredicate binary_pred)
{
	// TODO
	(void)binary_pred;
}

// Merge with compare function
template <class T, class Alloc>
template <class Compare>
void list<T, Alloc>::merge(list& lst, Compare comp)
{
	// TODO
	(void)lst;
	(void)comp;
}

// Sort with compare function
template <class T, class Alloc>
template <class Compare>
void list<T, Alloc>::sort(Compare comp)
{
	// TODO
	(void)comp;
}

// Merge
template <class T, class Alloc> void list<T, Alloc>::merge(list& lst)
{
	// TODO
	(void)lst;
}

// Reverse
template <class T, class Alloc> void list<T, Alloc>::reverse()
{
	// TODO
}

// Sort
template <class T, class Alloc> void list<T, Alloc>::sort()
{
	// TODO
}

// Splice range
template <class T, class Alloc>
void list<T, Alloc>::splice(iterator position,
							list& lst,
							iterator first,
							iterator last)
{
	// TODO
	(void)position;
	(void)lst;
	(void)first;
	(void)last;
}

// Splice single element
template <class T, class Alloc>
void list<T, Alloc>::splice(iterator position, list& lst, iterator itr)
{
	// TODO
	(void)position;
	(void)lst;
	(void)itr;
}

// Splice entire list
template <class T, class Alloc>
void list<T, Alloc>::splice(iterator position, list& lst)
{
	// TODO
	(void)position;
	(void)lst;
}

// Swap
template <class T, class Alloc> void list<T, Alloc>::swap(list& lst)
{
	// TODO
	(void)lst;
}

// Unique
template <class T, class Alloc> void list<T, Alloc>::unique()
{
	// TODO
}

// Equality operator
template <class T, class Allocator>
bool operator==(const list<T, Allocator>& lhs, const list<T, Allocator>& rhs)
{
	// TODO
	(void)lhs;
	(void)rhs;
	return false;
}

// Less than operator
template <class T, class Allocator>
bool operator<(const list<T, Allocator>& lhs, const list<T, Allocator>& rhs)
{
	// TODO
	(void)lhs;
	(void)rhs;
	return false;
}

// Inequality operator
template <class T, class Allocator>
bool operator!=(const list<T, Allocator>& lhs, const list<T, Allocator>& rhs)
{
	// TODO
	(void)lhs;
	(void)rhs;
	return false;
}

// Greater than operator
template <class T, class Allocator>
bool operator>(const list<T, Allocator>& lhs, const list<T, Allocator>& rhs)
{
	// TODO
	(void)lhs;
	(void)rhs;
	return false;
}

// Greater than or equal operator
template <class T, class Allocator>
bool operator>=(const list<T, Allocator>& lhs, const list<T, Allocator>& rhs)
{
	// TODO
	(void)lhs;
	(void)rhs;
	return false;
}

// Less than or equal operator
template <class T, class Allocator>
bool operator<=(const list<T, Allocator>& lhs, const list<T, Allocator>& rhs)
{
	// TODO
	(void)lhs;
	(void)rhs;
	return false;
}

// Global swap function
template <class T, class Allocator>
void swap(list<T, Allocator>& first, list<T, Allocator>& second)
{
	// TODO
	(void)first;
	(void)second;
}

} // namespace ft

#endif
