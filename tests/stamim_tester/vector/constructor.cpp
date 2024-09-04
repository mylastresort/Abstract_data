#include "../main.hpp"

#ifdef FT
#include "vector.hpp"
#else
#include <vector>
#endif

using __lib__::vector;
using std::allocator;

void unit_test_vector_default_constructor()
{
	TEST_CASE("default constructor")
	{
		vector< int > vec1;
	}

	TEST_CASE("default constructor with std::allocator")
	{
		vector< int, allocator< int > > vec1;
	}

#ifdef BAD
	TEST_CASE("default constructor with incorrect allocator type")
	{
		vector< int, int > vec1;
	}
#endif

	TEST_CASE("default constructor with derived class from std::allocator")
	{
		vector< int, my_allocator< int > > vec1;
	}
}

void unit_test_vector_constructor_size_constructor()
{
	TEST_CASE("default constructor with one size parameter")
	{
		std::allocator< int > instance;
		vector< int > vec1(1);
	}
}