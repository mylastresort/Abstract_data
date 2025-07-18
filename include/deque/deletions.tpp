#ifndef DELETIONS_DEQUE_TPP
#define DELETIONS_DEQUE_TPP

#include "deque/__impl_data_.hpp"
#pragma once
#include "deque.hpp"

namespace ft
{

template <class T, class Alloc> void deque<T, Alloc>::clear()
{
  typedef typename _deque_impl_data<Alloc>::map_t   map_t;
  typedef typename _deque_impl_data<Alloc>::chunk_t chunk_t;
  for (typename map_t::iterator itr = this->map.begin(); itr != this->map.end();
          itr++)
  {
    for (typename chunk_t::index_t i = (*itr)->head; i <= (*itr)->tail; i++)
    {
      this->alloc.destroy((*itr)->blocks + i); // NOLINT
    }
    this->alloc_chunk.deallocate(*itr, 1);
  }
  this->map.clear();
}

#ifdef TEST
// template class ft::deque< int >;
#endif

} // namespace ft

#endif