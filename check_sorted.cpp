#include<stdio.h>
#include<iostream>
using namespace std;

void swap(int arr[], int m, int n)
{
  int temp = arr[m];
  arr[m] = arr[n];
  arr[n] = temp;
}

int lomuto_partition(int arr[],int l, int h, int div)  // l and h are indicies
{
  int i=l-1;
  int pivot = arr[h];
  for(int j=0;j<=h;j++)
  {
    if(arr[j]==div)
    {
      i++;
      swap(arr,j,i);
    }
  }
  swap(arr,i+1,h);
  return i+1;
}

int main()
{
  

  int arr[] = {0,1,1,1,0,1,1,2,2,2,2,0,1,2};
  int n = sizeof(arr)/sizeof(arr[0]);
  int z = lomuto_partition(arr,0,n-1,0);
  lomuto_partition(arr,z,n-1,1);

  for(int i =0;i<n;i++)
  cout<<arr[i]<<" ";
}
