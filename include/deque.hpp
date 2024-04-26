#ifndef DEQUE_HPP
#define DEQUE_HPP

#include "iterator.hpp"
#include <cstddef>
#include <memory>

namespace ft
{
template < class T, class Allocator = std::allocator< T > > class deque
{
  public:
	typedef Allocator allocator_type;
	typedef const iterator< random_access_iterator_tag, T > const_iterator;
	typedef const T* const_pointer;
	typedef const T& const_reference;
	typedef iterator< random_access_iterator_tag, T > iterator;
	typedef ptrdiff_t difference_type;
	typedef reverse_iterator< const_iterator > const_reverse_iterator;
	typedef reverse_iterator< iterator > reverse_iterator;
	typedef size_t size_type;
	typedef T value_type;
	typedef T* pointer;
	typedef T& reference;

	// constructors
	explicit deque(const allocator_type& = allocator_type());
	explicit deque(size_type size,
				   const value_type& value = value_type(),
				   const allocator_type& alloc = allocator_type());
	template < class InputIterator >
	deque(InputIterator first,
		  InputIterator last,
		  const allocator_type& alloc = allocator_type());

	// copy constructor
	deque(const deque& cpy);

	// assignment constructor
	deque< T, allocator_type >& operator=(const deque& cpy);

	// destructor
	~deque();

	// allocator
	allocator_type get_allocator() const;

	// insertion
	iterator insert(iterator position, const value_type& val);
	template < class InputIterator >
	void assign(InputIterator first, InputIterator last);
	template < class InputIterator >
	void insert(iterator position, InputIterator first, InputIterator last);
	void assign(size_type count, const value_type& val);
	void insert(iterator position, size_type n, const value_type& val);
	void push_back(const value_type& val);
	void push_front(const value_type& val);

	// iterators
	const_iterator begin() const;
	const_iterator end() const;
	const_reverse_iterator rbegin() const;
	const_reverse_iterator rend() const;
	iterator begin();
	iterator end();
	reverse_iterator rbegin();
	reverse_iterator rend();

	// capacity
	bool empty() const;
	size_type max_size() const;
	size_type size() const;
	void resize(size_type size, value_type val = value_type());

	// element access
	const_reference at(size_type pos) const;
	const_reference back() const;
	const_reference front() const;
	const_reference operator[](size_type pos) const;
	reference at(size_type pos);
	reference back();
	reference front();
	reference operator[](size_type pos);

	// deletion
	iterator erase(iterator first, iterator last);
	iterator erase(iterator position);
	void clear();
	void pop_back();
	void pop_front();

	// modifiers
	void swap(deque& other);
};

template < class T, class Allocator >
bool operator==(const deque< T, Allocator >& lhs,
				const deque< T, Allocator >& rhs);
template < class T, class Allocator >
bool operator<(const deque< T, Allocator >& lhs,
			   const deque< T, Allocator >& rhs);
template < class T, class Allocator >
bool operator!=(const deque< T, Allocator >& lhs,
				const deque< T, Allocator >& rhs);
template < class T, class Allocator >
bool operator>(const deque< T, Allocator >& lhs,
			   const deque< T, Allocator >& rhs);
template < class T, class Allocator >
bool operator>=(const deque< T, Allocator >& lhs,
				const deque< T, Allocator >& rhs);
template < class T, class Allocator >
bool operator<=(const deque< T, Allocator >& lhs,
				const deque< T, Allocator >& rhs);

template < class T, class Allocator >
void swap(deque< T, Allocator >& first, deque< T, Allocator >& second);
} // namespace ft

#include "templates/deque.tpp"

#endif