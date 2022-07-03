//https://www.codingninjas.com/codestudio/problems/can-you-make_4244510
//Minimum Number of Deletions and Insertions(codestudio)
//Using Bottom Up Space Optimized approach
//TC:n*m  SC:n

int lcs(string s, string t)
{
	//Write your code here
	int m=s.length();
	int n=t.length();
	vector<int> prev(n+1,0),curr(n+1,0);
	
	//Base Case fill
	for(int j=0;j<=n;j++)
		prev[j]=0;
	
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(s[i-1]==t[j-1])
			curr[j]=1+prev[j-1];
			else
			curr[j]=max(curr[j-1],prev[j]);
		}
		prev=curr;
	}
	
	return prev[n];
}

int canYouMake(string &str, string &ptr)
{
    // Write your code here.
	int m=str.length();
	int n=ptr.length();
	int deletions=m-lcs(str,ptr);
	int insertions=n-lcs(str,ptr);
	return insertions+deletions;
}