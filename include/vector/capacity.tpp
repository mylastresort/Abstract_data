#ifndef CAPACITY_VECTOR_TPP
#define CAPACITY_VECTOR_TPP

#include <cmath>
#pragma once
#include "vector.hpp"

namespace ft
{

template <class T, class Alloc> bool vector<T, Alloc>::empty() const
{
	return begin() == end();
}

template <class T, class Alloc>
typename vector<T, Alloc>::size_type vector<T, Alloc>::capacity() const
{
	return iterator(this->cap_ptr) - begin();
}

template <class T, class Alloc>
typename vector<T, Alloc>::size_type vector<T, Alloc>::max_size() const
{
	return this->alloc.max_size();
}

template <class T, class Alloc>
typename vector<T, Alloc>::size_type vector<T, Alloc>::size() const
{
	return end() - begin();
}

template <class T, class Alloc> void vector<T, Alloc>::reserve(size_type cap)
{
	if (cap <= capacity())
		return;
	if (cap > max_size())
	{
		throw "Fatal: cannot allocate requested size exceeding max_size";
	}
	pointer new_list = this->alloc.allocate(cap);
	for (iterator i = begin(); i != end(); i++)
	{
		new_list[i - begin()] = *i;
		this->alloc.destroy(&*i);
	}
	difference_type len = size();
	this->alloc.deallocate(this->begin_ptr, capacity());
	this->begin_ptr = new_list;
	this->cap_ptr = new_list + cap;
	this->end_ptr = new_list + len;
}

template <class T, class Alloc>
void vector<T, Alloc>::resize(size_type n, value_type val)
{
	if (n == size())
		return;
	if (n < size())
	{
		erase(begin() + n, end());
		return;
	}
	if (n > capacity())
	{
		size_type cap = capacity() * 2;
		reserve(n > cap ? n : cap);
	}
	for (difference_type i = size(); i < n; i++)
	{
		this->alloc.construct(this->end_ptr, val);
		this->end_ptr++;
	}
}

} // namespace ft
#endif