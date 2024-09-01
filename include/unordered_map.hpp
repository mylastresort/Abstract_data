#ifndef UNORDERED_MAP_HPP
#define UNORDERED_MAP_HPP

#include "iterator.hpp"
#include "utility.hpp"
#include <functional>

namespace ft
{

template < class Key,
		   class T,
		   class Hash = hash< Key >,
		   class Pred = std::equal_to< Key >,
		   class Allocator = std::allocator< std::pair< const Key, T > > >
class unordered_map
{
  public:
	typedef Allocator allocator_type;
	typedef Hash hasher;
	typedef Key key_type;
	typedef Pred key_equal;
	typedef ptrdiff_t difference_type;
	typedef size_t size_type;
	typedef std::pair< const Key, T > value_type;
	typedef T mapped_type;

	typedef const iterator< value_type, Key > const_iterator;
	typedef const Key* const_pointer;
	typedef const Key& const_reference;
	typedef iterator< value_type, Key > iterator;
	typedef Key* pointer;
	typedef Key& reference;

	// construct/destroy/copy
	explicit unordered_map(size_type n,
						   const hasher& hf = hasher(),
						   const key_equal& eql = key_equal(),
						   const allocator_type& a = allocator_type());
	template < class InputIterator >
	unordered_map(InputIterator f,
				  InputIterator l,
				  size_type n,
				  const hasher& hf = hasher(),
				  const key_equal& eql = key_equal(),
				  const allocator_type& a = allocator_type());
	unordered_map(const unordered_map&);
	// unordered_map(unordered_map &&);
	explicit unordered_map(const Allocator&);
	unordered_map(const unordered_map&, const Allocator&);
	// unordered_map(unordered_map &&, const Allocator &);
	// unordered_map(initializer_list< value_type >,
	// 			  size_type = see below,
	// 			  const hasher &hf = hasher(),
	// 			  const key_equal &eql = key_equal(),
	// 			  const allocator_type &a = allocator_type());
	~unordered_map();
	unordered_map& operator=(const unordered_map&);
	// unordered_map &operator=(unordered_map &&);
	// unordered_map &operator=(initializer_list< value_type >);
	allocator_type get_allocator() const; // noexcept;
	// size and capacity
	bool empty() const;         // noexcept;
	size_type size() const;     // noexcept;
	size_type max_size() const; // noexcept;
	// iterators
	iterator begin();              // noexcept;
	const_iterator begin() const;  // noexcept;
	iterator end();                // noexcept;
	const_iterator end() const;    // noexcept;
	const_iterator cbegin() const; // noexcept;
	const_iterator cend() const;   // noexcept;
	// modifiers
	// template < class... Args > std::pair< iterator, bool > emplace(Args &&...args);
	// template < class... Args >
	// iterator emplace_hint(const_iterator position, Args &&...args);
	std::pair< iterator, bool > insert(const value_type& obj);
	// template < class P > std::pair< iterator, bool > insert(P &&obj);
	iterator insert(const_iterator hint, const value_type& obj);
	// template < class P > iterator insert(const_iterator hint, P &&obj);
	template < class InputIterator >
	void insert(InputIterator first, InputIterator last);
	// void insert(initializer_list< value_type >);
	iterator erase(const_iterator position);
	size_type erase(const key_type& k);
	iterator erase(const_iterator first, const_iterator last);
	void clear(); // noexcept;
	void swap(unordered_map&);
	// observers
	hasher hash_function() const;
	key_equal key_eq() const;
	// lookup
	iterator find(const key_type& k);
	const_iterator find(const key_type& k) const;
	size_type count(const key_type& k) const;
	std::pair< iterator, iterator > equal_range(const key_type& k);
	std::pair< const_iterator, const_iterator > equal_range(const key_type& k) const;
	mapped_type& operator[](const key_type& k);
	// mapped_type &operator[](key_type &&k);
	mapped_type& at(const key_type& k);
	const mapped_type& at(const key_type& k) const;
	// bucket interface
	size_type bucket_count() const;     // noexcept;
	size_type max_bucket_count() const; // noexcept;
	size_type bucket_size(size_type n) const;
	size_type bucket(const key_type& k) const;
	// local_iterator begin(size_type n);
	// const_local_iterator begin(size_type n) const;
	// local_iterator end(size_type n);
	// const_local_iterator end(size_type n) const;
	// const_local_iterator cbegin(size_type n) const;
	// const_local_iterator cend(size_type n) const;
	// hash policy
	float load_factor() const;     // noexcept;
	float max_load_factor() const; // noexcept;
	void max_load_factor(float z);
	void rehash(size_type n);
	void reserve(size_type n);
};
template < class Key, class T, class Hash, class Pred, class Alloc >
bool operator!=(const unordered_map< Key, T, Hash, Pred, Alloc >& a,
				const unordered_map< Key, T, Hash, Pred, Alloc >& b);

template < class Key, class T, class Hash, class Pred, class Alloc >
bool operator==(const unordered_map< Key, T, Hash, Pred, Alloc >& a,
				const unordered_map< Key, T, Hash, Pred, Alloc >& b);

template < class Key, class T, class Hash, class Pred, class Alloc >
void swap(unordered_map< Key, T, Hash, Pred, Alloc >& x,
		  unordered_map< Key, T, Hash, Pred, Alloc >& y);

template < class Key,
		   class T,
		   class Hash = hash< Key >,
		   class Pred = std::equal_to< Key >,
		   class Allocator = std::allocator< std::pair< const Key, T > > >
class unordered_multimap
{
  public:
	typedef Allocator allocator_type;
	typedef Hash hasher;
	typedef Key key_type;
	typedef Pred key_equal;
	typedef ptrdiff_t difference_type;
	typedef size_t size_type;
	typedef std::pair< const Key, T > value_type;
	typedef T mapped_type;

