#ifndef LIST_HPP
#define LIST_HPP

#include "_phc.hpp"
#include "iterator.hpp"

namespace ft
{

template <class T, class Allocator = std::allocator<T> > class list
{
  public:
	typedef Allocator allocator_type;
	typedef const iterator<random_access_iterator_tag, T> const_iterator;
	typedef const T* const_pointer;
	typedef const T& const_reference;
	typedef iterator<random_access_iterator_tag, T> iterator;
	typedef ptrdiff_t difference_type;
	typedef reverse_iterator<const_iterator> const_reverse_iterator;
	typedef reverse_iterator<iterator> reverse_iterator;
	typedef size_t size_type;
	typedef T value_type;
	typedef T* pointer;
	typedef T& reference;

	// constructor
	explicit list(const allocator_type& alloc = allocator_type());
	explicit list(size_type size,
				  const value_type& value = value_type(),
				  const allocator_type& alloc = allocator_type());
	template <class InputIterator>
	list(InputIterator first,
		 InputIterator last,
		 const allocator_type& alloc = allocator_type());

	// copy constructor
	list(const list& cpy);

	// assignement constructor
	list& operator=(const list& cpy);

	// destructor
	~list();

	// allocator
	allocator_type get_allocator() const;

	// iterators
	const_iterator begin() const;
	const_iterator end() const;
	const_reverse_iterator rbegin() const;
	const_reverse_iterator rend() const;
	iterator begin();
	iterator end();
	reverse_iterator rbegin();
	reverse_iterator rend();

	// insertion
	iterator insert(iterator position, const value_type& val);
	template <class InputIterator>
	void assign(InputIterator first, InputIterator last);
	template <class InputIterator>
	void insert(iterator position, InputIterator first, InputIterator last);
	void assign(size_type count, const value_type& val);
	void insert(iterator position, size_type count, const value_type& val);
	void push_back(const value_type& val);
	void push_front(const value_type& val);

	// capacity
	bool empty() const;
	size_type max_size() const;
	size_type size() const;
	void resize(size_type size, value_type val = value_type());

	// element access:
	const_reference back() const;
	const_reference front() const;
	reference back();
	reference front();

	// deletion
	iterator erase(iterator position, iterator last);
	iterator erase(iterator position);
	template <class Predicate> void remove_if(Predicate pred);
	void clear();
	void pop_back();
	void pop_front();
	void remove(const value_type& value);

	// modifiers:
	template <class BinaryPredicate> void unique(BinaryPredicate binary_pred);
	template <class Compare> void merge(list& lst, Compare comp);
	template <class Compare> void sort(Compare comp);
	void merge(list& lst);
	void reverse();
	void sort();
	void splice(iterator position, list& lst, iterator first, iterator last);
	void splice(iterator position, list& lst, iterator itr);
	void splice(iterator position, list& lst);
	void swap(list& lst);
	void unique();
};

template <class T, class Allocator>
bool operator==(const list<T, Allocator>& lhs, const list<T, Allocator>& rhs);
template <class T, class Allocator>
bool operator<(const list<T, Allocator>& lhs, const list<T, Allocator>& rhs);
template <class T, class Allocator>
bool operator!=(const list<T, Allocator>& lhs, const list<T, Allocator>& rhs);
template <class T, class Allocator>
bool operator>(const list<T, Allocator>& lhs, const list<T, Allocator>& rhs);
template <class T, class Allocator>
bool operator>=(const list<T, Allocator>& lhs, const list<T, Allocator>& rhs);
template <class T, class Allocator>
bool operator<=(const list<T, Allocator>& lhs, const list<T, Allocator>& rhs);

template <class T, class Allocator>
void swap(list<T, Allocator>& first, list<T, Allocator>& second);

} // namespace ft

#endif
