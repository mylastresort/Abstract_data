#ifndef DELETIONS_LIST_TPP
#define DELETIONS_LIST_TPP

#pragma once
#include "list.hpp"

namespace ft
{

// Erase range
template <class T, class Alloc>
typename list<T, Alloc>::iterator list<T, Alloc>::erase(
        iterator position, iterator last)
{
  // TODO
  (void)position;
  (void)last;
  return iterator();
}

// Erase single element
template <class T, class Alloc>
typename list<T, Alloc>::iterator list<T, Alloc>::erase(iterator position)
{
  // TODO
  (void)position;
  return iterator();
}

// Remove if predicate
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

// Pop back element
template <class T, class Alloc> void list<T, Alloc>::pop_back()
{
  // TODO
}

// Pop front element
template <class T, class Alloc> void list<T, Alloc>::pop_front()
{
  // TODO
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
