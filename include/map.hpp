#ifndef MAP_HPP
#define MAP_HPP

#include "__types__.hpp"
#include "_phc.hpp"
#include "iterator.hpp"

namespace ft
{

template < class Key,
		   class T,
		   class Compare = std::less< Key >,
		   class Allocator = std::allocator< std::pair< const Key, T > > >
class map
{
  public:
	typedef Allocator allocator_type;
	typedef Compare key_compare;
	typedef const iterator< bidirectional_iterator_tag, T > const_iterator;
	typedef const T* const_pointer;
	typedef const T& const_reference;
	typedef iterator< bidirectional_iterator_tag, T > iterator;
	typedef Key key_type;
	typedef ptrdiff_t difference_type;
	typedef reverse_iterator< const_iterator > const_reverse_iterator;
	typedef reverse_iterator< iterator > reverse_iterator;
	typedef size_t size_type;
	typedef std::pair< const Key, T > value_type;
	typedef T mapped_type;
	typedef T* pointer;
	typedef T& reference;

	typedef std::binary_function< value_type, value_type, bool > value_compare;

	// constructors
	explicit map(const key_compare& comp = key_compare(),
				 const allocator_type& alloc = allocator_type());
	template < class InputIterator >
	map(InputIterator first,
		InputIterator last,
		const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type());

	// copy constructor
	map(const map& cpy);

	// assignement constructor
	map& operator=(const map& cpy);

	// destructor
	~map();

	// iterators:
	const_iterator begin() const;
	const_iterator end() const;
	const_iterator lower_bound(const key_type& key) const;
	const_iterator upper_bound(const key_type& key) const;
	const_reverse_iterator rbegin() const;
	const_reverse_iterator rend() const;
	iterator begin();
	iterator end();
	iterator lower_bound(const key_type& key);
	iterator upper_bound(const key_type& key);
	reverse_iterator rbegin();
	reverse_iterator rend();

	// capacity:
	bool empty() const;
	size_type max_size() const;
	size_type size() const;

	// element access:
	mapped_type& operator[](const key_type& key);

	// insertion
	iterator insert(iterator position, const value_type& val);
	std::pair< iterator, bool > insert(const value_type& val);
	template < class InputIterator >
	void insert(InputIterator first, InputIterator last);

	// deletion
	size_type erase(const key_type& key);
	void clear();
	void erase(iterator first, iterator last);
	void erase(iterator position);

	// modifiers:
	void swap(map& other);

	// observers:
	key_compare key_comp() const;
	value_compare value_comp() const;

	// search
	const_iterator find(const key_type& key) const;
	iterator find(const key_type& key);
	std::pair< const_iterator, const_iterator > equal_range(const key_type& key) const;
	std::pair< iterator, iterator > equal_range(const key_type& key);

	// modifiers
	size_type count(const key_type& key) const;
};

template < class Key, class T, class Compare, class Allocator >
bool operator!=(const map< Key, T, Compare, Allocator >& lhs,
				const map< Key, T, Compare, Allocator >& rhs);

template < class Key, class T, class Compare, class Allocator >
bool operator<(const map< Key, T, Compare, Allocator >& lhs,
			   const map< Key, T, Compare, Allocator >& rhs);

template < class Key, class T, class Compare, class Allocator >
bool operator<=(const map< Key, T, Compare, Allocator >& lhs,
				const map< Key, T, Compare, Allocator >& rhs);
template < class Key, class T, class Compare, class Allocator >
bool operator>=(const map< Key, T, Compare, Allocator >& lhs,
				const map< Key, T, Compare, Allocator >& rhs);
template < class Key, class T, class Compare, class Allocator >
bool operator>(const map< Key, T, Compare, Allocator >& lhs,
			   const map< Key, T, Compare, Allocator >& rhs);
template < class Key, class T, class Compare, class Allocator >
bool operator==(const map< Key, T, Compare, Allocator >& lhs,
				const map< Key, T, Compare, Allocator >& rhs);

template < class Key, class T, class Compare, class Allocator >
void swap(map< Key, T, Compare, Allocator >& first,
		  map< Key, T, Compare, Allocator >& second);

template < class Key,
		   class T,
		   class Compare = std::less< Key >,
		   class Allocator = std::allocator< std::pair< const Key, T > > >
class multimap
{
  public:
	typedef Allocator allocator_type;
	typedef Compare key_compare;
	typedef const iterator< std::bidirectional_iterator_tag, T > const_iterator;
	typedef const T* const_pointer;
	typedef const T& const_reference;
	typedef iterator< std::bidirectional_iterator_tag, T > iterator;
	typedef Key key_type;
	typedef ptrdiff_t difference_type;
	typedef reverse_iterator< const_iterator > const_reverse_iterator;
	typedef reverse_iterator< iterator > reverse_iterator;
	typedef size_t size_type;
	typedef std::pair< const Key, T > value_type;
	typedef T mapped_type;
	typedef T* pointer;
	typedef T& reference;

