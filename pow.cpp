#include<iostream>
#include<time.h>
using namespace std;

long long int pow( int x, int n)
{
  long long int temp=1;
  while(n>0)
  {
    if(n%2==1) { temp = temp*x; }
    x = x*x;
    n= n/2;
  }
  return temp;
}

int main()
{
  clock_t st, et;
  long long int x;
  x = pow(5,5);
  cout<<x<<endl;
  cout<<"Amount of time taken : "<<time_taken<<endl;
}
