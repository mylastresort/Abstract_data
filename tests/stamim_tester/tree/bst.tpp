#ifndef __BST__TPP
#define __BST__TPP
#include "BinarySearchTreeTest.hpp"
#include "_phc.hpp"
#include "functional.hpp"

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
      assert(tree.lookup(num) != NUL);
    }
  }
}

template <class Tree> void test_erase()
{
  {
    Tree tree;

    // Generate random numbers in range [1, 100]
    std::vector<int> arr;
    std::set<int>    used_values;
    int              min_val = 1;
    int              max_val = 100;
    size_t           count = 25; // Generate 25 unique random numbers

    // Generate unique random numbers
    while (arr.size() < count)
    {
      int num = getRand(min_val, max_val);
      if (used_values.find(num) == used_values.end())
      {
        arr.push_back(num);
        used_values.insert(num);
      }
    }

    // Shuffle the array for different insertion order
    for (size_t i = arr.size() - 1; i > 0; i--)
    {
      size_t j = getRand(0, static_cast<int>(i));
      std::swap(arr[i], arr[j]);
    }

    for (size_t i = 0; i < arr.size(); i++)
    {
      tree.insert(arr[i]);
    }

    // Test erasing a non-existent value
    int non_existent = max_val + 50;
    tree.erase(non_existent);

    // Shuffle again for different deletion order
    for (size_t i = arr.size() - 1; i > 0; i--)
    {
      size_t j = getRand(0, static_cast<int>(i));
      std::swap(arr[i], arr[j]);
    }

    for (size_t i = 0; i < arr.size(); i++)
    {
      assert(tree.lookup(arr[i]) != NUL);
      tree.erase(arr[i]);
      assert(tree.lookup(arr[i]) == NUL);
    }
  }
}

template <class Tree> void test_iterator()
{
  {
    Tree tree;

    int arr[] = {
            15, 3, 18, 7, 12, 1, 19, 8, 4, 16, 11, 20, 6, 13, 2, 17, 9, 14, 5, 10};
    const int        sz = sizeof(arr) / sizeof(int);
    std::vector<int> arrSorted = std::vector<int>(arr, arr + sz);
    std::sort(arrSorted.begin(), arrSorted.end(), typename Tree::value_compare());

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

    int arr[] = {
            15, 3, 18, 7, 12, 1, 19, 8, 4, 16, 11, 20, 6, 13, 2, 17, 9, 14, 5, 10};
    const int        sz = sizeof(arr) / sizeof(int);
    std::vector<int> arrSorted = std::vector<int>(arr, arr + sz);
    std::sort(arrSorted.begin(),
            arrSorted.end(),
            ft::notCompare<typename Tree::value_compare, int>());

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
