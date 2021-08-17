#include<iostream>
using namespace std;

void swap(int arr[], int m, int n)
{
  int temp = arr[m];
  arr[m] = arr[n];
  arr[n] = temp;
}

int lomuto_partition(int arr[],int l, int h)  // l and h are indicies
{
  int i=l-1;
  int pivot = arr[h];
  for(int j=0;j<=h;j++)
  {
    if(arr[j]<pivot)
    {
      i++;
      swap(arr,j,i);
    }
  }
  swap(arr,i+1,h);
  return i+1;
}

int hoare_partition(int arr[], int l, int h) // l and h are indicies
{
  int i=l-1,pivot=arr[l];
  int j=h+1;
  while(true)
  {
    do{i++;}while(arr[i]<pivot);
    do{j--;}while(arr[j]>pivot);
    if(i>=j) return j;
    swap(arr,i,j);
  }
}

int* quickSort(int arr[], int l, int h)  // l and h are min and max indicies
{
  if(l<h)
  {

    int p = hoare_partition(arr,l,h);
    quickSort(arr,l,p);
    quickSort(arr,p+1,h);

    // int p = lomuto_partition(arr,l,h);
    // quickSort(arr,l,p-1);
    // quickSort(arr,p+1,h);
  }
  return arr;
}

int main()
{
  int arr1[] = {10, 3, 4, 2, 234, 5, 44, 9};
  int arr2[] = {10, 3, 4, 2, 234, 5, 44, -9};

  int n = sizeof(arr1)/sizeof(arr1[0]);
  int op = hoare_partition(arr1,0,n-1);// pivot is the first element
  cout<<op<<endl;
  for(int i =0;i<n;i++)
  cout<<arr1[i]<<" ";

  op = lomuto_partition(arr2,0,n-1);// pivot is the last element
  cout<<"\n"<<op<<endl;
  for(int i =0;i<n;i++)
  cout<<arr2[i]<<" ";

  int arr3[] = {10, 3, 4, 2, 234, 5, 44, 9};
  int *arr4 = quickSort(arr3, 0, n-1); cout<<endl;
  for(int i =0;i<n;i++)
  cout<<arr3[i]<<" ";
}
