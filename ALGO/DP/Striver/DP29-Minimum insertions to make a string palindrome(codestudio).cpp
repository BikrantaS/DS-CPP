#include<bits/stdc++.h>

//https://www.codingninjas.com/codestudio/problems/minimum-insertions-to-make-palindrome_985293
//Minimum insertions to make a string palindrome(codestudio) gives AC
//Using Bottom Up approach
//TC:n*m  SC:n*m
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
            string lcs="";
            int i=m,j=n;
            while(i>0 && j>0)
            {
                if(s[i-1]==t[j-1])
                {
                    lcs=s[i]+lcs;
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
            return dp[m][n];
        }
    int longestPalindromeSubseq(string s) 
    {
        string t=s;
        reverse(t.begin(),t.end());
        return lcs(s,t);
    }

int minInsertion(string &str)
{
    // Write your code here.
	return str.length()-longestPalindromeSubseq(str);
}