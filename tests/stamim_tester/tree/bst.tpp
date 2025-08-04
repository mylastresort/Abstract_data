#ifndef __BST__TPP
#define __BST__TPP
#include "BinarySearchTreeTest.hpp"
#include <cstdlib>
#include <set>

inline int getRand(int min, int max)
{
  if (min > max)
  {
    int temp = min;
    min = max;
    max = temp;
  }

  static bool seeded = false;
  if (!seeded)
  {
    srand(time(0)); // Seed once
    seeded = true;
  }

  return min + std::rand() % (max - min + 1);
}

template <class Tree> void test_insert()
{
  {
    Tree tree;

    std::set<int> used_values;
    int           min = -10;
    int           max = 10;

    for (int i = 0; i < 20; i++)
    {
      int num = getRand(min, max);
      while (used_values.count(num))
        num = getRand(min, max);
      tree.insert(num);
      assert(tree.find(num) != NUL);
    }

    cout << tree << endl;
  }
}

template <class Tree> void test_erase()
{
  {
    Tree tree;

    int arr[] = {1, -1, 3, -10, 20, -2, 4, 8, -5};

    for (int i = 0; i != sizeof(arr) / sizeof(int); i++)
    {
      tree.insert(arr[i]);
    }

    tree.erase(232);

    for (int i = 0; i != sizeof(arr) / sizeof(int); i++)
    {
      assert(tree.find(arr[i]) != NUL);
      tree.erase(arr[i]);
      assert(tree.find(arr[i]) == NUL);
    }
  }

  {
    Tree tree;

    int arr[] = {1, -1, 3, -10, 20, -2, 4, 8, -5};

    for (int i = 0; i != sizeof(arr) / sizeof(int); i++)
    {
      tree.insert(arr[i]);
    }

    tree.clear();
    assert(tree.size() == 0);
  }
}

template <class Tree> void test_iterator()
{
  {
    Tree tree;

    int              arr[] = {1, -1, 3, -10, 20, -2, 4, 8, -5};
    const int        sz = sizeof(arr) / sizeof(int);
    std::vector<int> arrSorted = std::vector<int>(arr, arr + sz);
    std::sort(arrSorted.begin(), arrSorted.end());

    for (int i = 0; i != sz; i++)
    {
      tree.insert(arr[i]);
    }

    int i = 0;
    for (typename Tree::iterator it = tree.begin(); it != tree.end(); ++it, ++i)
    {
      assert(*it == arrSorted[i]);
    }
  }
}

template <class Tree> void test_reverse_iterator()
{
  {
    Tree tree;

    int              arr[] = {1, -1, 3, -10, 20, -2, 4, 8, -5};
    const int        sz = sizeof(arr) / sizeof(int);
    std::vector<int> arrSorted = std::vector<int>(arr, arr + sz);
    std::sort(arrSorted.begin(), arrSorted.end(), std::greater<int>());

    for (int i = 0; i != sz; i++)
    {
      tree.insert(arr[i]);
    }

    int i = 0;

    for (typename Tree::reverse_iterator it = tree.rbegin(); it != tree.rend();
            ++it, ++i)
    {
      assert(*it == arrSorted[i]);
    }
  }
}

template <class Tree> void test_bst()
{
  test_reverse_iterator<Tree>();
  test_iterator<Tree>();
  test_erase<Tree>();
  test_insert<Tree>();
}

#endif
