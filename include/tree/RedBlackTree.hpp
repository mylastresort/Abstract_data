#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP

#include "__except__.hpp"
#include "__macros__.hpp"
#include "tree/BinarySearchTree.hpp"

namespace ft
{

enum Color
{
  RED,
  BLACK
};

template <class T, class Comp = less<T> >
struct RBNode : public TreeNode<T, Comp>
{
  typedef Comp value_compare;
  typedef Comp comp;
  typedef T    value_type;
  typedef T*   pointer;
  typedef T&   reference;

  RBNode* _parent;
  RBNode* _left;
  RBNode* _right;
  Color   _color;

  RBNode(T* _val, RBNode* _left = NUL, RBNode* _right = NUL, RBNode* _parent = NUL)
      : TreeNode<T, Comp>(_val), _parent(_parent), _left(_left), _right(_right),
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

  bool is(const T& val) const
  {
    return getValue() == val;
  }

  bool isNot(const T& val) const
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

  const T& getValue() const
  {
    return *getValueAddr();
  }

  T& getValue()
  {
    return *getValueAddr();
  }

  T* getValueAddr() const
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

  bool hasNilBlackLeft() const
  {
    return !hasLeft() || getLeft().is(BLACK);
  }

  bool hasNilBlackRight() const
  {
    return !hasRight() || getRight().is(BLACK);
  }
};

template <class T, class Comp = less<T>, class Alloc = std::allocator<T> >
class RedBlackTree : public BinarySearchTree<T, Comp, Alloc, RBNode<T, Comp> >
{
protected:
  typedef typename BinarySearchTree<T, Comp, Alloc, RBNode<T, Comp> >::pnode_t pnode_t;
  typedef typename BinarySearchTree<T, Comp, Alloc, RBNode<T, Comp> >::node_t node_t;

public:
  using typename BinarySearchTree<T, Comp, Alloc, RBNode<T, Comp> >::value_type;
  using typename BinarySearchTree<T, Comp, Alloc, RBNode<T, Comp> >::size_type;
  using typename BinarySearchTree<T, Comp, Alloc, RBNode<T, Comp> >::value_compare;
  using typename BinarySearchTree<T, Comp, Alloc, RBNode<T, Comp> >::iterator;

public:
  explicit RedBlackTree(const Comp& comp = Comp(), const Alloc& alloc = Alloc())
      : BinarySearchTree<T, Comp, Alloc, RBNode<T, Comp> >(comp, alloc)
  {
  }

  void insert(const value_type& val)
  {
    pnode_t node =
            BinarySearchTree<T, Comp, Alloc, RBNode<T, Comp> >::insert(val);
    if (node != NUL)
      rebalanceInsertion(node);
    if (this->hasRoot())
      ASSERT(this->getRoot().is(BLACK));
  }

