// #include<iostream>
// #include "chains.h"
// using namespace std;

// int hashh(int key)
// {
//     return key%10;
// }

// void Insert(node*H[],int key)
// {
//     int index=hashh(key);
//     linsert(H[index],key);
// }

// int main()
// {
//     node * HT[10];
//     for(int i=0;i<10;i++)
//     {
//         HT[i]=NULL;
//     }
//     Insert(HT,12);
//     Insert(HT,22);
//     Insert(HT,42);

//     node* temp;
//     cout<<isearch(HT[hashh(22)],22);
// }

// C++ program to demonstrate implementation of our 
// own hash table with chaining for collision detection 
// using list
#include<bits/stdc++.h>
using namespace std;

struct MyHash
{
    int BUCKET;
    list<int> *table;//=new list<int>[BUCKET];
    MyHash(int b)
    {
        BUCKET = b;
        table = new list<int>[BUCKET];
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


// using vector

// #include<bits/stdc++.h>
// using namespace std;

// class myhash
// {
//     public:
//     int bucket;
//     vector<int>v;
//     myhash(int b)
//     {
//         bucket=b;
//     }

//     void insert(int key)
//     {
//         int i=key%bucket;
//         v.push_back(key);
//     }

//     bool search(int key)
//     {
//         int i=key%bucket;
//         for(auto x:v)
//         {
//             if(x==key)
//                 return true;
//         }
//         return false;
//     }

//     void remove(int key)
//     {
//         int i=key%bucket;
//         v.pop_back();
//     }
// };


// int main()
// {
//     myhash t(6);
//     t.insert(70);
//     t.insert(71);
//     t.insert(9);
//     t.insert(72);
//     t.insert(56);
//     cout<<t.search(56);
// }
