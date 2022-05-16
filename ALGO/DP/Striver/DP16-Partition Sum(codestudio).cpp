//https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494?leftPanelTab=0


//Partition a set into two subsets such that the difference of subset sums is minimum.(codestudio) gives AC
//Using Bottom Up SPACE OPTIMIZED approach
//TC:(target)+totalsum/2 SC:target (prev array )

int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
	int tot=0;//stores total sum of array
	for(int i=0;i<n;i++)
		tot+=arr[i];
	
	//Code to check subset sum
	vector<bool> prev(tot+1,false),curr(tot+1,false);//dp[n][tot+1] initialized with false
	//Base case fill
	prev[0]=curr[0]=true;
	if(arr[0]<=tot)
		prev[arr[0]]=true;
	
	for(int i=1;i<n;i++)
	{
		for(int target=1;target<=tot;target++)
		{
			bool notpick=prev[target];
			bool take=false;
			if(arr[i]<=target)
				take=prev[target-arr[i]];
			curr[target]=take | notpick;		
		}
		prev=curr;
	}
	
	int minsum=1e9;
	//now we travese the last row the dp table,
	//if subset sum is possible,then store the minimum difference of two subset sums
	for(int i=0;i<=tot/2;i++)
	{
		if(prev[i]==true)
		{
			int s1=i;
			int s2=tot-s1;
			minsum=min(minsum,abs(s1-s2));
		}
		
	}
	return minsum; 
}



////////////////////////////////////////////////////////////////////////////////////////////


//Partition a set into two subsets such that the difference of subset sums is minimum.(codestudio) gives AC
//Using Bottom Up  approach
//TC:(n*target)+totalsum/2 SC:n*target (dp array )

int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
	int tot=0;//stores total sum of array
	for(int i=0;i<n;i++)
		tot+=arr[i];
	
	//Code to check subset sum
	vector<vector<bool>> dp(n,vector<bool> (tot+1,false));//dp[n][tot+1] initialized with false
	for(int i=0;i<n;i++)//Base case fill
		dp[i][0]=true;
	if(arr[0]<=tot)
		dp[0][arr[0]]=true;
	
	for(int i=1;i<n;i++)
	{
		for(int target=1;target<=tot;target++)
		{
			bool notpick=dp[i-1][target];
			bool take=false;
			if(arr[i]<=target)
				take=dp[i-1][target-arr[i]];
			dp[i][target]=take | notpick;
			
		}
	}
	int minsum=1e9;
	//now we travese the last row the dp table,
	//if subset sum is possible,then store the minimum difference of two subset sums
	for(int i=0;i<=tot/2;i++)
	{
		if(dp[n-1][i]==true)
		{
			int s1=i;
			int s2=tot-s1;
			minsum=min(minsum,abs(s1-s2));
		}
		
	}
	return minsum; 
}
