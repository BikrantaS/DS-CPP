#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N=5;
    int wt[N]={1,2,3,5,7};
    int val[N]={2,3,4,6,8};
    int W=7;
    int dp[N+1][W+1];

  for(int i=0;i<=N;i++)
    dp[i][0]=0;

  for(int j=0;j<=W;j++)
    dp[0][j]=0;

  for(int i=1;i<=N;i++)
  {
    for(int j=1;j<=W;j++)
    {
      if(wt[i-1]<=j)
      {
        dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
      }
      else dp[i][j]=dp[i-1][j];
    }
  }

  int ks=dp[N][W];
  cout<<"Max Value for Knapsack of weight "<<W<<" is :"<<ks;

 return 0;
}