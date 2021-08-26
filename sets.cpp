#include <iostream>
#include <set>
using namespace std;


int main() {
  // Insert, begin and end
	set<int> s;
	s.insert(10);
	s.insert(5);
	s.insert(20);
	for (int x : s) {
	    cout<<x<<" ";
	}cout<<endl;

	set<int,greater<int>> s1;//Decreasing order
	s1.insert(10);
	s1.insert(5);
	s1.insert(20);
	for (auto it=s1.begin();it!=s1.end();it++) {
	    cout<<(*it)<<" ";
	}cout<<endl;

// Insert, rbegin and rend
set<int,greater<int>> s;//Decreasing order
s.insert(10);
s.insert(5);
s.insert(20);
for (auto it=s.rbegin();it!=s.rend();it++) {
    cout<<(*it)<<" ";
}cout<<endl;

auto it=s.find(10);
if(it==s.end())
    cout<<"Not found"<<endl;
else
    cout<<"Found"<<endl;
s.clear();
cout<<"Size: "<<s.size()<<endl;

// Count and erase
set<int> s;
	s.insert(10);
	s.insert(5);
	s.insert(20);
	s.insert(7);

	if(s.count(10))
	    cout<<"Found"<<endl;
	else
	    cout<<"Not Found"<<endl;

	s.erase(5);
	for(int x: s){
	    cout<<x<<" ";
	}cout<<endl;

	auto it=s.find(7);
	s.erase(it);
	for(int x: s){
	    cout<<x<<" ";
	}cout<<endl;

  // upper_bound and lower_bound
  set<int> s;
  	s.insert(10);
  	s.insert(5);
  	s.insert(20);

  	auto it=s.lower_bound(5);
  	if(it!=s.end())
  	    cout<<(*it)<<endl;
  	else
  	    cout<<"Given element is greater than the largest"<<endl;

  	it=s.upper_bound(5);
  	if(it!=s.end())
  	    cout<<(*it)<<endl;
  	else
  	    cout<<"Given element is greater than the largest"<<endl;


return 0;

}
