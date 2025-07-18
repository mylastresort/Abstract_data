#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "__types__.hpp"
#include "_phc.hpp"

namespace ft
{

typedef std::bidirectional_iterator_tag bidirectional_iterator_tag;
typedef std::forward_iterator_tag       forward_iterator_tag;
typedef std::input_iterator_tag         input_iterator_tag;
typedef std::output_iterator_tag        output_iterator_tag;
typedef std::random_access_iterator_tag random_access_iterator_tag;

template <class Category,
        class T,
        class Distance = ptrdiff_t,
        class Pointer = T*,
        class Reference = T&>
struct iterator
{
  typedef T         value_type;
  typedef Distance  difference_type;
  typedef Pointer   pointer;
  typedef Reference reference;
  typedef Category  iterator_category;
};

template <class Iterator> struct iterator_traits
{
  typedef typename Iterator::difference_type   difference_type;
  typedef typename Iterator::iterator_category iterator_category;
  typedef typename Iterator::pointer           pointer;
  typedef typename Iterator::reference         reference;
  typedef typename Iterator::value_type        value_type;
};

template <class T> struct iterator_traits<T*>
{
  typedef ptrdiff_t                  difference_type;
  typedef random_access_iterator_tag iterator_category;
  typedef T                          value_type;
  typedef T*                         pointer;
  typedef T&                         reference;
};

template <class T> struct iterator_traits<const T*>
{
  typedef const T*                   pointer;
  typedef const T&                   reference;
  typedef ptrdiff_t                  difference_type;
  typedef random_access_iterator_tag iterator_category;
  typedef T                          value_type;
};

template <class Iterator>
class reverse_iterator : public iterator_traits<Iterator>
{
protected:
  Iterator current; // NOLINT

public:
  typedef Iterator iterator_type;
  using typename iterator_traits<Iterator>::difference_type;
  using typename iterator_traits<Iterator>::reference;
  using typename iterator_traits<Iterator>::pointer;

  reverse_iterator();
  explicit reverse_iterator(iterator_type itr);
  template <class Iter>
  reverse_iterator(const reverse_iterator<Iter>& rev_it); // NOLINT

  iterator_type base() const;

  reference         operator*() const;
  pointer           operator->() const;
  reverse_iterator& operator++();
  reverse_iterator  operator++(int); // NOLINT
  reverse_iterator& operator--();
  reverse_iterator  operator--(int); // NOLINT
  reverse_iterator  operator+(difference_type n) const;
  reverse_iterator& operator+=(difference_type n);
  reverse_iterator  operator-(difference_type n) const;
  reverse_iterator& operator-=(difference_type n);
  reference         operator[](difference_type n) const;
};

template <class Iterator>
bool operator==(const reverse_iterator<Iterator>& lhs,
        const reverse_iterator<Iterator>&         rhs);
template <class Iterator>
bool operator<(const reverse_iterator<Iterator>& lhs,
        const reverse_iterator<Iterator>&        rhs);
template <class Iterator>
bool operator!=(const reverse_iterator<Iterator>& lhs,
        const reverse_iterator<Iterator>&         rhs);
template <class Iterator>
bool operator>(const reverse_iterator<Iterator>& lhs,
        const reverse_iterator<Iterator>&        rhs);

template <class Iterator>
bool operator>=(const reverse_iterator<Iterator>& lhs,
        const reverse_iterator<Iterator>&         rhs);
template <class Iterator>
bool operator<=(const reverse_iterator<Iterator>& lhs,
        const reverse_iterator<Iterator>&         rhs);
template <class Iterator>
typename reverse_iterator<Iterator>::difference_type operator-(
        const reverse_iterator<Iterator>& lhs,
        const reverse_iterator<Iterator>& rhs);
template <class Iterator>
reverse_iterator<Iterator> operator+(
        typename reverse_iterator<Iterator>::difference_type n,
        const reverse_iterator<Iterator>&                    rev_it);

} // namespace ft

namespace ft
{
template <class Iterator>
reverse_iterator<Iterator>::reverse_iterator() : current()
{
}

template <class Iterator>
reverse_iterator<Iterator>::reverse_iterator(iterator_type itr) : current(itr)
{
}

template <class Iterator>
template <class Iter>
reverse_iterator<Iterator>::reverse_iterator(const reverse_iterator<Iter>& rev_it)
    : current(rev_it.base())
{
}

template <class Iterator>
typename reverse_iterator<Iterator>::iterator_type
reverse_iterator<Iterator>::base() const
{
  return current;
}

template <class Iterator>
typename reverse_iterator<Iterator>::reference
reverse_iterator<Iterator>::operator*() const
{
  return *current;
}

template <class Iterator>
typename reverse_iterator<Iterator>::pointer
reverse_iterator<Iterator>::operator->() const
{
  return &*current;
}

template <class Iterator>
reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator++()
{
  --current;
  return *this;
}

template <class Iterator>
reverse_iterator<Iterator> reverse_iterator<Iterator>::operator++(int) // NOLINT
{
  return reverse_iterator(current--);
}

template <class Iterator>
reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator--()
{
  ++current;
  return *this;
}

template <class Iterator>
reverse_iterator<Iterator> reverse_iterator<Iterator>::operator--(int) // NOLINT
{
  return reverse_iterator(current++);
}

template <class Iterator>
reverse_iterator<Iterator> reverse_iterator<Iterator>::operator+(
        difference_type n) const
{
  return reverse_iterator(current - n);
}

template <class Iterator>
reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator+=(
        difference_type n)
{
  current -= n;
  return *this;
}

template <class Iterator>
reverse_iterator<Iterator> reverse_iterator<Iterator>::operator-(
        difference_type n) const
{
  return reverse_iterator(current + n);
}

template <class Iterator>
reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator-=(
        difference_type n)
{
  current += n;
  return *this;
}

template <class Iterator>
typename reverse_iterator<Iterator>::reference
reverse_iterator<Iterator>::operator[](difference_type n) const
{
  return current[-n];
}

template <class Iterator>
bool operator==(const reverse_iterator<Iterator>& lhs,
        const reverse_iterator<Iterator>&         rhs)
{
  return lhs.base() == rhs.base();
}

template <class Iterator>
bool operator!=(const reverse_iterator<Iterator>& lhs,
        const reverse_iterator<Iterator>&         rhs)
{
  return !operator==(lhs, rhs);
}

template <class Iterator>
bool operator>(const reverse_iterator<Iterator>& lhs,
        const reverse_iterator<Iterator>&        rhs)
{
  return lhs.base() > rhs.base();
}

template <class Iterator>
bool operator<=(const reverse_iterator<Iterator>& lhs,
        const reverse_iterator<Iterator>&         rhs)
{
  return !operator>(lhs, rhs);
}

template <class Iterator>
bool operator<(const reverse_iterator<Iterator>& lhs,
        const reverse_iterator<Iterator>&        rhs)
{
  return lhs.base() < rhs.base();
}

template <class Iterator>
bool operator>=(const reverse_iterator<Iterator>& lhs,
        const reverse_iterator<Iterator>&         rhs)
{
  return !operator<(lhs, rhs);
}

template <class Iterator>
typename reverse_iterator<Iterator>::difference_type operator-(
        const reverse_iterator<Iterator>& lhs,
        const reverse_iterator<Iterator>& rhs)
{
  return lhs.base() - rhs.base();
}

template <class Iterator>
reverse_iterator<Iterator> operator+(
        typename reverse_iterator<Iterator>::difference_type n,
        const reverse_iterator<Iterator>&                    rev_it)
{
  return rev_it + n;
}

} // namespace ft

#endif
