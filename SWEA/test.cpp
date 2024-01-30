#include <iostream>
#include <queue>
#include <cstdio>
#include <functional>
using namespace std;

int mycomp[10] = {11,2,3,4,5,6,7,8,9,10};
struct comp {
    bool operator() (const int &a, const int &b) {
        //cout << "a :"<< a<<", comp[a] :"<<mycomp[a] <<", b:" <<b<<", mycomp[b]:"<<mycomp[b]<<endl;
        if(mycomp[a] == mycomp[b]) {
            return mycomp[a] > mycomp[b];
        } else return mycomp[a] > mycomp[b];
    }
};
int main()
{
    // priority_queue container declaration
    priority_queue<int, vector<int>, comp > mypqueue1;
    priority_queue<int, vector<int>, comp > mypqueue2;
 
    // pushing elements into the 1st priority queue
    mypqueue1.push(5);
    mypqueue1.push(4);
    mypqueue1.push(3);
    mypqueue1.push(2);
    mypqueue1.push(0);
   
    // pushing elements into the 2nd priority queue
    mypqueue2.push(3);
    mypqueue2.push(5);
    mypqueue2.push(7);
    mypqueue2.push(9);
    mypqueue2.push(8);
 
    // using swap() function to swap elements of priority queues
    mypqueue1.swap(mypqueue2);


    // printing the first priority queue
      cout<<"mypqueue1 = ";
    while (!mypqueue1.empty()) {
        cout<<mypqueue1.top() << " ";
        mypqueue1.pop();
    }
 
    // printing the second priority queue
      cout<<endl<<"mypqueue2 = ";
    while (!mypqueue2.empty()) {
        cout<<mypqueue2.top() << " ";
        mypqueue2.pop();
    }
    cout << endl;
    return 0;
}