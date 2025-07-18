#ifndef DELETIONS_LIST_TPP
#define DELETIONS_LIST_TPP

#pragma once
#include "list.hpp"

namespace ft
{

template <class T, class Alloc>
typename list<T, Alloc>::iterator list<T, Alloc>::erase(
        iterator position, iterator last)
{
  if (position == last)
    return position;
  Node<T>*  prev = position._cur->prev;
  size_type len = 0;
  for (iterator it = position; it != last;)
  {
    iterator _cur = it++;
    this->_a_node_t.destroy(_cur._cur);
    this->_a_node_t.deallocate(_cur._cur, 1);
    len++;
  }
  this->_len -= len;
  prev->next = last._cur;
  last._cur->prev = prev;
  return ++last;
}

template <class T, class Alloc>
typename list<T, Alloc>::iterator list<T, Alloc>::erase(iterator position)
{
  if (position == rend().base() || position == end())
    return position;
  iterator ret(position._cur->next);
  position._cur->prev->next = position._cur->next;
  position._cur->next->prev = position._cur->prev;
  this->_a_node_t.destroy(position._cur);
  this->_a_node_t.deallocate(position._cur, 1);
  this->_len -= 1;
  return ret;
}

template <class T, class Alloc>
template <class Predicate>
void list<T, Alloc>::remove_if(Predicate pred)
{
  // TODO
  (void)pred;
}

template <class T, class Alloc> void list<T, Alloc>::clear()
{
  for (iterator it = begin(); it != end();)
  {
    iterator _cur = it++;
    it._cur->prev = 0;
    this->_past_end_head->next = it._cur;
    it._cur->prev = this->_past_end_head;
    this->_len -= 1;
    this->_a_node_t.destroy(_cur._cur);
    this->_a_node_t.deallocate(_cur._cur, 1);
  }
}

template <class T, class Alloc> void list<T, Alloc>::pop_back()
{
  if (size() > 0)
    erase(--end());
}

template <class T, class Alloc> void list<T, Alloc>::pop_front()
{
  if (size() > 0)
    erase(begin());
}

// Remove specific value
template <class T, class Alloc>
void list<T, Alloc>::remove(const value_type& value)
{
  // TODO
  (void)value;
}

} // namespace ft

#endif
