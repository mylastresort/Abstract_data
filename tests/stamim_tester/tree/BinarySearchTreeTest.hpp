#ifndef BINARYSEARCHTREETEST_HPP
#define BINARYSEARCHTREETEST_HPP

#include "tree/BinarySearchTree.hpp"
#include "utility.hpp"

namespace ft
{

class BinarySearchTreeTest : public BinarySearchTree<>
{
  // TODO: add check: traversal from the null element works
public:
  void insert(const value_type& val)
  {
    size_t i = size();
    bool   count = this->count(val) >= 1;
    BinarySearchTree::insert(val);
    assert(isBinarySearchTree(*this));
    assert(isInOrderTraversalSorted(*this));
    assert(hasCorrectSize(*this, count ? i : i + 1));
  }

  void erase(const value_type& val)
  {
    size_t i = size();
    bool   count = this->count(val) >= 1;
    BinarySearchTree::erase(val);
    assert(isBinarySearchTree(*this));
    assert(isInOrderTraversalSorted(*this));
    assert(hasCorrectSize(*this, count ? i - 1 : i));
  }

  template <class Tree>
  static bool _isBST(
          const Tree& _tr, const typename Tree::node_t& _rt, int _min, int _max)
  {
    bool _cd = _tr.nCmp(_rt, _min) && _tr.cmp(_rt, _max);

    if (_cd && _rt.hasLeft())
      _cd = _tr.nCmp(_rt, _rt.getLeft());
    if (_cd && _rt.hasRight())
      _cd = _tr.cmp(_rt, _rt.getRight());
    if (_cd && _rt.hasLeft())
      _cd = _isBST(_tr, _rt.getLeft(), _min, _rt.getValue());
    if (_cd && _rt.hasRight())
      _cd = _isBST(_tr, _rt.getRight(), _rt.getValue(), _max);
    return _cd;
  }

  template <class Tree> static bool isBinarySearchTree(const Tree& tree)
  {
    if (!tree.hasRoot())
      return true;
    return _isBST(tree, tree.getRoot(), INT_MIN, INT_MAX);
  }

  struct BalancedTreeTest
  {
    struct Sol
    {
      int  _d;
      bool _b;
      Sol(size_t _d, bool _b) : _d(_d), _b(_b) {};
    };

    template <class TreeNode>
    static Sol isBalancedTree(const TreeNode* root, size_t k, size_t depth = 0)
    {
      Sol l = Sol(depth, true);
      if (root == NUL)
        return l;
      if (root->hasLeft())
        l = BalancedTreeTest::isBalancedTree(root->getLeftAddr(), depth + 1);
      if (!l._b)
        return l;
      Sol r = Sol(depth, true);
      if (root->hasRight())
        r = BalancedTreeTest::isBalancedTree(root->getRightAddr(), depth + 1);
      if (!r._b)
        return r;
      if ((size_t)std::abs(l._d - r._d) <= k)
      {
        return Sol(max(l._d, r._d), true);
      }
      return Sol(l._d, false);
    }
  };

  template <class Tree>
  static bool isBalanced(const Tree& _tree, const int k = 1)
  {
    return BalancedTreeTest::isBalancedTree(_tree.getRootAddr(), k)._b;
  }

  template <class Tree> static bool isInOrderTraversalSorted(const Tree& tree)
  {
    if (tree.size() != 0)
    {
      typename Tree::iterator it = tree.begin();
      typename Tree::iterator _it = ++tree.begin();
      typename Tree::iterator _end = tree.end();
      for (; _it != _end; ++_it, ++it)
      {
        if (tree.nCmp(*it, *_it))
          return false;
      }
    }

    return true;
  }

  template <class Tree>
  static bool isReverseInOrderTraversalSorted(const Tree& tree)
  {
    if (tree.size() != 0)
    {
      typename Tree::reverse_iterator it = tree.rbegin();
      typename Tree::reverse_iterator _it = ++tree.rbegin();
      typename Tree::reverse_iterator _end = tree.rend();
      for (; _it != _end; ++_it, ++it)
      {
        if (tree.cmp(*it, *_it))
          return false;
      }
    }

    return true;
  }

  template <class Tree>
  static bool hasCorrectSize(const Tree& tree, size_t expectedSize)
  {
    return tree.size() == expectedSize;
  }
};

} // namespace ft

#endif
