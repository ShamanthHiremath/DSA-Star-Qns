/*
673. Number of Longest Increasing Subsequence

https://leetcode.com/problems/number-of-longest-increasing-subsequence/

Given an integer array nums, return the number of longest increasing subsequences.

Notice that the sequence has to be strictly increasing.

Example 1:
Input: nums = [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].

Example 2:
Input: nums = [2,2,2,2,2]
Output: 5
Explanation: The length of the longest increasing subsequence is 1, and there are 5 increasing subsequences of length 1, so output 5.
*/

class Solution {
public:
    
    int findNumberOfLIS(vector<int>& nums) {
       int n = nums.size();
        // stores the length of LIS untill that index
        vector<int>dp(n, 1);
        vector<int>count(n, 1);
        // vector<int>prev_smaller(n);


        int maxiLISLen = 1;
        int lastindex = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[j] < nums[i] and dp[j] + 1 > dp[i]){
                    // if the current number is greater than the previous number
                    // and the LIS length at j + 1 is greater than the current LIS length at i
                    dp[i] =  dp[j] + 1;
                    count[i] = count[j];
                }
                else if(nums[j] < nums[i] and dp[i] == dp[j]+1){
                    count[i] += count[j];
                }
            }
            maxiLISLen = max(maxiLISLen, dp[i]);
        }

        // count in all the count[] values that have maxiLISLen in dp[] 

        int total = 0;

        for(int i=0; i<dp.size(); i++){
            if(dp[i] == maxiLISLen){
                total += count[i];
            }
        }

        return total;

        // LIS PRINTING CODE BELOW

        // vector<int>LIS;
        // LIS.push_back(nums[lastindex]);
        // while(prev_smaller[lastindex] != lastindex){
        //     lastindex = prev_smaller[lastindex];
        //     LIS.push_back(nums[lastindex]);
        // }


        // return maxiLISLen;

        // return *max_element(dp.begin(), dp.end());
    }
};