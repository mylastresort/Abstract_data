#ifndef BinarySearchTree_HPP
#define BinarySearchTree_HPP

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

struct BinaryTreeNode : public TreeNode
{
  BinaryTreeNode* _left;
  BinaryTreeNode* _right;

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
};

template <class Node> struct BinaryTree
{
  typedef Node         node_t;
  typedef node_t*      pnode_t;
  pnode_t              _root;
  size_t               _sz;
  std::allocator<Node> _a_node_t;
  std::allocator<int>  _a_t;
  value_compare        _c;

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

  bool hasRoot() const
  {
    return _root != NUL;
  }

  BinaryTree& setRoot(pnode_t _root)
  {
    this->_root = _root;
    return *this;
  }

  pnode_t newNode(const int& _val = int())
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

  static void _print_binary_tree(const node_t& _t,
          std::vector<std::vector<std::string> >& _d,
          size_t                                  h,
          size_t                                  c,
          size_t                                  depth = 0)
  {
    std::ostringstream oss;
    oss << _t.getValue();
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
public:
  typedef BinarySearchTreeIterator<Node> iterator;
  typedef const int                      value_type;
  typedef const int*                     pointer;
  typedef ft::reverse_iterator<BinarySearchTreeIterator<Node> > reverse_iterator;
  typedef const int&          reference;
  typedef ptrdiff_t           difference_type;
  typedef size_t              size_type;
  typedef std::allocator<int> allocator_type;
  typedef Node*               pnode;

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

  void insert(const value_type& val)
  {
    if (!this->hasRoot())
    {
      this->setRoot(this->newNode(val));
      this->setSize(this->size() + 1);
      return;
    }
    for (pnode head = this->getRootAddr(); head != NUL && !head->is(val);)
    {
      if (this->nCmp(*head, val))
      {
        if (!head->hasLeft())
        {
          head->setLeft(this->newNode(val));
          this->setSize(this->size() + 1);
          return;
        }
        head = head->getLeftAddr();
        continue;
      }
      if (!head->hasRight())
      {
        head->setRight(this->newNode(val));
        this->setSize(this->size() + 1);
        return;
      }
      head = head->getRightAddr();
    }
  }

  void erase(const value_type& val)
  {
    pnode* head = &this->_root;
    pnode* cur = head;
    pnode  right = NUL;
    while (*cur != NUL)
    {
      if ((*cur)->is(val))
      {
        pnode _r = (*cur)->getRightAddr(), _l = (*cur)->getLeftAddr();
        if (!(*cur)->hasLeft())
          *cur = (this->deleteNode(*cur), _r);
        else if (!(*cur)->hasRight())
          *cur = (this->deleteNode(*cur), _l);
        else
        {
          right = _r;
          *cur = (this->deleteNode(*cur), _l);
        }
        break;
      }
      if (this->nCmp(*cur, val))
        cur = (*cur)->hasLeft() ? &(*cur)->_left : &(*cur)->_right;
      else if (this->cmp(*cur, val))
        cur = (*cur)->hasRight() ? &(*cur)->_right : &(*cur)->_left;
    }
    if (right != NUL)
    {
      while ((*cur)->hasRight())
        cur = this->nCmp(*cur, val) ? &(*cur)->_left : &(*cur)->_right;
      (*cur)->setRight(right);
    }
    this->setSize(this->size() - 1);
    this->setRoot(*head);
  }

  pnode find(const value_type& val) const
  {
    pnode head = this->getRootAddr();
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
