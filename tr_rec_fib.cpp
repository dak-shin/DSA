#include <iostream>
#include <vector>
using namespace std;
//  Count the number of unique BSTs that can be generated given n keys
int f(int n)
{
    // cout<<"Computing BST for "<<n<<endl;
    if(n==0) return 1;
    if(n<=2) return n;
    int res = 0;
    for(int i =0;i<n;i++)
    {
      // cout<<"Calling for "<<i<<" and "<<n-i-1<<endl;
      res = res + f(i) * f(n-i-1);
    }
    return res;
}

int fRec(int n) // Recursive solution not working
{
    int dp[n+1];
    // cout<<"Computing BST for "<<n<<endl;
    int res=0;
    dp[0] = 1;
    for(int i =0;i<n;i++)
    {
      // cout<<"Calling for "<<i<<" and "<<n-i-1<<endl;
      res = res + f(i) * f(n-i-1);
    }
    return res;
}

int main()
{
    int n;
    cout << "Enter a number : ";
    cin >> n;
    cout<<f(n);
    return 0;
}
