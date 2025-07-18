#include "../main.hpp"

using __lib__::list;

void cplusplusexamples_list()
{
  // Test constructors and basic operations
  {
    list<int>                 lst1;
    list<int>::iterator       i = lst1.begin();
    list<int>::const_iterator j = lst1.begin();

    i = lst1.end();
    j = lst1.end();
  }

  // Test reverse iterators
  {
    list<int>                         lst1;
    list<int>::reverse_iterator       i = lst1.rbegin();
    list<int>::const_reverse_iterator j = lst1.rbegin();

    i = lst1.rend();
    j = lst1.rend();
  }

  // Test basic insertion and iteration
  {
    list<int> mylist;
    for (int i = 1; i <= 5; i++)
      mylist.push_back(i);

    std::cout << "mylist contains:";
    for (list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
      std::cout << ' ' << *it;
    std::cout << '\n';
  }

  // Test push_front and reverse iteration
  {
    list<int> mylist;
    for (int i = 1; i <= 5; i++)
      mylist.push_front(i);

    std::cout << "mylist contains (reverse order):";
    for (list<int>::reverse_iterator rit = mylist.rbegin(); rit != mylist.rend();
            ++rit)
      std::cout << ' ' << *rit;
    std::cout << '\n';
  }

  // // Test size operations
  // {
  //     list<int> myints;
  //     std::cout << "0. size: " << myints.size() << '\n';
  //
  //     for (int i = 0; i < 10; i++)
  //         myints.push_back(i);
  //     std::cout << "1. size: " << myints.size() << '\n';
  //
  //     myints.pop_back();
  //     std::cout << "2. size: " << myints.size() << '\n';
  //
  //     myints.pop_front();
  //     std::cout << "3. size: " << myints.size() << '\n';
  // }

  // // Test empty and back/front access
  // {
  //     list<int> mylist;
  //     int       sum(0);
  //
  //     for (int i = 1; i <= 10; i++)
  //         mylist.push_back(i);
  //
  //     while (!mylist.empty())
  //     {
  //         sum += mylist.back();
  //         mylist.pop_back();
  //     }
  //
  //     std::cout << "total: " << sum << '\n';
  // }

  // Test front access
  {
    list<int> mylist;

    mylist.push_back(77);
    mylist.push_back(22);

    // now front equals 77, and back 22

    mylist.front() -= mylist.back();

    std::cout << "mylist.front() is now " << mylist.front() << '\n';
  }

  // Test assignment operator
  {
    list<int> foo(3, 0);
    list<int> bar(5, 0);
    bar = foo;
    foo = list<int>();

    std::cout << "Size of foo: " << int(foo.size()) << '\n';
    std::cout << "Size of bar: " << int(bar.size()) << '\n';
  }

  // Test constructors with size and value
  {
    list<int> first;          // empty list of ints
    list<int> second(4, 100); // four ints with value 100
    std::cout << "The contents of second are:";
    for (list<int>::iterator it = second.begin(); it != second.end(); ++it)
      std::cout << ' ' << *it;
    std::cout << '\n';
  }

  // Test insert operations
  {
    list<int>           mylist;
    list<int>::iterator it;

    // set some initial values:
    for (int i = 1; i <= 5; ++i)
      mylist.push_back(i); // 1 2 3 4 5

    it = mylist.begin();
    ++it; // it points now to number 2           ^

    mylist.insert(it, 10); // 1 10 2 3 4 5

    // "it" still points to number 2                      ^
    mylist.insert(it, 2, 20); // 1 10 20 20 2 3 4 5

    std::cout << "mylist contains:";
    for (list<int>::iterator i = mylist.begin(); i != mylist.end(); ++i)
      std::cout << ' ' << *i;
    std::cout << '\n';
  }

  //
  // // Test erase operations
  // {
  // 	list<int> mylist;
  // 	list<int>::iterator it1, it2;
  //
  // 	// set some values:
  // 	for (int i = 1; i < 10; ++i)
  // 		mylist.push_back(i * 10);
  //
  // 	// 10 20 30 40 50 60 70 80 90
  // 	it1 = it2 = mylist.begin(); // ^^
  // 	++it2;                      // ^   ^
  // 	++it2;                      // ^     ^
  // 	++it2;                      // ^       ^
  //
  // 	it1 = mylist.erase(it1); // 20 30 40 50 60 70 80 90
  // 							 // ^  ^
  // 	it2 = mylist.erase(it2); // 20 30 50 60 70 80 90
  // 							 //    ^  ^
  //
  // 	++it1; //       ^     ^
  // 	--it2; //       ^   ^
  //
  // 	mylist.erase(it1, it2); // 20 30 70 80 90
  // 							//        ^
  //
  // 	std::cout << "mylist contains:";
  // 	for (it1 = mylist.begin(); it1 != mylist.end(); ++it1)
  // 		std::cout << ' ' << *it1;
  // 	std::cout << '\n';
  // }
  //
  // // Test swap
  // {
  // 	list<int> first(3, 100);  // three ints with a value of 100
  // 	list<int> second(5, 200); // five ints with a value of 200
  //
  // 	first.swap(second);
  //
  // 	std::cout << "first contains:";
  // 	for (list<int>::iterator it = first.begin(); it != first.end(); it++)
  // 		std::cout << ' ' << *it;
  // 	std::cout << '\n';
  //
  // 	std::cout << "second contains:";
  // 	for (list<int>::iterator it = second.begin(); it != second.end(); it++)
  // 		std::cout << ' ' << *it;
  // 	std::cout << '\n';
  // }
  //
  // // Test resize
  // {
  // 	list<int> mylist;
  //
  // 	// set some initial content:
  // 	for (int i = 1; i < 10; ++i)
  // 		mylist.push_back(i);
  //
  // 	mylist.resize(5);
  // 	mylist.resize(8, 100);
  // 	mylist.resize(12);
  //
  // 	std::cout << "mylist contains:";
  // 	for (list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
  // 		std::cout << ' ' << *it;
  // 	std::cout << '\n';
  // }
  //
  // // Test clear
  // {
  // 	list<int> mylist;
  // 	list<int>::iterator it;
  //
  // 	mylist.push_back(100);
  // 	mylist.push_back(200);
  // 	mylist.push_back(300);
  //
  // 	std::cout << "mylist contains:";
  // 	for (it = mylist.begin(); it != mylist.end(); ++it)
  // 		std::cout << ' ' << *it;
  // 	std::cout << '\n';
  //
  // 	mylist.clear();
  // 	mylist.push_back(1101);
  // 	mylist.push_back(2202);
  //
  // 	std::cout << "mylist contains:";
  // 	for (it = mylist.begin(); it != mylist.end(); ++it)
  // 		std::cout << ' ' << *it;
  // 	std::cout << '\n';
  // }
  //
  // // Test splice
  // {
  // 	list<int> mylist1, mylist2;
  // 	list<int>::iterator it;
  //
  // 	// set some initial values:
  // 	for (int i = 1; i <= 4; ++i)
  // 		mylist1.push_back(i); // mylist1: 1 2 3 4
  //
  // 	for (int i = 1; i <= 3; ++i)
  // 		mylist2.push_back(i * 10); // mylist2: 10 20 30
  //
  // 	it = mylist1.begin();
  // 	++it; // points to 2
  //
  // 	mylist1.splice(it, mylist2); // mylist1: 1 10 20 30 2 3 4
  // 								 // mylist2: (empty)
  // 								 // "it" still points to 2 (the 5th element)
  //
  // 	std::cout << "mylist1 contains:";
  // 	for (it = mylist1.begin(); it != mylist1.end(); ++it)
  // 		std::cout << ' ' << *it;
  // 	std::cout << '\n';
  //
  // 	std::cout << "mylist2 contains:";
  // 	for (it = mylist2.begin(); it != mylist2.end(); ++it)
  // 		std::cout << ' ' << *it;
  // 	std::cout << '\n';
  // }
  //
  // // Test remove
  // {
  // 	int myints[] = {17, 89, 7, 14};
  // 	list<int> mylist(myints, myints + 4);
  //
  // 	mylist.remove(89);
  //
  // 	std::cout << "mylist contains:";
  // 	for (list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
  // 		std::cout << ' ' << *it;
  // 	std::cout << '\n';
  // }
  //
  // // Test unique
  // {
  // 	double mydoubles[] = {
  // 		12.15, 2.72, 73.0, 12.77, 3.14, 12.77, 73.35, 72.25, 15.3, 72.25};
  // 	list<double> mylist(mydoubles, mydoubles + 10);
  //
  // 	mylist.sort(); //  2.72,  3.14, 12.15, 12.77, 12.77,
  // 				   // 15.3,  72.25, 72.25, 73.0,  73.35
  //
  // 	mylist.unique(); //  2.72,  3.14, 12.15, 12.77
  // 					 // 15.3,  72.25, 73.0,  73.35
  //
  // 	std::cout << "mylist contains:";
  // 	for (list<double>::iterator it = mylist.begin(); it != mylist.end();
  // ++it) 		std::cout << ' ' << *it; 	std::cout << '\n';
  // }
  //
  // // Test merge
  // {
  // 	list<double> first, second;
  //
  // 	first.push_back(3.1);
  // 	first.push_back(2.2);
  // 	first.push_back(2.9);
  //
  // 	second.push_back(3.7);
  // 	second.push_back(7.1);
  // 	second.push_back(1.4);
  //
  // 	first.sort();
  // 	second.sort();
  //
  // 	first.merge(second);
  //
  // 	// (second is now empty)
  //
  // 	std::cout << "first contains:";
  // 	for (list<double>::iterator it = first.begin(); it != first.end(); ++it)
  // 		std::cout << ' ' << *it;
  // 	std::cout << '\n';
  // }
  //
  // // Test reverse
  // {
  // 	list<int> mylist;
  //
  // 	for (int i = 1; i < 10; ++i)
  // 		mylist.push_back(i);
  //
  // 	mylist.reverse();
  //
  // 	std::cout << "mylist contains:";
  // 	for (list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
  // 		std::cout << ' ' << *it;
  // 	std::cout << '\n';
  // }
  //
  // // Test comparison operators
  // {
  // 	list<int> a(3, 100); // three ints with a value of 100
  // 	list<int> b(2, 200); // two ints with a value of 200
  //
  // 	if (a == b)
  // 		std::cout << "a and b are equal\n";
  // 	if (a != b)
  // 		std::cout << "a and b are not equal\n";
  // 	if (a < b)
  // 		std::cout << "a is less than b\n";
  // 	if (a > b)
  // 		std::cout << "a is greater than b\n";
  // 	if (a <= b)
  // 		std::cout << "a is less than or equal to b\n";
  // 	if (a >= b)
  // 		std::cout << "a is greater than or equal to b\n";
  // }
  //
  // Test iterator range constructor
  {
    int       myints[] = {16, 2, 77, 29};
    list<int> fifth(myints, myints + 4);

    std::cout << "fifth contains:";
    for (list<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
      std::cout << ' ' << *it;
    std::cout << '\n';
  }
  //
  // // Test get_allocator and max_size
  // {
  // 	list<int> mylist;
  // 	int* p;
  // 	unsigned int i;
  //
  // 	// allocate an array of 5 elements using mylist's allocator:
  // 	p = mylist.get_allocator().allocate(5);
  //
  // 	// assign some values to it
  // 	for (i = 0; i < 5; i++)
  // 		mylist.get_allocator().construct(&p[i], i);
  //
  // 	std::cout << "The allocated array contains:";
  // 	for (i = 0; i < 5; i++)
  // 		std::cout << ' ' << p[i];
  // 	std::cout << '\n';
  //
  // 	// destroy and deallocate:
  // 	for (i = 0; i < 5; i++)
  // 		mylist.get_allocator().destroy(&p[i]);
  // 	mylist.get_allocator().deallocate(p, 5);
  //
  // 	std::cout << "max_size: " << mylist.max_size() << '\n';
  // }
  //
  // Test assign methods
  {
    list<int> first;
    list<int> second;

    first.assign(7, 100); // 7 ints with value 100

    second.assign(first.begin(), first.end()); // a copy of first

    int myints[] = {1776, 7, 4};
    first.assign(myints, myints + 3); // assigning from array

    std::cout << "Size of first: " << int(first.size()) << '\n';
    std::cout << "Size of second: " << int(second.size()) << '\n';
  }
  //
  // // Test remove_if
  // {
  // 	int myints[] = {15, 36, 7, 17, 20, 39, 4, 1};
  // 	list<int> mylist(myints, myints + 8); // 15 36 7 17 20 39 4 1
  //
  // 	// remove odd numbers
  // 	class is_odd
  // 	{
  // 	  public:
  // 		bool operator()(const int& value)
  // 		{
  // 			return (value % 2) == 1;
  // 		}
  // 	};
  //
  // 	mylist.remove_if(is_odd()); // 36 20 4
  //
  // 	std::cout << "mylist contains:";
  // 	for (list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
  // 		std::cout << ' ' << *it;
  // 	std::cout << '\n';
  // }
  //
  // // Test unique with custom predicate
  // {
  // 	double mydoubles[] = {
  // 		12.15, 2.72, 73.0, 12.77, 3.14, 12.77, 73.35, 72.25, 15.3, 72.25};
  // 	list<double> mylist(mydoubles, mydoubles + 10);
  //
  // 	mylist.sort();
  //
  // 	// using a binary predicate
  // 	class same_integral_part
  // 	{
  // 	  public:
  // 		bool operator()(double first, double second)
  // 		{
  // 			return (int(first) == int(second));
  // 		}
  // 	};
  //
  // 	mylist.unique(same_integral_part());
  //
  // 	std::cout << "mylist contains:";
  // 	for (list<double>::iterator it = mylist.begin(); it != mylist.end(); ++it)
  // 		std::cout << ' ' << *it;
  // 	std::cout << '\n';
  // }
  //
  // // Test merge with custom comparator
  // {
  // 	list<double> first, second;
  //
  // 	first.push_back(3.1);
  // 	first.push_back(2.2);
  // 	first.push_back(2.9);
  //
  // 	second.push_back(3.7);
  // 	second.push_back(7.1);
  // 	second.push_back(1.4);
  //
  // 	// using a custom comparison object
  // 	class mycomparison
  // 	{
  // 	  public:
  // 		bool operator()(const double& first, const double& second)
  // 		{
  // 			return (int(first) < int(second));
  // 		}
  // 	};
  //
  // 	first.sort();
  // 	second.sort();
  //
  // 	first.merge(second, mycomparison());
  //
  // 	std::cout << "first contains:";
  // 	for (list<double>::iterator it = first.begin(); it != first.end(); ++it)
  // 		std::cout << ' ' << *it;
  // 	std::cout << '\n';
  // }
  //
  // // Test sort with custom comparator
  // {
  // 	list<std::string> mylist;
  // 	list<std::string>::iterator it;
  // 	mylist.push_back("one");
  // 	mylist.push_back("two");
  // 	mylist.push_back("Three");
  //
  // 	// using object as comp
  // 	class compare_length
  // 	{
  // 	  public:
  // 		bool operator()(const std::string& first, const std::string& second)
  // 		{
  // 			return (first.length() < second.length());
  // 		}
  // 	};
  //
  // 	mylist.sort(compare_length());
  //
  // 	std::cout << "mylist contains:";
  // 	for (it = mylist.begin(); it != mylist.end(); ++it)
  // 		std::cout << ' ' << *it;
  // 	std::cout << '\n';
  // }
  //
  // // Test splice variations (single element and range)
  // {
  // 	list<int> mylist1, mylist2;
  // 	list<int>::iterator it;
  //
  // 	// set some initial values:
  // 	for (int i = 1; i <= 4; ++i)
  // 		mylist1.push_back(i); // mylist1: 1 2 3 4
  //
  // 	for (int i = 1; i <= 3; ++i)
  // 		mylist2.push_back(i * 10); // mylist2: 10 20 30
  //
  // 	it = mylist1.begin();
  // 	++it; // points to 2
  //
  // 	// splice single element
  // 	mylist1.splice(it, mylist2, mylist2.begin()); // mylist1: 1 10 2 3 4
  // 												  // mylist2: 20 30
  //
  // 	std::cout << "After single element splice - mylist1 contains:";
  // 	for (it = mylist1.begin(); it != mylist1.end(); ++it)
  // 		std::cout << ' ' << *it;
  // 	std::cout << '\n';
  //
  // 	// splice range
  // 	list<int>::iterator it_start = mylist2.begin();
  // 	list<int>::iterator it_end = mylist2.end();
  // 	mylist1.splice(
  // 		mylist1.end(), mylist2, it_start, it_end); // mylist1: 1 10 2 3 4 20 30
  //
  // 	std::cout << "After range splice - mylist1 contains:";
  // 	for (it = mylist1.begin(); it != mylist1.end(); ++it)
  // 		std::cout << ' ' << *it;
  // 	std::cout << '\n';
  //
  // 	std::cout << "mylist2 contains:";
  // 	for (it = mylist2.begin(); it != mylist2.end(); ++it)
  // 		std::cout << ' ' << *it;
  // 	std::cout << '\n';
  // }
}
