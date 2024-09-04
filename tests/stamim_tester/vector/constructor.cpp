#include "../main.hpp"

#ifdef FT
#include "vector.hpp"
#else
#include <vector>
#endif

using __lib__::vector;
using std::allocator;

void unit_test_vector_constructor()
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
}