	typedef std::binary_function< value_type, value_type, bool > value_compare;

	// constructor
	explicit multimap(const key_compare& comp = key_compare(),
					  const allocator_type& alloc = allocator_type());
	template < class InputIterator >
	multimap(InputIterator first,
			 InputIterator last,
			 const key_compare& comp = key_compare(),
			 const allocator_type& alloc = allocator_type());

	// copy constructor
	multimap(const multimap& cpy);

	// assignement constructor
	multimap& operator=(const multimap& cpy);

	// destructor
	~multimap();

	allocator_type get_allocator() const;

	// iterators:
	const_iterator begin() const;
	const_iterator end() const;
	const_iterator lower_bound(const key_type& key) const;
	const_iterator upper_bound(const key_type& key) const;
	const_reverse_iterator rbegin() const;
	const_reverse_iterator rend() const;
	iterator begin();
	iterator end();
	iterator lower_bound(const key_type& key);
	iterator upper_bound(const key_type& key);
	reverse_iterator rbegin();
	reverse_iterator rend();

	// capacity:
	bool empty() const;
	size_type max_size() const;
	size_type size() const;

	// insertion
	iterator insert(const value_type& val);
	iterator insert(iterator position, const value_type& val);
	template < class InputIterator >
	void insert(InputIterator first, InputIterator last);

	// deletion
	size_type erase(const key_type& key);
	void clear();
	void erase(iterator first, iterator last);
	void erase(iterator position);

	// modifiers
	void swap(multimap& other);

	// observers
	key_compare key_comp() const;
	value_compare value_comp() const;

	// search
	const_iterator find(const key_type& key) const;
	iterator find(const key_type& key);
	size_type count(const key_type& key) const;
	std::pair< const_iterator, const_iterator > equal_range(const key_type& key) const;
	std::pair< iterator, iterator > equal_range(const key_type& key);
};

template < class Key, class T, class Compare, class Allocator >
bool operator<=(const multimap< Key, T, Compare, Allocator >& lhs,
				const multimap< Key, T, Compare, Allocator >& rhs);

template < class Key, class T, class Compare, class Allocator >
bool operator==(const multimap< Key, T, Compare, Allocator >& lhs,
				const multimap< Key, T, Compare, Allocator >& rhs);

template < class Key, class T, class Compare, class Allocator >
bool operator>(const multimap< Key, T, Compare, Allocator >& lhs,
			   const multimap< Key, T, Compare, Allocator >& rhs);

template < class Key, class T, class Compare, class Allocator >
bool operator>=(const multimap< Key, T, Compare, Allocator >& lhs,
				const multimap< Key, T, Compare, Allocator >& rhs);

template < class Key, class T, class Compare, class Allocator >
bool operator<(const multimap< Key, T, Compare, Allocator >& lhs,
			   const multimap< Key, T, Compare, Allocator >& rhs);

template < class Key, class T, class Compare, class Allocator >
bool operator!=(const multimap< Key, T, Compare, Allocator >& lhs,
				const multimap< Key, T, Compare, Allocator >& rhs);

template < class Key, class T, class Compare, class Allocator >
void swap(multimap< Key, T, Compare, Allocator >& first,
		  multimap< Key, T, Compare, Allocator >& second);

} // namespace ft
#endif
