

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
-----------------------------------------------------------------------------------------

2.Repeat and Missing Number
https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/

// Make two equations using sum and sum of squares
vector<int>repeatedNumber(const vector<int> &A) {
    long long int len = A.size();
    long long int Sum_N = (len * (len+1) ) /2, Sum_NSq = (len * (len +1) *(2*len +1) )/6;
    long long int missingNumber=0, repeating=0;
     
    for(int i=0;i<A.size(); i++){
       Sum_N -= (long long int)A[i];
       Sum_NSq -= (long long int)A[i]*(long long int)A[i];
    }
     
    missingNumber = (Sum_N + Sum_NSq/Sum_N)/2;
    repeating= missingNumber - Sum_N;
    vector <int> ans;
    ans.push_back(repeating);
    ans.push_back(missingNumber);
    return ans;
     
}

-----------------------------------------------------------------------------------------

3.Merge two sorted Arrays without extra space
https://www.geeksforgeeks.org/efficiently-merging-two-sorted-arrays-with-o1-extra-space/
https://www.techiedelight.com/inplace-merge-two-sorted-arrays/
 
// Utility function to print contents of an array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
 
// Function to in-place merge two sorted arrays X[] and Y[]
// invariant: `X[]` and `Y[]` are sorted at any point
void merge(int X[], int Y[], int m, int n)
{
    // Consider each element `X[i]` of array `X` and ignore the element if it is
    // already in the correct order; otherwise, swap it with the next smaller
    // element, which happens to be the first element of `Y`.
    for (int i = 0; i < m; i++)
    {
        // compare the current element of `X[]` with the first element of `Y[]`
        if (X[i] > Y[0])
        {
            swap(X[i], Y[0]);
            int first = Y[0];
 
            // move `Y[0]` to its correct position to maintain the sorted
            // order of `Y[]`. Note: `Y[1…n-1]` is already sorted
            int k;
            for (k = 1; k < n && Y[k] < first; k++) {
                Y[k - 1] = Y[k];
            }
 
            Y[k - 1] = first;
        }
    }
}
 
int main()
{
    int X[] = { 1, 4, 7, 8, 10 };
    int Y[] = { 2, 3, 9 };
 
    int m = sizeof(X) / sizeof(X[0]);
    int n = sizeof(Y) / sizeof(Y[0]);
 
    merge(X, Y, m, n);
 
    cout << "X: "; printArray(X, m);
    cout << "Y: "; printArray(Y, n);
 
    return 0;
}

-----------------------------------------------------------------------------------------

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

-----------------------------------------------------------------------------------------

5. Merge Overlapping Subintervals
https://www.youtube.com/watch?v=2JzRBPFYbKE&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=7
https://leetcode.com/problems/merge-intervals/