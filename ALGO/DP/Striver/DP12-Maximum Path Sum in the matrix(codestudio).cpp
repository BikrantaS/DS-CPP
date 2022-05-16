

//https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998?leftPanelTab=0

//Maximum Path Sum in the matrix (codestudio) gives AC
//Using Bottom UP Space Optimized approach
//TC:nm+m SC:m (prev array)

int getMaxPathSum(vector<vector<int>> &matrix)
{
	int n=matrix.size();
	int m=matrix[0].size();
	vector<int> prev(m,0);
	for(int k=0;k<m;k++)//base case fil
		prev[k]=matrix[0][k];
	for(int i=1;i<n;i++)
	{
		vector<int> curr(m,0);
		for(int j=0;j<m;j++)
		{
			int d=prev[j];
			int rd=-1e8,ld=-1e8;//for avoid out of boundary
			if(j+1<m)
				rd=prev[j+1];
			if(j-1>=0)
				ld=prev[j-1];
			curr[j]=max(ld,max(rd,d))+matrix[i][j];
		}
		prev=curr;
	}	
	int maxi=-1e8;
	for(int k=0;k<m;k++)//check each bottom cells in the last row
		maxi=max(maxi,prev[k]);
	return maxi;
}


////////////////////////////////////////////////////////////////////////

//Maximum Path Sum in the matrix (codestudio) gives AC
//Using Bottom UP approach
//TC:nm+m SC:nm (dp array)

int getMaxPathSum(vector<vector<int>> &matrix)
{
	int n=matrix.size();
	int m=matrix[0].size();
	vector<vector<int>> dp(n,vector<int>(m,0));
	for(int k=0;k<m;k++)//base case fil
		dp[0][k]=matrix[0][k];
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int d=dp[i-1][j];
			int rd=-1e8,ld=-1e8;//for avoid out of boundary
			if(j+1<m)
				rd=dp[i-1][j+1];
			if(j-1>=0)
				ld=dp[i-1][j-1];
			dp[i][j]=max(ld,max(rd,d))+matrix[i][j];
		}
	}	
	int maxi=-1e8;
	for(int k=0;k<m;k++)//check each bottom cells in the last row
		maxi=max(maxi,dp[n-1][k]);
	return maxi;
}


////////////////////////////////////////////////////////////////////////////////////

//Maximum Path Sum in the matrix (codestudio) gives AC
//Using Top Down approach
//TC:nm SC:nm+n (dp array + recursion stack space)

int f(int i,int j,vector<vector<int>> &matrix,vector<vector<int>>& dp)
{
	//BASE CASE
	if(j<0 || j>=matrix[0].size())return -1e8;//alway keep this condition forward
	if(i==0)return matrix[0][j];
	if(dp[i][j]!=-1)return dp[i][j];//return memoized value
	int d=f(i-1,j,matrix,dp);
	int ld=f(i-1,j-1,matrix,dp);
	int rd=f(i-1,j+1,matrix,dp);
	return dp[i][j]=max(d,max(ld,rd))+matrix[i][j];
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
	int n=matrix.size();
	int m=matrix[0].size();
	vector<vector<int>> dp(n,vector<int>(m,-1));
	int maxi=-1e8;
	for(int k=0;k<m;k++)//check each bottom cells in the last row
		maxi=max(maxi,f(n-1,k,matrix,dp));
	return maxi;
}


//////////////////////////////////////////////////////////////////////////////

//Maximum Path Sum in the matrix (codestudio) gives TLE
//Using Recursive approach
//TC:m*(3^n) SC:n (length of row)

int f(int i,int j,vector<vector<int>> &matrix)
{
	//BASE CASE
	if(j<0 || j>=matrix[0].size())return -1e8;//alway keep this condition forward
	if(i==0)return matrix[0][j];
	
	int d=f(i-1,j,matrix);
	int ld=f(i-1,j-1,matrix);
	int rd=f(i-1,j+1,matrix);
	return max(d,max(ld,rd))+matrix[i][j];
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
	int n=matrix.size();
	int m=matrix[0].size();
	int maxi=-1e8;
	for(int k=0;k<m;k++)//check each bottom cells in the last row
		maxi=max(maxi,f(n-1,k,matrix));
	return maxi;
}