#ifndef ITERATOR_TPP
#define ITERATOR_TPP

#pragma once
#include "iterator.hpp"
namespace ft
{

template < class Iterator >
reverse_iterator< Iterator >::reverse_iterator() : current()
{
}

template < class Iterator >
reverse_iterator< Iterator >::reverse_iterator(iterator_type itr) : current(itr)
{
}

template < class Iterator >
template < class Iter >
reverse_iterator< Iterator >::reverse_iterator(const reverse_iterator< Iter >& rev_it)
	: current(rev_it.base())
{
}

template < class Iterator >
typename reverse_iterator< Iterator >::iterator_type
reverse_iterator< Iterator >::base() const
{
	return current;
}

template < class Iterator >
typename reverse_iterator< Iterator >::reference
reverse_iterator< Iterator >::operator*() const
{
	return *current;
}

template < class Iterator >
typename reverse_iterator< Iterator >::pointer
reverse_iterator< Iterator >::operator->() const
{
	return &*current;
}

template < class Iterator >
reverse_iterator< Iterator >& reverse_iterator< Iterator >::operator++()
{
	--current;
	return *this;
}

template < class Iterator >
reverse_iterator< Iterator > reverse_iterator< Iterator >::operator++(int) // NOLINT
{
	return reverse_iterator(current--);
}

template < class Iterator >
reverse_iterator< Iterator >& reverse_iterator< Iterator >::operator--()
{
	++current;
	return *this;
}

template < class Iterator >
reverse_iterator< Iterator > reverse_iterator< Iterator >::operator--(int) // NOLINT
{
	return reverse_iterator(current++);
}

template < class Iterator >
reverse_iterator< Iterator >
reverse_iterator< Iterator >::operator+(difference_type n) const
{
	return reverse_iterator(current - n);
}

template < class Iterator >
reverse_iterator< Iterator >&
reverse_iterator< Iterator >::operator+=(difference_type n)
{
	current -= n;
	return *this;
}

template < class Iterator >
reverse_iterator< Iterator >
reverse_iterator< Iterator >::operator-(difference_type n) const
{
	return reverse_iterator(current + n);
}

template < class Iterator >
reverse_iterator< Iterator >&
reverse_iterator< Iterator >::operator-=(difference_type n)
{
	current += n;
	return *this;
}

template < class Iterator >
typename reverse_iterator< Iterator >::reference
reverse_iterator< Iterator >::operator[](difference_type n) const
{
	return current[-n];
}

template < class Iterator >
bool operator==(const reverse_iterator< Iterator >& lhs,
				const reverse_iterator< Iterator >& rhs)
{
	return lhs.base() == rhs.base();
}

template < class Iterator >
bool operator!=(const reverse_iterator< Iterator >& lhs,
				const reverse_iterator< Iterator >& rhs)
{
	return !operator==(lhs, rhs);
}

template < class Iterator >
bool operator>(const reverse_iterator< Iterator >& lhs,
			   const reverse_iterator< Iterator >& rhs)
{
	return lhs.base() > rhs.base();
}

template < class Iterator >
bool operator<=(const reverse_iterator< Iterator >& lhs,
				const reverse_iterator< Iterator >& rhs)
{
	return !operator>(lhs, rhs);
}

template < class Iterator >
bool operator<(const reverse_iterator< Iterator >& lhs,
			   const reverse_iterator< Iterator >& rhs)
{
	return lhs.base() < rhs.base();
}

template < class Iterator >
bool operator>=(const reverse_iterator< Iterator >& lhs,
				const reverse_iterator< Iterator >& rhs)
{
	return !operator<(lhs, rhs);
}

template < class Iterator >
typename reverse_iterator< Iterator >::difference_type
operator-(const reverse_iterator< Iterator >& lhs,
		  const reverse_iterator< Iterator >& rhs)
{
	return lhs.base() - rhs.base();
}

template < class Iterator >
reverse_iterator< Iterator >
operator+(typename reverse_iterator< Iterator >::difference_type n,
		  const reverse_iterator< Iterator >& rev_it)
{
	return rev_it + n;
}

} // namespace ft

#endif