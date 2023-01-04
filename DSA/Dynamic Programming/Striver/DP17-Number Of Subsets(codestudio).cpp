
//https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532?leftPanelTab=1

//Number Of Subsets (codestudio) gives AC
//Using Space optimized  approach
//TC:n*tar SC:tar 

int findWays(vector<int> &num, int tar)
{
    // Write your code here.
	int n=num.size();
	vector<int> prev(tar+1,0),curr(tar+1,0);
	
	//Base Case
	curr[0]=prev[0]=1;
	if(num[0]<=tar)
	prev[num[0]]=1;
	
	for(int i=1;i<n;i++)
	{
		for(int target=0;target<=tar;target++)
		{
			int pick=0;
			if(target-num[i]>=0)pick=prev[target-num[i]];
			int notpick=prev[target];
			curr[target]=pick+notpick;
		}
		prev=curr;
	}
	
	return prev[tar];
}


///////////////////////////////////////////////////////////////////////

//Number Of Subsets (codestudio) gives AC
//Using Bottom Up  approach
//TC:n*tar SC:n*tar 

int findWays(vector<int> &num, int tar)
{
    // Write your code here.
	int n=num.size();
	vector<vector<int>> dp(n,vector<int> (tar+1,0));
	
	//Base Case
	for(int i=0;i<n;i++)
		dp[i][0]=1;
	if(num[0]<=tar)
	dp[0][num[0]]=1;
	
	for(int i=1;i<n;i++)
	{
		for(int target=0;target<=tar;target++)
		{
			int pick=0;
			if(target-num[i]>=0)pick=dp[i-1][target-num[i]];
			int notpick=dp[i-1][target];
			dp[i][target]=pick+notpick;
		}
	}
	
	return dp[n-1][tar];
}


////////////////////////////////////////////////////////

//Number Of Subsets (codestudio) gives AC
//Using Top DOWN  approach
//TC:n*tar SC:n+ n*tar 

int f(int i,int target,vector<int> &num,vector<vector<int>>& dp)
{
	//base case
	if(target==0)return 1;
	if(i==0) return(target==num[i]);
	if(dp[i][target]!=-1)return dp[i][target];
	int pick=0;
	if(target-num[i]>=0)pick=f(i-1,target-num[i],num,dp);
	int notpick=f(i-1,target,num,dp);
	return dp[i][target]=pick+notpick;

}

int findWays(vector<int> &num, int tar)
{
    // Write your code here.
	int n=num.size();
	vector<vector<int>> dp(n,vector<int> (tar+1,-1));
	return f(n-1,tar,num,dp);
}


/////////////////////////////////////////////////////////////////////////////////////

//Number Of Subsets (codestudio) gives TLE
//Using recursive  approach
//TC:2^n SC:n 
int f(int i,int target,vector<int> &num)
{
	//base case
	if(target==0)return 1;
	if(i==0) return(target==num[i]);
	int pick=0;
	if(target-num[i]>=0)pick=f(i-1,target-num[i],num);
	int notpick=f(i-1,target,num);
	return pick+notpick;

}

int findWays(vector<int> &num, int tar)
{
    // Write your code here.
	int n=num.size();
	return f(n-1,tar,num);
}