#ifndef BinarySearchTree_HPP
#define BinarySearchTree_HPP

#include "__except__.hpp"
#include "__macros__.hpp"
#include "_phc.hpp"
#include "iterator.hpp"

namespace ft
{

struct less
{
  bool operator()(const int& a, const int& b) const
  {
    return a < b;
  }
};

struct value_compare
{
  less c;

  value_compare(less c = less()) : c(c)
  {
  }

  bool operator()(const int& a, const int& b) const
  {
    return c(a, b);
  }
};

class TreeNode
{
protected:
  int* _val;

public:
  TreeNode(int* _val) : _val(_val)
  {
  }

  const int& getValue() const
  {
    return *_val;
  }

  bool is(const int& val) const
  {
    return getValue() == val;
  }

  bool isNot(const int& val) const
  {
    return !is(val);
  }

  bool compare(const value_compare& cmp, const int& val) const
  {
    return cmp(getValue(), val);
  }

  bool notCompare(const value_compare& cmp, const int& val) const
  {
    return !compare(cmp, val);
  }
};

template <class Node> class BinarySearchTree;

class BinaryTreeNode : public TreeNode
{
  friend class BinarySearchTree<BinaryTreeNode>;

protected:
  BinaryTreeNode* _left;
  BinaryTreeNode* _right;

public:
  BinaryTreeNode(
          int* _val, BinaryTreeNode* _left = NUL, BinaryTreeNode* _right = NUL)
      : TreeNode(_val), _left(_left), _right(_right)
  {
  }

  bool hasLeft() const
  {
    return _left != NUL;
  }

  bool hasRight() const
  {
    return _right != NUL;
  }

  BinaryTreeNode& getLeft() const
  {
    return *_left;
  }

  BinaryTreeNode* getLeftAddr() const
  {
    return _left;
  }

  BinaryTreeNode& getRight() const
  {
    return *_right;
  }

  BinaryTreeNode* getRightAddr() const
  {
    return _right;
  }

  const int& getValue() const
  {
    return *this->_val;
  }

  int* getValueAddr() const
  {
    return this->_val;
  }

  BinaryTreeNode& setLeft(BinaryTreeNode* left)
  {
    _left = left;
    return *this;
  }

  BinaryTreeNode& setRight(BinaryTreeNode* right)
  {
    _right = right;
    return *this;
  }

  BinaryTreeNode& setParent(BinaryTreeNode* parent)
  {
    (void)parent;
    return *this;
  }

