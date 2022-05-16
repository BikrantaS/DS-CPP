#include <bits/stdc++.h>

//https://www.codingninjas.com/codestudio/problems/triangle_1229398?leftPanelTab=1

//Triangle (codestudio) gives AC
//Using Bottom Up SPACE OPTIMIZED approach
//TC:n*n SC:n (prev arry)

int minimumPathSum(vector<vector<int>>& triangle, int n){
	//base case:filling bottom of dp
	vector<int> prev(n,0);
	for(int k=0;k<n;k++)
		prev[k]=triangle[n-1][k];

	for(int i=n-2;i>=0;i--)//going to upper row
	{
		vector<int> curr(n,0);
		for(int j=i;j>=0;j--)//going to left cell
		{
			int down=prev[j];//up from down
			int diagonal=prev[j+1];//go up tp left diagonal from right diagonal
			curr[j]=min(down,diagonal)+ triangle[i][j];
		}
		prev=curr;
	}
	return prev[0];//the first cell will have the anwer
}


//////////////////////////////////////////////////////////////////////////////////////////

//Triangle (codestudio) gives AC
//Using Bottom Up approach
//TC:n*n SC:n*n (dp arry)

int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<vector<int>> dp(n,vector<int>(n,-1));//dp array// Write your code here.
	//base case:filling bottom of dp
	for(int k=0;k<n;k++)
		dp[n-1][k]=triangle[n-1][k];
	
	for(int i=n-2;i>=0;i--)//going to upper row
	{
		for(int j=i;j>=0;j--)//going to left cell
		{
			int down=dp[i+1][j];//up from down
			int diagonal=dp[i+1][j+1];//go up tp left diagonal from right diagonal
			dp[i][j]=min(down,diagonal)+ triangle[i][j];
		}
	}
	return dp[0][0];//the first cell will have the anwer
}


///////////////////////////////////////////////////////////////////////////////////////

//Triangle (codestudio) gives AC
//Using Recursive approach
//TC:n*n SC:n*n+n (dp arry+recursion stack space)

int f(int i,int j, vector<vector<int>>& triangle,vector<vector<int>>& dp)
{
	if(i==triangle.size()-1)return triangle[i][j];//if final row reached,return its value
	if(dp[i][j]!=-1)return dp[i][j];//return memoized value
	int down=f(i+1,j,triangle,dp);//go down
	int diagonal=f(i+1,j+1,triangle,dp);//go right diagonal
	return dp[i][j]=min(down,diagonal)+ triangle[i][j];//retrun the min of reached positions
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<vector<int>> dp(n,vector<int>(n,-1));//dp array// Write your code here.
	return f(0,0,triangle,dp);//we are goin from top cell to any cell in the last row
}


//////////////////////////////////////////////////////////////////////////////

//Triangle (codestudio) gives TLE
//Using Recursive approach
//TC:2^n SC:n*n (length of row)

int f(int i,int j, vector<vector<int>>& triangle)
{
	if(i==triangle.size()-1)return triangle[i][j];//if final row reached,return its value

	int down=f(i+1,j,triangle);//go down
	int diagonal=f(i+1,j+1,triangle);//go right diagonal
	return min(down,diagonal)+ triangle[i][j];//retrun the min of reached positions
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
	return f(0,0,triangle);//we are goin from top cell to any cell in the last row
}