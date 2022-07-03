https://www.codingninjas.com/codestudio/problems/shortest-supersequence_4244493
//Shortest Common Supersequence(codestudio) give AC
//Using Bottom Up approach
//TC:n*m  SC:n*m
string shortestSupersequence(string a, string b)
{
	// Write your code here.
	int m=a.length();
	int n=b.length();
	vector<vector<int>> dp(m+1,vector<int> (n+1,0));
	
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i-1]==b[j-1])
			dp[i][j]=1+dp[i-1][j-1];
			else
			dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
		}
	}
	
	//check the matrix to print the SCSS
	string ans="";
	int i=m,j=n;
	while(i>0 && j>0)
	{
		if(a[i-1]==b[j-1])
		{
			ans+=a[i-1];
			i--;
			j--;
		}
		else if(dp[i-1][j]>dp[i][j-1])//move to column
		{
			ans+=a[i-1];
			i--;
		}
		else//move to row
		{
			ans+=b[j-1];
			j--;
		}
	}
	
	while(i>0)
	{
		ans+=a[i-1];
		i--;
	}
	while(j>0)
	{
		ans+=b[j-1];
		j--;
	}
	reverse(ans.begin(),ans.end());
	return ans;	
}