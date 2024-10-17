/*
123. Best Time to Buy and Sell Stock III

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again)

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
*/
class Solution {
public:
    int solveDP(int index, bool buy, int transactions, vector<int>& prices, vector<vector<vector<int>>>&dp){
        if(index == prices.size() ||transactions == 2 ){
            return 0;
        }
        if(dp[index][buy][transactions] != -1){
            return dp[index][buy][transactions];
        }
        int profit = 0;
        if(buy){
            int incl = -prices[index] + solveDP(index+1, false, transactions, prices, dp);
            int excl = 0 + solveDP(index+1, true, transactions, prices, dp);
            profit = max(incl, excl);
        }
        else{
            int incl = prices[index] + solveDP(index+1, true, transactions+1, prices, dp);
            int excl = 0 + solveDP(index+1, false, transactions, prices, dp);
            profit = max(incl, excl);
        }

        return dp[index][buy][transactions] = profit;
    }
    int maxProfit(vector<int>& prices) {
        bool buy = true;
        vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>>(2, vector<int>(3, -1)));
        return solveDP(0, true, 0, prices,dp);
    }
};