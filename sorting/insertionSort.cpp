#include<iostream>
using namespace std;

int main()
{
  int arr[] = {10, 3, 4, 2, 234, 5, 44, -9};
  int n = sizeof(arr)/sizeof(arr[0]),key;

  for(int i=1 ;i<n;i++)
  {
    key=arr[i];
    int j;
    for(j =i-1; j>=0 && arr[j]>key; j--)
    {
      arr[j+1] = arr[j];
    }
    arr[j+1]=key;
    for(int i= 0; i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
  }

}
