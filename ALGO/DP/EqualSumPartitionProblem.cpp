#include <bits/stdc++.h>
using namespace std;
//Partition Equal Subset Sum
//https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1
int main()
{

    int N = 4;
    int arr[N] = {1,5,11,5};


    int s=0;//total sum of array
        for(int i=0;i<N;i++)
        s+=arr[i];
        
        if(s%2!=0)//By common sense,we know in order to divide into equal sum,the total sum must be even number.
        {
          cout<<"equal subset sum partition is NOT POSSIBLE"<<endl;
          exit(0);
        }
        
        int hsum=s/2;//half of total sum
        
        //Now we use the same algorithm we used in subset sum problem.
        int dp[N+1][hsum+1];
        for(int j=0;j<=hsum;j++)
        dp[0][j]=0;
        
        for(int i=0;i<=N;i++)
        dp[i][0]=1;
        
        for(int i=1;i<=N;i++)
        for(int j=1;j<=hsum;j++)
        {
            if(arr[i-1]<=j)
            dp[i][j]=max(dp[i-1][j-arr[i-1]] , dp[i-1][j] );
            else dp[i][j]=dp[i-1][j];
        }
        
        if(dp[N][hsum]==1)
        {
           cout<<"equal subset sum partition is POSSIBLE"<<endl;
        }
    
      
    return 0;
}