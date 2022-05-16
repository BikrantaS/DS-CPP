//https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=0


//Subset Sum Equal To K(codestudio) gives AC
//Using Bottom Up SPACE OPTIMIZED  approach
//TC:n*target SC:target (dp array )

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
	vector<bool> prev(k+1,0);
	//BASE CASE FILL
	prev[0]=true;
	if(arr[0]<=k)prev[arr[0]]=true;
	
	for(int i=1;i<n;i++)
	{
		vector<bool>curr(k+1,0);
		for(int target=0;target<=k;target++)
		{
			bool notpick=prev[target];
			bool pick=false;
			if(target-arr[i]>=0)
			pick=prev[target-arr[i]];
			curr[target]=(pick || notpick);
		}
		prev=curr;
	}
	return prev[k];
}


//////////////////////////////////////////////////////////////

//Subset Sum Equal To K(codestudio) gives AC
//Using Bottom Up  approach
//TC:n*target SC:n*target (dp array )

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
	vector<vector<bool>> dp(n,vector<bool>(k+1,0));
	
	//BASE CASE FILL
	for(int i=0;i<n;i++)
		dp[i][0]=true;
	dp[0][arr[0]]=true;
	
	for(int i=1;i<n;i++)
	{
		for(int target=0;target<=k;target++)
		{
			bool notpick=dp[i-1][target];
			bool pick=false;
			if(target-arr[i]>=0)
			pick=dp[i-1][target-arr[i]];
			dp[i][target]=(pick || notpick);
		}
	}

	return dp[n-1][k];
}

///////////////////////////////////////////////////////////////////////////////

//Subset Sum Equal To K(codestudio) gives AC
//Using Top Down approach
//TC:n*target SC:n*target+n (dp array + recursion stack space)

bool f(int i,vector<int> &arr,int target,vector<vector<int>>& dp)
{
	if(target==0)return true;
	if(i==0)return (arr[i]==target);
	if(dp[i][target]!=-1)return dp[i][target];
	bool notpick=f(i-1,arr,target,dp);
	bool pick=false;
	if(target-arr[i]>=0)
	pick=f(i-1,arr,target-arr[i],dp);
	return dp[i][target]=(pick || notpick);
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
	vector<vector<int>> dp(n,vector<int>(k+1,-1));
	return f(n-1,arr,k,dp);
}



//////////////////////////////////////////////////////////////////

//Subset Sum Equal To K(codestudio) gives TLE
//Using Recursion approach
//TC:2^n SC:n (aux stack space)

bool f(int i,vector<int> &arr,int target)
{
	if(target==0)return true;
	if(i==0)return (arr[i]==target);
	bool notpick=f(i-1,arr,target);
	bool pick=false;
	if(target-arr[i]>=0)
	pick=f(i-1,arr,target-arr[i]);
	return (pick || notpick);
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
	
	return f(n-1,arr,k);
}