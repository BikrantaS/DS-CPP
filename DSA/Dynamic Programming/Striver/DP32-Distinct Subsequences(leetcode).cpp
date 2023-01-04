
https://leetcode.com/problems/distinct-subsequences/

//Distinct Subsequences(leetcode)
//BOTTOM UP Space Optimized approach gives AC
//TC:m*n SC:n(using single array)
//index shifted
   
    int numDistinct(string s, string t) 
    {
        int m=s.length();
        int n=t.length();
        vector<double> prev(n+1,0);
        prev[0]=1;
        
        for(int i=1;i<=m;i++)
        {
            for(int j=n;j>=1;j--)
            {
                if(s[i-1]==t[j-1])
                    prev[j]=prev[j]+prev[j-1];
            }
        }
        
        return prev[n];
    }

////////////////////////////////////////////////////////////////////////////

//Distinct Subsequences(leetcode)
//BOTTOM UP Space Optimized approach gives AC
//TC:m*n SC:2n
//index shifted
   
    int numDistinct(string s, string t) 
    {
        int m=s.length();
        int n=t.length();
        vector<double> prev(n+1,0),curr(n+1,0);
		prev[0]=curr[0]=1;
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==t[j-1])
                    curr[j]=prev[j]+prev[j-1];
                else
                    curr[j]=prev[j];
            }
            prev=curr;
        }
        
        return prev[n];
    }
    
/////////////////////////////////////////////////////////////////////////

//Distinct Subsequences(leetcode)
//BOTTOM UP approach gives AC
//TC:m*n SC:m*n
//index shifted
   
    int numDistinct(string s, string t) 
    {
        int m=s.length();
        int n=t.length();
        vector<vector<double>> dp(m+1,vector<double> (n+1,-1));
        for(int i=0;i<=m;i++)
		dp[i][0]=1;
	    for(int j=1;j<=n;j++)
		dp[0][j]=0;
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==t[j-1])
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        
        return dp[m][n];
    }


/////////////////////////////////////////////////////////////////////////

//Distinct Subsequences(leetcode)
//Top Down approach gives AC
//TC:m*n SC:m*n+(n+m)
//index shifted
    int f(int i,int j,string& s, string& t,vector<vector<int>>& dp)
    {
        if(j==0)return 1;
        else if(i==0)return 0;
        else if(dp[i][j]!=-1)return dp[i][j];
        else if(s[i-1]==t[j-1])
            return dp[i][j]=f(i-1,j,s,t,dp)+f(i-1,j-1,s,t,dp);
        
        return dp[i][j]=f(i-1,j,s,t,dp);
    }
    int numDistinct(string s, string t) 
    {
        int m=s.length();
        int n=t.length();
        vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
        return f(m,n,s,t,dp);
    }


///////////////////////////////////////////////////////////////////////////////////


//Distinct Subsequences(leetcode)
//Top Down approach gives AC
//TC:m*n SC:m*n+(n+m)
    int f(int i,int j,string& s, string& t,vector<vector<int>>& dp)
    {
        if(j<0)return 1;
        else if(i<0)return 0;
        else if(dp[i][j]!=-1)return dp[i][j];
        else if(s[i]==t[j])
            return dp[i][j]=f(i-1,j,s,t,dp)+f(i-1,j-1,s,t,dp);
        
        return dp[i][j]=f(i-1,j,s,t,dp);
    }
    int numDistinct(string s, string t) 
    {
        int m=s.length();
        int n=t.length();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return f(m-1,n-1,s,t,dp);
    }

///////////////////////////////////////////////////////////////////

//Distinct Subsequences(leetcode)
//Recursive approach gives TLE
//TC:2^n(exponential) SC:n(exponential)
    int f(int i,int j,string& s, string& t)
    {
        if(j<0)return 1;
        else if(i<0)return 0;
        
        else if(s[i]==t[j])
            return f(i-1,j,s,t)+f(i-1,j-1,s,t);
        
        return f(i-1,j,s,t);
    }
    int numDistinct(string s, string t) 
    {
        int m=s.length();
        int n=t.length();
        return f(m-1,n-1,s,t);
    }