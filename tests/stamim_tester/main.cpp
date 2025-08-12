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

  test_bst<ft::BinarySearchTreeTest<> >();
  test_bst<ft::RedBlackTreeTest<> >();

  test_bst<ft::BinarySearchTreeTest<ft::less<int> > >();
  test_bst<ft::RedBlackTreeTest<ft::less<int> > >();

  test_bst<ft::BinarySearchTreeTest<ft::greater<int> > >();
  test_bst<ft::RedBlackTreeTest<ft::greater<int> > >();
}
