#include <bits/stdc++.h>
#include<queue>
using namespace std;

class MinHeap{
    int *arr;
    int size;
    int capacity;

    public:
        /*
        insert
        minHeapify
        maxheapify
        extractMin
        decreaseKey
        deleteKey
        buildHeap
        heapSort
        */
    MinHeap(int c){
    size = 0;
    capacity = c;
    arr = new int[c];
    }

    int left(int i) { return (2*i + 1); }
    int right(int i) { return (2*i + 2); }
    int parent(int i) { return (i-1)/2; }

    void buildHeap(){
        for(int i=(size-2)/2;i>=0;i--)
            minHeapify(i);
    }

    void heapSort(int arr[], int n)
{
	buildheap(arr,n);

	for (int i=n-1; i>0; i--)
	{
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

    void deleteKey(int i)
    {
        decreaseKey(i, INT_MIN);
        extractMin();
    }

    void insert(int x)
    {
    if (size == capacity)return;
    size++;
    arr[size-1]=x;

    for (int i=size-1;i!=0 && arr[parent(i)]>arr[i];)
    {
       swap(arr[i], arr[parent(i)]);
       i = parent(i);
    }
    }

    void minHeapify(int i)
    {
    int lt = left(i);
    int rt = right(i);
    int smallest = i;
    if (lt < size && arr[lt] < arr[i])
        smallest = lt;
    if (rt < size && arr[rt] < arr[smallest])
        smallest = rt;
    if (smallest != i)
    {
        swap(arr[i],arr[smallest]);
        minHeapify(smallest);
    }
    }

    void maxheapify(int arr[], int n, int i)
{
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;
	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

    int extractMin()
    {
    if (size <= 0)
        return INT_MAX;
    if (size == 1)
    {
        size--;
        return arr[0];
    }
    swap(arr[0],arr[size-1]);
    size--;
    minHeapify(0);

    return arr[size];
    }

    void decreaseKey(int i, int x)
    {
    arr[i] = x;
    while (i != 0 && arr[parent(i)] > arr[i])
    {
       swap(arr[i], arr[parent(i)]);
       i = parent(i);
    }
    }
};

void firstKLargestElements(int arr[], int n, int k)
{

	priority_queue <int,vector<int>,greater<int>> minHeap;
	for(int i = 0; i < k; i++)
	{
		minHeap.push(arr[i]);
	}
	for(int i = k; i < n; i++)
	{
		if (minHeap.top() > arr[i])
			continue;
		else
		{
			minHeap.pop();
			minHeap.push(arr[i]);
		}
	}

	while(minHeap.empty()==false){
	    cout<<minHeap.top()<<" ";
	    minHeap.pop();
	}
}

int sortK(int arr[], int n, int k)
{
	priority_queue<int, vector<int>, greater<int> > pq;

    for(int i=0;i<=k;i++)
        pq.push(arr[i]);

	int index = 0;
	for (int i = k + 1; i < n; i++) {
		arr[index++] = pq.top();
		pq.pop();
		pq.push(arr[i]);
	}

	while (pq.empty() == false) {
		arr[index++] = pq.top();
		pq.pop();
	}
}

void printKClosest(int arr[], int n, int k, int x)
{
     priority_queue<pair<int, int> > pq;
    for (int i = 0; i < k; i++)
        pq.push({ abs(arr[i] - x), i });

    for (int i = k; i < n; i++) {
        int diff = abs(arr[i] - x);
        if ( pq.top().first>diff ){
        pq.pop();
        pq.push({ diff, i });
        }
    }

    while (pq.empty() == false) {
        cout << arr[pq.top().second] << " ";
        pq.pop();
    }
}

int main()
{
    MinHeap h(11);
    h.insert(3);
    h.insert(2);
    h.insert(15);
    h.insert(20);
    cout << h.extractMin() << " ";

    int k = 3;
	int arr[] = { 2, 6, 3, 12, 56, 8 };
	int n = sizeof(arr) / sizeof(arr[0]);
	sortK(arr, n, k);

	cout << "Following is sorted array" << endl;
	printArray(arr, n);

    return 0;
}
