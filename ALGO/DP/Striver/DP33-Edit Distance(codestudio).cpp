
https://www.codingninjas.com/codestudio/problems/edit-distance_630420

//Edit Distance(codestudio) give AC
//Using SPACE OPTIMIZED Bottom uP approach
//TC:n*m SC:n
//index shifted
int editDistance(string str1, string str2)
{
    //write you code here
    int m=str1.length();
    int n=str2.length();
    vector<int> prev(n+1,0),curr(n+1,0);
    for(int j=0;j<=n;j++)prev[j]=j;

    for(int i=1;i<=m;i++)
    {
        curr[0]=i;//all cells in first rows have value of column no.
        for(int j=1;j<=n;j++)
        {
        if(str1[i-1]==str2[j-1])//postion match
        curr[j]=prev[j-1];
        else//check for(delete,insert,replace)respectively
        curr[j]=1+min(prev[j],min(curr[j-1],prev[j-1]));
        }
        prev=curr;
    }
    return prev[n];
}

///////////////////////////////////////////////////////////////////////////

//Edit Distance(codestudio) give AC
//Using Bottom uP approach
//TC:n*m SC:n*m
//index shifted
int editDistance(string str1, string str2)
{
    //write you code here
    int m=str1.length();
    int n=str2.length();
    vector<vector<int>> dp(m+1,vector<int> (n+1,0));
    for(int i=0;i<=m;i++)dp[i][0]=i;
    for(int j=0;j<=n;j++)dp[0][j]=j;

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
        if(str1[i-1]==str2[j-1])//postion match
        dp[i][j]=dp[i-1][j-1];
        else//check for(delete,insert,replace)respectively
        dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
        }
    }
    return dp[m][n];
}


///////////////////////////////////////////////////////////////////////////

//Edit Distance(codestudio) give AC
//Using Top Down approach
//TC:n*m SC:n*m+(n+m)
//index shifted
int f(int i,int j,string& s1,string& s2,vector<vector<int>>& dp)
{
    if(i==0)//if s1 gets exhausted return remaning strings of s2
        return j;
    if(j==0)//if s2 gets exhausted return remaning strings of s1
        return i;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s1[i-1]==s2[j-1])//postion match
        return dp[i][j]=f(i-1,j-1,s1,s2,dp);
    
    //check for(delete,insert,replace)respectively
    return dp[i][j]=1+min(f(i-1,j,s1,s2,dp),min(f(i,j-1,s1,s2,dp),f(i-1,j-1,s1,s2,dp)));
}
int editDistance(string str1, string str2)
{
    //write you code here
    int m=str1.length();
    int n=str2.length();
    vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
    return f(m,n,str1,str2,dp);
}

///////////////////////////////////////////////////////////////////////////

//Edit Distance(codestudio) give AC
//Using Top Down approach
//TC:n*m SC:n*m+(n+m)
int f(int i,int j,string& s1,string& s2,vector<vector<int>>& dp)
{
    if(i<0)//if s1 gets exhausted return remaning strings of s2
        return j+1;
    if(j<0)//if s2 gets exhausted return remaning strings of s1
        return i+1;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s1[i]==s2[j])//postion match
        return dp[i][j]=f(i-1,j-1,s1,s2,dp);
    
    //check for(delete,insert,replace)respectively
    return dp[i][j]=1+min(f(i-1,j,s1,s2,dp),min(f(i,j-1,s1,s2,dp),f(i-1,j-1,s1,s2,dp)));
}
int editDistance(string str1, string str2)
{
    //write you code here
    int m=str1.length();
    int n=str2.length();
    vector<vector<int>> dp(m,vector<int> (n,-1));
    return f(m-1,n-1,str1,str2,dp);
}

///////////////////////////////////////////////////////////////////////////

//Edit Distance(codestudio) give TLE
//Using Recursion approach
//TC:3^(m+n) [exponential] SC:n+m
int f(int i,int j,string& s1,string& s2)
{
    if(i<0)//if s1 gets exhausted return remaning strings of s2
        return j+1;
    if(j<0)//if s2 gets exhausted return remaning strings of s1
        return i+1;
    if(s1[i]==s2[j])//postion match
        return f(i-1,j-1,s1,s2);
    
    //check for(delete,insert,replace)respectively
    return 1+min(f(i-1,j,s1,s2),min(f(i,j-1,s1,s2),f(i-1,j-1,s1,s2)));
}
int editDistance(string str1, string str2)
{
    //write you code here
    int m=str1.length();
    int n=str2.length();
    return f(m-1,n-1,str1,str2);
}