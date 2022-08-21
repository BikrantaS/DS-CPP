
https://www.codingninjas.com/codestudio/problems/ways-to-make-coin-change_630471?leftPanelTab=1

//Ways To Make Coin Change(codestudio) give AC
//Using Space Optimaizaton approach
//TC:n*T  SC:T
#include<vector>
long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
	vector<long> prev(value+1,0),curr(value+1,0);
	//Base case fill
	for(int t=0;t<=value;t++)
		prev[t]=t%denominations[0]==0;
	
	for(int i=1;i<n;i++)
	{
		for(int t=0;t<=value;t++)
		{
			long notpick=prev[t];
			long pick=0;
			if(t>=denominations[i])
				pick=curr[t-denominations[i]];
			curr[t]=pick+notpick;
		}
		prev=curr;
	}
	
	return prev[value];
}


////////////////////////////////////////////////////////////

//Ways To Make Coin Change(codestudio) give AC
//Using Bottom UP approach
//TC:n*T  SC:n*T
#include<vector>
long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
	vector<vector<long>> dp(n,vector<long> (value+1,0));
	//Base case fill
	for(int t=0;t<=value;t++)
		dp[0][t]=t%denominations[0]==0;
	
	for(int i=1;i<n;i++)
	{
		for(int t=0;t<=value;t++)
		{
			long notpick=dp[i-1][t];
			long pick=0;
			if(t>=denominations[i])
				pick=dp[i][t-denominations[i]];
			dp[i][t]=pick+notpick;
		}
	}
	
	return dp[n-1][value];
}


////////////////////////////////////////////////////////////////////////


//Ways To Make Coin Change(codestudio) give AC
//Using Top Down approach
//TC:n*T  SC:n*T+T
#include<vector>
long f(int i,int target,int *denominations,vector<vector<long>>& dp)
{
	//Base Case
	if(i==0)
		return (target%denominations[i]==0);
	if(dp[i][target]!=-1)return dp[i][target];
	long notpick=f(i-1,target,denominations,dp);
	long pick=0;
	if(denominations[i]<=target)
		pick=f(i,target-denominations[i],denominations,dp);
	return dp[i][target]=pick+notpick;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
	vector<vector<long>> dp(n,vector<long> (value+1,-1));
	return f(n-1,value,denominations,dp);
}


/////////////////////////////////////////////////////

//Ways To Make Coin Change(codestudio) give TLE
//Using Recurion approach
//TC:2^n(more than this)  SC:n(more than this)

long f(int i,int target,int *denominations)
{
	//Base Case
	if(i==0)
		return (target%denominations[i]==0);
	long notpick=f(i-1,target,denominations);
	long pick=0;
	if(denominations[i]<=target)
		pick=f(i,target-denominations[i],denominations);
	return pick+notpick;
}


long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
	return f(n-1,value,denominations);
}