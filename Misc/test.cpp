#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;
// while declaring a vector for a class
// we should declare it using the = sign or the {} like
// vector<int> arr = vector<int>(10,0); OR
// vecotr<int> arr{0,0,0,0,0,0,0};

void func(vector<int>* m)
{
  cout<<"func was called";
}

int main()
{

  // single digit int to string and vice versa
  char ch = 1+'0' // to convert int 1 to char 1
  int i = '1'-'0' // to convert char 1 to int 1

  // string to int
  string s = string(1,'1')+'2';
  int i = stoi(s);

int i = stoi("011101");
cout<<INT_MAX;
vector<int> v = {1,2,3};
char ch = 'a';
string st = "Hello there";
cout<<"This is the string with char "<<st<<endl;
for(char ch: st) // each character of a string is of character datatype and NOT string itself.
  cout<<ch;
string h = "hello";
string t = "there";
cout<<h+t;

func(new vector<int>); // returns a pointer ( new always returns a pointer )

return 0;
}
