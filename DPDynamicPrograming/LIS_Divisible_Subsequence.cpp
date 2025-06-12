/*
368. Largest Divisible Subset

https://leetcode.com/problems/largest-divisible-subset/

Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.


Example 1:
Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.

Example 2:
Input: nums = [1,2,4,8]
Output: [1,2,4,8]
*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int n = nums.size();
        // stores the length of LIS untill that index
        vector<int>dp(n, 1);
        vector<int>prev_divisible(n);

        int maxiLISLen = 1;
        int lastindex = 0;

        for(int i=0; i<n; i++){
            prev_divisible[i] = i;
            for(int j=0; j<i; j++){
                // checking if the last included index (j) is divisible by the current index (i).
                if(nums[i] % nums[j] == 0 and dp[i] < dp[j] + 1){
                    // update the length of the Dvisible subset in dp[i] (current one)
                    dp[i] = dp[j] + 1;
                    prev_divisible[i] = j;
                }
            }
            if(dp[i] > maxiLISLen){
                maxiLISLen = dp[i];
                lastindex = i;
            }
        }

        vector<int>LIS;
        // traceback to include elements
        LIS.push_back(nums[lastindex]);
        while(prev_divisible[lastindex] != lastindex){
            lastindex = prev_divisible[lastindex];
            LIS.push_back(nums[lastindex]);
        }


        // return maxiLISLen;

        return LIS;
    }
};