//https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091?leftPanelTab=1

//Minimum Elements(codestudio) give AC
//Using Bottom up SPACE OPTIMIZED approach
//TC:n*T  SC:T

int minimumElements(vector<int> &num, int x)
{
	int n=num.size();
	vector<int> prev(x+1,0),curr(x+1,0);
	for(int t=0;t<=x;t++)
	{
			if(t%num[0]==0)prev[t]= t/num[0];
			else prev[t]=1e9;
	}
	for(int i=1;i<n;i++)
	{
		for(int t=0;t<=x;t++)
		{
			int notpick=prev[t];
			int pick=1e9;
			if(t>=num[i])
				pick=curr[t-num[i]]+1;
			curr[t]=min(pick,notpick);
		}
		prev=curr;
	}
	int ans=prev[x];
	if(ans>=1e9)return -1;
	return ans;
}

///////////////////////////////////////////////////////////////////////

//Minimum Elements(codestudio) give AC
//Using Bottom up approach
//TC:n*T  SC:n*T

int minimumElements(vector<int> &num, int x)
{
	int n=num.size();
	vector<vector<int>> dp(n,vector<int> (x+1,0));
	for(int t=0;t<=x;t++)
	{
			if(t%num[0]==0)dp[0][t]= t/num[0];
			else dp[0][t]=1e9;
	}
	for(int i=1;i<n;i++)
	{
		for(int t=0;t<=x;t++)
		{
			int notpick=dp[i-1][t];
			int pick=1e9;
			if(t>=num[i])
				pick=dp[i][t-num[i]]+1;
			dp[i][t]=min(pick,notpick);
		}
	}
	int ans=dp[n-1][x];
	if(ans>=1e9)return -1;
	return ans;
}


////////////////////////////////////////////////////////////////////

//Minimum Elements(codestudio) give AC
//Using Top Down approach
//TC:n*T  SC:n*T+T

int f(int i,int T,vector<int> &num,vector<vector<int>>& dp)
{
	if(i==0)
	{
		if(T%num[0]==0)return T/num[0];
		else return 1e9;
	}
	if(dp[i][T]!=-1)return dp[i][T];
	int notpick=f(i-1,T,num,dp);
	int pick=INT_MAX;
	if(T>=num[i])
		pick=f(i,T-num[i],num,dp)+1;
	return dp[i][T]=min(pick,notpick);
}

int minimumElements(vector<int> &num, int x)
{
	int n=num.size();
	vector<vector<int>> dp(n,vector<int> (x+1,-1));
	int ans=f(n-1,x,num,dp);
	if(ans>=1e9)return -1;
	return ans;
}

///////////////////////////////////////////////////////////

//Minimum Elements(codestudio) give TLE
//Using Recurion approach
//TC:2^n(more than this)  SC:n(more than this)

int f(int i,int T,vector<int> &num)
{
	if(i==0)
	{
		if(T%num[0]==0)return T/num[0];
		else return 1e9;
	}
	int notpick=f(i-1,T,num);
	int pick=INT_MAX;
	if(T>=num[i])
		pick=f(i,T-num[i],num)+1;
	return min(pick,notpick);
}

int minimumElements(vector<int> &num, int x)
{
	int n=num.size();
	int ans=f(n-1,x,num);
	if(ans>=1e9)return -1;
	return ans;
}