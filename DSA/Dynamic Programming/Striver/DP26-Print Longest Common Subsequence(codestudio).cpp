https://www.codingninjas.com/codestudio/problems/longest-common-subsequence_624879
//Printing Longest Common Subsequence(codestudio) give AC
//Using Bottom Up approach
//TC:n*m  SC:n*m
#include<bits/stdc++.h>
using namespace std;
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
	
	//check the matrix to print the LCS
	string LCS="";
	int i=m,j=n;
	while(i>0 && j>0)
	{
		if(s[i-1]==t[j-1])
		{
			LCS=s[i-1]+LCS;
			i--;
			j--;
		}
		else if(dp[i-1][j]>dp[i][j-1])//move to column
		{
			i--;
		}
		else//move to row
		{
			j--;
		}
	}
	cout<<"LCS:"<<LCS<<endl;
	return dp[m][n];
}

int main() {

  string s1= "abcde";
  string s2= "bdqek";
                                 
  cout<<"The Length of Longest Common Subsequence is "<<lcs(s1,s2);
}