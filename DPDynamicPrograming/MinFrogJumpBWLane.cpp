/*
There is a 3 lane road of length n that consists of n + 1 points labeled from 0 to n. A frog starts at point 0 in the second lane and wants to jump to point n. However, there could be obstacles along the way.

You are given an array obstacles of length n + 1 where each obstacles[i] (ranging from 0 to 3) describes an obstacle on the lane obstacles[i] at point i. If obstacles[i] == 0, there are no obstacles at point i. There will be at most one obstacle in the 3 lanes at each point.

For example, if obstacles[2] == 1, then there is an obstacle on lane 1 at point 2.
The frog can only travel from point i to point i + 1 on the same lane if there is not an obstacle on the lane at point i + 1. To avoid obstacles, the frog can also perform a side jump to jump to another lane (even if they are not adjacent) at the same point if there is no obstacle on the new lane.

For example, the frog can jump from lane 3 at point 3 to lane 1 at point 3.
Return the minimum number of side jumps the frog needs to reach any lane at point n starting from lane 2 at point 0.

Note: There will be no obstacles on points 0 and n.
*/

class Solution {
public:

    int solve(int i, int currlane, vector<int>& obstacles, vector<vector<int>>&dp){
        if(i == obstacles.size()-1){
            return 0;
        }
        if(dp[currlane][i] != -1){
            return dp[currlane][i];
        }
        if(obstacles[i+1] == currlane ){
            int ans = INT_MAX;
            for(int j=1; j<=3; j++){
                if(currlane != j && obstacles[i] != j){
                    ans = min(ans, 1 + solve(i, j, obstacles, dp));
                }
            }
            return dp[currlane][i] = ans;
        }
        else{
            return dp[currlane][i] = solve(i+1, currlane, obstacles, dp);
        }
    }

    int solveTab(vector<int>& obstacles) {
        int n = obstacles.size()-1;
        vector<vector<int>> dp(4, vector<int>(n, INT_MAX)); // Initialize dp table with INT_MAX

        // Base case: The frog reaches the last point with 0 side jumps
        for (int lane = 1; lane <= 3; ++lane) {
            dp[lane][n - 1] = 0;
        }

        // Fill the dp table from the second last point to the first point
        for (int i = n - 1; i >= 0; --i) {
            for (int currlane = 1; currlane <= 3; ++currlane) {
                if(obstacles[i+1] == currlane ){
                    int ans = INT_MAX;
                    for(int j=1; j<=3; j++){
                        if(currlane != j && obstacles[i] != j){
                            ans = min(ans, 1 + dp[j][i]);
                        }
                    }
                    return dp[currlane][i] = ans;
                }
                else {
                    dp[currlane][i] = dp[currlane][i+1]; // Current lane is blocked by an obstacle
                }
            }
        }

        // The minimum side jumps to reach the end from the start (lane 2)
        return min(dp[1][0], min(dp[2][0], dp[3][0]));
    }

    int minSideJumps(vector<int>& obstacles) {
        // vector<vector<int>>dp(4, vector<int>(obstacles.size(), -1));
        // return solve(0, 2, obstacles, dp);
        return solveTab(obstacles);
    }
};