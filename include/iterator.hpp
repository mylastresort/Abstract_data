#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "types/types.hpp"
#include <iterator>

namespace ft
{

using std::bidirectional_iterator_tag;
using std::forward_iterator_tag;
using std::input_iterator_tag;
using std::output_iterator_tag;
using std::random_access_iterator_tag;

template < class Category,
		   class T,
		   class Distance = ptrdiff_t,
		   class Pointer = T*,
		   class Reference = T& >
struct iterator
{
	typedef T value_type;
	typedef Distance difference_type;
	typedef Pointer pointer;
	typedef Reference reference;
	typedef Category iterator_category;
};

template < class Iterator > struct iterator_traits
{
	using typename Iterator::difference_type;
	using typename Iterator::iterator_category;
	using typename Iterator::pointer;
	using typename Iterator::reference;
	using typename Iterator::value_type;
};

template < class T > struct iterator_traits< T* >
{
	typedef ptrdiff_t difference_type;
	typedef random_access_iterator_tag iterator_category;
	typedef T value_type;
	typedef T* pointer;
	typedef T& reference;
};

template < class Iterator >
class reverse_iterator
	: public iterator< typename iterator_traits< Iterator >::iterator_category,
					   typename iterator_traits< Iterator >::value_type,
					   typename iterator_traits< Iterator >::difference_type,
					   typename iterator_traits< Iterator >::pointer,
					   typename iterator_traits< Iterator >::reference >
{
  protected:
	Iterator current;

  public:
	typedef Iterator iterator_type;
	using typename iterator_traits< Iterator >::difference_type;
	using typename iterator_traits< Iterator >::reference;
	using typename iterator_traits< Iterator >::pointer;

	// constructors
	reverse_iterator();
	explicit reverse_iterator(iterator_type itr);
	template < class Iter >
	reverse_iterator(const reverse_iterator< Iter >& rev_it);

	iterator_type base() const;

	reference operator*() const;
	pointer operator->() const;
	reverse_iterator& operator++();
	reverse_iterator operator++(int);
	reverse_iterator& operator--();
	reverse_iterator operator--(int);
	reverse_iterator operator+(difference_type step) const;
	reverse_iterator& operator+=(difference_type step);
	reverse_iterator operator-(difference_type step) const;
	reverse_iterator& operator-=(difference_type step);
	reference operator[](difference_type step) const;
};
template < class Iterator >
bool operator==(const reverse_iterator< Iterator >& lhs,
				const reverse_iterator< Iterator >& rhs);
template < class Iterator >
bool operator<(const reverse_iterator< Iterator >& lhs,
			   const reverse_iterator< Iterator >& rhs);
template < class Iterator >
bool operator!=(const reverse_iterator< Iterator >& lhs,
				const reverse_iterator< Iterator >& rhs);
template < class Iterator >
bool operator>(const reverse_iterator< Iterator >& lhs,
			   const reverse_iterator< Iterator >& rhs);

template < class Iterator >
bool operator>=(const reverse_iterator< Iterator >& lhs,
				const reverse_iterator< Iterator >& rhs);
template < class Iterator >
bool operator<=(const reverse_iterator< Iterator >& lhs,
				const reverse_iterator< Iterator >& rhs);
template < class Iterator >
typename reverse_iterator< Iterator >::difference_type
operator-(const reverse_iterator< Iterator >& lhs,
		  const reverse_iterator< Iterator >& rhs);
template < class Iterator >
reverse_iterator< Iterator >
operator+(typename reverse_iterator< Iterator >::difference_type step,
		  const reverse_iterator< Iterator >& rev_it);

} // namespace ft

#include "templates/iterator.tpp"

#endif