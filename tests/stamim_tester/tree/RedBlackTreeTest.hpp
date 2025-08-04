#ifndef BALANCEDTREETEST_HPP
#define BALANCEDTREETEST_HPP

#include "BinarySearchTreeTest.hpp"
#include "__types__.hpp"
#include "tree/BinarySearchTree.hpp"
#include "tree/RedBlackTree.hpp"
#include "utility.hpp"

namespace ft
{

class RedBlackTreeTest : public RedBlackTree
{
public:
  void insert(const value_type& val)
  {
    size_t i = size();
    bool   count = this->count(val) >= 1;
    RedBlackTree::insert(val);
    assertValidRedBlackTree(count ? i : i + 1);
  }

  void erase(const value_type& val)
  {
    // size_t i = size();
    // bool   count = this->count(val) >= 1;
    BinarySearchTree::erase(val);
    // assertValidRedBlackTree(count ? i - 1 : i);
  }

  void assertValidRedBlackTree(size_t size) const
  {
    if (!hasRoot())
      return;
    assertRootIsBlack();
    assertRBTreeStructure(getRoot(), INT_MIN, INT_MAX);
    assert(BinarySearchTreeTest::hasCorrectSize(*this, size));
    assert(BinarySearchTreeTest::isInOrderTraversalSorted(*this));
    assert(BinarySearchTreeTest::isReverseInOrderTraversalSorted(*this));
  }

  void assertRootIsBlack() const
  {
    assert(!hasRoot() || getRoot().is(BLACK));
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

  rbt_vars assertRBTreeStructure(const node_t& _rt, int _min, int _max) const
  {
    assert(nCmp(_rt, _min) && cmp(_rt, _max));
    assert(!_rt.hasLeft() || nCmp(_rt, _rt.getLeft()));
    assert(!_rt.hasRight() || cmp(_rt, _rt.getRight()));

    assertRBNodeColor(_rt);
    assert(verifyRule1Compliance(_rt));

    rbt_vars _vars[2];

    if (_rt.hasLeft())
      _vars[0] = assertRBTreeStructure(_rt.getLeft(), _min, _rt.getValue());

    if (_rt.hasRight())
      _vars[1] = assertRBTreeStructure(_rt.getRight(), _rt.getValue(), _max);

    // the count of black nodes from node to all paths to leaves must be equal
    // this assertion (bottom-up) aborts when it finds a difference
    assert(verifyRule2Compliance(_vars[0]._black_nodes, _vars[1]._black_nodes));

    return rbt_vars(1 + _vars[0]._count + _vars[1]._count,
            static_cast<size_t>(_rt.is(BLACK)) + _vars[0]._black_nodes);
  }

  static void assertRBNodeColor(const node_t& node)
  {
    assert(node.is(RED) || node.is(BLACK));
  }
};

} // namespace ft

#endif
