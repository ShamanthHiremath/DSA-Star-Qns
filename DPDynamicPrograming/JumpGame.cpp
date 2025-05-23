/*
55. Jump Game

https://leetcode.com/problems/jump-game/

You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
Return true if you can reach the last index, or false otherwise.

Example 1:
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 
*/
class Solution {
public:
    bool solveDP(int curr_ind, vector<int>& nums, vector<int>&dp){
        if(curr_ind >= nums.size()-1){
            return true;
        }
        if(dp[curr_ind] != -1){
            return dp[curr_ind];
        }
        for(int jump=1; jump<=nums[curr_ind]; ++jump){
            if(solveDP(curr_ind+jump, nums, dp)){
                return dp[curr_ind] = true;
            }
        }
        return dp[curr_ind] = false;

    }
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size(), -1);
        return solveDP(0, nums, dp);   
    }
};