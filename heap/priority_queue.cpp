#include <iostream>
#include<queue>
using namespace std;



int main(){
    // implemented using min heap explicitly
    priority_queue <int,vector<int>,greater<int>> pq;
    pq.push(10);
    pq.push(15);
    pq.push(5);
    cout<<pq.size()<<" ";
    cout<<pq.top()<<" ";
    while(pq.empty()==false){
        cout<<pq.top()<<" ";
        pq.pop();
    }

    // implemented using max heap by default
    priority_queue <int> pq;
    pq.push(10);
    pq.push(15);
    pq.push(5);
    cout<<pq.size()<<" ";
    cout<<pq.top()<<" ";
    while(pq.empty()==false){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    int k = 3;
  	int arr[] = { 2, 6, 3, 12, 56, 8 };
  	int n = sizeof(arr) / sizeof(arr[0]);
  	sortK(arr, n, k);

  	cout << "Following is sorted array" << endl;
  	printArray(arr, n);

    return 0;
}
