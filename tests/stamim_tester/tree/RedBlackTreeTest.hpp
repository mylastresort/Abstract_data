#ifndef BALANCEDTREETEST_HPP
#define BALANCEDTREETEST_HPP

#include "BinarySearchTreeTest.hpp"
#include "__types__.hpp"
#include "tree/BinarySearchTree.hpp"
#include "tree/RedBlackTree.hpp"
#include "utility.hpp"

namespace ft
{

template <class Comp = less<int> >
class RedBlackTreeTest : public RedBlackTree<Comp>
{
  using RedBlackTree<Comp>::value_type;

public:
  void insert(const typename RedBlackTree<Comp>::value_type& val)
  {
    size_t i = this->size();
    bool   count = this->count(val) >= 1;
    RedBlackTree<Comp>::insert(val);
    assertValidRedBlackTree(count ? i : i + 1);
  }

  void erase(const typename RedBlackTree<Comp>::value_type& val)
  {
    size_t i = this->size();
    bool   count = this->count(val) >= 1;
    RedBlackTree<Comp>::erase(val);
    assertValidRedBlackTree(count ? i - 1 : i);
  }

  void assertValidRedBlackTree(size_t size) const
  {
    if (!this->hasRoot())
      return;
    assertRootIsBlack();
    assertRBTreeStructure(
            this->getRoot(), this->_c.c.TEST_MIN, this->_c.c.TEST_MAX);
    assert(BinarySearchTreeTest<Comp>::hasCorrectSize(*this, size));
    assert(BinarySearchTreeTest<Comp>::isInOrderTraversalSorted(*this));
    assert(BinarySearchTreeTest<Comp>::isReverseInOrderTraversalSorted(*this));
  }

  void assertRootIsBlack() const
  {
    assert(!this->hasRoot() || this->getRoot().is(BLACK));
  }

  struct rbt_vars
  {
    size_t _black_nodes;
    size_t _count;

    rbt_vars(size_t _count = 0, size_t _black_nodes = 0)
        : _black_nodes(_black_nodes), _count(_count)
    {
    }
  };

  rbt_vars assertRBTreeStructure(
          const typename RedBlackTree<Comp>::node_t& _rt, int _min, int _max) const
  {
    assert(this->nCmp(_rt, _min) && this->cmp(_rt, _max));
    assert(!_rt.hasLeft() || this->nCmp(_rt, _rt.getLeft()));
    assert(!_rt.hasRight() || this->cmp(_rt, _rt.getRight()));

    assertRBNodeColor(_rt);
    assert(this->verifyRule1Compliance(_rt));

    rbt_vars _vars[2];

    if (_rt.hasLeft())
      _vars[0] = assertRBTreeStructure(_rt.getLeft(), _min, _rt.getValue());

    if (_rt.hasRight())
      _vars[1] = assertRBTreeStructure(_rt.getRight(), _rt.getValue(), _max);

    // the count of black nodes from node to all paths to leaves must be equal
    // this assertion (bottom-up) aborts when it finds a difference
    assert(this->verifyRule2Compliance(
            _vars[0]._black_nodes, _vars[1]._black_nodes));

    return rbt_vars(1 + _vars[0]._count + _vars[1]._count,
            static_cast<size_t>(_rt.is(BLACK)) + _vars[0]._black_nodes);
  }

  static void assertRBNodeColor(const typename RedBlackTree<Comp>::node_t& node)
  {
    assert(node.is(RED) || node.is(BLACK));
  }
};

} // namespace ft

#endif
