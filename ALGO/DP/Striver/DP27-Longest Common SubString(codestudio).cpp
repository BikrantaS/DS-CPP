
https://www.codingninjas.com/codestudio/problems/longest-common-substring_1235207
//Longest Common Substring(codestudio) give AC
//Using Bottom UP SPACE OPTIMIZED approach
//TC:n*m SC:n
int lcs(string &str1, string &str2)
{
	//	Write your code here.
	int m=str1.size();
	int n=str2.size();
	int ans=0;
	vector<int> prev(n+1,0),curr(n+1,0);
// 	for(int i=0;i<=m;i++)
// 		dp[i][0]=0;
// 	for(int j=0;j<=n;j++)
// 		dp[0][j]=0;

	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(str1[i-1]==str2[j-1])
			{
				curr[j]=prev[j-1]+1;
				ans=max(ans,curr[j]);
			}
			else
				curr[j]=0;
		}
		prev=curr;
	}
	return ans;
}

//////////////////////////////////////////////////////////

//Longest Common Substring(codestudio) give AC
//Using Bottom UP approach
//TC:n*m SC:n*m
int lcs(string &str1, string &str2)
{
	//	Write your code here.
	int m=str1.size();
	int n=str2.size();
	int ans=0;
	vector<vector<int>> dp(m+1,vector<int> (n+1,0));
// 	for(int i=0;i<=m;i++)
// 		dp[i][0]=0;
// 	for(int j=0;j<=n;j++)
// 		dp[0][j]=0;

	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(str1[i-1]==str2[j-1])
			{
				dp[i][j]=dp[i-1][j-1]+1;
				ans=max(ans,dp[i][j]);
			}
			else
				dp[i][j]=0;
		}
	}
	return ans;
}