#ifndef ITERATORS_LIST_TPP
#define ITERATORS_LIST_TPP

#pragma once
#include "list.hpp"

namespace ft
{

template <class T, class Alloc>
typename list<T, Alloc>::const_iterator list<T, Alloc>::begin() const
{
    return const_iterator(_past_end_head->next);
}

template <class T, class Alloc>
typename list<T, Alloc>::const_iterator list<T, Alloc>::end() const
{
    return const_iterator(_past_end_tail);
}

template <class T, class Alloc>
typename list<T, Alloc>::const_reverse_iterator list<T, Alloc>::rbegin() const
{
    if (size() > 0)
        return const_reverse_iterator(--end());
    return const_reverse_iterator(end());
}

template <class T, class Alloc>
typename list<T, Alloc>::const_reverse_iterator list<T, Alloc>::rend() const
{
    if (size() > 0)
        return const_reverse_iterator(--begin());
    return const_reverse_iterator(end());
}

template <class T, class Alloc>
typename list<T, Alloc>::iterator list<T, Alloc>::begin()
{
    return iterator(_past_end_head->next);
}

template <class T, class Alloc>
typename list<T, Alloc>::iterator list<T, Alloc>::end()
{
    return iterator(_past_end_tail);
}

template <class T, class Alloc>
typename list<T, Alloc>::reverse_iterator list<T, Alloc>::rbegin()
{
    if (size() > 0)
        return reverse_iterator(--end());
    return reverse_iterator(end());
}

template <class T, class Alloc>
typename list<T, Alloc>::reverse_iterator list<T, Alloc>::rend()
{
    if (size() > 0)
        return reverse_iterator(--begin());
    return reverse_iterator(end());
}

} // namespace ft

#endif // ITERATORS_LIST_TPP
