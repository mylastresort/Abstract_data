#ifndef CAPACITY_LIST_TPP
#define CAPACITY_LIST_TPP

#pragma once
#include "list.hpp"

namespace ft
{

// Check if list is empty
template <class T, class Alloc> bool list<T, Alloc>::empty() const
{
    // TODO
    return true;
}

// Get maximum size
template <class T, class Alloc>
typename list<T, Alloc>::size_type list<T, Alloc>::max_size() const
{
    // TODO
    return _a.max_size();
}

// Get size
template <class T, class Alloc>
typename list<T, Alloc>::size_type list<T, Alloc>::size() const
{
    return this->_len;
}

// Resize list
template <class T, class Alloc>
void list<T, Alloc>::resize(size_type size, value_type val)
{
    // TODO
    (void)size;
    (void)val;
}

} // namespace ft

#endif
