#include "../main.hpp"

using __lib__::set;

bool fncomp(int lhs, int rhs)
{
  return lhs < rhs;
}

struct classcomp
{
  bool operator()(const int& lhs, const int& rhs) const
  {
    return lhs < rhs;
  }
};

void cplusplusexamples_set()
{
  // Test constructors
  {
    set<int> first; // empty set of ints

    int      myints[] = {10, 20, 30, 40, 50};
    set<int> second(myints, myints + 5); // range

    set<int> third(second); // a copy of second

    set<int> fourth(second.begin(), second.end()); // iterator ctor.

    set<int, classcomp> fifth; // class as Compare

    bool (*fn_pt)(int, int) = fncomp;
    set<int, bool (*)(int, int)> sixth(fn_pt);
  }

  {
    int      myints[] = {12, 82, 37, 64, 15};
    set<int> first(myints, myints + 5); // set with 5 ints
    set<int> second;                    // empty set

    second = first;     // now second contains the 5 ints
    first = set<int>(); // and first is empty

    cout << "Size of first: " << int(first.size()) << '\n';
    cout << "Size of second: " << int(second.size()) << '\n';
  }

  {
    int      myints[] = {75, 23, 65, 42, 13};
    set<int> myset(myints, myints + 5);

    cout << "myset contains:";
    for (set<int>::iterator it = myset.begin(); it != myset.end(); ++it)
      cout << ' ' << *it;

    cout << '\n';
  }

  {
    int      myints[] = {75, 23, 65, 42, 13};
    set<int> myset(myints, myints + 5);

    cout << "myset contains:";
    for (set<int>::iterator it = myset.begin(); it != myset.end(); ++it)
      cout << ' ' << *it;

    cout << '\n';
  }

  {
    int      myints[] = {21, 64, 17, 78, 49};
    set<int> myset(myints, myints + 5);

    cout << myset.size() << endl;

    set<int>::reverse_iterator rit;

    cout << "myset contains:";
    for (rit = myset.rbegin(); rit != myset.rend(); ++rit)
    {
      cout << ' ' << *rit;
    }

    cout << '\n';
  }

  {
    int      myints[] = {21, 64, 17, 78, 49};
    set<int> myset(myints, myints + 5);

    set<int>::reverse_iterator rit;

    cout << "myset contains:";
    for (rit = myset.rbegin(); rit != myset.rend(); ++rit)
      cout << ' ' << *rit;

    cout << '\n';
  }

  {
    set<int> myset;

    myset.insert(20);
    myset.insert(30);
    myset.insert(10);

    std::cout << "myset contains:";
    while (!myset.empty())
    {
      std::cout << ' ' << *myset.begin();
      myset.erase(myset.begin());
    }
    std::cout << '\n';
  }

  {
    set<int> myset;

    myset.insert(100);
    myset.insert(200);
    myset.insert(300);

    cout << "myset contains:";
    for (set<int>::iterator it = myset.begin(); it != myset.end(); ++it)
      cout << ' ' << *it;
    cout << '\n';

    myset.clear();
    myset.insert(1101);
    myset.insert(2202);

    cout << "myset contains:";
    for (set<int>::iterator it = myset.begin(); it != myset.end(); ++it)
      cout << ' ' << *it;
    cout << '\n';
  }

  {
    set<int>           myset;
    set<int>::iterator it;

    // set some initial values:
    for (int i = 1; i <= 5; i++)
      myset.insert(i * 10); // set: 10 20 30 40 50

    it = myset.find(20);
    myset.erase(it);
    myset.erase(myset.find(40));

    cout << "myset contains:";
    for (it = myset.begin(); it != myset.end(); ++it)
      cout << ' ' << *it;
    cout << '\n';
  }

  {
    set<int> myset;

    // set some initial values:
    for (int i = 1; i < 5; ++i)
      myset.insert(i * 3); // set: 3 6 9 12

    for (int i = 0; i < 10; ++i)
    {
      cout << i;
      if (myset.count(i) != 0)
        cout << " is an element of myset.\n";
      else
        cout << " is not an element of myset.\n";
    }
  }

  // {
  //   set<int>           myset;
  //   set<int>::iterator itlow, itup;
  //
  //   for (int i = 1; i < 10; i++)
  //     myset.insert(i * 10); // 10 20 30 40 50 60 70 80 90
  //
  //   itlow = myset.lower_bound(30); //       ^
  //   itup = myset.upper_bound(60);  //                   ^
  //
  //   myset.erase(itlow, itup); // 10 20 70 80 90
  //
  //   cout << "myset contains:";
  //   for (set<int>::iterator it = myset.begin(); it != myset.end(); ++it)
  //     cout << ' ' << *it;
  //   cout << '\n';
  // }

  {
    set<int> myints;
    cout << "0. size: " << myints.size() << '\n';

    for (int i = 0; i < 10; ++i)
      myints.insert(i);
    cout << "1. size: " << myints.size() << '\n';

    myints.insert(100);
    cout << "2. size: " << myints.size() << '\n';

    myints.erase(5);
    cout << "3. size: " << myints.size() << '\n';
  }

  // {
  //   set<int>                       myset;
  //   set<int>::iterator             it;
  //   pair<set<int>::iterator, bool> ret;
  //
  //   // set some initial values:
  //   for (int i = 1; i <= 5; ++i)
  //     myset.insert(i * 10); // set: 10 20 30 40 50
  //
  //   ret = myset.insert(20); // no new element inserted
  //
  //   if (ret.second == false)
  //     it = ret.first; // "it" now points to element 20
  //
  //   myset.insert(it, 25); // max efficiency inserting
  //   myset.insert(it, 24); // max efficiency inserting
  //   myset.insert(it, 26); // no max efficiency inserting
  //
  //   int myints[] = {5, 10, 15}; // 10 already in set, not inserted
  //   myset.insert(myints, myints + 3);
  //
  //   cout << "myset contains:";
  //   for (it = myset.begin(); it != myset.end(); ++it)
  //     cout << ' ' << *it;
  //   cout << '\n';
  // }

  // {
  //   set<int>           myset;
  //   set<int>::iterator it;
  //
  //   // insert some values:
  //   for (int i = 1; i < 10; i++)
  //     myset.insert(i * 10); // 10 20 30 40 50 60 70 80 90
  //
  //   it = myset.begin();
  //   ++it; // "it" points now to 20
  //
  //   myset.erase(it);
  //
  //   myset.erase(40);
  //
  //   it = myset.find(60);
  //   myset.erase(it, myset.end());
  //
  //   cout << "myset contains:";
  //   for (it = myset.begin(); it != myset.end(); ++it)
  //     cout << ' ' << *it;
  //   cout << '\n';
  // }
  // {
  //   int      myints[] = {12, 75, 10, 32, 20, 25};
  //   set<int> first(myints, myints + 3);      // 10,12,75
  //   set<int> second(myints + 3, myints + 6); // 20,25,32
  //
  //   first.swap(second);
  //
  //   cout << "first contains:";
  //   for (set<int>::iterator it = first.begin(); it != first.end(); ++it)
  //     cout << ' ' << *it;
  //   cout << '\n';
  //
  //   cout << "second contains:";
  //   for (set<int>::iterator it = second.begin(); it != second.end(); ++it)
  //     cout << ' ' << *it;
  //   cout << '\n';
  // }
  // {
  //   set<int> myset;
  //   int      highest;
  //
  //   set<int>::key_compare mycomp = myset.key_comp();
  //
  //   for (int i = 0; i <= 5; i++)
  //     myset.insert(i);
  //
  //   cout << "myset contains:";
  //
  //   highest = *myset.rbegin();
  //   set<int>::iterator it = myset.begin();
  //   do
  //   {
  //     cout << ' ' << *it;
  //   } while (mycomp(*(++it), highest));
  //
  //   cout << '\n';
  // }

  // {
  //   set<int> myset;
  //
  //   set<int>::value_compare mycomp = myset.value_comp();
  //
  //   for (int i = 0; i <= 5; i++)
  //     myset.insert(i);
  //
  //   cout << "myset contains:";
  //
  //   int                highest = *myset.rbegin();
  //   set<int>::iterator it = myset.begin();
  //   do
  //   {
  //     cout << ' ' << *it;
  //   } while (mycomp(*(++it), highest));
  //
  //   cout << '\n';
  // }

  // {
  //   set<int> myset;
  //
  //   for (int i = 1; i <= 5; i++)
  //     myset.insert(i * 10); // myset: 10 20 30 40 50
  //
  //   pair<set<int>::const_iterator, set<int>::const_iterator> ret;
  //   ret = myset.equal_range(30);
  //
  //   std::cout << "the lower bound points to: " << *ret.first << '\n';
  //   std::cout << "the upper bound points to: " << *ret.second << '\n';
  // }
}
