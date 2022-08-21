https://www.codingninjas.com/codestudio/problems/unbounded-knapsack_1215029?leftPanelTab=0

//Unbounded Knapsack(codestudio) give AC
//Using ULTRA SPACE OPTIMIZED approach
//TC:n*W SC:W(requires single prev array)
int unboundedKnapsack(int n, int W, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
	vector<int> prev(W+1,0);
	for(int w=0;w<=W;w++)
		prev[w]=((w/weight[0])*profit[0]);
	for(int i=1;i<n;i++)
	{
		for(int w=0;w<=W;w++)
		{
			long notpick=prev[w];
			long pick=INT_MIN;
			if(w>=weight[i])
				pick=prev[w-weight[i]]+profit[i];
			prev[w]=max(pick,notpick);
		}
	}
	return prev[W];
}



/////////////////////////////////////////////////////////


//Unbounded Knapsack(codestudio) give AC
//Using Bottom Up SPACE OPTIMIZED approach
//TC:n*W SC:W
int unboundedKnapsack(int n, int W, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
	vector<int> prev(W+1,0),curr(W+1,0);
	for(int w=0;w<=W;w++)
		prev[w]=((w/weight[0])*profit[0]);
	for(int i=1;i<n;i++)
	{
		for(int w=0;w<=W;w++)
		{
			long notpick=prev[w];
			long pick=INT_MIN;
			if(w>=weight[i])
				pick=curr[w-weight[i]]+profit[i];
			curr[w]=max(pick,notpick);
		}
		prev=curr;
	}
	return prev[W];
}

////////////////////////////////////////////////////////////////

//Unbounded Knapsack(codestudio) give AC
//Using Bottom Up approach
//TC:n*W  SC:n*W
int unboundedKnapsack(int n, int W, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
	vector<vector<int>> dp(n,vector<int> (W+1,-1));
	for(int w=0;w<=W;w++)
		dp[0][w]=((w/weight[0])*profit[0]);
	for(int i=1;i<n;i++)
	{
		for(int w=0;w<=W;w++)
		{
			long notpick=dp[i-1][w];
			long pick=INT_MIN;
			if(w>=weight[i])
				pick=dp[i][w-weight[i]]+profit[i];
			dp[i][w]=max(pick,notpick);
		}
	}
	return dp[n-1][W];
}


//////////////////////////////////////////////////////////////////////////////


//Unbounded Knapsack(codestudio) give AC
//Using Top Down approach
//TC:n*W  SC:n*W+W
int f(int i,int W,vector<int> &profit, vector<int> &weight,vector<vector<int>>& dp)
{
	if(i==0)
		return((W/weight[0])*profit[0]);
	if(dp[i][W]!=-1)return dp[i][W];
	int notpick=f(i-1,W,profit,weight,dp);
	int pick=INT_MIN;
	if(weight[i]<=W)
		pick=f(i,W-weight[i],profit,weight,dp)+profit[i];
	return dp[i][W]=max(pick,notpick);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
	vector<vector<int>> dp(n,vector<int> (w+1,-1));
	return f(n-1,w,profit,weight,dp);
}


////////////////////////////////////////////////////////////

//Unbounded Knapsack(codestudio) give TLE
//Using Recurion approach
//TC:2^n(more than this)  SC:n(more than this)
int f(int i,int W,vector<int> &profit, vector<int> &weight)
{
	if(i==0)
		return((W/weight[0])*profit[0]);
	int notpick=f(i-1,W,profit,weight);
	int pick=INT_MIN;
	if(weight[i]<=W)
		pick=f(i,W-weight[i],profit,weight)+profit[i];
	return max(pick,notpick);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
	return f(n-1,w,profit,weight);
}
