#ifndef __DESTRUCTOR_LIST_TPP
#define __DESTRUCTOR_LIST_TPP

#pragma once
#include "list.hpp"

namespace ft
{

// Destructor
template <class T, class Alloc> list<T, Alloc>::~list()
{
  clear();
  this->_a_node_t.destroy(this->_past_end_head);
  this->_a_node_t.deallocate(this->_past_end_head, 1);
  this->_a_node_t.destroy(this->_past_end_tail);
  this->_a_node_t.deallocate(this->_past_end_tail, 1);
}

} // namespace ft

#endif
