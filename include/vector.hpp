#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "iterator.hpp"
#include "type_traits.hpp"
#include "types/types.hpp"

namespace ft
{

template < class T, class Alloc > class vector;
template < class T > struct vector_iterator;

template < class T, class Alloc = std::allocator< T > > class vector
{
  public:
	typedef Alloc allocator_type;
	typedef ptrdiff_t difference_type;
	typedef size_t size_type;
	typedef T value_type;

	typedef typename allocator_type::const_pointer const_pointer;
	typedef typename allocator_type::const_reference const_reference;
	typedef typename allocator_type::pointer pointer;
	typedef typename allocator_type::reference reference;

	typedef vector_iterator< const value_type > const_iterator;
	typedef vector_iterator< value_type > iterator;

	typedef ft::reverse_iterator< const_iterator > const_reverse_iterator;
	typedef ft::reverse_iterator< iterator > reverse_iterator;

  private:
	allocator_type alc;
	pointer list;
	size_type length;

  public:
	explicit vector(const allocator_type& alloc = allocator_type());
	vector(const vector& cpy);
	explicit vector(size_type n,
					const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type());
	template < class InputIterator >
	vector(InputIterator first,
		   InputIterator last,
		   const allocator_type& alloc = allocator_type(),
		   typename enable_if< !numeric_limits< InputIterator >::is_integer >::type* /*unused*/ =
			   0);

	vector& operator=(const vector& cpy);

	~vector();

	allocator_type get_allocator() const;

	const_iterator begin() const;
	const_iterator end() const;
	const_reverse_iterator rbegin() const;
	const_reverse_iterator rend() const;
	iterator begin();
	iterator end();
	reverse_iterator rbegin();
	reverse_iterator rend();

	bool empty() const;
	size_type capacity() const;
	size_type max_size() const;
	size_type size() const;
	void reserve(size_type cap);
	void resize(size_type n, value_type val = value_type());

	const_reference at(size_type pos) const;
	const_reference back() const;
	const_reference front() const;
	const_reference operator[](size_type pos) const;
	reference at(size_type pos);
	reference back();
	reference front();
	reference operator[](size_type pos);

	iterator erase(iterator first, iterator last);
	iterator erase(iterator position);
	iterator insert(iterator position, const value_type& val);
	template < class InputIterator >
	void assign(
		InputIterator first,
		InputIterator last,
		typename enable_if< !numeric_limits< InputIterator >::is_integer >::type* /*unused*/ =
			0);
	template < class InputIterator >
	void insert(
		iterator position,
		InputIterator first,
		InputIterator last,
		typename enable_if< !numeric_limits< InputIterator >::is_integer >::type* /*unused*/ =
			0);
	void assign(size_type n, const value_type& val);
	void clear();
	void insert(iterator position, size_type n, const value_type& val);
	void pop_back();
	void push_back(const value_type& val);
	void swap(vector& other);
};

template < class T, class Alloc >
bool operator==(const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs);
template < class T, class Alloc >
bool operator!=(const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs);
template < class T, class Alloc >
bool operator<(const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs);
template < class T, class Alloc >
bool operator>(const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs);
template < class T, class Alloc >
bool operator>=(const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs);
template < class T, class Alloc >
bool operator<=(const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs);
template < class T, class Alloc >
void swap(vector< T, Alloc >& first, vector< T, Alloc >& second);

template < class T >
struct vector_iterator : public ft::iterator< random_access_iterator_tag, T >
{
	typedef ft::iterator< random_access_iterator_tag, T > _iterator;

	using typename _iterator::difference_type;
	using typename _iterator::iterator_category;
	using typename _iterator::pointer;
	using typename _iterator::reference;
	using typename _iterator::value_type;

	vector_iterator();
	vector_iterator(const vector_iterator& cpy);
	vector_iterator& operator=(const vector_iterator& cpy);
	~vector_iterator();

	explicit vector_iterator(pointer _current);

	bool operator!=(const vector_iterator& rhs);
	bool operator<(const vector_iterator& rhs);
	bool operator<=(const vector_iterator& rhs);
	bool operator==(const vector_iterator& rhs);
	bool operator>(const vector_iterator& rhs);
	bool operator>=(const vector_iterator& rhs);
	const pointer operator->() const;
	const reference operator[](int pos) const;
	const reference operator*() const;
	pointer base() const;
	pointer operator->();
	reference operator[](int pos);
	reference operator*();
	template < class U >
	difference_type operator-(const vector_iterator< U >& rhs);
	vector_iterator operator--(int); // NOLINT
	vector_iterator operator-(const difference_type n);
	vector_iterator operator+(const difference_type n);
	vector_iterator operator++(int); // NOLINT
	vector_iterator& operator--();
	vector_iterator& operator-=(const difference_type n);
	vector_iterator& operator++();
	vector_iterator& operator+=(const difference_type n);

  private:
	pointer current;
};

template < class T >
vector_iterator< T >&
operator+(const typename vector_iterator< T >::difference_type lhs,
		  vector_iterator< T >& rhs);

} // namespace ft

#include "templates/vector/__vector__.hpp" // IWYU pragma: export

#endif