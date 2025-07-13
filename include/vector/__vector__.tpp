#ifndef __VECTOR__TPP
#define __VECTOR__TPP

#pragma once
#include "algorithm.hpp"
#include "functional.hpp"
#include "vector.hpp"

namespace ft
{

template <class T, class Alloc>
bool operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
{
	return lhs.size() == rhs.size() &&
		ft::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template <class T, class Alloc>
bool operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
{
	return !operator==(lhs, rhs);
}

template <class T, class Alloc>
bool operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
{
	return ft::lexicographical_compare(
		lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <class T, class Alloc>
bool operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
{
	return ft::lexicographical_compare(
		lhs.begin(), lhs.end(), rhs.begin(), rhs.end(), ft::greater<T>());
}

template <class T, class Alloc>
bool operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
{
	return !operator<(lhs, rhs);
}

template <class T, class Alloc>
bool operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
{
	return !operator>(lhs, rhs);
}

template <class T, class Alloc>
void swap(vector<T, Alloc>& first, vector<T, Alloc>& second)
{
	first.swap(second);
}

} // namespace ft

#endif