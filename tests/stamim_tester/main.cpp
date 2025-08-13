#include "main.hpp"
#include "functional.hpp"
#include "tree/BinarySearchTreeTest.hpp"
#include "tree/RedBlackTreeTest.hpp"

void test_vector()
{
  unit_test_vector_default_constructor();
  unit_test_vector_constructor_size_constructor();
  cplusplusexamples_vector();
}

void test_deque()
{
  cplusplusexamples_deque();
  // test_deque_all();
}

void test_list()
{
  cplusplusexamples_list();
}

int main()
{
  test_vector();
  test_deque();
  test_list();

  test_bst<ft::BinarySearchTreeTest<int> >();
  test_bst<ft::RedBlackTreeTest<int> >();

  test_bst<ft::BinarySearchTreeTest<int, ft::less<int> > >();
  test_bst<ft::RedBlackTreeTest<int, ft::less<int> > >();

  test_bst<ft::BinarySearchTreeTest<int, ft::greater<int> > >();
  test_bst<ft::RedBlackTreeTest<int, ft::greater<int> > >();
}
