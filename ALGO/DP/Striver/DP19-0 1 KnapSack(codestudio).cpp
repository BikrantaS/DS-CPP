
//https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542

//0 1 Knapsack(codestudio) give AC
//Using Bottom Up SPACE OPTIMIZED approach
//TC:nw  SC:w

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<int> prev(maxWeight+1,0),curr(maxWeight+1,0);
	
	//Base case fill
	for(int w=0;w<maxWeight+1;w++)
		if(weight[0]<=w)prev[w]=value[0];
	
// 	can also write:
// 	for(int w=weight[0];w<maxWeight+1;w++)
// 		dp[0][w]=value[0];
	
	for(int i=1;i<n;i++)
	{
		for(int w=0;w<=maxWeight;w++)
		{
		int notpick=prev[w];
		int pick=INT_MIN;
		if(w-weight[i]>=0)
			pick=prev[w-weight[i]]+value[i];
		curr[w]= max(pick,notpick);
		}
		prev=curr;
	}
	return prev[maxWeight];
}

//////////////////////////////////////////////////////////////////////////////


//0 1 Knapsack(codestudio) give AC
//Using Bottom Up approach
//TC:nw  SC:nw

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n,vector<int> (maxWeight+1,0));
	
	//Base case fill
	for(int w=0;w<maxWeight+1;w++)
		if(weight[0]<=w)dp[0][w]=value[0];
	
// 	can also write:
// 	for(int w=weight[0];w<maxWeight+1;w++)
// 		dp[0][w]=value[0];
	
	for(int i=1;i<n;i++)
	{
		for(int w=0;w<=maxWeight;w++)
		{
		int notpick=dp[i-1][w];
		int pick=INT_MIN;
		if(w-weight[i]>=0)
			pick=dp[i-1][w-weight[i]]+value[i];
		dp[i][w]= max(pick,notpick);
		}
	}
	return dp[n-1][maxWeight];
}


//////////////////////////////////////////////////////////////////////////////

//0 1 Knapsack(codestudio) give AC
//Using Top DOWN approach
//TC:nw  SC:nw+n

int f(int i,int W,vector<int>& weight, vector<int>& value,vector<vector<int>>& dp)
{
	if(i==0)
	{
		if(weight[0]<=W)return value[0];
		else return 0;
	}
	if(dp[i][W]!=-1)return dp[i][W];
	int notpick=f(i-1,W,weight,value,dp);
	int pick=INT_MIN;
	if(W-weight[i]>=0)
		pick=f(i-1,W-weight[i],weight,value,dp)+value[i];
	return dp[i][W]= max(pick,notpick);
}


int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n,vector<int> (maxWeight+1,-1));
	return f(n-1,maxWeight,weight,value,dp);
}


////////////////////////////////////////////////////////////////////////////////

//0 1 Knapsack(codestudio) give TLE
//Using Recurion approach
//TC:2^n  SC:n

int f(int i,int W,vector<int>& weight, vector<int>& value)
{
	if(i==0)
	{
		if(weight[0]<=W)return value[0];
		else return 0;
	}
	int notpick=f(i-1,W,weight,value);
	int pick=INT_MIN;
	if(W-weight[i]>=0)
		pick=f(i-1,W-weight[i],weight,value)+value[i];
	return max(pick,notpick);
}


int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	return f(n-1,maxWeight,weight,value);
}