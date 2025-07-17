#ifndef INSERTIONS_DEQUE_TPP
#define INSERTIONS_DEQUE_TPP

#pragma once
#include "deque.hpp"

namespace ft
{

template <class T, class Alloc>
template <class InputIterator>
void deque<T, Alloc>::assign(
	InputIterator first,
	InputIterator last,
	typename enable_if<!numeric_limits<InputIterator>::is_integer>::type* /*unused*/)
{
	clear();
	size_type count = last - first;
	size_type size = count / CHUNK_SIZE + 1;
	if (size > this->_chunks_sz)
	{
		if (this->_map_ptr == 0)
		{
			this->_map_ptr = this->_a_map.allocate(size);
			for (size_type i = 0; i < size; i++)
			{
				this->_map_ptr[i] = this->_a.allocate(CHUNK_SIZE);
			}
		}
		else
		{
			map_t ptr = this->_a_map.allocate(size);
			for (size_type i = 0; i < this->_chunks_sz; i++)
			{
				ptr[i] = this->_map_ptr[i];
			}
			for (size_type i = this->_chunks_sz; i < size; i++)
			{
				ptr[i] = this->_a.allocate(CHUNK_SIZE);
			}
			this->_a_map.deallocate(this->_map_ptr, this->_chunks_sz);
			this->_map_ptr = ptr;
		}
		this->_chunks_sz = size;
	}
	size = this->_chunks_sz;
	this->_begin_offset = (size * CHUNK_SIZE - count) / 2;
	this->_past_end_offset = this->_begin_offset + count;
	InputIterator _it = first;
	for (iterator it = begin(); it != end(); it++, _it++)
	{
		this->_a.construct(&*it, *_it);
	}
}

template <class T, class Alloc>
void deque<T, Alloc>::assign(size_type count, const value_type& val)
{
	clear();
	size_type size = count / CHUNK_SIZE + 1;
	if (size > this->_chunks_sz)
	{
		if (this->_map_ptr == 0)
		{
			this->_map_ptr = this->_a_map.allocate(size);
			for (size_type i = 0; i < size; i++)
			{
				this->_map_ptr[i] = this->_a.allocate(CHUNK_SIZE);
			}
		}
		else
		{
			map_t ptr = this->_a_map.allocate(size);
			for (size_type i = 0; i < this->_chunks_sz; i++)
			{
				ptr[i] = this->_map_ptr[i];
			}
			for (size_type i = this->_chunks_sz; i < size; i++)
			{
				ptr[i] = this->_a.allocate(CHUNK_SIZE);
			}
			this->_a_map.deallocate(this->_map_ptr, this->_chunks_sz);
			this->_map_ptr = ptr;
		}
		this->_chunks_sz = size;
	}
	size = this->_chunks_sz;
	this->_begin_offset = (size * CHUNK_SIZE - count) / 2;
	this->_past_end_offset = this->_begin_offset + count;
	for (iterator it = begin(); it != end(); it++)
	{
		this->_a.construct(&*it, val);
	}
}

template <class T, class Alloc>
typename deque<T, Alloc>::iterator deque<T, Alloc>::insert(iterator position,
														   const value_type& val)
{
	size_type pos = position - begin();
	insert(position, 1, val);
	return begin() + pos;
}

template <class T, class Alloc>
template <class InputIterator>
void deque<T, Alloc>::insert(
	iterator position,
	InputIterator first,
	InputIterator last,
	typename enable_if<!numeric_limits<InputIterator>::is_integer>::type*)
{
	size_type n = last - first;
	if (n == 0)
		return;
	size_type new_size = (size() + this->_begin_offset + n) / CHUNK_SIZE + 1;
	if (new_size > this->_chunks_sz)
	{
		if (this->_map_ptr == 0)
		{
			this->_map_ptr = this->_a_map.allocate(new_size);
			for (size_type i = 0; i < new_size; i++)
			{
				this->_map_ptr[i] = this->_a.allocate(CHUNK_SIZE);
			}
		}
		else
		{
			map_t ptr = this->_a_map.allocate(new_size);
			for (size_type i = 0; i < this->_chunks_sz; i++)
			{
				ptr[i] = this->_map_ptr[i];
			}
			for (size_type i = this->_chunks_sz; i < new_size; i++)
			{
				ptr[i] = this->_a.allocate(CHUNK_SIZE);
			}
			this->_a_map.deallocate(this->_map_ptr, this->_chunks_sz);
			this->_map_ptr = ptr;
		}
		this->_chunks_sz = new_size;
	}
	size_type dis = end() - position;
	this->_past_end_offset += n;
	for (reverse_iterator it = rbegin(), _end = rbegin() + dis; it != _end; it++)
	{
		this->_a.construct(&*it, it[n]);
	}
	InputIterator _it = first;
	for (iterator it = position; it != position + n; it++, _it++)
	{
		this->_a.construct(&*it, *_it);
	}
}

template <class T, class Alloc>
void deque<T, Alloc>::insert(iterator position, size_type n, const value_type& val)
{
	if (n == 0)
		return;
	size_type new_size = (size() + this->_begin_offset + n) / CHUNK_SIZE + 1;
	if (new_size > this->_chunks_sz)
	{
		if (this->_map_ptr == 0)
		{
			this->_map_ptr = this->_a_map.allocate(new_size);
			for (size_type i = 0; i < new_size; i++)
			{
				this->_map_ptr[i] = this->_a.allocate(CHUNK_SIZE);
			}
		}
		else
		{
			map_t ptr = this->_a_map.allocate(new_size);
			for (size_type i = 0; i < this->_chunks_sz; i++)
			{
				ptr[i] = this->_map_ptr[i];
			}
			for (size_type i = this->_chunks_sz; i < new_size; i++)
			{
				ptr[i] = this->_a.allocate(CHUNK_SIZE);
			}
			this->_a_map.deallocate(this->_map_ptr, this->_chunks_sz);
			this->_map_ptr = ptr;
		}
		this->_chunks_sz = new_size;
	}
	size_type dis = end() - position;
	this->_past_end_offset += n;
	for (reverse_iterator it = rbegin(), _end = rbegin() + dis; it != _end; it++)
	{
		this->_a.construct(&*it, it[n]);
	}
	for (iterator it = position; it != position + n; it++)
	{
		this->_a.construct(&*it, val);
	}
}

template <class T, class Alloc>
void deque<T, Alloc>::push_back(const value_type& val)
{
	insert(end(), val);
}

template <class T, class Alloc>
void deque<T, Alloc>::push_front(const value_type& val)
{
	insert(begin(), val);
}

#ifdef TEST
template class ft::deque<int>;
#endif

} // namespace ft

#endif
