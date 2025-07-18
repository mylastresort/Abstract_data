#ifndef __ITERATOR__LIST_TPP
#define __ITERATOR__LIST_TPP

#pragma once
#include "list.hpp"

namespace ft
{

template <class T> list_iterator<T>::list_iterator(list_type _lst) : _cur(_lst)
{
}

template <class T> list_iterator<T>::list_iterator() : _cur(0)
{
}

template <class T>
list_iterator<T>::list_iterator(const list_iterator& cpy) : _cur(cpy._cur)
{
}

template <class T>
list_iterator<T>& list_iterator<T>::operator=(const list_iterator& cpy)
{
    if (this != &cpy)
    {
        _cur = cpy._cur;
    }
    return *this;
}

template <class T>
template <class U>
list_iterator<T>::list_iterator(const list_iterator<U>& cpy) : _cur(cpy._cur)
{
}

template <class T>
template <class U>
list_iterator<T>& list_iterator<T>::operator=(const list_iterator<U>& cpy)
{
    if (static_cast<const void*>(this) != static_cast<const void*>(&cpy))
    {
        _cur = cpy._cur;
    }
    return *this;
}

template <class T> list_iterator<T>::~list_iterator()
{
}

template <class T>
template <class U>
list_iterator<T>::operator list_iterator<U>() const
{
    return list_iterator<U>(_cur);
}

template <class T>
bool list_iterator<T>::operator!=(const list_iterator& rhs) const
{
    return _cur != rhs._cur;
}

template <class T>
bool list_iterator<T>::operator==(const list_iterator& rhs) const
{
    return _cur == rhs._cur;
}

template <class T>
const typename list_iterator<T>::pointer list_iterator<T>::operator->() const
{
    return _cur->val;
}

template <class T>
const typename list_iterator<T>::reference list_iterator<T>::operator*() const
{
    return _cur->val;
}

template <class T>
typename list_iterator<T>::pointer list_iterator<T>::operator->()
{
    return _cur->val;
}

template <class T>
typename list_iterator<T>::reference list_iterator<T>::operator*()
{
    return _cur->val;
}

template <class T> list_iterator<T> list_iterator<T>::operator--(int)
{
    list_iterator ret(_cur);
    _cur = _cur->prev;
    return ret;
}

template <class T> list_iterator<T> list_iterator<T>::operator++(int)
{
    list_iterator ret(_cur);
    _cur = _cur->next;
    return ret;
}

template <class T> list_iterator<T>& list_iterator<T>::operator--()
{
    _cur = _cur->prev;
    return *this;
}

template <class T> list_iterator<T>& list_iterator<T>::operator++()
{
    _cur = _cur->next;
    return *this;
}

} // namespace ft

#endif
