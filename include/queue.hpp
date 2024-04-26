#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "deque.hpp"
#include "vector.hpp"

namespace ft
{

template < class T, class Container = deque< T > > class queue
{
  public:
	typedef Container container_type;
	typedef typename Container::value_type value_type;
	typedef typename Container::size_type size_type;

  protected:
	container_type c;

  public:
	bool empty() const;
	const value_type& back() const;
	const value_type& front() const;
	explicit queue(const container_type& = container_type());
	size_type size() const;
	value_type& back();
	value_type& front();
	void pop();
	void push(const value_type& val);
};

template < class T, class Container >
bool operator==(const queue< T, Container >& lhs,
				const queue< T, Container >& rhs);

template < class T, class Container >
bool operator<(const queue< T, Container >& lhs,
			   const queue< T, Container >& rhs);

template < class T, class Container >
bool operator!=(const queue< T, Container >& lhs,
				const queue< T, Container >& rhs);

template < class T, class Container >
bool operator>(const queue< T, Container >& lhs,
			   const queue< T, Container >& rhs);

template < class T, class Container >
bool operator>=(const queue< T, Container >& lhs,
				const queue< T, Container >& rhs);

template < class T, class Container >
bool operator<=(const queue< T, Container >& lhs,
				const queue< T, Container >& rhs);

template < class T,
		   class Container = vector< T >,
		   class Compare = std::less< typename Container::value_type > >
class priority_queue
{
  public:
	typedef Container container_type;
	typedef typename Container::size_type size_type;
	typedef typename Container::value_type value_type;

  protected:
	Compare comp;
	container_type c;

  public:
	bool empty() const;
	const value_type& top() const;
	explicit priority_queue(const Compare& comp = Compare(),
							const container_type& ctnr = container_type());
	size_type size() const;
	template < class InputIterator >
	priority_queue(InputIterator first,
				   InputIterator last,
				   const Compare& comp = Compare(),
				   const container_type& ctnr = Container());
	void pop();
	void push(const value_type& val);
};

} // namespace ft

#endif