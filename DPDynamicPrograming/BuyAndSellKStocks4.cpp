/*
188. Best Time to Buy and Sell Stock IV

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
*/
class Solution {
public:
    int solveDP(int k, int index, bool buy, int transactions, vector<int>& prices, vector<vector<vector<int>>>&dp){
        if(index == prices.size() ||transactions == k ){
            return 0;
        }
        if(dp[index][buy][transactions] != -1){
            return dp[index][buy][transactions];
        }
        int profit = 0;
        if(buy){
            int incl = -prices[index] + solveDP(k, index+1, false, transactions, prices, dp);
            int excl = 0 + solveDP(k, index+1, true, transactions, prices, dp);
            profit = max(profit, max(incl, excl));
        }
        else{
            int incl = prices[index] + solveDP(k, index+1, true, transactions+1, prices, dp);
            int excl = 0 + solveDP(k, index+1, false, transactions, prices, dp);
            profit = max(profit, max(incl, excl));
        }

        return dp[index][buy][transactions] = profit;
    }

    int solveTab(int k, vector<int>& prices){
        vector<vector<int>> next(2, vector<int>(k+1, 0));
        vector<vector<int>> curr(2, vector<int>(k+1, 0));

        for(int index=prices.size()-1; index>=0; index--){
            for(int buy=0; buy<2; buy++){
                for(int transactions=k-1; transactions>=0; transactions--){
                    int profit = 0;
                    if(buy){
                        int incl = -prices[index] + next[false][transactions];
                        int excl = next[true][transactions];
                        profit =  max(incl, excl);
                    }
                    else{
                        int incl = prices[index] +  next[true][transactions+1];
                        int excl =  next[false][transactions];
                        profit = max(incl, excl);
                    }
                    curr[buy][transactions] = profit;
                }
            }
            next = curr;
        }

        return next[1][0];

    } 
    int maxProfit(int k, vector<int>& prices) {
        bool buy = true;
        vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>>(2, vector<int>(3, -1)));
        return solveDP(k, 0, true, 0, prices,dp);
        // return solveTab(k, prices);
    }
};