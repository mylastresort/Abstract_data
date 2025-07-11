#ifndef SET_HPP
#define SET_HPP

#include "_phc.hpp"
#include "iterator.hpp"

namespace ft
{
template < class Key,
		   class Compare = std::less< Key >,
		   class Allocator = std::allocator< Key > >
class set
{
  public:
	typedef Allocator allocator_type;
	typedef Compare key_compare;
	typedef Compare value_compare;
	typedef const iterator< bidirectional_iterator_tag, Key > const_iterator;
	typedef const Key* const_pointer;
	typedef const Key& const_reference;
	typedef iterator< bidirectional_iterator_tag, Key > iterator;
	typedef Key key_type;
	typedef Key value_type;
	typedef Key* pointer;
	typedef Key& reference;
	typedef ptrdiff_t difference_type;
	typedef reverse_iterator< const_iterator > const_reverse_iterator;
	typedef reverse_iterator< iterator > reverse_iterator;
	typedef size_t size_type;

	// construct
	explicit set(const key_compare& comp = key_compare(),
				 const allocator_type& alloc = allocator_type());
	template < class InputIterator >
	set(InputIterator first,
		InputIterator last,
		const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type());

	// copy constructor
	set(const set& cpy);

	// assignement constructor
	set& operator=(const set& cpy);

	allocator_type get_allocator() const;

	// destructor
	~set();

	// iterators
	const_iterator begin() const;
	const_iterator end() const;
	const_reverse_iterator rbegin() const;
	const_reverse_iterator rend() const;
	iterator begin();
	iterator end();
	iterator lower_bound(const key_type& key) const;
	iterator upper_bound(const key_type& key) const;
	reverse_iterator rbegin();
	reverse_iterator rend();

	// capacity
	bool empty() const;
	size_type max_size() const;
	size_type size() const;

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

	// observers
	key_compare key_comp() const;
	value_compare value_comp() const;

	// search
	iterator find(const key_type& key) const;
	size_type count(const key_type& key) const;
	std::pair< iterator, iterator > equal_range(const key_type& key) const;

	// modifiers
	void swap(set& other);
};

template < class Key, class Compare, class Allocator >
bool operator!=(const set< Key, Compare, Allocator >& lhs,
				const set< Key, Compare, Allocator >& rhs);

template < class Key, class Compare, class Allocator >
bool operator<(const set< Key, Compare, Allocator >& lhs,
			   const set< Key, Compare, Allocator >& rhs);

template < class Key, class Compare, class Allocator >
bool operator<=(const set< Key, Compare, Allocator >& lhs,
				const set< Key, Compare, Allocator >& rhs);

template < class Key, class Compare, class Allocator >
bool operator==(const set< Key, Compare, Allocator >& lhs,
				const set< Key, Compare, Allocator >& rhs);

template < class Key, class Compare, class Allocator >
bool operator>(const set< Key, Compare, Allocator >& lhs,
			   const set< Key, Compare, Allocator >& rhs);

template < class Key, class Compare, class Allocator >
bool operator>=(const set< Key, Compare, Allocator >& lhs,
				const set< Key, Compare, Allocator >& rhs);

template < class Key, class Compare, class Allocator >
void swap(set< Key, Compare, Allocator >& first,
		  set< Key, Compare, Allocator >& second);

template < class Key,
		   class Compare = std::less< Key >,
		   class Allocator = std::allocator< Key > >
class multiset
{
  public:
	typedef Allocator allocator_type;
	typedef Compare key_compare;
	typedef Compare value_compare;
	typedef Key key_type;
	typedef Key value_type;
	typedef typename Allocator::const_pointer const_pointer;
	typedef typename Allocator::const_reference const_reference;
	typedef typename Allocator::difference_type difference_type;
	typedef typename Allocator::pointer pointer;
	typedef typename Allocator::reference reference;
	typedef typename Allocator::size_type size_type;

	typedef const iterator< bidirectional_iterator_tag, value_type > const_iterator;
	typedef iterator< bidirectional_iterator_tag, value_type > iterator;
	typedef std::reverse_iterator< const_iterator > const_reverse_iterator;
	typedef std::reverse_iterator< iterator > reverse_iterator;

	// constructors
	explicit multiset(const key_compare& comp = key_compare(),
					  const allocator_type& alloc = allocator_type());
	template < class InputIterator >
	multiset(InputIterator first,
			 InputIterator last,
			 const key_compare& comp = key_compare(),
			 const allocator_type& alloc = allocator_type());

	// copy constructor
	multiset(const multiset& cpy);

	// assignement constructor
	multiset& operator=(const multiset& cpy);

	allocator_type get_allocator() const;

	// destructor
	~multiset();

	// iterators
	const_iterator begin() const;
	const_iterator end() const;
	const_reverse_iterator rbegin() const;
	const_reverse_iterator rend() const;
	iterator begin();
	iterator end();
	iterator lower_bound(const key_type& key) const;
	iterator upper_bound(const key_type& key) const;
	reverse_iterator rbegin();
	reverse_iterator rend();

	// capacity
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

	// observers:
	key_compare key_comp() const;
	value_compare value_comp() const;

	// search
	iterator find(const key_type& key) const;
	size_type count(const key_type& key) const;
	std::pair< iterator, iterator > equal_range(const key_type& key) const;

	// modifiers
	void swap(multiset& other);
};

template < class Key, class Compare, class Allocator >
bool operator!=(const multiset< Key, Compare, Allocator >& lhs,
				const multiset< Key, Compare, Allocator >& rhs);
template < class Key, class Compare, class Allocator >
bool operator<(const multiset< Key, Compare, Allocator >& lhs,
			   const multiset< Key, Compare, Allocator >& rhs);
template < class Key, class Compare, class Allocator >
bool operator<=(const multiset< Key, Compare, Allocator >& lhs,
				const multiset< Key, Compare, Allocator >& rhs);
template < class Key, class Compare, class Allocator >
bool operator==(const multiset< Key, Compare, Allocator >& lhs,
				const multiset< Key, Compare, Allocator >& rhs);
template < class Key, class Compare, class Allocator >
bool operator>(const multiset< Key, Compare, Allocator >& lhs,
			   const multiset< Key, Compare, Allocator >& rhs);
template < class Key, class Compare, class Allocator >
bool operator>=(const multiset< Key, Compare, Allocator >& lhs,
				const multiset< Key, Compare, Allocator >& rhs);

template < class Key, class Compare, class Allocator >
void swap(multiset< Key, Compare, Allocator >& first,
		  multiset< Key, Compare, Allocator >& second);

} // namespace ft
#endif
