#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP

#include "tree/BinarySearchTree.hpp"

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

  Color getColor() const
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

  bool isNot(Color color) const
  {
    return !is(color);
  }

  bool is(const int& val) const
  {
    return getValue() == val;
  }

  bool isNot(const int& val) const
  {
    return !is(val);
  }

  bool hasSibling() const
  {
    return getSiblingAddr() != NUL;
  }

  RBNode* getSiblingAddr() const
  {
    if (!hasGrandParent())
      return NUL;
    return getParent().getPosition() == LEFT ? getGrandParent().getRightAddr()
                                             : getGrandParent().getLeftAddr();
  }

  RBNode& getSibling() const
  {
    ASSERT(hasSibling());
    return *getSiblingAddr();
  }

  Position getPosition() const
  {
    ASSERT(hasParent());
    ASSERT(getParent().getLeftAddr() == this
            || getParent().getRightAddr() == this);
    return getParent().getLeftAddr() == this ? LEFT : RIGHT;
  }

  RBNode& getParent() const
  {
    ASSERT(hasParent());
    return *getParentAddr();
  }

  RBNode* getParentAddr() const
  {
    return _parent;
  }

  RBNode& setParent(RBNode* parent)
  {
    _parent = parent;
    return *this;
  }

  bool hasParent() const
  {
    return _parent != NUL;
  }

  bool hasGrandParent() const
  {
    return hasParent() && getParent().getParentAddr() != NUL;
  }

  RBNode* getGrandParentAddr() const
  {
    ASSERT(hasGrandParent());

    RBNode* parent = getParentAddr();
    ASSERT(parent->getLeftAddr() == this || parent->getRightAddr() == this);

    RBNode* grandparent = parent->getParentAddr();
    ASSERT(grandparent->getLeftAddr() == parent
            || grandparent->getRightAddr() == parent);
    return grandparent;
  }

  RBNode& getGrandParent() const
  {
    ASSERT(hasGrandParent());
    return *getGrandParentAddr();
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
    ASSERT(hasLeft());
    return *getLeftAddr();
  }

  RBNode* getLeftAddr() const
  {
    return _left;
  }

  RBNode& getRight() const
  {
    ASSERT(hasRight());
    return *getRightAddr();
  }

  RBNode* getRightAddr() const
  {
    return _right;
  }

  const int& getValue() const
  {
    return *getValueAddr();
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

  friend std::ostream& operator<<(std::ostream& os, const RBNode& node)
  {
    return os << (node.is(RED) ? RED_COLOR : WHITE_COLOR) << node.getValue()

              << RESET_COLOR;
  }
};

class RedBlackTree : public BinarySearchTree<RBNode>
{
public:
  RedBlackTree()
  {
  }

  void insert(const value_type& val)
  {
    pnode_t node = BinarySearchTree::_insert(val);
    if (node != NUL)
      rebalanceInsertion(node);
    if (hasRoot())
      ASSERT(getRoot().is(BLACK));
  }

  void rebalanceInsertion(pnode_t node)
  {
    ASSERT_NOT_NUL(node);
    while (node->hasGrandParent() && node->getParent().is(RED))
    {
      Position pos = node->getParent().getPosition();
      if (node->hasSibling() && node->getSibling().is(RED))
      {
        recolorSibling(node);
        ASSERT(verifyRule1Compliance(*node));
      }
      else
      {
        pnode_t x = NUL;
        pnode_t y = NUL;
        pnode_t q = node;
        if (node->getPosition() == pos)
          y = node->getParentAddr();
        else
          handleCaseThreeInsertion(pos, node, x, y, q);
        handleCaseTwoInsertion(pos, x, y, q);
        ASSERT(verifyRule1Compliance(*y));
        break;
      }
    }
    getRoot().set(BLACK);
    ASSERT(getRoot().is(BLACK));
  }

  void recolorSibling(pnode_t& node) const
  {
    node->getSibling().set(BLACK);
    node->getParent().set(BLACK);
    node->getGrandParent().set(RED);
    node = node->getGrandParentAddr();
  }

  void handleCaseThreeInsertion(
          Position pos, pnode_t node, pnode_t& x, pnode_t& y, pnode_t& q)
  {
    x = node->getParentAddr();
    if (pos == LEFT)
    {
      y = x->getRightAddr();
      leftRotate(x, y);
    }
    else
    {
      y = x->getLeftAddr();
      rightRotate(x, y);
    }
    q = x;
  }

  void handleCaseTwoInsertion(Position pos, pnode_t x, pnode_t y, pnode_t q)
  {
    x = q->getGrandParentAddr();
    x->set(RED);
    y->set(BLACK);
    if (pos == LEFT)
      rightRotate(x, y);
    else
      leftRotate(x, y);
  }

  bool verifyRule1Compliance(const node_t& node) const
  {
    return node.isNot(RED)
            || ((!node.hasLeft() || node.getLeft().isNot(RED))
                    && (!node.hasRight() || node.getRight().isNot(RED)));
  }

  bool verifyRule2Compliance(
          const size_t& leftBlackNodes, const size_t& rightBlackNodes) const
  {
    return leftBlackNodes == rightBlackNodes;
  }

  void rotate(Position pos, pnode_t x, pnode_t y)
  {
    // LEFT: set X Right to Y Left
    // RIGHT: set X Left to Y Right
    pnode_t C = pos == LEFT ? y->getLeftAddr() : y->getRightAddr();
    if (pos == LEFT)
      x->setRight(C);
    else
      x->setLeft(C);
    if (C != NUL)
      C->setParent(x);

    // switch Y parent and X Parent
    pnode_t xParent = x->getParentAddr();
    if (xParent == NUL)
      setRoot(y);
    else if (x->getPosition() == LEFT)
      xParent->setLeft(y);
    else
      xParent->setRight(y);
    // xParent->setLeft(y);
    y->setParent(xParent);

    // LEFT: set Y Left to X
    // RIGHT: set Y Right to X
    if (pos == LEFT)
      y->setLeft(x);
    else
      y->setRight(x);
    x->setParent(y);
  }

  void leftRotate(pnode_t x, pnode_t y)
  {
    rotate(LEFT, x, y);
  }

  void rightRotate(pnode_t x, pnode_t y)
  {
    rotate(RIGHT, x, y);
  }

  void _erase(const value_type& val)
  {
    BinarySearchTree::erase(val);
  }

  void erase(const value_type& val)
  {
    _erase(val);
    // rebalance
  }
};

} // namespace ft

#endif
