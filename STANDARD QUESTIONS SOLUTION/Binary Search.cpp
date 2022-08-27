


NO.1******Nth Root Of M***************************

Problem Statement: Given two numbers N and M, find the Nth root of M.
The nth root of a number M is defined as a number X when raised to the power N equals M.

Example 1:
Input: N=3 M=27
Output: 3
Explanation: The cube root of 27 is 3.
///////////////////////////////////////////////////////////////////////

double multiply(double x,int n)
{
    double quotient=1.0;
    for(int i=0;i<n;i++)
    {
        quotient=quotient*x;
    }
    return quotient;
}

double findNthRootOfM(int n, int m) 
{
    double low=1;
    double high=m;
    double epsilon=1e-8;//the precision upto which we will find root
    
    while((high-low)>epsilon)//we will runn while loop until differnce between high and low is negligle upto precision
    {
        double mid=(high+low)/2.0;
        if(multiply(mid,n)<m)//mid^n<m
            low=mid;
        else
            high=mid;
    }
    return high;//either high or low will give same result cuz the difference is les than 1e-6
}

https://www.codingninjas.com/codestudio/problems/1062679?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0 Of M
TC:Nlog(M*10^d)   ;where d is the decimal precision
SC:1
---------------------------------------------------------------------------------



NO.2******Single Number***************************
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.


Example 1:

Input: nums = [2,2,1]
Output: 1
Example 2:

Input: nums = [4,1,2,1,2]
Output: 4
Example 3:

Input: nums = [1]
Output: 1
////////////////////////////////////////////////////////////////////////

int singleNumber(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int low=0;
        int high=nums.size()-2;//To counter a an edge case
        while(low<=high)
        {
            int mid=(high+low)/2;
            
            //check if mid value is in left portion of array
            if(nums[mid]==nums[mid^1])
                low=mid+1;//Then go towards right
            else//else mid value is in right portion of array
                high=mid-1;//Then go towards left
        }
        return nums[low];
    }

https://leetcode.com/problems/single-number/
TC:logN   
SC:1
-------------------------------------------------------------------------------------------------------



NO.3******Search in Rotated Sorted Array*****************

There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
////////////////////////////////////////////////////////////////////////////////////

int search(vector<int>& nums, int target) 
    {
        int low=0,high=nums.size()-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==target)return mid;
            
            //check if left halve of array is sorted or not
            if(nums[low]<=nums[mid])
            {
                if(nums[low]<=target && target<=nums[mid])//if target lies between low and mid
                    high=mid-1;
                else
                    low=mid+1;
            }
            //check if right halve of array is sorted or not
            else
            {
                if(nums[mid]<=target && target<=nums[high])//if target lies between high and mid
                    low=mid+1;
                else
                    high=mid-1;
            }
        }
        return -1;
    }


https://leetcode.com/problems/search-in-rotated-sorted-array/
TC:logN   
SC:1

-------------------------------------------------------------------------------------------------