#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP

#include "BinarySearchTree.hpp"
#include "__types__.hpp"
#include "_phc.hpp"
#include "iterator.hpp"
#include "type_traits.hpp"

namespace ft
{

enum Color
{
  RED,
  BLACK
};

struct RBNode : public TreeNode
{
  RBNode* _parent;
  RBNode* _left;
  RBNode* _right;
  Color   _color;

  RBNode(int* _val, RBNode* _left = NUL, RBNode* _right = NUL, RBNode* _parent = NUL)
      : TreeNode(_val), _parent(_parent), _left(_left), _right(_right),
        _color(RED)
  {
  }

  Color get() const
  {
    return _color;
  }

  void set(Color color)
  {
    _color = color;
  }

  bool is(Color color) const
  {
    return _color == color;
  }

  bool is(const int& val) const
  {
    return getValue() == val;
  }

  RBNode& getParent() const
  {
    return *_parent;
  }

  RBNode& setParent(RBNode* parent)
  {
    _parent = parent;
    return *this;
  }

  bool hasLeft() const
  {
    return _left != NUL;
  }

  bool hasRight() const
  {
    return _right != NUL;
  }

  RBNode& getLeft() const
  {
    return *_left;
  }

  RBNode* getLeftAddr() const
  {
    return _left;
  }

  RBNode& getRight() const
  {
    return *_right;
  }

  RBNode* getRightAddr() const
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

  RBNode& setLeft(RBNode* left)
  {
    _left = left;
    return *this;
  }

  RBNode& setRight(RBNode* right)
  {
    _right = right;
    return *this;
  }
};

class RedBlackTree : public BinarySearchTree<RBNode>
{
  RBNode* _parent_root;
  RBNode* _nil;

public:
  using typename BinarySearchTree<RBNode>::iterator;
  using typename BinarySearchTree<RBNode>::value_type;
  using typename BinarySearchTree<RBNode>::pointer;
  using typename BinarySearchTree<RBNode>::reverse_iterator;
  using typename BinarySearchTree<RBNode>::reference;
  using typename BinarySearchTree<RBNode>::difference_type;
  using typename BinarySearchTree<RBNode>::size_type;
  using typename BinarySearchTree<RBNode>::allocator_type;
  using typename BinarySearchTree<RBNode>::pnode;
  using typename BinarySearchTree<RBNode>::pnode_t;

  RedBlackTree() : _parent_root(NUL), _nil(NUL)
  {
  }

  void insert(const value_type& val)
  {
    // search and insert
    BinarySearchTree::insert(val);
    // rebalance
  }

  void erase(const value_type& val)
  {
    // search and delete
    BinarySearchTree::erase(val);
    // rebalance
  }
};

} // namespace ft

#endif
