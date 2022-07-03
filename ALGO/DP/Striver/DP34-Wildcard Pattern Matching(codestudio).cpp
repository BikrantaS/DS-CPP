https://www.codingninjas.com/codestudio/problems/wildcard-pattern-matching_701650

//Wildcard Pattern Matching(codestudio) give AC
//Using Bottom UP SPACE OPTIMIZED approach
//TC:n*m SC:n
//index shifted
bool wildcardMatching(string pattern, string text)
{
    int n=text.length();
    int m=pattern.length();
    vector<bool> prev(n+1,false),curr(n+1,false);
    prev[0]=true;
    for(int j=1;j<=n;j++)
        prev[j]=false;
 
    
    for(int i=1;i<=m;i++)
    {
        //for every row assiging 0th col value
        bool flag=true;
        for(int k=1;k<=i;k++)//check  the remaining pattern left has only '*' or not
        {
            if(pattern[k-1]!='*')flag=false;
            break;
        }
        curr[0]=flag;
        
        for(int j=1;j<=n;j++)
        {
            if(pattern[i-1]==text[j-1] || pattern[i-1]=='?')
            curr[j]=prev[j-1];

            else if(pattern[i-1]=='*')//consider * as the character OR do not consider '*' and move on
            curr[j]=(curr[j-1] | prev[j]);

            else curr[j]=false;
        }
        prev=curr;
    }
    return prev[n];
}

//////////////////////////////////////////////////////////////////////////

//Wildcard Pattern Matching(codestudio) give AC
//Using Bottom UP approach
//TC:n*m SC:n*m
//index shifted
bool wildcardMatching(string pattern, string text)
{
    int n=text.length();
    int m=pattern.length();
    vector<vector<bool>> dp(m+1,vector<bool> (n+1,false));
    dp[0][0]=true;
    for(int j=1;j<=n;j++)
        dp[0][j]=false;
    for(int i=1;i<=m;i++)
    {
        bool flag=true;
        for(int k=1;k<=i;k++)//check  the remaining pattern left has only '*' or not
        {
            if(pattern[k-1]!='*')flag=false;
            break;
        }
        dp[i][0]=flag;
    }
    
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
        if(pattern[i-1]==text[j-1] || pattern[i-1]=='?')
        dp[i][j]=dp[i-1][j-1];
    
        else if(pattern[i-1]=='*')//consider * as the character OR do not consider '*' and move on
        dp[i][j]=dp[i][j-1] | dp[i-1][j];
    
        else dp[i][j]=false;
        }
    }
    return dp[m][n];
}

//////////////////////////////////////////////////////////////////////////

//Wildcard Pattern Matching(codestudio) give AC
//Using Top Down approach
//TC:n*m SC:n*m+(n+m)
//index shifted
bool f(int i,int j,string& pattern, string& text,vector<vector<int>>& dp)//i->pattern,j->text
{
    if(j==0 && i==0)return true;//both pattern and text is exhausted
    if(j>0 && i==0)return false;//pattern is exhausted but text is not
    if(j==0 && i>0)//text is exhausted but pattern is not
    {
        for(int k=i;k>=1;k--)//check  the remaining pattern left has only '*' or not
            if(pattern[k-1]!='*')return false;
        return true;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    if(pattern[i-1]==text[j-1] || pattern[i-1]=='?')
        return dp[i][j]=f(i-1,j-1,pattern,text,dp);
    
    if(pattern[i-1]=='*')//consider * as the character OR do not consider '*' and move on
        return dp[i][j]=f(i,j-1,pattern,text,dp) | f(i-1,j,pattern,text,dp);
    
    return dp[i][j]=false;
}
bool wildcardMatching(string pattern, string text)
{
    int n=text.length();
    int m=pattern.length();
    vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
    return f(m,n,pattern,text,dp);
}

//////////////////////////////////////////////////////////////////////////

//Wildcard Pattern Matching(codestudio) give AC
//Using Top Down approach
//TC:n*m SC:n*m+(n+m)

bool f(int i,int j,string& pattern, string& text,vector<vector<int>>& dp)//i->pattern,j->text
{
    if(j<0 && i<0)return true;//both pattern and text is exhausted
    if(j>=0 && i<0)return false;//pattern is exhausted but text is not
    if(j<0 && i>=0)//text is exhausted but pattern is not
    {
        for(int k=i;k>=0;k--)//check  the remaining pattern left has only '*' or not
            if(pattern[k]!='*')return false;
        return true;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    if(pattern[i]==text[j] || pattern[i]=='?')
        return dp[i][j]=f(i-1,j-1,pattern,text,dp);
    
    if(pattern[i]=='*')//consider * as the character OR do not consider '*' and move on
        return dp[i][j]=f(i,j-1,pattern,text,dp) | f(i-1,j,pattern,text,dp);
    
    return dp[i][j]=false;
}
bool wildcardMatching(string pattern, string text)
{
    int n=text.length();
    int m=pattern.length();
    vector<vector<int>> dp(m,vector<int> (n,-1));
    return f(m-1,n-1,pattern,text,dp);
}

//////////////////////////////////////////////////////////////////////////

//Wildcard Pattern Matching(codestudio) give TLE
//Using Recursion approach
//TC:2^(m+n) [exponential] SC:n+m

bool f(int i,int j,string& pattern, string& text)//i->pattern,j->text
{
    if(j<0 && i<0)return true;//both pattern and text is exhausted
    if(j>=0 && i<0)return false;//pattern is exhausted but text is not
    if(j<0 && i>=0)//text is exhausted but pattern is not
    {
        for(int k=i;k>=0;k--)//check  the remaining pattern left has only '*' or not
            if(pattern[k]!='*')return false;
        return true;
    }
    if(pattern[i]==text[j] || pattern[i]=='?')
        return f(i-1,j-1,pattern,text);
    
    if(pattern[i]=='*')//consider * as the character OR do not consider '*' and move on
        return f(i,j-1,pattern,text) | f(i-1,j,pattern,text);
    
    return false;
}
bool wildcardMatching(string pattern, string text)
{
    int n=text.length();
    int m=pattern.length();
    f(m-1,n-1,pattern,text);
}
