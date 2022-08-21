//https://www.codingninjas.com/codestudio/problems/selling-stock_630282
// Best Time to Buy and Sell Stock II (gives AC)
// Using Bottom Up Approach SPACE OPTIMIZED
// TC:2*n SC:4

long getMaximumProfit(long *values, int n)
{
    vector<long> ahead(2,0),curr(2,0);
    ahead[0]=ahead[1]=0;
    for(int i=n-1;i>=0;i--)
    {
        for(int buy=0;buy<=1;buy++)
        {
            long profit=0;
            if(buy)//if you are allowed to buy:
            {
                //when buying you are basically subtracting from profit and
                //going to next index hoping to sell OR
                //not buying this inorder to buy next time;
                profit=max(-values[i]+ahead[0],
                           0+ahead[1]);
            }
            else//if you are NOT allowed to buy:
            {
                 //when not buying you are basically adding to profit by selling and
                //going to next index hoping to buy OR
                //not selling this inorder to sell next time;

                profit=max(values[i]+ahead[1],
                           0+ahead[0]);
            }
            curr[buy]=profit;
        }
        ahead=curr;
    }
    
    return ahead[1];
}


/////////////////////////////////////////////////////

// Best Time to Buy and Sell Stock II (gives AC)
// Using Bottom Up Approach
// TC:2*n SC:2*n

long getMaximumProfit(long *values, int n)
{
    vector<vector<long>> dp(n+1,vector<long>(2,0));
    dp[n][0]=dp[n][1]=0;
    for(int i=n-1;i>=0;i--)
    {
        for(int buy=0;buy<=1;buy++)
        {
            long profit=0;
            if(buy)//if you are allowed to buy:
            {
                //when buying you are basically subtracting from profit and
                //going to next index hoping to sell OR
                //not buying this inorder to buy next time;
                profit=max(-values[i]+dp[i+1][0],
                           0+dp[i+1][1]);
            }
            else//if you are NOT allowed to buy:
            {
                 //when not buying you are basically adding to profit by selling and
                //going to next index hoping to buy OR
                //not selling this inorder to sell next time;

                profit=max(values[i]+dp[i+1][1],
                           0+dp[i+1][0]);
            }
            dp[i][buy]=profit;
        }
    }
    
    return dp[0][1];
}


/////////////////////////////////////////////////////////

// Best Time to Buy and Sell Stock II (gives AC)
// Using Top Down
// TC:2*n SC:2*n+n
long f(int i,int buy,long *values, int& n,vector<vector<long>>& dp)
{
    if(i==n)return 0;
    long profit=0;
    if(dp[i][buy]!=-1)return dp[i][buy];
    if(buy)//if you are allowed to buy:
    {
        //when buying you are basically subtracting from profit and
        //going to next index hoping to sell OR
        //not buying this inorder to buy next time;
        profit=max(-values[i]+f(i+1,0,values,n,dp),
                   0+f(i+1,1,values,n,dp));
    }
    else//if you are NOT allowed to buy:
    {
         //when not buying you are basically adding to profit by selling and
        //going to next index hoping to buy OR
        //not selling this inorder to sell next time;

        profit=max(values[i]+f(i+1,1,values,n,dp),
                   0+f(i+1,0,values,n,dp));
    }
    return dp[i][buy]=profit;
}

long getMaximumProfit(long *values, int n)
{
    vector<vector<long>> dp(n,vector<long>(2,-1));
    return f(0,1,values,n,dp);
}


//////////////////////////////////////////////////////////////////

// Best Time to Buy and Sell Stock II (gives TLE)
// Using Recusrion
// TC:2^n SC:n
long f(int i,int buy,long *values, int& n)
{
    if(i==n)return 0;
    long profit=0;
    if(buy)//if you are allowed to buy:
    {
        //when buying you are basically subtracting from profit and
        //going to next index hoping to sell OR
        //not buying this inorder to buy next time;
        profit=max(-values[i]+f(i+1,0,values,n),
                   0+f(i+1,1,values,n));
    }
    else//if you are NOT allowed to buy:
    {
         //when not buying you are basically adding to profit by selling and
        //going to next index hoping to buy OR
        //not selling this inorder to sell next time;

        profit=max(values[i]+f(i+1,1,values,n),
                   0+f(i+1,0,values,n));
    }
    return profit;
}

long getMaximumProfit(long *values, int n)
{
    return f(0,1,values,n);
}


