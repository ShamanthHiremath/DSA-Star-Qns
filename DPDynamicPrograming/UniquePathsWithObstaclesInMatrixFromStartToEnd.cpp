/*
63. Unique Paths II

https://leetcode.com/problems/unique-paths-ii/

You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.

*/

class Solution {
public:
    int solveDP(int row, int col, int &m, int &n, vector<vector<int>>&dp, vector<vector<int>>& obstacleGrid){
        if(row == m-1 && col == n-1){
            // end reached
            return 1;
        }
        else if(row >=m || col >= n || obstacleGrid[row][col] == 1){
            // out of bounds or obstacles found
            return 0;
        }
        else if(dp[row][col] != -1){
            return dp[row][col];
        }
        int down = 0, right = 0;
        if(row<m && col<n){
            down = solveDP(row+1, col, m, n, dp, obstacleGrid);
            right = solveDP(row, col+1, m, n, dp, obstacleGrid);
        }

        // talks about the no of unique possible ways so its a sum of down and right
        return dp[row][col] = down + right;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] || obstacleGrid[m-1][n-1]){
            return 0;
        }
        vector<vector<int>>dp(m, (vector<int>(n, -1)));
        return solveDP(0, 0, m, n, dp, obstacleGrid);
    }
};