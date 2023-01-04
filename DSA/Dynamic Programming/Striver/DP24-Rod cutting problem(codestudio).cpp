https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284


//Rod cutting problem(codestudio) give AC
//Using Bottom UP [ULTRA] SPACE OPTIMIZED approach
//TC:n*N SC:N

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<int> prev(n+1,0);
	
	//base case fill
	for(int N=0;N<=n;N++)
		prev[N]=N*price[0];
	
	for(int i=1;i<n;i++)
	{
		for(int N=0;N<=n;N++)
		{
		int rodLength=i+1;
		int notpick=prev[N];
		int pick=INT_MIN;
		if(rodLength<=N)
		pick=prev[N-rodLength]+price[i];
		prev[N]=max(pick,notpick);
		}
	}

	return prev[n];
}



///////////////////////////////////////////////////////////////////////

//Rod cutting problem(codestudio) give AC
//Using Bottom UP SPACE OPTIMIZED approach
//TC:n*N SC:N

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<int> prev(n+1,0),curr(n+1,0);
	
	//base case fill
	for(int N=0;N<=n;N++)
		prev[N]=N*price[0];
	
	for(int i=1;i<n;i++)
	{
		for(int N=0;N<=n;N++)
		{
		int rodLength=i+1;
		int notpick=prev[N];
		int pick=INT_MIN;
		if(rodLength<=N)
		pick=curr[N-rodLength]+price[i];
		curr[N]=max(pick,notpick);
		}
		prev=curr;
	}

	return prev[n];
}



////////////////////////////////////////////////////////////////////////////

//Rod cutting problem(codestudio) give AC
//Using Bottom UP approach
//TC:n*N SC:n*N

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<vector<int>> dp(n,vector<int> (n+1,0));
	
	//base case fill
	for(int N=0;N<=n;N++)
		dp[0][N]=N*price[0];
	
	for(int i=1;i<n;i++)
	{
		for(int N=0;N<=n;N++)
		{
		int rodLength=i+1;
		int notpick=dp[i-1][N];
		int pick=INT_MIN;
		if(rodLength<=N)
		pick=dp[i][N-rodLength]+price[i];
		dp[i][N]=max(pick,notpick);
		}
	}
	
	return dp[n-1][n];
}




/////////////////////////////////////////////////////////////////////////

//Rod cutting problem(codestudio) give AC
//Using Top Down approach
//TC:n*N SC:n*N+N

int f(int i,int N,vector<int> &price,vector<vector<int>>& dp)
{
	if(i==0)
		return N*price[0];//last to pick value is 1, so we need total 1*n*price
	if(dp[i][N]!=-1)return dp[i][N];
	int rodLength=i+1;
	int notpick=f(i-1,N,price,dp);
	int pick=INT_MIN;
	if(rodLength<=N)
	pick=f(i,N-rodLength,price,dp)+price[i];
	return dp[i][N]=max(pick,notpick);
	
}

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<vector<int>> dp(n,vector<int> (n+1,-1));
	return f(n-1,n,price,dp);
}



//////////////////////////////////////////////////////////////////////////

//Rod cutting problem(codestudio) give TLE
//Using Recurion approach
//TC:2^n(more than this)  SC:n(more than this)

int f(int i,int N,vector<int> &price)
{
	if(i==0)
		return N*price[0];//last to pick value is 1, so we need total 1*n*price
	
	int rodLength=i+1;
	int notpick=f(i-1,N,price);
	int pick=INT_MIN;
	if(rodLength<=N)
	pick=f(i,N-rodLength,price)+price[i];
	return max(pick,notpick);
	
}

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	return f(n-1,n,price);
}
