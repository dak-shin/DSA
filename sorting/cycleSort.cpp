#include<iostream>
using namespace std;
// Wrong implementation
void swap(int arr[], int m, int n)
{
  int temp = arr[m];
  arr[m] = arr[n];
  arr[n] = temp;
}

int main()
{
  int arr[] = {22,45,1,-1,3,54,-69,0};
  int n = sizeof(arr)/sizeof(arr[0]);
  for(int i=0; i<n;i++)
  {
    int count=0;
    for(int j=0;j<n;j++)
    {
      if(arr[j]<arr[i] && i!=j) count++;
    }
    swap(arr, count,i);
    for(int i =0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
    cout<<count<<" "<<i<<endl;

  }

  for(int i =0;i<n;i++)
  cout<<arr[i]<<" ";
}
