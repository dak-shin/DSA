#include<iostream>
#include<vector>
using namespace std;

void bin_rep(int n)
{
  std::vector<int> v;
  // if(n>1)
  //   bin_rep(n>>1);
  // cout<<(n&1);
  while(n>0)
  {
    v.push_back(n&1);
    n = n>>1;
  }

  for(int i = v.size()-1;i>=0;i--)
  {
    cout<<v[i];
  }
}

int main()
{
  int n;
  cout<<"Enter the number :";
  cin>>n;
  bin_rep(n);
}
