/*
1402. Reducing Dishes

https://leetcode.com/problems/reducing-dishes/description/

******************************************************************************************************
SIMILAR TO KNAPSACK PROBLEM INCL, EXCL GAME
******************************************************************************************************

A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.

Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].

Return the maximum sum of like-time coefficient that the chef can obtain after preparing some amount of dishes.

Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.

 

Example 1:

Input: satisfaction = [-1,-8,0,5,-9]
Output: 14
Explanation: After Removing the second and last dish, the maximum total like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14).
Each dish is prepared in one unit of time.
Example 2:

Input: satisfaction = [4,3,2]
Output: 20
Explanation: Dishes can be prepared in any order, (2*1 + 3*2 + 4*3 = 20)
Example 3:

Input: satisfaction = [-1,-4,-5]
Output: 0
Explanation: People do not like the dishes. No dish is prepared. So maxi is 0


*/

class Solution {
public:
    // Memoization
    int solvedp(vector<int>&satisfy, vector<vector<int>>&dp, int index, int time){
        if(index == satisfy.size()){
            return 0;
        }
        if(dp[index][time] != -1){
            return dp[index][time];
        }
        int incl = (satisfy[index] * time) + solvedp(satisfy, dp, index+1, time+1);
        int excl = 0 + solvedp(satisfy, dp, index+1, time);

        return dp[index][time] = max(incl, excl);
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        // return solvedp(satisfaction, dp, 0, 1);

        // Tabulation
        for(int index=n-1; index>=0; index--){
            for(int time=n-1; time>=0; time--){
                int incl = (satisfaction[index] * (time + 1)) + dp[index+1][time+1];
                int excl = 0 + dp[index+1][time];

                dp[index][time] = max(incl, excl);
            }
        }
        return dp[0][0];
        
    }
};

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        vector<int>curr(n+1, 0);
        vector<int>prev(n+1, 0);
        for(int index=n-1; index>=0; index--){
            for(int time=n-1; time>=0; time--){
                int incl = (satisfaction[index] * (time + 1)) + prev[time+1];
                int excl = 0 + prev[time];

                curr[time] = max(incl, excl);
            }
            prev = curr;
        }
        return curr[0];
        
    }
};