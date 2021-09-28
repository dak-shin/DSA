#include<iostream>
#include<string>
using namespace std;

int main()
{
  string st;
  cout<<"Enter the string"<<endl;
  cin>> st;

  int l=0, r=st.length()-1;

  while(l<r)
  {
    while(!isdigit(st[l])) l++;
    while(!isdigit(st[r])) r--;
    // cout<<l<<" "<<r;
    string r_ch(1,st[r]);
    string l_ch(1,st[l]);
    st.replace(l,1,r_ch);
    st.replace(r,1,l_ch);
    l++; r--;
  }
  cout<<st;



}
