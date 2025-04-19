/*
3218. Minimum Cost for Cutting Cake I

https://leetcode.com/problems/minimum-cost-for-cutting-cake-i/

There is an m x n cake that needs to be cut into 1 x 1 pieces.
You are given integers m, n, and two arrays:
horizontalCut of size m - 1, where horizontalCut[i] represents the cost to cut along the horizontal line i.
verticalCut of size n - 1, where verticalCut[j] represents the cost to cut along the vertical line j.
In one operation, you can choose any piece of cake that is not yet a 1 x 1 square and perform one of the following cuts:

Cut along a horizontal line i at a cost of horizontalCut[i].
Cut along a vertical line j at a cost of verticalCut[j].

After the cut, the piece of cake is divided into two distinct pieces.
The cost of a cut depends only on the initial cost of the line and does not change.

Return the minimum total cost to cut the entire cake into 1 x 1 pieces.

Example 1:
Input: m = 3, n = 2, horizontalCut = [1,3], verticalCut = [5]
Output: 13
Explanation:
Perform a cut on the vertical line 0 with cost 5, current total cost is 5.
Perform a cut on the horizontal line 0 on 3 x 1 subgrid with cost 1.
Perform a cut on the horizontal line 0 on 3 x 1 subgrid with cost 1.
Perform a cut on the horizontal line 1 on 2 x 1 subgrid with cost 3.
Perform a cut on the horizontal line 1 on 2 x 1 subgrid with cost 3.
The total cost is 5 + 1 + 1 + 3 + 3 = 13.

Example 2:
Input: m = 2, n = 2, horizontalCut = [7], verticalCut = [4]
Output: 15
Explanation:
Perform a cut on the horizontal line 0 with cost 7.
Perform a cut on the vertical line 0 on 1 x 2 subgrid with cost 4.
Perform a cut on the vertical line 0 on 1 x 2 subgrid with cost 4.
The total cost is 7 + 4 + 4 = 15.
*/

class Solution {
    public:
    
        int solveDP(int start_row, int start_col, int end_row, int end_col, vector<int>& horizCut, vector<int>& vertiCut, vector<vector<vector<vector<int>>>>&dp){
            // when we have one sized 1x1 (startrow-endrow == 0)  then we return 0 to indicate no cost needed.
            if((end_row - start_row) == 1 and (end_col - start_col) == 1){
                return 0;
            }
    
            if(dp[start_row][start_col][end_row][end_col] != -1){
                return dp[start_row][start_col][end_row][end_col];
            }
            int ans  = INT_MAX;
            // for horizontal cut answers
            for(int next=start_row + 1; next<end_row; next++){
                int cost = horizCut[next-1] + solveDP(start_row, start_col, next, end_col, horizCut, vertiCut, dp) +  solveDP(next, start_col, end_row, end_col, horizCut, vertiCut, dp);
    
                ans = min(ans, cost);
            }
    
            // for vertical cut answers
            for(int next=start_col + 1; next<end_col; next++){
                int cost = vertiCut[next-1] + solveDP(start_row, start_col, end_row, next, horizCut, vertiCut, dp) +  solveDP(start_row, next, end_row, end_col, horizCut, vertiCut, dp);
    
                ans = min(ans, cost);
            }
    
            return dp[start_row][start_col][end_row][end_col] =  ans; 
    
        }
    
        int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
            vector<vector<vector<vector<int>>>> dp(
                m+1, vector<vector<vector<int>>>(
                    n+1, vector<vector<int>>(
                        m+1, vector<int>(n+1, -1)
                    )
                )
            );
    
            return solveDP(0, 0, m, n, horizontalCut, verticalCut, dp);
        }
    };