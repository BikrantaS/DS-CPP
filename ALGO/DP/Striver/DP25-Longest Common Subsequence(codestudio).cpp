https://www.codingninjas.com/codestudio/problems/longest-common-subsequence_624879

//Longest Common Subsequence(codestudio) give AC
//Using Bottom Up Space Optimized approach
//TC:n*m  SC:n
//Shifting od indexes
#include<bits/stdc++.h>
int lcs(string s, string t)
{
	//Write your code here
	int m=s.length();
	int n=t.length();
	vector<int> prev(n+1,0),curr(n+1,0);
	
	//Base Case fill
	for(int j=0;j<=n;j++)
		prev[j]=0;
	
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(s[i-1]==t[j-1])
			curr[j]=1+prev[j-1];
			else
			curr[j]=max(curr[j-1],prev[j]);
		}
		prev=curr;
	}
	
	return prev[n];
}


/////////////////////////////////////////////////////////////////////////////////

//Longest Common Subsequence(codestudio) give AC
//Using Bottom Up approach
//TC:n*m  SC:n*m
//Shifting of indexes
#include<bits/stdc++.h>
int lcs(string s, string t)
{
	//Write your code here
	int m=s.length();
	int n=t.length();
	vector<vector<int>> dp(m+1,vector<int> (n+1,0));
	
	//Base Case fill
	for(int i=0;i<=m;i++)
		dp[i][0]=0;
	for(int j=0;j<=n;j++)
		dp[0][j]=0;
	
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(s[i-1]==t[j-1])
			dp[i][j]=1+dp[i-1][j-1];
			else
			dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
		}
	}
	
	return dp[m][n];
}


/////////////////////////////////////////////////////////////////////////////

//Longest Common Subsequence(codestudio) give AC
//UsingBottom Up approach
//TC:n*m  SC:n*m n+m
//Shifting od indexes
#include<bits/stdc++.h>
int f(int i,int j,string& s, string& t,vector<vector<int>>& dp)
{
	//Base case:
	if(i==0 || j==0)
		return 0;
	
	if(dp[i][j]!=-1)return dp[i][j];
	if(s[i-1]==t[j-1])
		return dp[i][j]=1+f(i-1,j-1,s,t,dp);
	return dp[i][j]=max(f(i,j-1,s,t,dp),f(i-1,j,s,t,dp));
}

int lcs(string s, string t)
{
	//Write your code here
	int m=s.length();
	int n=t.length();
	vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
	return f(m,n,s,t,dp);
}

////////////////////////////////////////////////////////////////////////////

//Longest Common Subsequence(codestudio) give AC
//Using Top Down approach
//TC:n*m  SC:n*m n+m

#include<bits/stdc++.h>
int f(int i,int j,string& s, string& t,vector<vector<int>>& dp)
{
	//Base case:
	if(i<0 || j<0)
		return 0;
	
	if(dp[i][j]!=-1)return dp[i][j];
	if(s[i]==t[j])
		return dp[i][j]=1+f(i-1,j-1,s,t,dp);
	return dp[i][j]=max(f(i,j-1,s,t,dp),f(i-1,j,s,t,dp));
}

int lcs(string s, string t)
{
	//Write your code here
	int m=s.length();
	int n=t.length();
	vector<vector<int>> dp(m,vector<int> (n,-1));
	return f(m-1,n-1,s,t,dp);
}


/////////////////////////////////////////////////////////////////////////


//Longest Common Subsequence(codestudio) give TLE
//Using Recurion approach
//TC:(2^n)*(2^m)  SC:n+m

int f(int i,int j,string& s, string& t)
{
	//Base case:
	if(i<0 || j<0)
		return 0;
	if(s[i]==t[j])
		return f(i-1,j-1,s,t)+1;
	return max(f(i,j-1,s,t),f(i-1,j,s,t));
}


int lcs(string s, string t)
{
	//Write your code here
	int m=s.length();
	int n=t.length();
	return f(m-1,n-1,s,t);
}