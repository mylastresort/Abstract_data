#ifndef MAIN_HPP
#define MAIN_HPP

#include "_phc.hpp"
#include "tree/bst.tpp"

#ifdef STD
#define __lib__ std
#else
#define FT
#include "deque.hpp" // IWYU pragma: export
#include "list.hpp"
#include "vector.hpp"
#define __lib__ ft
#endif

using std::cin;
using std::cout;
using std::endl;

// TEST_CASE only logs the test case being run
#define TEST_CASE(x) std::cout << (x) << std::endl;
// CHECK only output to stdout because
// we need later to check the difference of std and ft containers
#define CHECK(x) std::cout << (x) << std::endl

// vector
void unit_test_vector_default_constructor();
void unit_test_vector_constructor_size_constructor();
void unit_test_vector_constructor_iterator_constructor();
void unit_test_vector_capacity();
void cplusplusexamples_vector();

// deque
void cplusplusexamples_deque();
void test_deque_all();

// list
void cplusplusexamples_list();

// types
typedef int                   VEC_T;
typedef std::allocator<VEC_T> allocator;
using __lib__::vector; // NOLINT
typedef __lib__::vector<VEC_T> Vector;
typedef Vector::iterator       itr;

template <class T> class my_allocator : public std::allocator<T>
{
};

using std::cin;
using std::cout;
using std::endl;

#endif
