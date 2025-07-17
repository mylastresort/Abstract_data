#include "../main.hpp"

using __lib__::deque;

void cplusplusexamples_deque()
{
	{
		deque<int> vec1;
		deque<int>::iterator i = vec1.begin();
		deque<int>::const_iterator j = vec1.begin();

		i = vec1.end();
		j = vec1.end();
	}

	{
		deque<int> vec1;
		deque<int>::reverse_iterator i = vec1.rbegin();
		deque<int>::const_reverse_iterator j = vec1.rbegin();

		i = vec1.rend();
		j = vec1.rend();
	}

	{
		// constructors used in the same order as described above:
		deque<int> first; // empty deque of ints
		cout << first.size() << endl;
		deque<int> second(4, 100); // four ints with value 100
		cout << second.size() << endl;
		for (deque<int>::iterator it = second.begin(); it != second.end(); it++)
		{
			cout << *it << endl;
		}
		for (deque<int>::const_iterator it = second.begin(); it != second.end();
			 it++)
		{
			cout << *it << endl;
		}
		deque<int> third(second.begin(),
						 second.end()); // iterating through second
		cout << third.size() << endl;
		for (deque<int>::iterator it = third.begin(); it != third.end(); it++)
		{
			cout << *it << endl;
		}
		for (deque<int>::const_iterator it = third.begin(); it != third.end();
			 it++)
		{
			cout << *it << endl;
		}
		deque<int> fourth(third); // a copy of third
		cout << fourth.size() << endl;
		for (deque<int>::iterator it = fourth.begin(); it != fourth.end(); it++)
		{
			cout << *it << endl;
		}
		for (deque<int>::const_iterator it = fourth.begin(); it != fourth.end();
			 it++)
		{
			cout << *it << endl;
		}

		// the iterator constructor can be used to copy arrays:
		int myints[] = {16, 2, 77, 29};
		deque<int> fifth(myints, myints + sizeof(myints) / sizeof(int));

		std::cout << "The contents of fifth are:";
		for (deque<int>::iterator it = second.begin(); it != second.end(); ++it)
			std::cout << ' ' << *it;

		std::cout << '\n';
	}

	{
		deque<int> first(3); // deque with 3 zero-initialized ints
		cout << first.size() << endl;
		deque<int> second(5); // deque with 5 zero-initialized ints
		cout << second.size() << endl;

		second = first;
		cout << first.size() << endl;
		cout << second.size() << endl;
		for (deque<int>::iterator it = first.begin(); it != first.end(); it++)
		{
			cout << *it << endl;
		}
		for (deque<int>::iterator it = second.begin(); it != second.end(); it++)
		{
			cout << *it << endl;
		}
		first = deque<int>();
		cout << first.size() << endl;
		for (deque<int>::iterator it = first.begin(); it != first.end(); it++)
		{
			cout << *it << endl;
		}

		cout << "Size of first: " << int(first.size()) << '\n';
		cout << "Size of second: " << int(second.size()) << '\n';
	}

	{
		deque<int> mydeque(5); // 5 default-constructed ints

		deque<int>::reverse_iterator rit = mydeque.rbegin();

		int i = 0;
		for (rit = mydeque.rbegin(); rit != mydeque.rend(); ++rit)
			*rit = ++i;

		cout << "mydeque contains:";
		for (deque<int>::iterator it = mydeque.begin(); it != mydeque.end(); ++it)
			cout << ' ' << *it;
		cout << '\n';
	}

	{
		deque<int> mydeque(5); // 5 default-constructed ints

		deque<int>::reverse_iterator rit = mydeque.rbegin();

		int i = 0;
		for (rit = mydeque.rbegin(); rit != mydeque.rend(); ++rit)
			*rit = ++i;

		cout << "mydeque contains:";
		for (deque<int>::iterator it = mydeque.begin(); it != mydeque.end(); ++it)
			cout << ' ' << *it;
		cout << '\n';
	}

	{
		deque<int> mydeque(10);

		cout << mydeque.size() << endl;
		for (deque<int>::iterator it = mydeque.begin(); it != mydeque.end(); it++)
		{
			cout << *it << endl;
		}

		// erase the 6th element
		mydeque.erase(mydeque.begin() + 5);

		cout << mydeque.size() << endl;
		for (deque<int>::iterator it = mydeque.begin(); it != mydeque.end(); it++)
		{
			cout << *it << endl;
		}

		// erase the first 3 elements:
		mydeque.erase(mydeque.begin(), mydeque.begin() + 3);

		cout << mydeque.size() << endl;
		for (deque<int>::iterator it = mydeque.begin(); it != mydeque.end(); it++)
		{
			cout << *it << endl;
		}

		cout << "mydeque contains:";
		for (deque<int>::iterator it = mydeque.begin(); it != mydeque.end(); ++it)
			cout << ' ' << *it;
		cout << '\n';
	}

	// Test pop_front and pop_back
	{
		// Create deque using constructor with size and value
		deque<int> mydeque(5, 10); // 5 elements with value 10

		cout << "Initial deque size: " << mydeque.size() << endl;
		cout << "Initial deque contents:";
		for (deque<int>::iterator it = mydeque.begin(); it != mydeque.end(); ++it)
			cout << ' ' << *it;
		cout << '\n';

		// Test front() and back() before popping
		cout << "Front element: " << mydeque.front() << endl;
		cout << "Back element: " << mydeque.back() << endl;

		// Test pop_front
		mydeque.pop_front();
		cout << "After pop_front() - size: " << mydeque.size() << endl;
		if (!mydeque.empty())
			cout << "After pop_front() - front: " << mydeque.front() << endl;
		cout << "Contents:";
		for (deque<int>::iterator it = mydeque.begin(); it != mydeque.end(); ++it)
			cout << ' ' << *it;
		cout << '\n';

		// Test pop_back
		mydeque.pop_back();
		cout << "After pop_back() - size: " << mydeque.size() << endl;
		if (!mydeque.empty())
			cout << "After pop_back() - back: " << mydeque.back() << endl;
		cout << "Contents:";
		for (deque<int>::iterator it = mydeque.begin(); it != mydeque.end(); ++it)
			cout << ' ' << *it;
		cout << '\n';

		// Continue popping until only one element remains
		mydeque.pop_front();
		cout << "After second pop_front() - size: " << mydeque.size() << endl;
		cout << "Remaining elements:";
		for (deque<int>::iterator it = mydeque.begin(); it != mydeque.end(); ++it)
			cout << ' ' << *it;
		cout << '\n';

		mydeque.pop_back();
		cout << "After second pop_back() - size: " << mydeque.size() << endl;
		cout << "Remaining elements:";
		for (deque<int>::iterator it = mydeque.begin(); it != mydeque.end(); ++it)
			cout << ' ' << *it;
		cout << '\n';

		// Continue until deque is empty
		mydeque.pop_front();
		cout << "After final pop_front() - size: " << mydeque.size() << endl;
		cout << "Is deque empty? " << (mydeque.empty() ? "Yes" : "No") << endl;
	}

	{
		deque<int> mydeque(5);

		cout << mydeque.size() << endl;

		deque<int>::iterator it = mydeque.begin();
		++it;

		mydeque.insert(it, 3, 10);

		cout << mydeque.size() << endl;

		for (deque<int>::iterator it = mydeque.begin(); it != mydeque.end(); it++)
		{
			cout << *it << endl;
		}
	}

	{
		deque<int> mydeque(5);

		deque<int>::iterator it = mydeque.begin();
		++it;

		it = mydeque.insert(it, 10);

		cout << mydeque.size() << endl;

		for (deque<int>::iterator i = mydeque.begin(); i != mydeque.end(); i++)
		{
			cout << *i << endl;
		}

		cout << *it << endl;
	}

	{
		deque<int> mydeque(10);

		deque<int>::iterator it = mydeque.begin();
		++it;

		it = mydeque.insert(it, 10); // 0 10 0 0 0 0
									 // "it" now points to the newly inserted 10
		cout << "mydeque contains:";
		for (it = mydeque.begin(); it != mydeque.end(); ++it)
			cout << ' ' << *it;
		cout << '\n';
		mydeque.insert(it, 2, 20); // 0 20 20 10 0 0 0 0
								   // "it" no longer valid!
		cout << "mydeque contains:";
		for (it = mydeque.begin(); it != mydeque.end(); ++it)
			cout << ' ' << *it;
		cout << '\n';
		it = mydeque.begin() + 2;

		vector<int> myvector(2, 30);
		mydeque.insert(it, myvector.begin(), myvector.end());
		// // 0 20 30 30 20 10 0 0 0 0
		cout << "mydeque contains:";
		for (it = mydeque.begin(); it != mydeque.end(); ++it)
			cout << ' ' << *it;
		cout << '\n';
	}

	{
		deque<int> mydeque(2, 100); // two ints with a value of 100
		cout << "mydeque contains:";
		for (deque<int>::iterator it = mydeque.begin(); it != mydeque.end(); ++it)
			cout << ' ' << *it;
		cout << '\n';
		mydeque.push_front(200);
		cout << "mydeque contains:";
		for (deque<int>::iterator it = mydeque.begin(); it != mydeque.end(); ++it)
			cout << ' ' << *it;
		cout << '\n';
		mydeque.push_front(300);

		cout << "mydeque contains:";
		for (deque<int>::iterator it = mydeque.begin(); it != mydeque.end(); ++it)
			cout << ' ' << *it;
		cout << '\n';
	}

	{
		deque<int> mydeque(2, 100); // two ints with a value of 100
		cout << "mydeque contains:";
		for (deque<int>::iterator it = mydeque.begin(); it != mydeque.end(); ++it)
			cout << ' ' << *it;
		cout << '\n';
		mydeque.push_back(200);
		cout << "mydeque contains:";
		for (deque<int>::iterator it = mydeque.begin(); it != mydeque.end(); ++it)
			cout << ' ' << *it;
		cout << '\n';
		mydeque.push_back(300);

		cout << "mydeque contains:";
		for (deque<int>::iterator it = mydeque.begin(); it != mydeque.end(); ++it)
			cout << ' ' << *it;
		cout << '\n';
	}
}
