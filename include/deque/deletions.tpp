#ifndef DELETIONS_DEQUE_TPP
#define DELETIONS_DEQUE_TPP

#pragma once
#include "deque.hpp"

namespace ft
{

template <class T, class Alloc> void deque<T, Alloc>::clear()
{
	if (this->_map_ptr == 0 || this->_chunks_sz == 0)
		return;
	for (iterator itr = begin(); itr != end(); itr++)
	{
		this->_a.destroy(&*itr);
	}
	this->_begin_offset = (this->_chunks_sz * CHUNK_SIZE) / 2;
	this->_past_end_offset = this->_begin_offset;
}

template <class T, class Alloc>
typename deque<T, Alloc>::iterator deque<T, Alloc>::erase(iterator first,
														  iterator last)
{
	size_type dis = first - begin();
	for (iterator it = first; it != last; it++)
	{
		this->_a.destroy(&*it);
		if (last + (it - first) < end())
		{
			this->_a.construct(&*it, it[last - first]);
		}
	}
	this->_past_end_offset -= last - first;
	return begin() + dis;
}

template <class T, class Alloc>
typename deque<T, Alloc>::iterator deque<T, Alloc>::erase(iterator pos)
{
	size_type dis = pos - begin();
	this->_a.destroy(&*pos);
	if (pos < end())
	{
		for (iterator it = pos; it != end(); it++)
		{
			if (pos + 1 < end())
			{
				this->_a.construct(&*it, pos[1]);
			}
		}
		this->_past_end_offset -= 1;
	}
	return begin() + dis;
}

template <class T, class Alloc> void deque<T, Alloc>::pop_back()
{
	if (size())
		erase(end() - 1);
}

template <class T, class Alloc> void deque<T, Alloc>::pop_front()
{
	if (size())
	{
		this->_a.destroy(&*begin());
		this->_begin_offset++;
	}
}

#ifdef TEST
// template class ft::deque<int>;
#endif

} // namespace ft

#endif
