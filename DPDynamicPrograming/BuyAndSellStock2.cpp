/*
122. Best Time to Buy and Sell Stock II

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
*/
class Solution {
public:
    int solveDP(int index, bool buy, vector<int>& prices, vector<vector<int>>&dp){
        if(index == prices.size()){
            return 0;
        }
        if(dp[index][buy] != -1){
            return dp[index][buy];
        }
        int profit = 0;
        if(buy){
            int incl = -prices[index] + solveDP(index+1, false, prices, dp);
            int excl = 0 + solveDP(index+1, true, prices, dp);
            profit = max(profit, max(incl, excl));
        }
        else{
            int incl = prices[index] + solveDP(index+1, true, prices, dp);
            int excl = 0 + solveDP(index+1, false, prices, dp);
            profit = max(profit, max(incl, excl));
        }

        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        bool buy = true;
        vector<vector<int>>dp(prices.size()+1, vector<int>(2, -1));
        return solveDP(0, true, prices,dp);
    }
};