#ifndef BALANCEDTREETEST_HPP
#define BALANCEDTREETEST_HPP

#include "BinarySearchTreeTest.hpp"
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
    assert(BinarySearchTreeTest::isBinarySearchTree(*this));
    assert(BinarySearchTreeTest::isInOrderTraversalSorted(*this));
    assert(BinarySearchTreeTest::hasCorrectSize(*this, count ? i : i + 1));
    assert(BinarySearchTreeTest::isBalanced(*this));
  }

  void erase(const value_type& val)
  {
    size_t i = size();
    bool   count = this->count(val) >= 1;
    BinarySearchTree::erase(val);
    assert(BinarySearchTreeTest::isBinarySearchTree(*this));
    assert(BinarySearchTreeTest::isInOrderTraversalSorted(*this));
    assert(BinarySearchTreeTest::hasCorrectSize(*this, count ? i - 1 : i));
    assert(BinarySearchTreeTest::isBalanced(*this));
  }
};

} // namespace ft

#endif
