#ifndef __IMPL_DATA_DEQUE_HPP
#define __IMPL_DATA_DEQUE_HPP

#include "__types__.hpp"
#include "iterator.hpp"
#include "vector.hpp"
#include <iostream>

#define CHUNK_SIZE 8

namespace ft
{

template <class T> struct chunk
{
  typedef unsigned short index_t;

  index_t head;
  index_t tail;
  T       blocks[CHUNK_SIZE];

  explicit chunk(const index_t _head, const index_t _tail)
      : head(_head), tail(_tail)
  {
  }
};

template <class Alloc> struct _deque_impl_data
{
  typedef Alloc allocator_type;

  typedef typename Alloc::value_type value_type;

  typedef chunk<value_type> chunk_t;

  typedef chunk_t* pchunk_t;

  typedef typename allocator_type::template rebind<chunk_t>::other  achunk_t;
  typedef typename allocator_type::template rebind<pchunk_t>::other amap_t;

  typedef vector<pchunk_t, amap_t> map_t;

  achunk_t       alloc_chunk;
  allocator_type alloc;
  map_t          map;

  explicit _deque_impl_data(const allocator_type& alloc)
      : alloc_chunk(achunk_t()), alloc(alloc), map(amap_t())
  {
  }

  struct _chunk_iterator
      : public ft::iterator<random_access_iterator_tag, value_type>
  {
    struct _iterator
    {
      typedef typename chunk<value_type>::index_t index_t;
      achunk_t                                    alloc_chunk;
      allocator_type                              alloc;
      const value_type&                           val; // NOLINT
      size_t                                      current;
      int                                         head;

      pchunk_t operator*()
      {
        pchunk_t ret = alloc_chunk.allocate(1);
        std::cout << "hello" << std::endl;
        index_t tail = (current > CHUNK_SIZE ? CHUNK_SIZE : current) - 1;
        *ret = chunk<value_type>(head, tail);
        // for (index_t i = head; i <= tail; i++)
        // {
        // 	this->alloc.construct(&ret->blocks[i], val); // NOLINT
        // }
        return ret;
      }

      _iterator& operator++()
      {
        int res = CHUNK_SIZE - head;
        // current = res <= 0 ? 0 : current - res;
        std::cout << "res" << res << std::endl;
        current = 0;
        head = 0;
        return *this;
      }

      _iterator operator++(int) // NOLINT
      {
        _iterator res(*this);
        ++(*this);
        return res;
      }

      bool operator!=(const _iterator& rhs)
      {
        std::cout << "current- rhs" << rhs.current << std::endl;
        std::cout << "current- " << current << std::endl;
        return current != rhs.current;
      }

      ptrdiff_t operator-(const _iterator& rhs)
      {
        std::cout << "current " << current << std::endl;
        std::cout << "rhs.current " << rhs.current << std::endl;
        ptrdiff_t ret = (rhs.current - current) / CHUNK_SIZE + 1;
        std::cout << "hello " << ret << std::endl;
        return ret;
      }

      explicit _iterator(size_t     _current = 0,
              const value_type&     _val = value_type(),
              const achunk_t&       _alloc_chunk = achunk_t(),
              const allocator_type& alloc = allocator_type())
          : alloc_chunk(_alloc_chunk), alloc(alloc), val(_val),
            current(_current), head(CHUNK_SIZE - (_current % CHUNK_SIZE) / 2)
      {
      }
    };

    achunk_t  alloc_chunk;
    pchunk_t  data;
    _iterator first;
    _iterator last;

    _chunk_iterator(size_t    count,
            const value_type& val,
            const achunk_t&   alloc_chunk = achunk_t())
        : alloc_chunk(alloc_chunk), data(this->alloc_chunk.allocate(1)),
          first(_iterator(count, val)), last(_iterator(0))
    {
    }
    // _chunk_iterator(
    // 	InputIterator first,
    // 	InputIterator last,
    // 	typename enable_if< !numeric_limits< InputIterator >::is_integer
    // >::type* /*unused*/ = 		0);
  };
};

#ifdef TEST
// template struct _deque_impl_data< std::allocator< int > >;
template struct _deque_impl_data<std::allocator<int> >::_chunk_iterator;
#endif

} // namespace ft

#endif