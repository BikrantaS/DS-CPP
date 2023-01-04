//https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261

//Maximum sum of non-adjacent elements (codestudio) gives AC
//Using Bottom UP SPACE OPTIMIZED approach
//TC:n SC:1

int maximumNonAdjacentSum(vector<int> &nums)
{
	int n=nums.size();
	int prev=nums[0];
	int prev2=0;
	int curr=0;
	for(int i=1;i<n;i++)
	{
		int pick=nums[i];
		if(i>1)//if index does not becomes negative, add the the previous adjacent dp[] value
		pick+=prev2;//pick and add adjacent index's number
		
		int notpick=prev;
		curr=max(pick,notpick);//return max of pick and notpick result,then memoize it
		prev2=prev;
		prev=curr;
	}
	return prev;
}

///////////////////////////////////////////////////////////////////////////////////////

//Maximum sum of non-adjacent elements (codestudio) gives AC
//Using Bottom UP approach
//TC:n SC:n

int maximumNonAdjacentSum(vector<int> &nums)
{
    // Write your code here.
	int n=nums.size();
	vector<int> dp(n,-1);//memoization
	
	dp[0]=nums[0];//incase the 0th index is reached return value at 0th index
	for(int i=1;i<n;i++)
	{
		int pick=nums[i];
		if(i>=1)//if index does not becomes negative, add the the previous adjacent dp[] value
		pick+=dp[i-2];//pick and add adjacent index's number
		
		int notpick=dp[i-1];
		dp[i]=max(pick,notpick);//return max of pick and notpick result,then memoize it
	}
	
	return dp[n-1];
	
}

////////////////////////////////////////////////////////////////////////////////////


//Maximum sum of non-adjacent elements (codestudio) gives AC
//Using Top Down approach
//TC:n SC:n+n

int f(int index,vector<int> &nums,vector<int>& dp)
{
	if(dp[index]!=-1)return dp[index];//if already present in dp[] return from it
	if(index==0)return nums[0];//incase the 0th index is reached return value at 0th index
	if(index<0)return 0;//if picking goes out of range just return 0, it acts as not picking
	
	int pick=nums[index]+f(index-2,nums,dp);//pick and add adjacent index's number
	int notpick=f(index-1,nums,dp);//if not picked,just call the previous index,since we are not adding anthing,its like picking adjacent number
	return dp[index]=max(pick,notpick);//return max of pick and notpick result,then memoize it
}
int maximumNonAdjacentSum(vector<int> &nums)
{
    // Write your code here.
	int n=nums.size();
	vector<int> dp(n,-1);//memoization
	return f(n-1,nums,dp);//return answer
	
}

//////////////////////////////////////////////////////////////////////////////////

//Maximum sum of non-adjacent elements (codestudio) gives TLE
//Using Plain Recursion approach
//TC:2^n SC:n

int f(int index,vector<int> &nums)
{
	if(index==0)return nums[0];//incase the 0th index is reached return value at 0th index
	if(index<0)return 0;//if picking goes out of range just return 0, it acts as not picking
	
	int pick=nums[index]+f(index-2,nums);//pick and add adjacent index's number
	int notpick=f(index-1,nums);//if not picked,just call the previous index,since we are not adding anthing,its like picking adjacent number
	return max(pick,notpick);//return max of pick and notpick result
}
int maximumNonAdjacentSum(vector<int> &nums)
{
	int n=nums.size();
	return f(n-1,nums);//return answer
}

//////////////////////////////////////////////////////////////////////////////////////

