/*
312. Burst Balloons

https://leetcode.com/problems/burst-balloons/description/

You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.

Example 1:
Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167

Example 2:
Input: nums = [1,5]
Output: 10
*/

class Solution {
public:
    int solve(int i, int j, vector<int>&nums, vector<vector<int>>&dp){
        if(i > j){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int maxi = INT_MIN;

        for(int ind=i; ind<=j; ind++){
            // cost would be the index we are assuming will be burst at the last, and the left and right most indexes balloons 
            // handling edge cases, only one balloon at end or start
            int leftBalloonCost = 1;
            if(i-1 >= 0){
                leftBalloonCost = nums[i-1];
            }
            int rightBalloonCost = 1;
            if(j+1 <= nums.size()-1){
                rightBalloonCost = nums[j+1];
            }
            int cost = leftBalloonCost * nums[ind] * rightBalloonCost  + solve(i, ind-1, nums, dp) + solve(ind+1, j, nums, dp);

            maxi = max(maxi, cost);
        }


        return dp[i][j] = maxi;
    }

    int maxCoins(vector<int>& nums) {
        vector<vector<int>>dp(nums.size()+1, vector<int>(nums.size()+1, -1));
        return solve(0, nums.size()-1, nums, dp);
    }
};