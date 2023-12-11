/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police such that u dont rob any two adjacent houses

Example 1:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
*/

class Solution {
public:
    int solve(vector<int>& nums, int n, int i, vector<int>&dp ){
        //the 0th house u rob all the money and it isnt an adjacent house
        if(i==0)return nums[0];
        //if the street ends... ull go home richhhhh
        if(i<0)return 0;
        //the max money robbed which if has been already stored in dp[i]i.e dp[i]!=-1(not unsaved)is returned
        if(dp[i]!=-1)return dp[i];
        //if u choose to rob a house then u rib it and go for the net to next(no adjacents.... shushhhh) 
        int choose=nums[i]+solve(nums, n, i-2, dp);
        //if u dont choose that house go for the next one(boommmmm)
        int notchoose=solve(nums, n, i-1, dp );
        //store the max value of these two in dp[i], i.e max value of money robbed in that very ith house and return
        return dp[i]=max(choose, notchoose);

    }
    int rob(vector<int>& nums) {
    //initialise a vector to  store the returned minvalue for each jump
        vector<int>dp(nums.size()+1, -1);
        return solve(nums, nums.size()-1, nums.size()-1, dp);
    }
};