/*
120. Triangle

https://leetcode.com/problems/triangle/

Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.


Example 1:
Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).

Example 2:
Input: triangle = [[-10]]
Output: -10
 
*/
class Solution {
public:
    int solve(int ind, int row, vector<vector<int>>& triangle, vector<vector<int>>&dp){
        if(row >= triangle.size()){
            return 0;
        }

        if(dp[ind][row] != -1){
            return dp[ind][row];
        }

        int ans = triangle[row][ind];
        int left = solve(ind, row+1, triangle, dp);
        int right =  solve(ind+1, row+1, triangle, dp);

       
        return dp[ind][row] = ans + min(left, right);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return solve(0, 0, triangle, dp);
    }
};