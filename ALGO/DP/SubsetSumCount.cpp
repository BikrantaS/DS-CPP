#include <bits/stdc++.h>
using namespace std;
//https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1#
int main()
{
    int N = 6;
    int arr[N] =  {2, 3, 5, 6, 8, 10};
    // int sum = 30;
    int sum=10;


    int dp[N+1][sum+1];
    for(int i=0;i<=sum;i++)
      dp[0][i]=0;
    for(int j=0;j<=N;j++)
      dp[j][0]=1;

    for(int i=1;i<=N;i++)
      for(int j=1;j<=sum;j++)
      {
        if(arr[i-1]<=j)
          dp[i][j]=( (dp[i-1][j-arr[i-1]]) + (dp[i-1][j]) );
        else
          dp[i][j]=dp[i-1][j];
      }

     int total=dp[N][sum];


   //If subset array can be formed for the sum
   //prints number of subsets with given sum
   cout<<"Number of subsets:"<<total;
   


    return 0;
}