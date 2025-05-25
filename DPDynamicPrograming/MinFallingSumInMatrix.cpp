/*
931. Minimum Falling Path Sum

https://leetcode.com/problems/minimum-falling-path-sum/

Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

 
Example 1:
Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.

Example 2:
Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.
*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp = matrix;  // copy input matrix

        for(int row = n - 2; row >= 0; --row){
            for(int col = 0; col < n; ++col){
                int down = dp[row + 1][col];
                int left = col > 0 ? dp[row + 1][col - 1] : INT_MAX;
                int right = col < n - 1 ? dp[row + 1][col + 1] : INT_MAX;

                dp[row][col] += min({down, left, right});
            }
        }

        return *min_element(dp[0].begin(), dp[0].end());
    }
};



class Solution {
public:
    int solve(int ind, int row, vector<vector<int>>& matrix, vector<vector<int>>&dp){
        if(row >= matrix.size()){
            return 0;
        }

        if(ind<0 || ind>=matrix.size()){
            return INT_MAX;
        }

        if(dp[ind][row] != -1){
            return dp[ind][row];
        }

        int ans = matrix[row][ind];
        int left = solve(ind-1, row+1, matrix, dp);
        int under = solve(ind, row+1, matrix, dp);
        int right =  solve(ind+1, row+1, matrix, dp);

       
        return dp[ind][row] = ans + min({under, left, right});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
         int n = matrix.size();
        
        int mini = INT_MAX;
        vector<vector<int>>dp(n, vector<int>(n, -1));
        for(int start=0; start<n; start++){
            mini  = min(mini, solve(start, 0, matrix, dp));
        }
        return mini;
    }
};
