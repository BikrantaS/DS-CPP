#include <bits/stdc++.h>
using namespace std;
//https://www.geeksforgeeks.org/subset-sum-problem-dp-25/
int main()
{
    int N = 6;
    int arr[N] = {3, 34, 4, 12, 5, 2};
    // int sum = 30;
    int sum=11;


    bool dp[N+1][sum+1];
    for(int i=0;i<=sum;i++)
      dp[0][i]=false;
    for(int j=0;j<=N;j++)
      dp[j][0]=true;

    for(int i=1;i<=N;i++)
      for(int j=1;j<=sum;j++)
      {
        if(arr[i-1]<=j)
          dp[i][j]=( (dp[i-1][j-arr[i-1]]) || (dp[i-1][j]) );
        else
          dp[i][j]=dp[i-1][j];
      }

      bool verdict=dp[N][sum];


   //If subset array can be formed for the sum
   //prints true else prints false
   cout<<"Verdict:"<<verdict;
   


    return 0;
}