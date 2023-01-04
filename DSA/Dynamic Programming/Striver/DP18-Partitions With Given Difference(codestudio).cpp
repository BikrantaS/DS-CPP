
//https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628?leftPanelTab=1

//Partitions with Given Difference(codestudio) gives AC
//Using Space Optimized approach
//TC:n*tar SC:tar 

int mod=(int)(1e9+7);
int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here
	int tot=0;
	for(int i=0;i<n;i++)
		tot+=arr[i];

	if((tot-d)%2 || tot-d<0)return 0;
	
	int tar=(tot-d)/2;
	vector<int> prev(tar+1,0),curr(tar+1,0);
	//base case fill:
	if(arr[0]==0)prev[0]=2;
	else prev[0]=1;
	if(arr[0]!=0 && arr[0]<=tar)prev[arr[0]]=1;
	
	for(int i=1;i<n;i++)
	{
		for(int target=0;target<=tar;target++)
		{
			int pick=0;
			if(target-arr[i]>=0)pick=prev[target-arr[i]];
			int notpick=prev[target];
			curr[target]=(pick+notpick)%mod;
		}
		prev=curr;
	}
	
	return prev[tar];
}


////////////////////////////////////////////////////////////////////////////////////

//Partitions With Given Difference(codestudio) gives AC
//Using Bottom UP approach
//TC:n*tar SC:n*tar 

int mod=(int)(1e9+7);
int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here
	int tot=0;
	for(int i=0;i<n;i++)
		tot+=arr[i];

	if((tot-d)%2 || tot-d<0)return 0;
	
	int tar=(tot-d)/2;
	vector<vector<int>> dp(n,vector<int> (tar+1,0));
	//base case fill:
	if(arr[0]==0)dp[0][0]=2;
	else dp[0][0]=1;
	if(arr[0]!=0 && arr[0]<=tar)dp[0][arr[0]]=1;
	
	for(int i=1;i<n;i++)
	{
		for(int target=0;target<=tar;target++)
		{
			int pick=0;
			if(target-arr[i]>=0)pick=dp[i-1][target-arr[i]];
			int notpick=dp[i-1][target];
			dp[i][target]=(pick+notpick)%mod;
		}
	}
	
	return dp[n-1][tar];
}


////////////////////////////////////////////////////////////////////////////////


//Partitions With Given Difference(codestudio) gives AC
//Using Top DOWN  approach
//TC:n*tar SC:n+ n*tar 

int mod=(int)(1e9+7);
int f(int i,int target,vector<int> &arr,vector<vector<int>>& dp)
{
	//Base case
	if(i==0)
	{
		if(target==0 && arr[0]==0)return 2;
		if(target==0 || target==arr[0])return 1;
		return 0;
	}
	if(dp[i][target]!=-1)return dp[i][target];
	int notpick=f(i-1,target,arr,dp);
	int pick=0;
	if(target-arr[i]>=0)
	pick=f(i-1,target-arr[i],arr,dp);
	return dp[i][target]=(pick+notpick)%mod;
}

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here
	int tot=0;
	for(int i=0;i<n;i++)
		tot+=arr[i];
	
	if((tot-d)%2 || tot-d<0)return 0;
	
	int target=(tot-d)/2;
	vector<vector<int>> dp(n,vector<int> (target+1,-1));
	return f(n-1,target,arr,dp);
}


////////////////////////////////////////////////////////////////////////


//Partitions With Given Difference(codestudio) gives TLE
//Using recursive  approach
//TC:2^n SC:n 


int mod=(int)(1e9+7);
int f(int i,int target,vector<int> &arr)
{
	//Base case
	if(i==0)
	{
		if(target==0 && arr[0]==0)return 2;
		if(target==0 || target==arr[0])return 1;
		return 0;
	}
	int notpick=f(i-1,target,arr);
	int pick=0;
	if(target-arr[i]>=0)
	pick=f(i-1,target-arr[i],arr);
	return (pick+notpick)%mod;
}

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here
	int tot=0;
	for(int i=0;i<n;i++)
		tot+=arr[i];
	
	if((tot-d)%2 || tot-d<0)return 0;
	return f(n-1,(tot-d)/2,arr);
}