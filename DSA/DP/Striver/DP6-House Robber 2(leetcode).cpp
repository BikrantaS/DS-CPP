
//https://leetcode.com/problems/house-robber-ii/

//House Robber II (leetcode) gives AC
//Using Bottom UP approach Space Optimized
//TC:n SC:1
    
    int loot(int start,int end,vector<int>& valueInHouse)
    {
        int prev2=0;//non adjacent value
        int prev=0;//adjacent value
        int curr=0;//current value
        for(int i=start;i<=end;i++)
        {
            curr=max(valueInHouse[i]+prev2,prev);//either pick or not pick
            prev2=prev;
            prev=curr;
        }
        return curr;//returns the final state
    }

    int rob(vector<int>& valueInHouse) 
    {
        int n=valueInHouse.size();
        if(n<2)//edge case
            return (n==1)?valueInHouse[0]:0;
        
        int a=loot(0,n-2,valueInHouse);//from first to second last index
        int b=loot(1,n-1,valueInHouse);//from second to last index
         
        return max(a,b);//return the max out of two approach
    }

////////////////////////////////////////////////////////////////////////////////////////////////

//House Robber II (leetcode) gives AC
//Using Bottom UP approach
//TC:n SC:n

    int rob(vector<int>& valueInHouse) 
    {
        int n=valueInHouse.size();
        if(n<2)//edge case
            return (n==1)?valueInHouse[0]:0;
        
        int dpa[n],dpb[n];//dpa[] to check from index 0 to n-2,dpb[] from index 1 to n-1
        for(int i=0;i<n;i++)//always initialise,else leetcode test case will give error
        {
            dpa[i]=0;
            dpb[i]=0;
        }
        dpa[0]=valueInHouse[0];//initialise dpa[]'s first value
        dpb[1]=valueInHouse[1];//initialise dpb[]'s first value
        
        for(int i=0;i<n;i++)//fill dpa[] and dpb[]
        {
            if(i>0 && i<=n-2)//from first to second last index
            {
                int pick=INT_MIN;
                if(i-2>=0)//only take if index is valid
                pick=valueInHouse[i]+dpa[i-2];//pick and add adjacent index's number
                int notpick=dpa[i-1];//if not picked,just call the previous index,since we are not adding anthing,its like picking adjacent number
                dpa[i]=max(pick,notpick);//set current index dpa[] to max of pick and notpick result
            }
            
            if(i>1 && i<=n-1)//from second to last index
            {
                int pick=INT_MIN;
                if(i-2>=0)//only take if index is valid
                pick=valueInHouse[i]+dpb[i-2];//pick and add adjacent index's number
                int notpick=dpb[i-1];//if not picked,just call the previous index,since we are not adding anthing,its like picking adjacent number
                dpb[i]=max(pick,notpick);//set current index dpb[] to max of pick and notpick result
            }
        }
        
         
        return max(dpa[n-2],dpb[n-1]);//return the max out of two approach
    }

////////////////////////////////////////////////////////////////////////////////////

//House Robber II (leetcode) gives AC
//Using Top Down approach
//TC:n SC:n+n
int f(int i,vector<int>& valueInHouse,vector<int>& dp,int start)
    {
        if(i<start)return 0;//if index goes beyond start limit ignore by returning 0
        if(dp[i]!=-1)return dp[i];//return indexed value if already previously calculated
        if(i==start)return valueInHouse[start];//if index reached start postion,return its value

        int pick=valueInHouse[i]+f(i-2,valueInHouse,dp,start);//pick and add adjacent index's number
        int notpick=f(i-1,valueInHouse,dp,start);//if not picked,just call the previous index,since we are not adding anthing,its like picking adjacent number
    
        return dp[i]=max(pick,notpick);//return max of pick and notpick result and memoize
    }
    int rob(vector<int>& valueInHouse) 
    {
        int n=valueInHouse.size();
        if(n<2)//edge case
            return (n==1)?valueInHouse[0]:0;
        
        vector<int> dp(n,-1);
        int a=f(n-2,valueInHouse,dp,0);//from first to second last index
        
        fill(dp.begin(), dp.end(),-1);
        int b=f(n-1,valueInHouse,dp,1);//from second to last index
        return max(a,b);//return which ever process get maximum gains          
    }

//////////////////////////////////////////////////////////////////////////////////////////////////

//House Robber II (leetcode) gives TLE
//Using Plain Recursion approach
//TC:2^n SC:n
int f(int i,vector<int>& valueInHouse,int start)
    {
        if(i<start)return 0;//if index goes beyond start limit ignore by returning 0
        if(i==start)return valueInHouse[start];//if index reached start postion,return its value

        int pick=valueInHouse[i]+f(i-2,valueInHouse,start);//pick and add adjacent index's number
        int notpick=f(i-1,valueInHouse,start);//if not picked,just call the previous index,since we are not adding anthing,its like picking adjacent number
        return max(pick,notpick);//return max of pick and notpick result
    }
    int rob(vector<int>& valueInHouse) 
    {
        int n=valueInHouse.size();
        if(n<2)//edge case
            return (n==1)?valueInHouse[0]:0;
        
        int a=f(n-2,valueInHouse,0);//from first to second last index
        int b=f(n-1,valueInHouse,1);//from second to last index
        return max(a,b);//return which ever process get maximum gains          
    }
