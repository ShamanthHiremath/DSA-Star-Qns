/*
300. Longest Increasing Subsequence

https://leetcode.com/problems/longest-increasing-subsequence/

Given an integer array nums, return the length of the longest strictly increasing subsequence.

Example 1:
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Example 2:
Input: nums = [0,1,0,3,2,3]
Output: 4

Example 3:
Input: nums = [7,7,7,7,7,7,7]
Output: 1
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // stores the length of LIS untill that index
        vector<int>dp(n, 1);
        vector<int>prev_smaller(n);

        int maxiLISLen = 1;
        int lastindex = 0;

        for(int i=0; i<n; i++){
            // mark itself as smallest
            // so that it can be used as a previous smaller element
            prev_smaller[i] = i;
            for(int j=0; j<i; j++){
                if(nums[j] < nums[i] and dp[j] + 1 > dp[i]){
                    // if the current number is greater than the previous number
                    // and the LIS length at j + 1 is greater than the current LIS length at i
                    dp[i] =  dp[j] + 1;
                    prev_smaller[i] = j;
                }
            }
            if(dp[i] > maxiLISLen){
                maxiLISLen = dp[i];
                lastindex = i;
            }
        }

        vector<int>LIS;
        LIS.push_back(nums[lastindex]);
        while(prev_smaller[lastindex] != lastindex){
            lastindex = prev_smaller[lastindex];
            LIS.push_back(nums[lastindex]);
        }


        // return maxiLISLen;

        return *max_element(dp.begin(), dp.end());
    }
};