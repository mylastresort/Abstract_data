#ifndef __ITERATOR__DEQUE_TPP
#define __ITERATOR__DEQUE_TPP

#include "deque/__impl_data_.hpp"
#pragma once
#include "deque.hpp"

namespace ft
{

template <class T> deque_iterator<T>::deque_iterator() : current(0), data()
{
}

template <class T>
deque_iterator<T>::deque_iterator(const deque_iterator& cpy)
	: current(cpy.current), data(cpy.data)
{
}

template <class T>
deque_iterator<T>& deque_iterator<T>::operator=(const deque_iterator& cpy)
{
	if (this != &cpy)
	{
		current = cpy.current;
		data = cpy.data;
	}
	return *this;
}

template <class T>
template <class U>
deque_iterator<T>::deque_iterator(const deque_iterator<U>& cpy)
	: current(cpy.current),
	  data((typename deque_iterator::data_t)cpy.data) // NOLINT
{
}

template <class T>
template <class U>
deque_iterator<T>& deque_iterator<T>::operator=(const deque_iterator<U>& cpy)
{
	if (static_cast<void*>(this) != &cpy)
	{
		current = cpy.current;
		data = (typename deque_iterator::data_t)cpy.data; // NOLINT
	}
	return *this;
}

template <class T>
template <class U>
deque_iterator<T>::operator deque_iterator<U>()
{
	// NOLINTNEXTLINE
	return deque_iterator<U>((typename deque_iterator<U>::data_t)data, current);
}

template <class T> deque_iterator<T>::~deque_iterator()
{
}

template <class T>
deque_iterator<T>::deque_iterator(data_t _data, size_t _current)
	: current(_current), data(_data)
{
}

template <class T> bool deque_iterator<T>::operator!=(const deque_iterator& rhs)
{
	return base() != rhs.base();
}

template <class T> bool deque_iterator<T>::operator<(const deque_iterator& rhs)
{
	return data != rhs.data ? data < rhs.data : current < rhs.current;
}

template <class T> bool deque_iterator<T>::operator>(const deque_iterator& rhs)
{
	return data != rhs.data ? data > rhs.data : current > rhs.current;
}

template <class T> bool deque_iterator<T>::operator<=(const deque_iterator& rhs)
{
	return !operator>(rhs);
}

template <class T> bool deque_iterator<T>::operator>=(const deque_iterator& rhs)
{
	return !operator<(rhs);
}

template <class T> bool deque_iterator<T>::operator==(const deque_iterator& rhs)
{
	return base() == rhs.base();
}

template <class T>
const typename deque_iterator<T>::pointer deque_iterator<T>::operator->() const
{
	return base();
}

template <class T>
const typename deque_iterator<T>::reference deque_iterator<T>::operator[](int pos) const
{
	pos += current + data[0]->head;                          // NOLINT
	return data[pos / CHUNK_SIZE]->blocks[pos % CHUNK_SIZE]; // NOLINT
}

template <class T>
const typename deque_iterator<T>::reference deque_iterator<T>::operator*() const
{
	return *base();
}

template <class T>
template <class U>
typename deque_iterator<T>::difference_type
deque_iterator<T>::operator-(const deque_iterator<U>& rhs)
{
	return data - rhs.data + (current - rhs.current);
}

template <class T>
typename deque_iterator<T>::pointer deque_iterator<T>::operator->()
{
	return base();
}

template <class T>
typename deque_iterator<T>::reference deque_iterator<T>::operator[](int pos)
{
	pos += current + data[0]->head;                          // NOLINT
	return data[pos / CHUNK_SIZE]->blocks[pos % CHUNK_SIZE]; // NOLINT
}

template <class T>
typename deque_iterator<T>::reference deque_iterator<T>::operator*()
{
	return *base();
}

template <class T>
deque_iterator<T> deque_iterator<T>::operator--(int) // NOLINT
{
	deque_iterator res(*this);
	current--;
	return res;
}

template <class T>
deque_iterator<T> deque_iterator<T>::operator++(int) // NOLINT
{
	deque_iterator res(*this);
	current++;
	return res;
}

template <class T>
typename deque_iterator<T>::pointer deque_iterator<T>::base() const
{
	return &operator[](0);
}

template <class T> deque_iterator<T>& deque_iterator<T>::operator--()
{
	current--;
	return *this;
}

template <class T>
deque_iterator<T> deque_iterator<T>::operator-(const difference_type n)
{
	return deque_iterator(data, current - n);
}

template <class T>
deque_iterator<T>& deque_iterator<T>::operator-=(const difference_type n)
{
	current -= n;
	return *this;
}

template <class T>
deque_iterator<T> deque_iterator<T>::operator+(const difference_type n)
{
	return deque_iterator(data, current + n);
}

template <class T> deque_iterator<T>& deque_iterator<T>::operator++()
{
	current++;
	return *this;
}

template <class T>
deque_iterator<T>& deque_iterator<T>::operator+=(const difference_type n)
{
	current += n;
	return *this;
}

template <class T>
typename deque_iterator<T>::difference_type
operator+(const typename deque_iterator<T>::difference_type lhs,
		  deque_iterator<T>& rhs)
{
	return rhs + lhs;
}

} // namespace ft

#ifdef TEST
template struct ft::deque_iterator<int>;
template struct ft::deque_iterator<const int>;
#endif

#endif