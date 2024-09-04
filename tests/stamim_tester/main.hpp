#ifndef MAIN_HPP
#define MAIN_HPP

#ifdef STD
#define __lib__ std
#else
#define FT
#define __lib__ ft
#endif

#include <iostream> // IWYU pragma: export

#define TEST_CASE(x) std::cout << x << std::endl;

#define CHECK(x) std::cout << x << std::endl

// declarations
void unit_test_vector_default_constructor();
void unit_test_vector_constructor_size_constructor();
void unit_test_vector_constructor_iterator_constructor();

// types
template < class T > class my_allocator : public std::allocator< T >
{
};

#endif