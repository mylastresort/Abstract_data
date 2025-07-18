#ifndef __CONSTRUCTOR__LIST_TPP
#define __CONSTRUCTOR__LIST_TPP

#pragma once
#include "list.hpp"

namespace ft
{

template <class T, class Alloc>
list<T, Alloc>::list(const allocator_type& alloc) : _a(alloc), _len(0)
{
  this->_past_end_head = this->_a_node_t.allocate(1);
  this->_past_end_tail = this->_a_node_t.allocate(1);
  this->_a_node_t.construct(
          this->_past_end_head, Node<T>(0, this->_past_end_tail));
  this->_a_node_t.construct(
          this->_past_end_tail, Node<T>(this->_past_end_head, 0));
}

template <class T, class Alloc>
list<T, Alloc>::list(const list& cpy) : _a(cpy._a), _len(0)
{
  this->_past_end_head = this->_a_node_t.allocate(1);
  this->_past_end_tail = this->_a_node_t.allocate(1);
  this->_a_node_t.construct(
          this->_past_end_head, Node<T>(0, this->_past_end_tail));
  this->_a_node_t.construct(
          this->_past_end_tail, Node<T>(this->_past_end_head, 0));

  assign(cpy.begin(), cpy.end());
}

template <class T, class Alloc>
list<T, Alloc>::list(
        size_type size, const value_type& value, const allocator_type& alloc)
    : _a(alloc), _len(0)
{
  this->_past_end_head = this->_a_node_t.allocate(1);
  this->_past_end_tail = this->_a_node_t.allocate(1);
  this->_a_node_t.construct(
          this->_past_end_head, Node<T>(0, this->_past_end_tail));
  this->_a_node_t.construct(
          this->_past_end_tail, Node<T>(this->_past_end_head, 0));

  assign(size, value);
}

template <class T, class Alloc>
template <class InputIterator>
list<T, Alloc>::list(InputIterator first,
        InputIterator              last,
        const allocator_type&      alloc,
        typename enable_if<!numeric_limits<InputIterator>::is_integer>::type*)
    : _a(alloc), _len(0)
{
  this->_past_end_head = this->_a_node_t.allocate(1);
  this->_past_end_tail = this->_a_node_t.allocate(1);
  this->_a_node_t.construct(
          this->_past_end_head, Node<T>(0, this->_past_end_tail));
  this->_a_node_t.construct(
          this->_past_end_tail, Node<T>(this->_past_end_head, 0));

  assign(first, last);
}

template <class T, class Alloc>
list<T, Alloc>& list<T, Alloc>::operator=(const list& cpy)
{
  if (this != &cpy)
  {
    assign(cpy.begin(), cpy.end());
  }
  return *this;
}

template <class T, class Alloc>
typename list<T, Alloc>::allocator_type list<T, Alloc>::get_allocator() const
{
  return _a;
}

} // namespace ft

#endif
