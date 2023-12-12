/*
Example 1:
Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
Example 2:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
*/
class Solution {
public:
    int solve(vector<int>& nums, vector<int>&dp, int i, int end){
        if(i==end){
            return nums[end];
        }
        if(i<end){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int choose= nums[i]+solve(nums,dp,i-2,end);
        int notchoose=solve(nums,dp,i-1,end);
        return dp[i]=max(choose,notchoose);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        vector<int>dp1(nums.size(),-1);
        vector<int>dp2(nums.size(),-1);
        return max(solve(nums,dp1,nums.size()-2,0),solve(nums,dp2,nums.size()-1,1));
    }
};