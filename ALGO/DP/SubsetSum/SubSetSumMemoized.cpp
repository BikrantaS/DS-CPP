#include <bits/stdc++.h>
using namespace std;

int memo[100][100];
bool subset(int set[],int N,int sum)
{
    if(sum==0 || N==0)
    {
        if(sum!=0)return 0;
        else return 1;
    }
    else if(memo[sum][N]==-1)
    {
      if(set[N-1]<=sum)
      {
          memo[sum][N]=(subset(set,N-1,sum-set[N-1]) || subset(set,N-1,sum));
          return memo[sum][N];
      }
      else 
        {
          memo[sum][N]=subset(set,N-1,sum);
          return memo[sum][N];
        }
    }

    else return memo[sum][N];
    
}
int main()
{
    int N = 6;
    int arr[N] = {3, 34, 4, 12, 5, 2};
    // int sum = 30;
    int sum=11;


   for(int i=0;i<=sum;i++)
    for(int j=0;j<=N;j++)
      memo[i][j]=-1;

   int verdict=subset(arr,N,sum);


   //If subset array can be formed for the sum
   //prints 1 else prints 0
   cout<<"Veridict:"<<verdict;
   


    return 0;
}