#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
  int sum = 57;
  int arr[] = {12,3,45,5,67,7,34,31,1,2,4};
  sort(arr,arr+11);
  int l=0,h=10;
  bool res=false;
  for(int i =0 ; i<11;i++)
  {
    cout<<arr[l]<<"-"<<arr[h]<<endl;
    if(l==h || arr[l]+arr[h]==sum )
    {res = true;break;}
    else if(arr[l]+arr[h]>sum )
    h--;
    else l++;
  }
  cout<<arr[l]<<" and "<<arr[h]<<" are the results";

}
