#ifndef DEQUE_HPP
#define DEQUE_HPP

#include "deque/__impl_data_.hpp"
#include "iterator.hpp"
#include "type_traits.hpp"

namespace ft
{

template < class T > struct deque_iterator;

template < class T, class Alloc = std::allocator< T > >
class deque : protected _deque_impl_data< Alloc >
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

	typedef deque_iterator< const value_type > const_iterator;
	typedef deque_iterator< value_type > iterator;

	typedef ft::reverse_iterator< const_iterator > const_reverse_iterator;
	typedef ft::reverse_iterator< iterator > reverse_iterator;

	explicit deque(const allocator_type& alloc = allocator_type());
	deque(const deque& cpy);
	explicit deque(size_type n,
				   const value_type& value = value_type(),
				   const allocator_type& alloc = allocator_type());
	template < class InputIterator >
	deque(InputIterator first,
		  InputIterator last,
		  const allocator_type& alloc = allocator_type(),
		  typename enable_if< !numeric_limits< InputIterator >::is_integer >::type* /*unused*/ =
			  0);

	deque& operator=(const deque& cpy);

	~deque();

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
	size_type max_size() const;
	size_type size() const;
	void resize(size_type size, value_type val = value_type());

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
	void clear();
	void pop_back();
	void pop_front();

	iterator insert(iterator position, const value_type& val);
	template < class InputIterator >
	void assign(
		InputIterator first,
		InputIterator last,
		typename enable_if< !numeric_limits< InputIterator >::is_integer >::type* =
			0);
	template < class InputIterator >
	void insert(
		iterator position,
		InputIterator first,
		InputIterator last,
		typename enable_if< !numeric_limits< InputIterator >::is_integer >::type* =
			0);
	void assign(size_type count, const value_type& val);
	void insert(iterator position, size_type n, const value_type& val);
	void push_back(const value_type& val);
	void push_front(const value_type& val);

	void swap(deque& other);
};

template < class T, class Alloc >
bool operator==(const deque< T, Alloc >& lhs, const deque< T, Alloc >& rhs);
template < class T, class Alloc >
bool operator<(const deque< T, Alloc >& lhs, const deque< T, Alloc >& rhs);
template < class T, class Alloc >
bool operator!=(const deque< T, Alloc >& lhs, const deque< T, Alloc >& rhs);
template < class T, class Alloc >
bool operator>(const deque< T, Alloc >& lhs, const deque< T, Alloc >& rhs);
template < class T, class Alloc >
bool operator>=(const deque< T, Alloc >& lhs, const deque< T, Alloc >& rhs);
template < class T, class Alloc >
bool operator<=(const deque< T, Alloc >& lhs, const deque< T, Alloc >& rhs);

template < class T, class Alloc >
void swap(deque< T, Alloc >& first, deque< T, Alloc >& second);

template < class T >
struct deque_iterator : public ft::iterator< random_access_iterator_tag, T >
{
	typedef ft::iterator< random_access_iterator_tag, T > _iterator;

	using typename _iterator::difference_type;
	using typename _iterator::iterator_category;
	using typename _iterator::pointer;
	using typename _iterator::reference;
	using typename _iterator::value_type;

	typedef chunk< value_type >** data_t;

	deque_iterator();
	deque_iterator(const deque_iterator& cpy);
	deque_iterator& operator=(const deque_iterator& cpy);
	template < class U >
	explicit deque_iterator(const deque_iterator< U >& cpy);
	template < class U >
	deque_iterator& operator=(const deque_iterator< U >& cpy);
	~deque_iterator();

	template < class U > operator deque_iterator< U >(); // NOLINT

	explicit deque_iterator(data_t _data, size_t _current = 0);

	bool operator!=(const deque_iterator& rhs);
	bool operator<(const deque_iterator& rhs);
	bool operator<=(const deque_iterator& rhs);
	bool operator==(const deque_iterator& rhs);
	bool operator>(const deque_iterator& rhs);
	bool operator>=(const deque_iterator& rhs);
	const pointer operator->() const;
	const reference operator[](int post) const;
	const reference operator*() const;
	pointer base() const;
	pointer operator->();
	reference operator[](int pos);
	reference operator*();
	template < class U >
	difference_type operator-(const deque_iterator< U >& rhs);
	deque_iterator operator--(int); // NOLINT
	deque_iterator operator-(const difference_type n);
	deque_iterator operator+(const difference_type n);
	deque_iterator operator++(int); // NOLINT
	deque_iterator& operator--();
	deque_iterator& operator-=(const difference_type n);
	deque_iterator& operator++();
	deque_iterator& operator+=(const difference_type n);

	size_t current;
	data_t data;
};

template < class T >
deque_iterator< T >&
operator+(const typename deque_iterator< T >::difference_type lhs,
		  deque_iterator< T >& rhs);

} // namespace ft

#include "deque/__deque__.hpp" // IWYU pragma: export

#ifdef TEST
// template class ft::deque< int >;
#endif

#endif