#include <iostream>
using namespace std;

int knapsack(int wt[],int val[],int N,int W)
{
  //if the knapsack capacity 'W' becomes 0
  //OR the last value is reached while traversing
  //return base case as 0
  if(W==0 || N==0)return 0;


  //If and only if the current wheight 'wt[N-1]' is less than the current capacity 'W'
  //then only return max of whether taking element is profitable or not taking is profitable
  if(wt[N-1]<=W)
    return max(val[N-1]+knapsack(wt,val,N-1,W-wt[N-1]),knapsack(wt,val,N-1,W));
  else 
    return knapsack(wt,val,N-1,W);//if current weight is higher thank knapsack, go to next value.
}

int main() {
    int n=5;
    int wt[n]={1,2,3,5,7};
    int val[n]={2,3,4,6,8};

  int weight=7;
  int ks=knapsack(wt,val,n,weight);
  cout<<"Max Value for Knapsack of weight "<<weight<<" is :"<<ks;

 return 0;
}