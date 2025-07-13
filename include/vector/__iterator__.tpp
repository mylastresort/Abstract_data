#ifndef __ITERATOR__VECTOR_TPP
#define __ITERATOR__VECTOR_TPP

#pragma once
#include "vector.hpp"
namespace ft
{

template <class T> vector_iterator<T>::vector_iterator() : current(pointer())
{
}

template <class T>
vector_iterator<T>::vector_iterator(const vector_iterator& cpy)
{
	*this = cpy;
}

template <class T>
vector_iterator<T>& vector_iterator<T>::operator=(const vector_iterator& cpy)
{
	if (this != &cpy)
	{
		current = cpy.current;
	}
	return *this;
}

template <class T>
template <class U>
vector_iterator<T>::vector_iterator(const vector_iterator<U>& cpy)
{
	*this = cpy;
}

template <class T>
template <class U>
vector_iterator<T>& vector_iterator<T>::operator=(const vector_iterator<U>& cpy)
{
	if (static_cast<void*>(this) != &cpy)
	{
		current = cpy.base();
	}
	return *this;
}

template <class T>
template <class U>
vector_iterator<T>::operator vector_iterator<U>()
{
	return vector_iterator<U>(current);
}

template <class T> vector_iterator<T>::~vector_iterator()
{
}

template <class T>
vector_iterator<T>::vector_iterator(pointer _current) : current(_current)
{
}

template <class T>
bool vector_iterator<T>::operator!=(const vector_iterator& rhs)
{
	return current != rhs.current;
}

template <class T>
bool vector_iterator<T>::operator<(const vector_iterator& rhs)
{
	return current > rhs.current;
}

template <class T>
bool vector_iterator<T>::operator>(const vector_iterator& rhs)
{
	return current > rhs.current;
}

template <class T>
bool vector_iterator<T>::operator<=(const vector_iterator& rhs)
{
	return current <= rhs.current;
}

template <class T>
bool vector_iterator<T>::operator==(const vector_iterator& rhs)
{
	return current == rhs.current;
}

template <class T>
bool vector_iterator<T>::operator>=(const vector_iterator& rhs)
{
	return current >= rhs.current;
}

template <class T>
const typename vector_iterator<T>::pointer vector_iterator<T>::operator->() const
{
	return current;
}

template <class T>
const typename vector_iterator<T>::reference
vector_iterator<T>::operator[](int pos) const
{
	return *(current + pos);
}

template <class T>
const typename vector_iterator<T>::reference vector_iterator<T>::operator*() const
{
	return *current;
}

template <class T>
template <class U>
typename vector_iterator<T>::difference_type
vector_iterator<T>::operator-(const vector_iterator<U>& rhs)
{
	return current - rhs.base();
}

template <class T>
typename vector_iterator<T>::pointer vector_iterator<T>::operator->()
{
	return current;
}

template <class T>
typename vector_iterator<T>::reference vector_iterator<T>::operator[](int pos)
{
	return *(current + pos);
}

template <class T>
typename vector_iterator<T>::reference vector_iterator<T>::operator*()
{
	return *current;
}

template <class T>
vector_iterator<T> vector_iterator<T>::operator--(int) // NOLINT
{
	vector_iterator res(*this);
	current--;
	return res;
}

template <class T>
vector_iterator<T> vector_iterator<T>::operator++(int) // NOLINT
{
	vector_iterator res(*this);
	current++;
	return res;
}

template <class T>
typename vector_iterator<T>::pointer vector_iterator<T>::base() const
{
	return current;
}

template <class T> vector_iterator<T>& vector_iterator<T>::operator--()
{
	current--;
	return *this;
}

template <class T>
vector_iterator<T> vector_iterator<T>::operator-(const difference_type n)
{
	return vector_iterator(current - n);
}

template <class T>
vector_iterator<T>& vector_iterator<T>::operator-=(const difference_type n)
{
	current -= n;
	return *this;
}

template <class T>
vector_iterator<T> vector_iterator<T>::operator+(const difference_type n)
{
	return vector_iterator(current + n);
}

template <class T> vector_iterator<T>& vector_iterator<T>::operator++()
{
	current++;
	return *this;
}

template <class T>
vector_iterator<T>& vector_iterator<T>::operator+=(const difference_type n)
{
	current += n;
	return *this;
}

template <class T>
typename vector_iterator<T>::difference_type
operator+(const typename vector_iterator<T>::difference_type lhs,
		  vector_iterator<T>& rhs)
{
	return rhs + lhs;
}

#ifdef TEST
template struct ft::vector_iterator<int>;
template struct ft::vector_iterator<const int>;
#endif

} // namespace ft

#endif