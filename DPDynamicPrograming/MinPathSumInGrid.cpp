/*
64. Minimum Path Sum

https://leetcode.com/problems/minimum-path-sum/

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example 1:
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

Example 2:
Input: grid = [[1,2,3],[4,5,6]]
Output: 12
 
*/
class Solution {
public:
    int solveDP(int row, int col, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(row >= m || col >= n){
            return INT_MAX;
        }
        if(row == m - 1 && col == n - 1){
            return grid[row][col];
        }
        if(dp[row][col] != -1){
            return dp[row][col];
        }
        int right = solveDP(row, col + 1, m, n, grid, dp);
        int down = solveDP(row + 1, col, m, n, grid, dp);

        dp[row][col] = grid[row][col] + min(right, down);

        return dp[row][col];

    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        // int ans = INT_MAX;
        return solveDP(0, 0, m, n, grid, dp);
    }
};