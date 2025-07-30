#include "BinarySearchTreeTest.hpp"

using ft::BinarySearchTreeTest;

void test_insert()
{
  {
    BinarySearchTreeTest tree;

    int arr[] = {1, -1, 3, -10, 20, -2, 4, 4, 4};

    for (int i = 0; i != sizeof(arr) / sizeof(int); i++)
    {
      tree.insert(arr[i]);
    }

    cout << tree << endl;

    for (int i = 0; i != sizeof(arr) / sizeof(int); i++)
    {
      assert(tree.find(arr[i]) != NUL);
    }
  }
}

void test_erase()
{
  {
    BinarySearchTreeTest tree;

    int arr[] = {1, -1, 3, -10, 20, -2, 4, 8, -5};

    for (int i = 0; i != sizeof(arr) / sizeof(int); i++)
    {
      tree.insert(arr[i]);
    }

    for (int i = 0; i != sizeof(arr) / sizeof(int); i++)
    {
      assert(tree.find(arr[i]) != NUL);
      tree.erase(arr[i]);
      assert(tree.find(arr[i]) == NUL);
    }
  }

  {
    BinarySearchTreeTest tree;

    int arr[] = {1, -1, 3, -10, 20, -2, 4, 8, -5};

    for (int i = 0; i != sizeof(arr) / sizeof(int); i++)
    {
      tree.insert(arr[i]);
    }

    tree.clear();
    assert(tree.size() == 0);
  }
}

void test_iterator()
{
  {
    BinarySearchTreeTest tree;

    int              arr[] = {1, -1, 3, -10, 20, -2, 4, 8, -5};
    const int        sz = sizeof(arr) / sizeof(int);
    std::vector<int> arrSorted = std::vector<int>(arr, arr + sz);
    std::sort(arrSorted.begin(), arrSorted.end());

    for (int i = 0; i != sz; i++)
    {
      tree.insert(arr[i]);
    }

    int i = 0;
    for (BinarySearchTreeTest::iterator it = tree.begin(); it != tree.end();
            ++it, ++i)
    {
      assert(*it == arrSorted[i]);
    }
  }
}

void test_reverse_iterator()
{
  {
    BinarySearchTreeTest tree;

    int              arr[] = {1, -1, 3, -10, 20, -2, 4, 8, -5};
    const int        sz = sizeof(arr) / sizeof(int);
    std::vector<int> arrSorted = std::vector<int>(arr, arr + sz);
    std::sort(arrSorted.begin(), arrSorted.end(), std::greater<int>());

    for (int i = 0; i != sz; i++)
    {
      tree.insert(arr[i]);
    }

    int i = 0;

    for (BinarySearchTreeTest::reverse_iterator it = tree.rbegin();
            it != tree.rend();
            ++it, ++i)
    {
      assert(*it == arrSorted[i]);
    }
  }
}

void test_bst()
{
  test_reverse_iterator();
  test_iterator();
  test_erase();
  test_insert();
}
