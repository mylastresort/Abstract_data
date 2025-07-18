#ifndef __IMPL_DATA_VECTOR_HPP
#define __IMPL_DATA_VECTOR_HPP

#include <memory>

namespace ft
{

template <class pointer, class allocator> class _vector_impl_data
{
protected:
  allocator alloc;
  pointer   begin_ptr;
  pointer   cap_ptr;
  pointer   end_ptr;

  explicit _vector_impl_data(const allocator& alloc)
      : alloc(alloc), begin_ptr(), cap_ptr(begin_ptr), end_ptr(begin_ptr)
  {
  }
};

#ifdef TEST
typedef std::allocator<int> allocator;
template class _vector_impl_data<allocator, allocator::pointer>;
#endif

} // namespace ft

#endif