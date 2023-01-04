#include<bits/stdc++.h>
using namespace std;
//https://atcoder.jp/contests/dp/tasks/dp_b

//B - Frog 2 (Atcoder) gives AC
//Using Bottom Up approach
//TC:nk SC:n
int main()
{
    //input
    int n,k;cin>>n>>k;
    vector<int> h(n);
    for(int i=0;i<n;i++)
    cin>>h[i];
    
    
   int dp[n]={0};//initialize dp array of size n
   dp[0]=0;//the energy to jump from 0th index to 0th index is 0
   for(int i=1;i<n;i++)//traverse dp arrat from 1st index
   {
       int minSteps=INT_MAX;
       for(int j=1;j<=k;j++)//get the minimum steps required among k steps
       {
           if(i-j>=0)//if index is valid
           {
              int jumpEnergy=dp[i-j]+abs(h[i]-h[i-j]);//store energy required to jump from i to i+k th jumps
            minSteps=min(minSteps,jumpEnergy);//get minimum energy spent among k th jumps 
           }
       }
       dp[i]=minSteps;//store the final minimum jump energy in dp array
   }
   
   //print the minimum energy required to reach nth stone
    cout<<dp[n-1]<<endl;
    
    
    //print dp array
    // for(int i=0;i<n;i++)
    // cout<<dp[i]<<" ";
        
    return 0;
}



//B - Frog 2 (Atcoder) gives AC
//Using Memoized(Top Down) approach
//TC:n*k SC:n+n

int f(int index,int &k,vector<int>& h,vector<int>& dp)
{
    if(index==0)return 0;
    if(dp[index]!=-1)return dp[index];
    int minSteps=INT_MAX;
    
    for(int i=1;i<=k;i++)//get the minimum steps required among k steps
    {
        if(index-i>=0)//if index is valid
        {
            int jumpEnergy=f(index-i,k,h,dp)+abs(h[index]-h[index-i]);//store energy required to jump from i to i+k th jumps
            minSteps=min(minSteps,jumpEnergy);//get minimum energy spent among k th jumps 
        }
    }
    return dp[index]=minSteps;//return the final minimum jump energy required to get to index
}
int main()
{
    //input
    int n,k;cin>>n>>k;
    vector<int> h(n);
    for(int i=0;i<n;i++)
    cin>>h[i];
    
    //initialising dp array with -1
    vector<int> dp(n);
    for(int i=0;i<n;i++)
    dp[i]=-1;
    
    dp[0]=0;
    
    //print the output of Recursion
    cout<<f(n-1,k,h,dp)<<endl;
    
    return 0;
}



//B - Frog 2 (Atcoder) gives TLE
//Using Plain Recursion approach
//TC:k^n SC:n

int f(int index,int &k,vector<int>& h)
{
    if(index==0)return 0;
    int minSteps=INT_MAX;
    
    for(int i=1;i<=k;i++)//get the minimum steps required among k steps
    {
        if(index-i>=0)//if index is valid
        {
            int jumpEnergy=f(index-i,k,h)+abs(h[index]-h[index-i]);//store energy required to jump from i to i+k th jumps
            minSteps=min(minSteps,jumpEnergy);//get minimum energy spent among k th jumps 
        }
    }
    return minSteps;//return the final minimum jump energy required to get to index
}
int main()
{
    //input
    int n,k;cin>>n>>k;
    vector<int> h(n);
    for(int i=0;i<n;i++)
    cin>>h[i];
    
    //print the output of Recursion
    cout<<f(n-1,k,h)<<endl;
    
    return 0;
}


// Solution of follow up: Space Optimized to k

// Approach:

// 1. Maintain a Linked List which will contain AT MOST K nodes, (analogous to DP array of size K)

// 2. For i'th state, traverse through the linked list to access previous K dp states to find the minimum energy required for the jump.

// 3. Now, to store the result, 
//      a. if LinkedList already has K nodes, then 
//               i. remove the HEAD node from list
//               ii. update HEAD
//               iii. to store the result and attach it to TAIL. 
//      b. else,
//               i. create a new node and attach it to the TAIL of the linked list.

// Note: This is the reason Linked List is used instead of an array to shift the elements in O(1) time.

// Note: We can use Queues and Iterators also for the same purpose, but memory reuse won't be possible.

// Time Complexity: O(N*K), Space Complexity: O(K)

// Code:
// public class Solution {
//     static FrogKJumps obj = new FrogKJumps();
  
//     public static int frogJump(int n, int heights[]) {
//         return obj.minJumps(heights,2);
//     }

// }

// class FrogKJumps {

//     static class Node {
//         int val;
//         Node next;

//         Node(int val) {
//             this.val = val;
//         }
//     }

//     public int minJumps(int[] heights, int k) {

//         if (heights == null || heights.length < 2)
//             return 0;

//         Node[] headTailRef = { null, null }; // 0th index = head, 1st index = tail
//         boolean hasAtLeastKNodes = false;

//         headTailRef[0] = headTailRef[1] = new Node(0);

//         for (int i = 1; i < heights.length; i++) {
//             int j = Math.max(0, i - k);
//             int minEnergy = Integer.MAX_VALUE;
//             Node nodeItr = headTailRef[0];
            
//             for (; j < i; j++, nodeItr = nodeItr.next) {
//                 minEnergy = Math.min(minEnergy, Math.abs(heights[i] - heights[j]) + nodeItr.val);
//             }

//             append(headTailRef, hasAtLeastKNodes, minEnergy);

//             hasAtLeastKNodes = i >= k - 1;
//         }

//         return headTailRef[1].val; // analogous to dp[n-1]

//     }

//     /**
//      * if willEvictHead is true, then uses the current head node as next node
//      * (analogous to FIFO replacement strategy)
//      * else, a new node is created and attached to end of linked list
//      * 
//      * Assumes, linked list contains at least one node
//      */
//     private void append(Node[] headTailRef, boolean willEvictHead, int data) {
//         if (willEvictHead) {
//             Node head = headTailRef[0];

//             head.val = data;
//             headTailRef[0] = head.next;

//             headTailRef[1].next = head;
//         } else {
//             headTailRef[1].next = new Node(data);
//         }
//         headTailRef[1] = headTailRef[1].next;
//     }

//     public static void main(String[] args) {
//         int[] heights = { 4, 8, 3, 10, 4, 4 };
//         int k = 2;

//         System.out.println(new FrogKJumps().minJumps(heights, k));
//     }
// }

// Github Gist: /SujanKumarMitra/0544d830e41ca55f858976fbbb5a7491