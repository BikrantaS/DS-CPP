

Day1: (Arrays)

1. Sort an array of 0’s 1’s 2’s without using extra space or sorting algo
https://leetcode.com/problems/sort-colors/
****DUTCH NATIONAL FLAG ALGORITHM************

class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int low=0;
        int mid=0;
        int high=nums.size()-1;
        while(mid<=high)
        {
            if(nums[mid]==2)
            {
                swap(nums[mid],nums[high]);
                high--;
            }
            else if(nums[mid]==0)
            {
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid]==1)
            {
                mid++;
            }
        }  
    }
};


2.Repeat and Missing Number
https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/

3.Merge two sorted Arrays without extra space
https://www.geeksforgeeks.org/efficiently-merging-two-sorted-arrays-with-o1-extra-space/
https://www.techiedelight.com/inplace-merge-two-sorted-arrays/

4. KADANE'S ALGORITHM
https://leetcode.com/problems/maximum-subarray/
****KADANE'S ALGORITHM*********

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len=nums.size();
        int maxsum=nums[0];
        int currsum=0;
        for(int i=0;i<len;i++)
        {
            currsum+=nums[i];
            if(currsum>maxsum)maxsum=currsum;
            if(currsum<0)currsum=0;
        }
        return maxsum;
    }
};

