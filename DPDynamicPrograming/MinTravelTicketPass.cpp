/*
983. Minimum Cost For Tickets

https://leetcode.com/problems/minimum-cost-for-tickets/description/

You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.

Train tickets are sold in three different ways:
a 1-day pass is sold for costs[0] dollars,
a 7-day pass is sold for costs[1] dollars, and
a 30-day pass is sold for costs[2] dollars.

The passes allow that many days of consecutive travel.
For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
Return the minimum number of dollars you need to travel every day in the given list of days.

Example 1:
Input: days = [1,4,6,7,8,20], costs = [2,7,15]
Output: 11
Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
On day 4, you bought a 7-day pass for costs[1] = $7, which covered days  4,5,..., 9.
On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
In total, you spent $11 and covered all the days of your travel.

Example 2:
Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
Output: 17
Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 30-day pass for costs[2] = $15 which covered days 1, 2, ..., 30.
On day 31, you bought a 1-day pass for costs[0] = $2 which covered day 31.
In total, you spent $17 and covered all the days of your travel.
*/

class Solution {
public:
    int solveDP(int idx, const vector<int>& days, const vector<int>& costs, vector<int>& dp) {
        if (idx >= days.size()){
            return 0; // No more travel days, cost is 0
        }
        if (dp[idx] != -1){
            return dp[idx];
        }
        // 1-day pass
        int option1 = costs[0] + solveDP(idx + 1, days, costs, dp);
        
        // 7-day pass
        int i = idx;
        while (i < days.size() && days[i] < days[idx] + 7) i++;
        int option2 = costs[1] + solveDP(i, days, costs, dp);
        
        // 30-day pass
        int j = idx;
        while (j < days.size() && days[j] < days[idx] + 30) j++;
        int option3 = costs[2] + solveDP(j, days, costs, dp);
        
        return dp[idx] = min({option1, option2, option3});
    }

    int solveMem(vector<int>& days, vector<int>& costs){
        vector<int>dp(366, 0);

        for(int idx=days.size()-1; idx>=0; idx--){
            int option1 = costs[0] + dp[idx+1];
        
            // 7-day pass
            int i = idx;
            while (i < days.size() && days[i] < days[idx] + 7) i++;
            int option2 = costs[1] + dp[i];
            
            // 30-day pass
            int j = idx;
            while (j < days.size() && days[j] < days[idx] + 30) j++;
            int option3 = costs[2] + dp[j];
            
            dp[idx] = min({option1, option2, option3});
        }
        return dp[0];
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // vector<int> dp(days.size(), -1);
        // return solveDP(0, days, costs, dp);

        return solveMem(days, costs);
    }
};