  friend std::ostream& operator<<(std::ostream& os, const BinaryTreeNode& _t)
  {
    os << _t.getValue();
    return os;
  }
};

enum Position
{
  LEFT,
  RIGHT
};

template <class Node> class BinaryTree
{
public:
  typedef std::allocator<int> allocator_type;
  typedef Node                node_t;
  typedef node_t*             pnode_t;
  typedef size_t              size_type;
  typedef const int&          reference;
  typedef ptrdiff_t           difference_type;
  typedef const int           value_type;
  typedef const int*          pointer;

protected:
  pnode_t                _root;
  size_t                 _sz;
  std::allocator<node_t> _a_node_t;
  allocator_type         _a_t;
  value_compare          _c;

public:
  size_t size() const
  {
    return _sz;
  }

  bool empty() const
  {
    return size() == 0;
  }

  void clear()
  {
    std::queue<pnode_t> _q;
    if (hasRoot())
      _q.push(getRootAddr());
    setRoot(NUL);
    while (_q.size() != 0)
    {
      size_t len = _q.size();
      for (size_t i = 0; i != len; i++)
      {
        pnode_t node = _q.front();
        _q.pop();
        if (node->hasLeft())
          _q.push(node->getLeftAddr());
        if (node->hasRight())
          _q.push(node->getRightAddr());
        deleteNode(node);
        setSize(size() - 1);
      }
    }
  }

  BinaryTree() : _root(NUL), _sz(0)
  {
  }

  ~BinaryTree()
  {
    clear();
  }

  bool cmp(const int& a, const int& b) const
  {
    return _c(a, b);
  }

  bool nCmp(const int& a, const int& b) const
  {
    return !cmp(a, b);
  }

  bool cmp(const node_t& a, const int& b) const
  {
    return a.compare(_c, b);
  }

  bool nCmp(const node_t& a, const int& b) const
  {
    return !cmp(a, b);
  }

  bool cmp(const node_t& a, const node_t& b) const
  {
    return a.compare(_c, b.getValue());
  }

  bool nCmp(const node_t& a, const node_t& b) const
  {
    return !cmp(a, b);
  }

  bool cmp(const node_t* a, const int& b) const
  {
    return a->compare(_c, b);
  }

  bool nCmp(const node_t* a, const int& b) const
  {
    return !cmp(a, b);
  }

  bool cmp(const node_t* a, const node_t& b) const
  {
    return a->compare(_c, b.getValue());
  }

  bool notCmp(const node_t* a, const node_t& b) const
  {
    return !cmp(a, b);
  }

  pnode_t getRootAddr() const
  {
    return _root;
  }

  const node_t& getRoot() const
  {
    return *_root;
  }

  node_t& getRoot()
  {
    return *_root;
  }

  bool hasRoot() const
  {
    return _root != NUL;
  }

  BinaryTree& setRoot(pnode_t _root)
  {
    this->_root = _root;
    return *this;
  }

  pnode_t newNode(const int& _val)
  {
    int* ptr = _a_t.allocate(1);
    _a_t.construct(ptr, _val);
    pnode_t nptr = _a_node_t.allocate(1);
    _a_node_t.construct(nptr, node_t(ptr));
    return nptr;
  }

  void deleteNode(pnode_t _node)
  {
    _a_t.destroy(_node->getValueAddr());
    _a_t.deallocate(_node->getValueAddr(), 1);
    _a_node_t.destroy(_node);
    _a_node_t.deallocate(_node, 1);
  }

  size_t getHeight() const
  {
    if (!hasRoot())
      return 0;
    return _getHeightRecursive(getRoot());
  }

  BinaryTree& setSize(size_t size)
  {
    _sz = size;
    return *this;
  }

  size_t _getHeightRecursive(const node_t& node) const
  {
    size_t leftHeight = 0;
    size_t rightHeight = 0;

    if (node.hasLeft())
      leftHeight = _getHeightRecursive(node.getLeft());
    if (node.hasRight())
      rightHeight = _getHeightRecursive(node.getRight());

    return 1 + std::max(leftHeight, rightHeight);
  }

  static void _print_binary_tree(const node_t&    _t,
          std::vector<std::vector<std::string> >& _d,
          size_t                                  h,
          size_t                                  c,
          size_t                                  depth = 0)
  {
    std::ostringstream oss;
    oss << _t;
    _d[depth][c] = oss.str();
    if (_t.hasLeft())
      _print_binary_tree(
              _t.getLeft(), _d, h, c - pow(2, h - depth - 1), depth + 1);
    if (_t.hasRight())
      _print_binary_tree(
              _t.getRight(), _d, h, c + pow(2, h - depth - 1), depth + 1);
  }

  friend std::ostream& operator<<(std::ostream& os, const BinaryTree& tree)
  {
    const size_t height = tree.getHeight();

    std::vector<std::vector<std::string> > out(
            height + 1, std::vector<std::string>(pow(2, height + 1) - 1, " "));

    size_t n = pow(2, height + 1) - 1;

    if (tree.size() != 0)
      BinaryTree::_print_binary_tree(tree.getRoot(), out, height, (n - 1) / 2);

    for (size_t i = 0; i != out.size(); i++)
    {
      for (size_t j = 0; j != out[i].size(); j++)
      {
        os << out[i][j];
      }
      os << endl;
    }
    return os;
  }
};

template <class Node> class BinarySearchTreeIterator
{
  typedef Node* node_t;

private:
  std::vector<int>   _prev;
  std::stack<node_t> _st;
  size_t             _cur;
  bool               _is_rev;
  size_t             _sz;

public:
  typedef std::bidirectional_iterator_tag iterator_category;
  typedef const int                       value_type;
  typedef ptrdiff_t                       difference_type;
  typedef const int*                      pointer;
  typedef const int&                      reference;

  BinarySearchTreeIterator(size_t _sz, bool _is_reversed = false)
      : _prev(std::vector<int>(1)), _cur(1), _is_rev(_is_reversed), _sz(_sz)
  {
  }

  BinarySearchTreeIterator(node_t root, size_t _sz, bool _is_reversed = false)
      : _prev(std::vector<int>(1)), _cur(1), _is_rev(_is_reversed), _sz(_sz)
  {
    if (root == NUL)
      return;
    _st.push(root);
    while (_is_reversed ? _st.top()->hasRight() : _st.top()->hasLeft())
      _st.push(_is_reversed ? _st.top()->getRightAddr()
                            : _st.top()->getLeftAddr());
  }

  reference operator*() const
  {
    if (_cur < _prev.size())
      return _prev[_cur];
    return _st.top()->getValue();
  }

  BinarySearchTreeIterator& operator--()
  {
    return isRev() ? increment() : decrement();
  }

  BinarySearchTreeIterator& operator++()
  {
    return isRev() ? decrement() : increment();
  }

  bool operator==(const BinarySearchTreeIterator& other) const
  {
    if (isRev())
      return _sz - _cur == other._cur;
    return _cur - 1 == _sz - other._cur;
  }

  bool operator!=(const BinarySearchTreeIterator& other) const
  {
    return !operator==(other);
  }

private:
  BinarySearchTreeIterator& increment()
  {
    if (_st.size() == 0)
      return *this;

    node_t top = _st.top();
    _st.pop();
    _prev.push_back(top->getValue());
    if (isRev() ? top->hasLeft() : top->hasRight())
    {
      _st.push(isRev() ? top->getLeftAddr() : top->getRightAddr());
      while (isRev() ? _st.top()->hasRight() : _st.top()->hasLeft())
        _st.push(isRev() ? _st.top()->getRightAddr() : _st.top()->getLeftAddr());
    }
    _cur++;
    return *this;
  }

  bool isRev() const
  {
    return _is_rev;
  }

  BinarySearchTreeIterator& decrement()
  {
    if (_cur > 0)
      _cur--;
    return *this;
  }
};

template <class Node = BinaryTreeNode>
class BinarySearchTree : public BinaryTree<Node>
{
protected:
  using typename BinaryTree<Node>::pnode_t;

public:
  using typename BinaryTree<Node>::value_type;
  using typename BinaryTree<Node>::size_type;

