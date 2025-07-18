#ifndef INSERTIONS_LIST_TPP
#define INSERTIONS_LIST_TPP

#pragma once
#include "list.hpp"

namespace ft
{

template <class T, class Alloc>
typename list<T, Alloc>::iterator list<T, Alloc>::_insert(
        iterator position, size_type count, const value_type& val)
{
  if (count == 0)
    return position;
  Node<T>* prev = 0;
  Node<T>* head = this->_a_node_t.allocate(1);
  this->_a_node_t.construct(head, Node<T>(val));
  prev = position._cur->prev;
  prev->next = head;
  head->prev = prev;
  Node<T>* cur = head;
  prev = head;
  for (size_type it = 0; it < (count - 1); it++)
  {
    cur = this->_a_node_t.allocate(1);
    this->_a_node_t.construct(cur, Node<T>(prev, 0, val));
    prev->next = cur;
    prev = cur;
  }
  position._cur->prev = cur;
  cur->next = position._cur;
  this->_len += count;
  return iterator(head);
}

template <class T, class Alloc>
typename list<T, Alloc>::iterator list<T, Alloc>::insert(
        iterator position, const value_type& val)
{
  return _insert(position, 1, val);
}

template <class T, class Alloc>
template <class InputIterator>
void list<T, Alloc>::assign(InputIterator first,
        InputIterator                     last,
        typename enable_if<!numeric_limits<InputIterator>::is_integer>::type*)
{
  clear();
  insert(begin(), first, last);
}

template <class T, class Alloc>
template <class InputIterator>
void list<T, Alloc>::insert(iterator position,
        InputIterator                first,
        InputIterator                last,
        typename enable_if<!numeric_limits<InputIterator>::is_integer>::type*)
{
  if (first == last)
    return;
  Node<T>* prev = 0;
  Node<T>* head = this->_a_node_t.allocate(1);
  this->_a_node_t.construct(head, Node<T>(*first));
  prev = position._cur->prev;
  prev->next = head;
  head->prev = prev;
  Node<T>* cur = head;
  prev = head;
  size_type len = 1;
  for (InputIterator it = ++first; it != last; it++)
  {
    cur = this->_a_node_t.allocate(1);
    this->_a_node_t.construct(cur, Node<T>(prev, 0, *it));
    prev->next = cur;
    prev = cur;
    len++;
  }
  position._cur->prev = cur;
  cur->next = position._cur;
  this->_len += len;
}

template <class T, class Alloc>
void list<T, Alloc>::assign(size_type count, const value_type& val)
{
  clear();
  insert(begin(), count, val);
}

template <class T, class Alloc>
void list<T, Alloc>::insert(
        iterator position, size_type count, const value_type& val)
{
  _insert(position, count, val);
}

template <class T, class Alloc>
void list<T, Alloc>::push_back(const value_type& val)
{
  insert(end(), val);
}

template <class T, class Alloc>
void list<T, Alloc>::push_front(const value_type& val)
{
  insert(begin(), val);
}

template <class T, class Alloc>
typename list<T, Alloc>::const_reference list<T, Alloc>::back() const
{
  return *rbegin();
}

template <class T, class Alloc>
typename list<T, Alloc>::const_reference list<T, Alloc>::front() const
{
  return *begin();
}

template <class T, class Alloc>
typename list<T, Alloc>::reference list<T, Alloc>::back()
{
  return *rbegin();
}

template <class T, class Alloc>
typename list<T, Alloc>::reference list<T, Alloc>::front()
{
  return *begin();
}

} // namespace ft

#endif // INSERTIONS_LIST_TPP
