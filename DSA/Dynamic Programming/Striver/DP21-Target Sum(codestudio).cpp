
//https://www.codingninjas.com/codestudio/problems/target-sum_4127362

//Target Sum(codestudio) give AC
//Using Bottom SPACE OPTIMIZED approach
//TC:n*target  SC:target
//using same code as DP18: https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628?leftPanelTab=1

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
			curr[target]=(pick+notpick);
		}
		prev=curr;
	}
	
	return prev[tar];
}


int targetSum(int n, int target, vector<int>& arr) 
{
	return countPartitions(n,target,arr);
}

////////////////////////////////////////////////////////////


//Target Sum(codestudio) give AC
//Using Bottom approach
//TC:n*target  SC:n*target
//using same code as DP18: https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628?leftPanelTab=1

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
			dp[i][target]=(pick+notpick);
		}
	}
	
	return dp[n-1][tar];
}


int targetSum(int n, int target, vector<int>& arr) 
{
	return countPartitions(n,target,arr);
}
