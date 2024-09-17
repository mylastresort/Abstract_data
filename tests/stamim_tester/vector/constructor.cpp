#include "../main.hpp"

void unit_test_vector_default_constructor()
{
	TEST_CASE("default constructor and check the size")
	{
		Vector vec1;

		CHECK(vec1.size());
	}

	TEST_CASE("looping over default constructor")
	{
		Vector vec1;

		for (itr itr = vec1.begin(); itr != vec1.end(); itr++)
		{
			CHECK(*itr);
		}
	}

	TEST_CASE("default constructor with std::allocator")
	{
		Vector vec1;
	}

#ifdef BAD
	TEST_CASE("default constructor with incorrect allocator type")
	{
		vector< __T, __T > vec1;
	}
#endif

	TEST_CASE("default constructor with derived class from std::allocator")
	{
		vector< VEC_T, my_allocator< VEC_T > > vec1;
	}
}

void unit_test_vector_constructor_size_constructor()
{
	TEST_CASE("constructor with one size parameter")
	{
		allocator instance;
		Vector vec1(1);

		CHECK(vec1.size());
	}

	TEST_CASE("constructor with size parameter and value_type")
	{
		{
			Vector vec1(1, 1);

			CHECK(vec1.size());
			CHECK(vec1.capacity());

			for (itr i = vec1.begin(); i != vec1.end(); i++)
			{
				CHECK(*i);
			}
		}

		{
			Vector vec1(10, 1);

			CHECK(vec1.size());
			CHECK(vec1.capacity());

			for (itr i = vec1.begin(); i != vec1.end(); i++)
			{
				CHECK(*i);
			}
		}

		{
			Vector vec1(10, 10);

			CHECK(vec1.size());
			CHECK(vec1.capacity());

			for (itr i = vec1.begin(); i != vec1.end(); i++)
			{
				CHECK(*i);
			}
		}
	}
}