  void rebalanceInsertion(pnode_t node)
  {
    ASSERT_NOT_NUL(node);
    while (node->hasGrandParent() && node->getParent().is(RED))
    {
      Position pos = node->getParent().getPosition();
      if (node->hasSibling() && node->getSibling().is(RED))
      {
        node->getSibling().set(BLACK);
        node->getParent().set(BLACK);
        node->getGrandParent().set(RED);
        node = node->getGrandParentAddr();
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
        handleCaseTwoInsertion(pos, y, q);
        ASSERT(verifyRule1Compliance(*y));
        break;
      }
    }
    this->getRoot().set(BLACK);
    ASSERT(this->getRoot().is(BLACK));
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

  void handleCaseTwoInsertion(Position pos, pnode_t y, pnode_t q)
  {
    pnode_t x = q->getGrandParentAddr();
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
      this->setRoot(y);
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

  void erase(const iterator& pos)
  {
    pnode_t node = pos.base();
    erase(node);
  }

  void erase(const value_type& val)
  {
    pnode_t p = this->lookup(val);
    erase(p);
  }

  void erase(const pnode_t p)
  {
    pnode_t  x = NUL;
    pnode_t  pa = NUL;
    Position pos;

    if (p == NUL)
      return;

    if (!p->hasRight())
      handleCaseOneDeletion(p, pa, x, pos);
    else if (!p->getRight().hasLeft())
      handleCaseTwoDeletion(p, pa, x, pos);
    else
      handleCaseThreeDeletion(p, pa, x, pos);

    this->setSize(this->size() - 1);
    rebalanceDeletion(p->getColor(), pa, x, pos);
    this->deleteNode(p);
  }

  void rebalanceDeletion(Color clr, pnode_t pa, pnode_t x, Position pos)
  {
    if (clr == RED)
      return;
    for (;;)
    {
      if (x != NUL && x->is(RED))
      {
        x->set(BLACK);
        break;
      }
      if (pa == NUL)
        break;
      {
        pnode_t w = pos == LEFT ? pa->getRightAddr() : pa->getLeftAddr();
        if (w->is(RED))
          handleCaseDeletionSiblingisNotBlack(w, pa, pos);
        if (w->hasNilBlackLeft() && w->hasNilBlackRight())
          handleCaseOneDeletionRebalance(w);
        else
        {
          handleCaseTwoDeletionRebalance(w, pos);
          handleCaseThreeDeletionRebalance(w, pa, pos);
          break;
        }
      }
      x = pa;
      if (pa->hasParent())
        pos = pa->getPosition();
      pa = pa->getParentAddr();
    }
  }

  // handleCaseDeletionSiblingChildInSameSideIsRed
  void handleCaseTwoDeletionRebalance(pnode_t& w, Position pos)
  {
    if (pos == LEFT && w->hasNilBlackRight())
    {
      pnode_t y = w->getLeftAddr();
      w->set(RED);
      y->set(BLACK);
      rightRotate(w, y);
      w = y;
    }
    else if (pos == RIGHT && w->hasNilBlackLeft())
    {
      pnode_t y = w->getRightAddr();
      w->set(RED);
      y->set(BLACK);
      leftRotate(w, y);
      w = y;
    }
  }

  // handleCaseDeletionSiblingChildInOppositeSideIsRed
  void handleCaseThreeDeletionRebalance(pnode_t w, pnode_t pa, Position pos)
  {
    w->set(pa->getColor());
    pa->set(BLACK);
    if (pos == LEFT)
    {
      w->getRight().set(BLACK);
      leftRotate(pa, w);
    }
    else
    {
      w->getLeft().set(BLACK);
      rightRotate(pa, w);
    }
  }

  // handleCaseDeletionSiblingHasNoRedChildren
  void handleCaseOneDeletionRebalance(pnode_t w)
  {
    w->set(RED);
  }

  void handleCaseDeletionSiblingisNotBlack(pnode_t& w, pnode_t pa, Position pos)
  {
    w->set(BLACK);
    pa->set(RED);
    if (pos == LEFT)
    {
      leftRotate(pa, w);
      w = pa->getRightAddr();
    }
    else
    {
      rightRotate(pa, w);
      w = pa->getLeftAddr();
    }
  }

  void handleCaseThreeDeletion(
          pnode_t node, pnode_t& pa, pnode_t& x, Position& pos)
  {
    ASSERT_NOT_NUL(node);
    ASSERT(node->hasRight());
    ASSERT(node->getRight().hasLeft());
    pnode_t succ = this->upper_bound(node);
    ASSERT(node != succ);

    pnode_t parent = node->getParentAddr();
    pnode_t right = succ->getParentAddr();

    ASSERT(succ != right);

    if (parent == NUL)
      this->setRoot(succ);
    else if (node->getPosition() == LEFT)
      parent->setLeft(succ);
    else
      parent->setRight(succ);
    succ->setParent(parent);

    pnode_t left = node->getLeftAddr();
    succ->setLeft(left);
    if (left != NUL)
      left->setParent(succ);

    pnode_t succRight = succ->getRightAddr();
    right->setLeft(succRight);
    if (succRight != NUL)
      succRight->setParent(right);

    succ->setRight(node->getRightAddr());
    ASSERT(node->hasRight());
    node->getRight().setParent(succ);

    Color clr = succ->getColor();
    succ->set(node->getColor());
    node->set(clr);

    pa = right;
    x = right->getLeftAddr();
    pos = LEFT;
  }

  void handleCaseTwoDeletion(pnode_t node, pnode_t& pa, pnode_t& x, Position& pos)
  {
    ASSERT_NOT_NUL(node);
    pnode_t parent = node->getParentAddr();
    pnode_t right = node->getRightAddr();
    ASSERT_NOT_NUL(right);

    if (parent == NUL)
      this->setRoot(right);
    else if (node->getPosition() == LEFT)
      parent->setLeft(right);
    else
      parent->setRight(right);
    right->setParent(parent);

    pnode_t left = node->getLeftAddr();
    right->setLeft(left);
    if (left != NUL)
      left->setParent(right);

    Color clr = right->getColor();
    right->set(node->getColor());
    node->set(clr);
    pa = right;
    x = right->getRightAddr();
    pos = RIGHT;
  }

  void handleCaseOneDeletion(pnode_t node, pnode_t& pa, pnode_t& x, Position& pos)
  {
    ASSERT_NOT_NUL(node);
    pnode_t parent = node->getParentAddr();
    pnode_t left = node->getLeftAddr();

    pos = LEFT;
    if (parent == NUL)
      this->setRoot(left);
    else if (node->getPosition() == LEFT)
    {
      parent->setLeft(left);
      pos = LEFT;
    }
    else
    {
      parent->setRight(left);
      pos = RIGHT;
    }
    if (node->hasLeft())
      left->setParent(parent);
    pa = parent;
    x = left;
  }
};

} // namespace ft

#endif
