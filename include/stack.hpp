#ifndef STACK_HPP
#define STACK_HPP

#include "deque.hpp"

namespace ft
{

template <class T, class Container = deque<T> > class stack
{
  public:
	typedef typename Container::value_type value_type;
	typedef typename Container::size_type size_type;
	typedef Container container_type;

  protected:
	container_type c;

  public:
	bool empty() const;
	const value_type& top() const;
	explicit stack(const container_type& = container_type());
	size_type size() const;
	value_type& top();
	void pop();
	void push(const value_type& val);
};

template <class T, class Container>
bool operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs);

template <class T, class Container>
bool operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs);

template <class T, class Container>
bool operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs);

template <class T, class Container>
bool operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs);

template <class T, class Container>
bool operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs);

template <class T, class Container>
bool operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs);

} // namespace ft

#endif