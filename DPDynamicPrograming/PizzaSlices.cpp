/*
1388. Pizza With 3n Slices

******************************************************************************************************
SIMILAR TO HOUSE ROBBERY PROBLEM WTH CIRCULAR ARRAY WHERE NO ADJACENT ELEMENTS CAN BE PICKED
******************************************************************************************************

https://leetcode.com/problems/pizza-with-3n-slices/description/

There is a pizza with 3n slices of varying size, you and your friends will take slices of pizza as follows:

You will pick any pizza slice.
Your friend Alice will pick the next slice in the anti-clockwise direction of your pick.
Your friend Bob will pick the next slice in the clockwise direction of your pick.
Repeat until there are no more slices of pizzas.
Given an integer array slices that represent the sizes of the pizza slices in a clockwise direction, return the maximum possible sum of slice sizes that you can pick.

Input: slices = [1,2,3,4,5,6]
Output: 10
Explanation: Pick pizza slice of size 4, Alice and Bob will pick slices with size 3 and 5 respectively. Then Pick slices with size 6, finally Alice and Bob will pick slice of size 2 and 1 respectively. Total = 4 + 6.

Input: slices = [8,9,8,6,1,1]
Output: 16
Explanation: Pick pizza slice of size 8 in each turn. If you pick slice with size 9 your partners will pick slices of size 8.
*/

class Solution {
public:
    int solveDP(vector<int>&slices, vector<vector<int>>&dp, int eat, int index, int endindex){
        if(eat == 0 || index > endindex){
            return 0;
        }
        if(dp[index][eat] != -1){
            return dp[index][eat];
        }
        int pick = slices[index] + solveDP(slices, dp, eat-1, index+2, endindex);
        int notpick = 0 + solveDP(slices, dp, eat, index+1, endindex);

        return dp[index][eat] = max(pick , notpick);
    } 

    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();

        // case 1 when starting from the 0th index
        vector<vector<int>>dp1(n, vector<int>(n/3+1, -1));
        int case1 = solveDP(slices, dp1, n/3, 0, n-2);
        
        // case 2 when starting from the 0th index
        vector<vector<int>>dp2(n, vector<int>(n/3+1, -1));
        int case2 = solveDP(slices, dp2, n/3, 1, n-1);

        return max(case1, case2);
    }
};