#ifndef INSERTIONS_VECTOR_TPP
#define INSERTIONS_VECTOR_TPP

#pragma once
#include "type_traits.hpp"
#include "vector.hpp"

namespace ft
{

template <class T, class Alloc>
void vector<T, Alloc>::push_back(const value_type& val)
{
  resize(size() + 1, val);
}

template <class T, class Alloc>
template <class InputIterator>
void vector<T, Alloc>::assign(InputIterator first,
        InputIterator                       last,
        typename enable_if<!numeric_limits<InputIterator>::is_integer>::type*
        /*unused*/)
{
  clear();
  reserve(last - first);
  for (InputIterator i = first; i != last; i++)
  {
    this->alloc.construct(this->begin_ptr + (i - first), *i);
  }
  this->end_ptr = this->begin_ptr + (last - first);
}

template <class T, class Alloc>
void vector<T, Alloc>::assign(size_type n, const value_type& val)
{
  clear();
  reserve(n);
  for (size_type i = 0; i < n; i++)
  {
    this->alloc.construct(this->begin_ptr + i, val);
  }
  this->end_ptr = this->begin_ptr + n;
}

template <class T, class Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::insert(
        iterator position, const value_type& val)
{
  difference_type distance = position - begin();
  insert(position, 1, val);
  return begin() + distance;
}

template <class T, class Alloc>
template <class InputIterator>
void vector<T, Alloc>::insert(iterator position,
        InputIterator                  first,
        InputIterator                  last,
        typename enable_if<!numeric_limits<InputIterator>::is_integer>::type*
        /*unused*/)
{
  difference_type distance = last - first;
  if (capacity() >= size() + distance)
  {
    for (reverse_iterator i = rbegin(),
                          j = reverse_iterator(end() - 1 + distance);
            i.base() != position;
            i++, j++)
    {
      *j = *i;
    }
    InputIterator itr = first;
    for (iterator i = position; i != position + distance; i++)
    {
      this->alloc.construct(&*i, *itr);
      itr++;
    }
    this->end_ptr += distance;
  }
  else
  {
    if (size() + distance > max_size())
    {
      throw "Fatal: cannot allocate requested size exceeding max_size";
    }
    size_type new_size = size() + distance;
    pointer   new_list = this->alloc.allocate(new_size);
    for (iterator i = begin(); i != position; i++)
    {
      new_list[i - begin()] = *i;
    }
    InputIterator itr = first;
    for (difference_type i = position - begin();
            i < position - begin() + distance;
            i++)
    {
      this->alloc.construct(new_list + i, *itr);
      itr++;
    }
    iterator new_post_pos = iterator(new_list) + (position + distance - begin());
    for (iterator i = new_post_pos, j = position; j != end(); i++, j++)
    {
      *i = *j;
    }
    this->alloc.deallocate(this->begin_ptr, capacity());
    this->begin_ptr = new_list;
    this->end_ptr = this->begin_ptr + new_size;
    this->cap_ptr = this->begin_ptr + new_size;
  }
}

template <class T, class Alloc>
void vector<T, Alloc>::insert(
        iterator position, size_type n, const value_type& val)
{
  if (capacity() >= size() + n)
  {
    for (reverse_iterator i = rbegin(), j = reverse_iterator(end() - 1 + n);
            i.base() != position;
            i++, j++)
    {
      *j = *i;
    }
    for (iterator i = position; i != position + n; i++)
    {
      this->alloc.construct(&*i, val);
    }
    this->end_ptr += n;
  }
  else
  {
    if (size() + n > max_size())
    {
      throw "Fatal: cannot allocate requested size exceeding max_size";
    }
    size_type new_size = size() + n;
    pointer   new_list = this->alloc.allocate(new_size);
    for (iterator i = begin(); i != position; i++)
    {
      new_list[i - begin()] = *i;
    }
    for (difference_type i = position - begin(); i < position - begin() + n; i++)
    {
      this->alloc.construct(new_list + i, val);
    }
    iterator new_post_pos = iterator(new_list) + (position + n - begin());
    for (iterator i = new_post_pos, j = position; j != end(); i++, j++)
    {
      *i = *j;
    }
    this->alloc.deallocate(this->begin_ptr, capacity());
    this->begin_ptr = new_list;
    this->end_ptr = this->begin_ptr + new_size;
    this->cap_ptr = this->begin_ptr + new_size;
  }
}

} // namespace ft

#endif