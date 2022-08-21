//https://www.codingninjas.com/codestudio/problems/stocks-are-profitable_893405
//Best Time to Buy and Sell Stock
//TC:n SC:1
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int n=prices.size();
    int min_price=prices[0];
    int max_profit=0;
    //start sell index from 1 because initially we held index 0 for 
    //for initial buy price
    for(int i=1;i<n;i++)
    {
        int profit=prices[i]-min_price;//calculates the current profit
        max_profit=max(max_profit,profit);//stoes max profit
        min_price=min(min_price,prices[i]);//if current price less than prevous min_price, then update
    }
    return max_profit;
}