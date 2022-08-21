//https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003


//Ninja’s Training (codestudio) gives AC
//Using Bottom Up SPACE OPTIMZED approach
//TC:4n*3 SC:4


int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
 vector < int > prev(4, 0);//1*4 matrix initialized with -0

  //declaring initial states at day 0
  prev[0] = max(points[0][1], points[0][2]);
  prev[1] = max(points[0][0], points[0][2]);
  prev[2] = max(points[0][0], points[0][1]);
  prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

	
	for(int day=1;day<n;day++)//visit the 'day' row
	{
		vector <int> temp(4, 0);//stores current optimize values
		for(int last=0;last<4;last++)//visit the 'last' column
		{
			
			temp[last]=0;//initialise previous state 'last' cell value to 0
			for(int task=0;task<3;task++)
			{
				if(task!=last)//check if current task is not as same as prevous day's task
				{
					temp[last]=max(temp[last],points[day][task]+prev[task]);//take max of points
				}
			}
			
		}
		prev=temp;//previous becomes temp for next iteration
	}
	return prev[3];//the first last work is 3, which doenot exist,so we can choose any work in first day
}


//////////////////////////////////////////////////////////////////////

//Ninja’s Training (codestudio) gives AC
//Using Bottom Up approach
//TC:4n*3 SC:4n

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
	vector < vector < int > > dp(n, vector < int > (4, 0));//4*n matrix initialized with -1

  //declaring initial states at day 0
  dp[0][0] = max(points[0][1], points[0][2]);
  dp[0][1] = max(points[0][0], points[0][2]);
  dp[0][2] = max(points[0][0], points[0][1]);
  dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

	
	for(int day=1;day<n;day++)//visit the 'day' row
	{
		for(int last=0;last<4;last++)//visit the 'last' column
		{
			dp[day][last]=0;//initialise current dp cell value to 0;
			for(int task=0;task<3;task++)
			{
				if(task!=last)//check if current task is not as same as prevous day's task
				{
					int point=points[day][task]+dp[day-1][task];//todays point+previus days points
					dp[day][last]=max(dp[day][last],point);//take max of points
				}
			}
			
		}
	}
	return dp[n-1][3];//the first last work is 3, which doenot exist,so we can choose any work in first day
}



/////////////////////////////////////////////////////////////////////////////////////

//Ninja’s Training (codestudio) gives AC
//Using Top Down approach
//TC:4n*3 SC:n+4n

int f(int day,int last,vector<vector<int>> &points,vector<vector<int>>& dp)
{
	if(day==0)//BASE CASE
	{
		int maxpoints=0;
		for(int i=0;i<3;i++)//days are 0 1 2.
			if(i!=last)//if if it aint the same work done in previous day
				maxpoints=max(maxpoints,points[0][i]);//take the maximum of the work that can be done
		return maxpoints;
	}
	if(dp[day][last]!=-1)return dp[day][last];//if memoized return the value
	int maxpoints=0;
	for(int i=0;i<3;i++)
	{
		if(i!=last)//if if it aint the same work done in previous day
		{
			int point=points[day][i]+f(day-1,i,points,dp);//take current work and addthe previous day;'s work'
			maxpoints=max(maxpoints,point);//take the maximum of the work that can be done
		}
	}
	return dp[day][last]=maxpoints;//memoize and return
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
	vector<vector<int>> dp(n,vector<int>(4,-1));//4*n matrix initialized with -1
	return f(n-1,3,points,dp);//the first last work is 3, which doenot exist,so we can choose any work in first day
}



////////////////////////////////////////////////////////////////////////////////


//Ninja’s Training (codestudio) gives TLE
//Using Recursive approach
//TC:3^n SC:n

int f(int day,int last,vector<vector<int>> &points)
{
	if(day==0)//BASE CASE
	{
		int maxpoints=0;
		for(int i=0;i<3;i++)//days are 0 1 2.
			if(i!=last)//if if it aint the same work done in previous day
				maxpoints=max(maxpoints,points[0][i]);//take the maximum of the work that can be done
		return maxpoints;
	}
	int maxpoints=0;
	for(int i=0;i<3;i++)
	{
		if(i!=last)//if if it aint the same work done in previous day
		{
			int point=points[day][i]+f(day-1,i,points);//take current work and addthe previous day;'s work'
			maxpoints=max(maxpoints,point);//take the maximum of the work that can be done
		}
	}
	return maxpoints;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
	return f(n-1,3,points);//the first last work is 3, which doenot exist,so we can choose any work in first day
}