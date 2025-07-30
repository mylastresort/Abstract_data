#ifndef LIST_HPP
#define LIST_HPP

#include "_phc.hpp"
#include "iterator.hpp"
#include "type_traits.hpp"

namespace ft
{
template <class T> struct Node
{
  Node<T>* prev;
  Node<T>* next;
  T        val;

  Node(T val = T()) : prev(0), next(0), val(val)
  {
  }

  Node(void* prev, void* next, T val = T())
      : prev((Node*)prev), next((Node*)next), val(val)
  {
  }
};

template <class T> class list_iterator;

template <class T, class Alloc = std::allocator<T> > class list
{
private:
  typename Alloc::template rebind<Node<T> >::other _a_node_t;
  Alloc                                            _a;
  Node<T>*                                         _past_end_head;
  Node<T>*                                         _past_end_tail;
  size_t                                           _len;

  friend class list_iterator<T>;
  friend class list_iterator<const T>;
  friend class list_iterator<volatile T>;
  friend class list_iterator<const volatile T>;

public:
  typedef Alloc                                    allocator_type;
  typedef ptrdiff_t                                difference_type;
  typedef size_t                                   size_type;
  typedef T                                        value_type;
  typedef typename allocator_type::const_pointer   const_pointer;
  typedef typename allocator_type::const_reference const_reference;
  typedef typename allocator_type::pointer         pointer;
  typedef typename allocator_type::reference       reference;
  typedef list_iterator<const value_type>          const_iterator;
  typedef list_iterator<value_type>                iterator;
  typedef ft::reverse_iterator<const_iterator>     const_reverse_iterator;
  typedef ft::reverse_iterator<iterator>           reverse_iterator;

private:
  iterator _insert(iterator position, size_type count, const value_type& val);

public:
  explicit list(const allocator_type& alloc = allocator_type());
  list(const list& cpy);
  explicit list(size_type       size,
          const value_type&     value = value_type(),
          const allocator_type& alloc = allocator_type());
  template <class InputIterator>
  list(InputIterator            first,
          InputIterator         last,
          const allocator_type& alloc = allocator_type(),
          typename enable_if<!numeric_limits<InputIterator>::is_integer>::type* = 0);
  list& operator=(const list& cpy);
  ~list();
  allocator_type         get_allocator() const;
  const_iterator         begin() const;
  const_iterator         end() const;
  const_reverse_iterator rbegin() const;
  const_reverse_iterator rend() const;
  iterator               begin();
  iterator               end();
  reverse_iterator       rbegin();
  reverse_iterator       rend();
  bool                   empty() const;
  size_type              max_size() const;
  size_type              size() const;
  void                   resize(size_type size, value_type val = value_type());
  const_reference        back() const;
  const_reference        front() const;
  reference              back();
  reference              front();
  iterator               erase(iterator position, iterator last);
  iterator               erase(iterator position);
  template <class Predicate> void remove_if(Predicate pred);
  void                            clear();
  void                            pop_back();
  void                            pop_front();
  void                            remove(const value_type& value);
  iterator insert(iterator position, const value_type& val);
  template <class InputIterator>
  void assign(InputIterator first,
          InputIterator     last,
          typename enable_if<!numeric_limits<InputIterator>::is_integer>::type* = 0);
  template <class InputIterator>
  void insert(iterator  position,
          InputIterator first,
          InputIterator last,
          typename enable_if<!numeric_limits<InputIterator>::is_integer>::type* = 0);
  void assign(size_type count, const value_type& val);
  void insert(iterator position, size_type count, const value_type& val);
  void push_back(const value_type& val);
  void push_front(const value_type& val);
  template <class BinaryPredicate> void unique(BinaryPredicate binary_pred);
  template <class Compare> void         merge(list& lst, Compare comp);
  template <class Compare> void         sort(Compare comp);
  void                                  merge(list& lst);
  void                                  reverse();
  void                                  sort();
  void splice(iterator position, list& lst, iterator first, iterator last);
  void splice(iterator position, list& lst, iterator itr);
  void splice(iterator position, list& lst);
  void swap(list& lst);
  void unique();
};

/**
 * forbidden class specialization - begin
 * missing definition prevents the user from instantiation
 */
template <class T> class list<const T>;
template <class T> class list<volatile T>;
template <class T> class list<const volatile T>;
/** forbidden class specialization - end */

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

template <class T>
class list_iterator : public ft::iterator<bidirectional_iterator_tag, T>
{
public:
  typedef typename conditional<is_const<T>::value,
          const Node<typename remove_cv<T>::type>*,
          Node<typename remove_cv<T>::type>*>::type list_type;

  list_type _cur;

  explicit list_iterator(list_type _lst);
  template <class U> friend class list_iterator;

public:
  template <class U> friend class list_iterator;
  friend class list<typename remove_cv<T>::type>;

  typedef ft::iterator<bidirectional_iterator_tag, T> _iterator;
  using typename _iterator::difference_type;
  using typename _iterator::iterator_category;
  using typename _iterator::pointer;
  using typename _iterator::reference;
  using typename _iterator::value_type;

  list_iterator();
  list_iterator(const list_iterator& cpy);
  list_iterator& operator=(const list_iterator& cpy);
  template <class U> explicit list_iterator(const list_iterator<U>& cpy);
  template <class U> list_iterator& operator=(const list_iterator<U>& cpy);
  ~list_iterator();
  template <class U> operator list_iterator<U>() const;
  bool            operator==(const list_iterator& rhs) const;
  bool            operator!=(const list_iterator& rhs) const;
  const pointer   operator->() const;
  const reference operator*() const;
  pointer         operator->();
  reference       operator[](int pos);
  reference       operator*();
  list_iterator   operator--(int);
  list_iterator   operator++(int);
  list_iterator&  operator--();
  list_iterator&  operator++();
};

} // namespace ft

#include "list/__list__.hpp"

#endif
