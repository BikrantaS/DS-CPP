

//Total Unique Paths (codestudio) gives AC
//Using Bottom Up  SPACE OPTIMIZED approach
//TC:mn SC:n (prev array length)

int uniquePaths(int m, int n) 
{
	// Write your code here.
	vector<int> prev(n,0);//dp array
	for(int i=0;i<m;i++)
	{
		vector<int> temp(n,0);
		for(int j=0;j<n;j++)
		{
			if(i==0 && j==0)
			{
				temp[j]=1;
				continue;
			}
			  int up=0;
			  int left = 0;

			  if(i>0) 
				up = prev[j];
			  if(j>0)
				left = temp[j-1];

			  temp[j] = up+left;
		}
		prev=temp;
	}
	return prev[n-1];//start traversing from (m-1,n-1) index
}



////////////////////////////////////////////////////////

//Total Unique Paths (codestudio) gives AC
//Using Bottom Up approach
//TC:mn SC:mn (dp array length)

int uniquePaths(int m, int n) 
{
	// Write your code here.
	vector<vector<int>> dp(m,vector<int>(n,-1));//dp array
	dp[0][0]=1;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==0 && j==0)
			{
				dp[0][0]=1;
				continue;
			}
			  int up=0;
			  int left = 0;

			  if(i>0) 
				up = dp[i-1][j];
			  if(j>0)
				left = dp[i][j-1];

			  dp[i][j] = up+left;
		}
	}
	return dp[m-1][n-1];//start traversing from (m-1,n-1) index
}



////////////////////////////////////////////////////////////////////////////////


//Total Unique Paths (codestudio) gives AC
//Using TOP DOWN approach
//TC:mn SC:(m+n)+mn (path length+dp array length)
int f(int i,int j,vector<vector<int>>& dp)
{
	if(i==0 && j==0)return 1;//position reached rutun 1
	else if(i<0 || j<0)return 0;//reached out of bound,dont consider,return 0
	if(dp[i][j]!=-1)return dp[i][j];//retrun memoized value
	int up=f(i-1,j,dp);//move up
	int left=f(i,j-1,dp);//move left
	return dp[i][j]=up+left;//retrun the sum of reached (m,n) positions and memoize
}
int uniquePaths(int m, int n) 
{
	// Write your code here.
	vector<vector<int>> dp(m,vector<int>(n,-1));//dp array
	return f(m-1,n-1,dp);//start traversing from (m-1,n-1) index
}


///////////////////////////////////////////////////////////////////////

//Total Unique Paths (codestudio) gives TLE
//Using Recursive approach
//TC:2^(mn) SC:m+n (path length)
int f(int i,int j)
{
	if(i==0 && j==0)return 1;//position reached rutun 1
	else if(i<0 || j<0)return 0;//reached out of bound,dont consider,return 0
	int up=f(i-1,j);//move up
	int left=f(i,j-1);//move left
	return up+left;//retrun the sum of reached (m,n) positions
}
int uniquePaths(int m, int n) 
{
	// Write your code here.
	return f(m-1,n-1);//start traversing from (m-1,n-1) index
}