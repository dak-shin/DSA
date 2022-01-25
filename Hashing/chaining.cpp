// C++ program to demonstrate implementation of our
// own hash table with chaining for collision detection
#include<bits/stdc++.h>
using namespace std;

struct MyHash
{
    // list is a container in C++ STL for lined lists ( DLL )
    int BUCKET;
    list<int> *table; // table is a pointer of type linked list
    MyHash(int b)
    {
        BUCKET = b;
        table = new list<int>[BUCKET]; // creates an array of linked lists of size bucket
        // new list<int> creates a new linked list
        // [BUCKET] creates an array of that size
    }
    void insert(int k)
    {
        int i = k % BUCKET;
        table[i].push_back(k);
    }
    bool search(int k)
    {
        int i = k % BUCKET;
        for (auto x : table[i])
           if (x == k)
              return true;
        return false;
    }
    void remove(int k)
    {
        int i = k % BUCKET;
        table[i].remove(k);
    }
};

	// Driver method to test Map class
	int main()
	{
	    MyHash mh(7);
	    mh.insert(10);
	    mh.insert(20);
	    mh.insert(15);
	    mh.insert(7);
	    cout << mh.search(10) << endl;
	    mh.remove(15);
	    cout << mh.search(15);
	}
