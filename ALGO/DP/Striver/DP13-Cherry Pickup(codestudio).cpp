//https://www.codingninjas.com/codestudio/problems/ninja-and-his-friends_3125885?leftPanelTab=1

//Ninja And His Friends(codestudio) gives TLE
//Using Tabulation SPACE OPTIMZED approach
//TC:n*m*m*9 SC:m*m (front array)

int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
    // Write your code here.
	 vector<vector<int>> front(m,vector<int>(m,0));

  for (int j1 = 0; j1 < m; j1++) {
    for (int j2 = 0; j2 < m; j2++) {
      if (j1 == j2)
        front[j1][j2] = grid[n - 1][j1];
      else
        front[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
    }
  }

  //Outer Nested Loops for travering DP Array
  for (int i = n - 2; i >= 0; i--) 
  {
	 vector<vector<int>> curr(m,vector<int>(m,0));
    for (int j1 = 0; j1 < m; j1++) 
	{
      for (int j2 = 0; j2 < m; j2++) 
	  {
        int maxi = INT_MIN;

        //Inner nested loops to try out 9 options
        for (int di = -1; di <= 1; di++) {
          for (int dj = -1; dj <= 1; dj++) {

            int ans;

            if (j1 == j2)
              ans = grid[i][j1];
            else
              ans = grid[i][j1] + grid[i][j2];

            if ((j1 + di < 0 || j1 + di >= m) ||
              (j2 + dj < 0 || j2 + dj >= m))

              ans += -1e9;
            else
              ans += front[j1 + di][j2 + dj];

            maxi = max(ans, maxi);
          }
        }
        curr[j1][j2] = maxi;
      }
    }
	  front=curr;
  }

  return front[0][m - 1];
}



////////////////////////////////////////////////////////////////////////////////////


//Ninja And His Friends(codestudio) gives TLE
//Using Tabulation approach
//TC:n*m*m*9 SC:n*m*m (dp array)

int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
    // Write your code here.
	vector < vector < vector < int >>> dp(n, vector < vector < int >> (m, 
  vector < int > (m, 0)));

  for (int j1 = 0; j1 < m; j1++) {
    for (int j2 = 0; j2 < m; j2++) {
      if (j1 == j2)
        dp[n - 1][j1][j2] = grid[n - 1][j1];
      else
        dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
    }
  }

  //Outer Nested Loops for travering DP Array
  for (int i = n - 2; i >= 0; i--) {
    for (int j1 = 0; j1 < m; j1++) {
      for (int j2 = 0; j2 < m; j2++) {

        int maxi = INT_MIN;

        //Inner nested loops to try out 9 options
        for (int di = -1; di <= 1; di++) {
          for (int dj = -1; dj <= 1; dj++) {

            int ans;

            if (j1 == j2)
              ans = grid[i][j1];
            else
              ans = grid[i][j1] + grid[i][j2];

            if ((j1 + di < 0 || j1 + di >= m) ||
              (j2 + dj < 0 || j2 + dj >= m))

              ans += -1e9;
            else
              ans += dp[i + 1][j1 + di][j2 + dj];

            maxi = max(ans, maxi);
          }
        }
        dp[i][j1][j2] = maxi;
      }
    }
  }

  return dp[0][0][m - 1];
}

///////////////////////////////////////////////////////////////////////////

//Ninja And His Friends(codestudio) gives TLE
//Using Top Down approach
//TC:n*m*m*9 SC:n*m*m +n (dp array+ aux space)


int f(int i,int j1,int j2,int& r, int& c, vector<vector<int>> &grid,vector<vector<vector<int>>>& dp)
{
	if(j1<0 || j2<0 || j1>=c || j2>=c)//boundary conditions
		return -1e8;
	if(i==r-1)//reached bottom row
	{
		if(j1!=j2)return grid[i][j1]+grid[i][j2];
		else return grid[i][j1];
	}
	if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
	int maxi=-1e8;
	for(int dj1=-1;dj1<=1;dj1++)//check in all directions
	{
		for(int dj2=-1;dj2<=1;dj2++)
		{
			int value=0;
			if(j1!=j2)value=grid[i][j1]+grid[i][j2];
			else value=grid[i][j1];
			value+=f(i+1,j1+dj1,j2+dj2,r,c,grid,dp);
			maxi=max(maxi,value);
		}
	}
	return dp[i][j1][j2]=maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
	vector<vector<vector<int>>> dp(r,vector<vector<int>> (c,vector<int> (c,-1)));
	return f(0,0,c-1,r,c,grid,dp);
}


////////////////////////////////////////////////////////////////////////////////////


//Ninja And His Friends(codestudio) gives TLE
//Using Recursive approach
//TC:(3^n)*(3^n) SC:n (length of row)


int f(int i,int j1,int j2,int& r, int& c, vector<vector<int>> &grid)
{
	if(j1<0 || j2<0 || j1>=c || j2>=c)//boundary conditions
		return -1e8;
	if(i==r-1)//reached bottom row
	{
		if(j1!=j2)return grid[i][j1]+grid[i][j2];
		else return grid[i][j1];
	}
	int maxi=-1e8;
	for(int dj1=-1;dj1<=1;dj1++)//check in all directions
	{
		for(int dj2=-1;dj2<=1;dj2++)
		{
			int value=0;
			if(j1!=j2)value=grid[i][j1]+grid[i][j2];
			else value=grid[i][j1];
			value+=f(i+1,j1+dj1,j2+dj2,r,c,grid);
			maxi=max(maxi,value);
		}
	}
	return maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
	return f(0,0,c-1,r,c,grid);
}