#include "../main.hpp"

using __lib__::vector;

// #include <vector>

void cplusplusexamples_vector()
{
	{
		vector<int> vec1;
		vector<int>::iterator i = vec1.begin();
		vector<int>::const_iterator j = vec1.begin();

		i = vec1.end();
		j = vec1.end();
	}

	{
		vector<int> vec1;
		vector<int>::reverse_iterator i = vec1.rbegin();
		vector<int>::const_reverse_iterator j = vec1.rbegin();

		i = vec1.rend();
		j = vec1.rend();
	}

	{
		vector<int> myvector(5); // 5 default-constructed ints

		int i = 0;

		vector<int>::reverse_iterator rit = myvector.rbegin();
		for (; rit != myvector.rend(); ++rit)
			*rit = ++i;

		std::cout << "myvector contains:";
		for (vector<int>::iterator it = myvector.begin(); it != myvector.end();
			 ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}

	{
		vector<int> foo(3, 0);
		vector<int> bar(5, 0);

		bar = foo;
		foo = vector<int>();

		std::cout << "Size of foo: " << int(foo.size()) << '\n';
		std::cout << "Size of bar: " << int(bar.size()) << '\n';
	}

	{
		vector<int> myvector;
		for (int i = 1; i <= 5; i++)
			myvector.push_back(i);

		std::cout << "myvector contains:";
		for (vector<int>::iterator it = myvector.begin(); it != myvector.end();
			 ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}

	{
		vector<int> myvector;
		for (int i = 1; i <= 5; i++)
			myvector.push_back(i);

		std::cout << "myvector contains:";
		for (vector<int>::iterator it = myvector.begin(); it != myvector.end();
			 ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}

	{
		vector<int> myvector(5); // 5 default-constructed ints

		int i = 0;

		vector<int>::reverse_iterator rit = myvector.rbegin();
		for (; rit != myvector.rend(); ++rit)
			*rit = ++i;

		std::cout << "myvector contains:";
		for (vector<int>::iterator it = myvector.begin(); it != myvector.end();
			 ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}

	{
		vector<int> myvector(5); // 5 default-constructed ints

		vector<int>::reverse_iterator rit = myvector.rbegin();

		int i = 0;
		for (rit = myvector.rbegin(); rit != myvector.rend(); ++rit)
			*rit = ++i;

		std::cout << "myvector contains:";
		for (vector<int>::iterator it = myvector.begin(); it != myvector.end();
			 ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}

	{
		vector<int> myints;
		std::cout << "0. size: " << myints.size() << '\n';

		for (int i = 0; i < 10; i++)
			myints.push_back(i);
		std::cout << "1. size: " << myints.size() << '\n';

		myints.insert(myints.end(), 10, 100);
		std::cout << "2. size: " << myints.size() << '\n';

		myints.pop_back();
		std::cout << "3. size: " << myints.size() << '\n';
	}

	{
		vector<int> myvector;
		int sum(0);

		for (int i = 1; i <= 10; i++)
			myvector.push_back(i);

		while (!myvector.empty())
		{
			sum += myvector.back();
			myvector.pop_back();
		}

		std::cout << "total: " << sum << '\n';
	}

	{
		// vector< int >::size_type sz;

		// vector< int > foo;
		// sz = foo.capacity();
		// std::cout << "making foo grow:\n";
		// for (int i = 0; i < 100; ++i)
		// {
		// 	foo.push_back(i);
		// 	if (sz != foo.capacity())
		// 	{
		// 		sz = foo.capacity();
		// 		std::cout << "capacity changed: " << sz << '\n';
		// 	}
		// }

		// vector< int > bar;
		// sz = bar.capacity();
		// bar.reserve(100); // this is the only difference with foo above
		// std::cout << "making bar grow:\n";
		// for (int i = 0; i < 100; ++i)
		// {
		// 	bar.push_back(i);
		// 	if (sz != bar.capacity())
		// 	{
		// 		sz = bar.capacity();
		// 		std::cout << "capacity changed: " << sz << '\n';
		// 	}
		// }
	}

	{
		vector<int> myvector(10); // 10 zero-initialized elements

		vector<int>::size_type sz = myvector.size();

		// assign some values:
		for (unsigned i = 0; i < sz; i++)
			myvector[i] = i;

		// reverse vector using operator[]:
		for (unsigned i = 0; i < sz / 2; i++)
		{
			int temp;
			temp = myvector[sz - 1 - i];
			myvector[sz - 1 - i] = myvector[i];
			myvector[i] = temp;
		}

		std::cout << "myvector contains:";
		for (unsigned i = 0; i < sz; i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	}

	{
		vector<int> myvector(10); // 10 zero-initialized ints

		// assign some values:
		for (unsigned i = 0; i < myvector.size(); i++)
			myvector.at(i) = i;

		std::cout << "myvector contains:";
		for (unsigned i = 0; i < myvector.size(); i++)
			std::cout << ' ' << myvector.at(i);
		std::cout << '\n';
	}

	{
		vector<int> myvector;

		myvector.push_back(78);

		std::cout << "size: " << myvector.size() << std::endl;

		myvector.push_back(16);

		std::cout << "size: " << myvector.size() << std::endl;

		std::cout << "begin: " << *myvector.begin() << std::endl;
		std::cout << "front: " << myvector.front() << std::endl;
		std::cout << "back: " << myvector.back() << std::endl;

		// now front equals 78, and back 16

		myvector.front() -= myvector.back();

		std::cout << "myvector.front() is now " << myvector.front() << '\n';
	}

	{
		vector<int> myvector;

		myvector.push_back(10);

		while (myvector.back() != 0)
		{
			myvector.push_back(myvector.back() - 1);
		}

		std::cout << "myvector contains:";
		for (unsigned i = 0; i < myvector.size(); i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	}

	{
		vector<int> first;
		vector<int> second;
		vector<int> third;

		first.assign(7, 100); // 7 ints with a value of 100

		vector<int>::iterator it;
		it = first.begin() + 1;

		second.assign(it, first.end() - 1); // the 5 central values of first

		int myints[] = {1776, 7, 4};
		third.assign(myints, myints + 3); // assigning from array.

		std::cout << "Size of first: " << int(first.size()) << '\n';
		std::cout << "Size of second: " << int(second.size()) << '\n';
		std::cout << "Size of third: " << int(third.size()) << '\n';
	}

	{
		vector<int> myvector;
		int sum(0);
		myvector.push_back(100);
		myvector.push_back(200);
		myvector.push_back(300);

		while (!myvector.empty())
		{
			sum += myvector.back();
			myvector.pop_back();
		}

		std::cout << "The elements of myvector add up to " << sum << '\n';
	}

	{
		vector<int> myvector(3, 100);
		vector<int>::iterator it;

		it = myvector.begin();
		it = myvector.insert(it, 200);

		std::cout << *it << std::endl;

		myvector.insert(it, 2, 300);

		// "it" no longer valid, get a new one:
		it = myvector.begin();

		std::cout << "something" << *it << std::endl;

		vector<int> anothervector(2, 400);
		myvector.insert(it + 2, anothervector.begin(), anothervector.end());

		int myarray[] = {501, 502, 503};
		myvector.insert(myvector.begin(), myarray, myarray + 3);

		std::cout << "myvector contains:";
		for (it = myvector.begin(); it != myvector.end(); it++)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}

	{
		vector<int> myvector;

		// set some values (from 1 to 10)
		for (int i = 1; i <= 10; i++)
			myvector.push_back(i);

		// erase the 6th element
		myvector.erase(myvector.begin() + 5);

		// erase the first 3 elements:
		myvector.erase(myvector.begin(), myvector.begin() + 3);

		std::cout << "myvector contains:";
		for (unsigned i = 0; i < myvector.size(); ++i)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	}

	{
		vector<int> foo(3, 100); // three ints with a value of 100
		vector<int> bar(5, 200); // five ints with a value of 200

		foo.swap(bar);

		std::cout << "foo contains:";
		for (unsigned i = 0; i < foo.size(); i++)
			std::cout << ' ' << foo[i];
		std::cout << '\n';

		std::cout << "bar contains:";
		for (unsigned i = 0; i < bar.size(); i++)
			std::cout << ' ' << bar[i];
		std::cout << '\n';
	}

	{
		vector<int> myvector;
		myvector.push_back(100);
		myvector.push_back(200);
		myvector.push_back(300);

		std::cout << "myvector contains:";
		for (unsigned i = 0; i < myvector.size(); i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';

		myvector.clear();
		myvector.push_back(1101);
		myvector.push_back(2202);

		std::cout << "myvector contains:";
		for (unsigned i = 0; i < myvector.size(); i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	}

	{
		vector<int> myvector;
		int* p;
		unsigned int i;

		// allocate an array with space for 5 elements using vector's allocator:
		p = myvector.get_allocator().allocate(5);

		// construct values in-place on the array:
		for (i = 0; i < 5; i++)
			myvector.get_allocator().construct(&p[i], i);

		std::cout << "The allocated array contains:";
		for (i = 0; i < 5; i++)
			std::cout << ' ' << p[i];
		std::cout << '\n';

		// destroy and deallocate:
		for (i = 0; i < 5; i++)
			myvector.get_allocator().destroy(&p[i]);
		myvector.get_allocator().deallocate(p, 5);
	}

	{
		vector<int> foo(3, 100); // three ints with a value of 100
		vector<int> bar(2, 200); // two ints with a value of 200

		if (foo == bar)
			std::cout << "foo and bar are equal\n";
		if (foo != bar)
			std::cout << "foo and bar are not equal\n";
		if (foo < bar)
			std::cout << "foo is less than bar\n";
		if (foo > bar)
			std::cout << "foo is greater than bar\n";
		if (foo <= bar)
			std::cout << "foo is less than or equal to bar\n";
		if (foo >= bar)
			std::cout << "foo is greater than or equal to bar\n";
	}

	{
		vector<int> foo(3, 100); // three ints with a value of 100
		vector<int> bar(5, 200); // five ints with a value of 200

		foo.swap(bar);

		std::cout << "foo contains:";
		for (vector<int>::iterator it = foo.begin(); it != foo.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		std::cout << "bar contains:";
		for (vector<int>::iterator it = bar.begin(); it != bar.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
}