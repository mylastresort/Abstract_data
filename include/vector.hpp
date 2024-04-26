#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "iterator.hpp"
#include <iterator>
#include <memory>

namespace ft
{

template < typename T >
class vector_iterator : public iterator< random_access_iterator_tag, T >
{
};

template < typename It >
class vector_reverse_iterator : public reverse_iterator< It >
{
};

template < class T, class Alloc = std::allocator< T > > class vector
{
  public:
	typedef Alloc allocator_type;
	typedef const vector_iterator< T > const_iterator;
	typedef const T* const_pointer;
	typedef const T& const_reference;
	typedef vector_iterator< T > iterator;
	typedef ptrdiff_t difference_type;
	typedef vector_reverse_iterator< const_iterator > const_reverse_iterator;
	typedef vector_reverse_iterator< iterator > reverse_iterator;
	typedef size_t size_type;
	typedef T value_type;
	typedef T* pointer;
	typedef T& reference;

  private:
	allocator_type alc;
	pointer list;
	size_type length;

  public:
	// constructors
	explicit vector(const allocator_type& alloc = allocator_type());
	explicit vector(size_type size,
					const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type());
	template < class InputIterator >
	vector(InputIterator first,
		   InputIterator last,
		   const allocator_type& alloc = allocator_type());

	// copy constructor
	vector(const vector& cpy);

	// assignment constructor
	vector& operator=(const vector& cpy);

	// allocator
	allocator_type get_allocator() const;

	// destructors
	~vector();

	// iterators:
	const_iterator begin() const;
	const_iterator end() const;
	const_reverse_iterator rbegin() const;
	const_reverse_iterator rend() const;
	iterator begin();
	iterator end();
	reverse_iterator rbegin();
	reverse_iterator rend();

	// capacity:
	bool empty() const;
	size_type capacity() const;
	size_type max_size() const;
	size_type size() const;
	void reserve(size_type cap);
	void resize(size_type size, value_type val = value_type());

	// element access:
	const_reference at(size_type pos) const;
	const_reference back() const;
	const_reference front() const;
	const_reference operator[](size_type pos) const;
	reference at(size_type pos);
	reference back();
	reference front();
	reference operator[](size_type pos);

	// insertion
	iterator insert(iterator position, const value_type& val);
	template < class InputIterator >
	void assign(InputIterator first, InputIterator last);
	template < class InputIterator >
	void insert(iterator position, InputIterator first, InputIterator last);
	void assign(size_type size, const value_type& val);
	void insert(iterator position, size_type size, const value_type& val);
	void push_back(const value_type& val);

	// modifiers:
	iterator erase(iterator first, iterator last);
	iterator erase(iterator position);
	void clear();
	void pop_back();
	void swap(vector& other);
};

template < class T, class Alloc >
bool operator==(const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs);
template < class T, class Alloc >
bool operator<(const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs);
template < class T, class Alloc >
bool operator!=(const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs);
template < class T, class Alloc >
bool operator>(const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs);
template < class T, class Alloc >
bool operator>=(const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs);
template < class T, class Alloc >
bool operator<=(const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs);

template < class T, class Alloc >
void swap(vector< T, Alloc >& first, vector< T, Alloc >& second);

} // namespace ft

#include "templates/vector.tpp"

#endif