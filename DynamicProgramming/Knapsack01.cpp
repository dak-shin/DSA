#include<iostream>
using namespace std;

int ks(int w, int wt[], int val[], int n)
{
  int dp[n+1][w+1];

  for(int i=0;i<=n;i++) dp[i][0] = 0;
  for(int j=0;j<=w;j++) dp[0][j] = 0;

  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=w;j++)
    {
      if(wt[i-1]>j)
        dp[i][j] = dp[i-1][j];
      else
        dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
    }
  }
  return dp[n][w];
}

int ksRec(int w, int wt[], int val[], int n)
{

  if(n==0 || w==0) return 0;

  if(wt[n-1]>w)
    return ks(w,wt,val,n-1);
  else
    return max(ks(w,wt,val,n-1), val[n-1]+ks(w-wt[n-1],wt,val,n-1));

}


int main()
{
  int val[] = { 10, 40, 30, 50 };
  int wt[] = { 5, 4, 6, 3 };
  int W = 10;
  int n = 4;
  cout<<ks(W, wt, val, n)<<"\n"<<ksRec(W, wt, val, n);

}
