#ifndef MAIN_HPP
#define MAIN_HPP

#ifdef STD
#include <vector>
#define __lib__ std
#else
#define FT
#include "vector.hpp"
#define __lib__ ft
#endif

#include <iostream> // IWYU pragma: export
#define TEST_CASE(x) std::cout << x << std::endl;
#define CHECK(x) std::cout << x << std::endl

// declarations
void unit_test_vector_default_constructor();
void unit_test_vector_constructor_size_constructor();
void unit_test_vector_constructor_iterator_constructor();
void unit_test_vector_capacity();

void cplusplusexamples();

// types
typedef int VEC_T;
typedef std::allocator< VEC_T > allocator;
using __lib__::vector; // NOLINT
typedef __lib__::vector< VEC_T > Vector;
typedef Vector::iterator itr;

template < class T > class my_allocator : public std::allocator< T >
{
};

#endif