
//https://www.codingninjas.com/codestudio/problems/minimum-path-sum_985349?leftPanelTab=0


//Minimum Path Sum (codestudio) gives AC
//Using Bottom Up  SPACE OPTIMIZED approach
//TC:mn SC:m (prev array length)


int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
	int n=grid.size();
	int m=grid[0].size();
	vector<int> prev(m,0);
	for(int i=0;i<n;i++)
	{
		vector<int> curr(m,0);
		for(int j=0;j<m;j++)
		{
			if(i==0 && j==0)
			{
				curr[0]=grid[0][0];
			}
			else
			{
				int up=0;
			  	int left = 0;
				
			  	if(i>0) 
				up = prev[j];
				else
				up=1e9;
			  	if(j>0)
				left =curr[j-1];
				else
				left=1e9;
		
			 	curr[j] = min(up,left)+grid[i][j];
			}
		}
		prev=curr;
	}
	return prev[m-1];//start traversing from (n-1,m-1) index
}



///////////////////////////////////////////////////////////////////////////

//Minimum Path Sum (codestudio) gives AC
//Using Bottom up approach
//TC:mn SC:mn (dp array length)


int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
	int n=grid.size();
	int m=grid[0].size();
	vector<vector<int>> dp(n,vector<int>(m,-1));//dp array
	dp[0][0]=grid[0][0];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			
			if(i==0 && j==0)
			{
				dp[0][0]=grid[0][0];
			}
			else
			{
				int up=0;
			  	int left = 0;
				
			  	if(i>0) 
				up = dp[i-1][j];
				else
				up=1e9;
			  	if(j>0)
				left = dp[i][j-1];
				else
				left=1e9;
		
			 	dp[i][j] = min(up,left)+grid[i][j];
			}
			  
		}
	}
	return dp[n-1][m-1];//start traversing from (n-1,m-1) index
}

////////////////////////////////////////////////////////////////////////////////////

//Minimum Path Sum (codestudio) gives AC
//Using TOP DOWN approach
//TC:mn SC:(m+n)+mn (path length+dp array length)
int f(int i,int j, vector<vector<int>>& grid,vector<vector<int>>& dp)
{
	if(i==0 && j==0)return grid[0][0];//position reached ruturn grid value
	else if(i<0 || j<0)return 1e9;//reached out of bound,dont consider,return a bizzare large value
	else if(dp[i][j]!=-1)return dp[i][j];
	int up=f(i-1,j,grid,dp);//move up
	int left=f(i,j-1,grid,dp);//move left
	return dp[i][j]=min(up,left)+grid[i][j];//retrun the min of reached positions
}

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
	int n=grid.size();
	int m=grid[0].size();
	vector<vector<int>> dp(n,vector<int>(m,-1));//dp array
	return f(n-1,m-1,grid,dp);
}

//////////////////////////////////////////////////////////////////////////////////////

//Minimum Path Sum (codestudio) gives TLE
//Using Recursive approach
//TC:2^(mn) SC:m+n (path length)
int f(int i,int j, vector<vector<int>>& grid)
{
	if(i==0 && j==0)return grid[0][0];//position reached ruturn grid value
	else if(i<0 || j<0)return INT_MAX;//reached out of bound,dont consider,return a bizzare large value

	int up=f(i-1,j,grid);//move up
	int left=f(i,j-1,grid);//move left
	return min(up,left)+grid[i][j];//retrun the min of reached positions
}

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
	int n=grid.size();
	int m=grid[0].size();
	
	return f(n-1,m-1,grid);
}