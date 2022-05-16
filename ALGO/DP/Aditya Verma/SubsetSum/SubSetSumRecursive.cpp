#include <bits/stdc++.h>
using namespace std;

bool subset(int set[],int N,int sum)
{
    if(sum==0 || N==0)
    {
        if(sum!=0)return 0;
        else return 1;
    }
    if(set[N-1]<=sum)
        return (subset(set,N-1,sum-set[N-1]) || subset(set,N-1,sum));
    else return subset(set,N-1,sum);
}
int main()
{
   int N = 6;
   int arr[N] = {3, 34, 4, 12, 5, 2};
    // int sum = 30;
   int sum=11;
   int verdict=subset(arr,N,sum);
   cout<<"Verdict:"<<verdict;
    return 0;
}