	typedef const iterator< value_type, Key > const_iterator;
	typedef const Key* const_pointer;
	typedef const Key& const_reference;
	typedef iterator< value_type, Key > iterator;
	typedef Key* pointer;
	typedef Key& reference;

	// construct/destroy/copy
	explicit unordered_multimap(size_type n,
								const hasher& hf = hasher(),
								const key_equal& eql = key_equal(),
								const allocator_type& a = allocator_type());
	template < class InputIterator >
	unordered_multimap(InputIterator f,
					   InputIterator l,
					   size_type n,
					   const hasher& hf = hasher(),
					   const key_equal& eql = key_equal(),
					   const allocator_type& a = allocator_type());
	unordered_multimap(const unordered_multimap&);
	// unordered_multimap(unordered_multimap &&);
	explicit unordered_multimap(const Allocator&);
	unordered_multimap(const unordered_multimap&, const Allocator&);
	// unordered_multimap(unordered_multimap &&, const Allocator &);
	// unordered_multimap(initializer_list< value_type >,
	// 				   size_type = see below,
	// 				   const hasher &hf = hasher(),
	// 				   const key_equal &eql = key_equal(),
	// 				   const allocator_type &a = allocator_type());
	~unordered_multimap();
	unordered_multimap& operator=(const unordered_multimap&);
	// unordered_multimap &operator=(unordered_multimap &&);
	// unordered_multimap &operator=(initializer_list< value_type >);
	allocator_type get_allocator() const; // noexcept;
	// size and capacity
	bool empty() const;         // noexcept;
	size_type size() const;     // noexcept;
	size_type max_size() const; // noexcept;
	// iterators
	iterator begin();              // noexcept;
	const_iterator begin() const;  // noexcept;
	iterator end();                // noexcept;
	const_iterator end() const;    // noexcept;
	const_iterator cbegin() const; // noexcept;
	const_iterator cend() const;   // noexcept;
	// modifiers
	// template < class... Args > iterator emplace(Args &&...args);
	// template < class... Args >
	// iterator emplace_hint(const_iterator position, Args &&...args);
	iterator insert(const value_type& obj);
	// template < class P > iterator insert(P &&obj);
	iterator insert(const_iterator hint, const value_type& obj);
	// template < class P > iterator insert(const_iterator hint, P &&obj);
	template < class InputIterator >
	void insert(InputIterator first, InputIterator last);
	// void insert(initializer_list< value_type >);
	iterator erase(const_iterator position);
	size_type erase(const key_type& k);
	iterator erase(const_iterator first, const_iterator last);
	void clear(); // noexcept;
	void swap(unordered_multimap&);
	// observers
	hasher hash_function() const;
	key_equal key_eq() const;
	// lookup
	iterator find(const key_type& k);
	const_iterator find(const key_type& k) const;
	size_type count(const key_type& k) const;
	std::pair< iterator, iterator > equal_range(const key_type& k);
	std::pair< const_iterator, const_iterator > equal_range(const key_type& k) const;
	// bucket interface
	size_type bucket_count() const;     // noexcept;
	size_type max_bucket_count() const; // noexcept;
	size_type bucket_size(size_type n) const;
	size_type bucket(const key_type& k) const;
	// local_iterator begin(size_type n);
	// const_local_iterator begin(size_type n) const;
	// local_iterator end(size_type n);
	// const_local_iterator end(size_type n) const;
	// const_local_iterator cbegin(size_type n) const;
	// const_local_iterator cend(size_type n) const;
	// hash policy
	float load_factor() const;     // noexcept;
	float max_load_factor() const; // noexcept;
	void max_load_factor(float z);
	void rehash(size_type n);
	void reserve(size_type n);
};

template < class Key, class T, class Hash, class Pred, class Alloc >
bool operator==(const unordered_multimap< Key, T, Hash, Pred, Alloc >& a,
				const unordered_multimap< Key, T, Hash, Pred, Alloc >& b);

template < class Key, class T, class Hash, class Pred, class Alloc >
bool operator!=(const unordered_multimap< Key, T, Hash, Pred, Alloc >& a,
				const unordered_multimap< Key, T, Hash, Pred, Alloc >& b);

}; // namespace ft

#endif