




/* Function to check if x is power of 2*/
// https://www.geeksforgeeks.org/program-to-find-whether-a-given-number-is-power-of-2/
// Time complexity : O(1) Space complexity : O(1) 
bool isPowerOfTwo (int x)
{
    /* First x in the below expression is for the case when x is 0 */
    return x && (!(x&(x-1)));
}