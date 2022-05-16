#include<bits/stdc++.h>
//https://www.codingninjas.com/codestudio/problems/frog-jump_3621012

//Frog Jump (codestudio) 
//Using Bottom Up approach(Space Optimized) [gives AC]
//TC:n SC:1

int frogJump(int n, vector<int> &heights)
{
	int prev=0;
	int prev2=0;
	for(int ind=1;ind<n;ind++)
	{
		//enertgy to jump with 1 step
		int jumpOne= prev + abs(heights[ind]-heights[ind-1]);
		
		//enertgy to jump with 1 step  
		int jumpTwo = INT_MAX;
			if(ind>1)//if valid index
			jumpTwo = prev2 + abs(heights[ind]-heights[ind-2]);
	
		int curi=min(jumpOne,jumpTwo);
		prev2=prev;
		prev=curi;
		
  	}
	return prev;//return the last position energy(prev)
}



/////////////////////////////////////////////////////////////////////////////////
//Frog Jump (codestudio) 
//Using Bottom Up approach [gives AC]
//TC:n SC:n

int frogJump(int n, vector<int> &heights)
{
	  vector<int> dp(n+1,0);//initialise dp[] with -0
	  dp[0]=0;//the energy to jump from 0th index to 0th index is 0
	  for(int ind=1;ind<n;ind++)
	{
		//enertgy to jump with 1 step
		int jumpOne= dp[ind-1] + abs(heights[ind]-heights[ind-1]);
		
		//enertgy to jump with 1 step  
		int jumpTwo = INT_MAX;
			if(ind>1)//if valid index
			jumpTwo = dp[ind-2] + abs(heights[ind]-heights[ind-2]);

		dp[ind]=min(jumpOne, jumpTwo);//return minimum of two types of steps and store it in dp[]
  	}
	return dp[n-1];//return the nth position energy
}

////////////////////////////////////////////////////////////////////////////////////////////
//Frog Jump (codestudio) 
//Using Top Down [gives AC]
//TC:n SC:n+n
int f(int index,vector<int> &heights,vector<int>& dp)
{
	if(index==0)return 0;//the energy to jump from 0th index to 0th index is 0
	if(dp[index]!=-1)return dp[index];//if value already present in dp[] return it
	
	//left recursion call
	int left=f(index-1,heights,dp)+abs(heights[index]-heights[index-1]);
	
	//right recursion call
	int right=INT_MAX;
	if(index>1)//if valid index
	right=f(index-2,heights,dp)+abs(heights[index]-heights[index-2]);
	
	return dp[index]=min(left,right);//return minimum of two recursion and store it in dp[]
}

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
	vector<int> dp(n+1,-1);//initialise dp[] with -1
	return f(n-1,heights,dp);//return recursive function output
}


/////////////////////////////////////////////////////////////////////////////////
//Frog Jump (codestudio) 
//Using Plain Recursion approach [gives TLE]
//TC:2^n SC:n
int f(int index,vector<int> &heights)
{
	if(index==0)return 0;//the energy to jump from 0th index to 0th index is 0

	//left recursion call
	int left=f(index-1,heights)+abs(heights[index]-heights[index-1]);
	
	//right recursion call
	int right=INT_MAX;
	if(index>1)//if valid index
	right=f(index-2,heights)+abs(heights[index]-heights[index-2]);
	
	return min(left,right);//return minimum of two recursion
}

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
	return f(n-1,heights);//return recursive function output
}


