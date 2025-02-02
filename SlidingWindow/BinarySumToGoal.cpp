/*
930. Binary Subarrays With Sum

https://leetcode.com/problems/binary-subarrays-with-sum/

Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
A subarray is a contiguous part of the array.

Example 1:
Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]

Example 2:
Input: nums = [0,0,0,0,0], goal = 0
Output: 15
*/

class Solution {
public:
    int solve(vector<int>& nums, int goal) {

        if(goal<0){
            return 0;
        }

        int l=0, r=0;
        int count = 0;
        int sum = 0;

        while(r<nums.size()){
            sum += nums[r];
            while(sum > goal){
                sum -= nums[l];
                l++; 
            }
            // if(sum == goal){
                count += (r-l+1);
            // }
            r++;
        }

        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal){

        // The number of non-empty subarrays with sum exactly equal to goal can be calculated as : 
        // NO. of Subarrays(Goal) = NO. of Subarrays(Goal) - NO. of Subarrays(Goal - 1)
            return solve(nums, goal) - solve(nums, goal-1);
        }
};