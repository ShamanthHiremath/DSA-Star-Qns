/*
45. Jump Game II

https://leetcode.com/problems/jump-game-ii/description/

You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2
*/

class Solution {
public:
    int solve(int ind, vector<int>&nums, vector<int>&dp){
        // assume u r at the last index, how many jumps needed? 0
        if(ind >= nums.size()-1){
            return 0;
        }

        if(dp[ind] != -1){
            return dp[ind];
        }

        int mini = INT_MAX;
        for(int i=1; i<=nums[ind]; i++){
            int res = solve(ind + i, nums, dp);
            if(res != INT_MAX){
                mini = min(mini, 1 + res);
            }
        }

        return dp[ind] = mini;
    }

    int jump(vector<int>& nums) {
        vector<int>dp(nums.size()+1, -1);
        return solve(0, nums, dp);
    }
};

