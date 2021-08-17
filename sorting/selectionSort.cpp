#include <iostream>

using namespace std;
void swap(int arr[], int m, int n)
{
  int temp = arr[m];
  arr[m] = arr[n];
  arr[n] = temp;

}

int main()
{
    int arr[] = {10, 3, 4, 2, 234, 5, 44, -9};
    int n = sizeof(arr)/sizeof(arr[0]),min;
    for(int i =0 ;i<n-1; i++)
    {
      min=i;
      for(int j=i+1; j<n;j++)
      {
        if(arr[j]<arr[min])
          min = j;
      }
      swap(arr,min, i);
      for(int i= 0; i<n;i++)
      cout<<arr[i]<<" ";
      cout<<endl;
    }
}
