#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

void func(vector<int> m)
{
  cout<<"func was called";
}

int main()
{
int i = stoi("011101");
cout<<INT_MAX;
vector<int> v = {1,2,3};
string st = "Hello there";
for(char ch: st)
  cout<<ch<<endl;
string h = "hello";
string t = "there";
cout<<h+t;

func(new vector<int>(10,0));

return 0;
}
