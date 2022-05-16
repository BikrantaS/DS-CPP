//https://www.codingninjas.com/codestudio/problems/maze-obstacles_977241?leftPanelTab=0

//Maze obstacles (codestudio) gives AC
//Using Bottom Up  SPACE OPTIMIZED approach
//TC:mn SC:m (prev array length)
int mod=(int)(1e9+7);
int mazeObstacles(int n, int m, vector<vector<int>>& mat) 
{    
	vector<int> prev(m,0);
	for(int i=0;i<n;i++)
	{
		vector<int> curr(m,0);
		for(int j=0;j<m;j++)
		{
			if(mat[i][j]==-1)
			{
				curr[j]=0;
			}
			else if(i==0 && j==0)
			{
				curr[0]=1;
			}
			else
			{
				int up=0;
			  	int left = 0;
			  	if(i>0) 
				up =prev[j];
			  	if(j>0)
				left = curr[j-1];
			 	curr[j] = (up+left)%mod;
			}
			  
		}
		prev=curr;
	}
	return prev[m-1];//start traversing from (n-1,m-1) index
}

/////////////////////////////////////////////////////////////////////


//Maze obstacles (codestudio) gives AC
//Using Bottom Up approach
//TC:mn SC:mn (dp array length)
int mod=(int)(1e9+7);
int mazeObstacles(int n, int m, vector<vector<int>>& mat) 
{    
	vector<vector<int>> dp(n,vector<int>(m,-1));//dp array
	dp[0][0]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(mat[i][j]==-1)
			{
				dp[i][j]=0;
			}
			else if(i==0 && j==0)
			{
				dp[0][0]=1;
			}
			else
			{
				int up=0;
			  	int left = 0;
			  	if(i>0) 
				up = dp[i-1][j];
			  	if(j>0)
				left = dp[i][j-1];
			 	dp[i][j] = (up+left)%mod;
			}
			  
		}
	}
	return dp[n-1][m-1];//start traversing from (n-1,m-1) index
}


///////////////////////////////////////////////////////////////////////////////

//Maze obstacles (codestudio) gives AC
//Using TOP DOWN approach
//TC:mn SC:(m+n)+mn (path length+dp array length)

int mod=(int)(1e9+7);
int f(int i,int j, vector<vector<int>>& mat,vector<vector<int>>& dp)
{
	
	if(i==0 && j==0)return 1;//position reached rutun 1
	else if(i<0 || j<0)return 0;//reached out of bound,dont consider,return 0
	else if(mat[i][j]==-1)return 0;//if path obstructed,dont consider,return 
	else if(dp[i][j]!=-1)return dp[i][j];//retrun memoized value
	int up=f(i-1,j,mat,dp);//move up
	int left=f(i,j-1,mat,dp);//move left
	return dp[i][j]=(up+left)%mod;//return the sum of reached (m,n) positions and memoize
}

int mazeObstacles(int n, int m, vector<vector<int>>& mat) 
{    // Write your code here
	vector<vector<int>> dp(n,vector<int>(m,-1));//dp array
	return f(n-1,m-1,mat,dp);
}


//////////////////////////////////////////////////////////////////////////



//Maze obstacles (codestudio) gives TLE
//Using Recursive approach
//TC:2^(mn) SC:m+n (path length)
int mod=(int)(1e9+7);
int f(int i,int j, vector<vector<int>>& mat)
{
	if(i==0 && j==0)return 1;//position reached rutun 1
	else if(i<0 || j<0)return 0;//reached out of bound,dont consider,return 0
	else if(mat[i][j]==-1)return 0;//if path obstructed,dont consider,return 0
	int up=f(i-1,j,mat)%mod;//move up
	int left=f(i,j-1,mat)%mod;//move left
	return (up+left)%mod;//retrun the sum of reached (m,n) positions
}

int mazeObstacles(int n, int m, vector<vector<int>>& mat) 
{
    // Write your code here
	return f(n-1,m-1,mat);
}
