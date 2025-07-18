#ifndef __ITERATOR__DEQUE_TPP
#define __ITERATOR__DEQUE_TPP

#include "__types__.hpp"
#pragma once
#include "deque.hpp"

namespace ft
{

template <class T> deque_iterator<T>::deque_iterator() : _deq(0), _cur(0)
{
}

template <class T>
deque_iterator<T>::deque_iterator(const deque_iterator& cpy)
    : _deq(cpy._deq), _cur(cpy._cur)
{
}

template <class T>
deque_iterator<T>& deque_iterator<T>::operator=(const deque_iterator& cpy)
{
  if (this != &cpy)
  {
    _cur = cpy._cur;
    _deq = cpy._deq;
  }
  return *this;
}

template <class T>
template <class U>
deque_iterator<T>::deque_iterator(const deque_iterator<U>& cpy)
    : _deq(cpy._deq), _cur(cpy._cur)
{
}

template <class T>
template <class U>
deque_iterator<T>& deque_iterator<T>::operator=(const deque_iterator<U>& cpy)
{
  if (static_cast<const void*>(this) != static_cast<const void*>(&cpy))
  {
    _cur = cpy._cur;
    _deq = cpy._deq;
  }
  return *this;
}

template <class T>
template <class U>
deque_iterator<T>::operator deque_iterator<U>() const
{
  return deque_iterator<U>(_deq, _cur);
}

template <class T> deque_iterator<T>::~deque_iterator()
{
}

template <class T>
deque_iterator<T>::deque_iterator(deque_type* _deq, size_t _cur)
    : _deq(_deq), _cur(_cur)
{
}

template <class T>
bool deque_iterator<T>::operator!=(const deque_iterator& rhs) const
{
  return base() != rhs.base();
}

template <class T>
bool deque_iterator<T>::operator<(const deque_iterator& rhs) const
{
  return this->_deq != rhs._deq ? this->_deq < rhs._deq : this->_cur < rhs._cur;
}

template <class T>
bool deque_iterator<T>::operator>(const deque_iterator& rhs) const
{
  return this->_deq != rhs._deq ? this->_deq > rhs._deq : this->_cur > rhs._cur;
}

template <class T>
bool deque_iterator<T>::operator<=(const deque_iterator& rhs) const
{
  return !operator>(rhs);
}

template <class T>
bool deque_iterator<T>::operator>=(const deque_iterator& rhs) const
{
  return !operator<(rhs);
}

template <class T>
bool deque_iterator<T>::operator==(const deque_iterator& rhs) const
{
  return base() == rhs.base();
}

template <class T>
const typename deque_iterator<T>::pointer deque_iterator<T>::operator->() const
{
  return base();
}

template <class T>
const typename deque_iterator<T>::reference deque_iterator<T>::operator[](
        int pos) const
{
  return (*_deq)[_cur + pos];
}

template <class T>
const typename deque_iterator<T>::reference deque_iterator<T>::operator*() const
{
  return *base();
}

template <class T>
template <class U>
typename deque_iterator<T>::difference_type deque_iterator<T>::operator-(
        const deque_iterator<U>& rhs) const
{
  return this->_cur - rhs._cur;
}

template <class T>
typename deque_iterator<T>::pointer deque_iterator<T>::operator->()
{
  return base();
}

template <class T>
typename deque_iterator<T>::reference deque_iterator<T>::operator[](int pos)
{
  return (*this->_deq)[pos];
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
  _cur--;
  return res;
}

template <class T>
deque_iterator<T> deque_iterator<T>::operator++(int) // NOLINT
{
  deque_iterator res(*this);
  _cur++;
  return res;
}

template <class T>
typename deque_iterator<T>::pointer deque_iterator<T>::base() const
{
  return &((*this->_deq)[_cur]);
}

template <class T> deque_iterator<T>& deque_iterator<T>::operator--()
{
  _cur--;
  return *this;
}

template <class T>
deque_iterator<T> deque_iterator<T>::operator-(const difference_type n) const
{
  return deque_iterator(_deq, _cur - n);
}

template <class T>
deque_iterator<T>& deque_iterator<T>::operator-=(const difference_type n)
{
  _cur -= n;
  return *this;
}

template <class T>
deque_iterator<T> deque_iterator<T>::operator+(const difference_type n) const
{
  return deque_iterator(_deq, _cur + n);
}

template <class T> deque_iterator<T>& deque_iterator<T>::operator++()
{
  _cur++;
  return *this;
}

template <class T>
deque_iterator<T>& deque_iterator<T>::operator+=(const difference_type n)
{
  _cur += n;
  return *this;
}

template <class T>
typename deque_iterator<T>::difference_type operator+(
        const typename deque_iterator<T>::difference_type lhs,
        deque_iterator<T>&                                rhs)
{
  return rhs + lhs;
}

} // namespace ft

#ifdef TEST
template class ft::deque_iterator<int>;
template class ft::deque_iterator<const int>;
#endif

#endif