  typedef BinarySearchTreeIterator<Node> iterator;
  typedef ft::reverse_iterator<BinarySearchTreeIterator<Node> > reverse_iterator;

  BinarySearchTree()
  {
  }

  iterator begin() const
  {
    return iterator(this->getRootAddr(), this->size());
  }

  iterator end() const
  {
    return ++iterator(this->getRootAddr(), this->size(), true);
  }

  reverse_iterator rbegin() const
  {
    if (this->size() == 0)
      return reverse_iterator(this->end());
    return reverse_iterator(--this->end());
  }

  reverse_iterator rend() const
  {
    if (this->size() == 0)
      return reverse_iterator(this->end());
    return reverse_iterator(--this->begin());
  }

  pnode_t insert(const value_type& val)
  {
    return _insert(val);
  }

  pnode_t _insert(const value_type& val)
  {
    pnode_t node = NUL;

    if (!this->hasRoot())
    {
      node = this->newNode(val);
      this->setRoot(node);
      this->setSize(this->size() + 1);
      return node;
    }
    pnode_t head = this->getRootAddr();
    for (; head != NUL && !head->is(val);)
    {
      if (this->nCmp(*head, val))
      {
        if (!head->hasLeft())
        {
          node = this->newNode(val);
          node->setParent(head);
          head->setLeft(node);
          this->setSize(this->size() + 1);
          return node;
        }
        head = head->getLeftAddr();
        continue;
      }
      if (!head->hasRight())
      {
        node = this->newNode(val);
        node->setParent(head);
        head->setRight(node);
        this->setSize(this->size() + 1);
        return node;
      }
      head = head->getRightAddr();
    }
    if (head != NUL)
      ASSERT(head->is(val));
    else
      ABORT("insertion should return early");
    return node;
  }

  void erase(const value_type& val)
  {
    pnode_t* head = &this->_root;
    pnode_t* cur = head;
    pnode_t  right = NUL;
    pnode_t  parent = NUL;

    while (*cur != NUL)
    {
      pnode_t node = *cur;
      if (node->is(val))
      {
        if (node->hasLeft() && node->hasRight())
          right = node->getRightAddr();

        *cur = node->hasLeft() ? node->getLeftAddr() : node->getRightAddr();
        if (*cur)
          (*cur)->setParent(parent);

        this->deleteNode(node);
        this->setSize(this->size() - 1);
        break;
      }
      parent = *cur;
      cur = this->nCmp(*cur, val) && (*cur)->hasLeft() ? &(*cur)->_left
                                                       : &(*cur)->_right;
    }
    if (right != NUL)
    {
      while ((*cur)->hasRight())
        cur = this->nCmp(*cur, val) ? &(*cur)->_left : &(*cur)->_right;
      (*cur)->setRight(right);
    }
    this->setRoot(*head);
  }

  pnode_t find(const value_type& val) const
  {
    pnode_t head = this->getRootAddr();
    for (; head != NUL && head->isNot(val); head = this->nCmp(*head, val)
                    ? head->getLeftAddr()
                    : head->getRightAddr())
      ;
    return head;
  }

  size_type count(const value_type& val) const
  {
    if (find(val) != NUL)
      return 1;
    return 0;
  }
};

} // namespace ft

#endif
