/*
1004. Max Consecutive Ones III

https://leetcode.com/problems/max-consecutive-ones-iii/description/

Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

Example 1:
Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

Example 2:  
Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0, r=0;
        int zeros = 0;
        int ans = 0;
        int window = 0;
        
        int i=0;
        while(r<nums.size()){
            // if zero enters right increase
            if(nums[r] == 0){
                zeros++;
            }
            // if no of 0s in window less than k update ans
            if(zeros<=k){
                ans = max(ans, r-l+1);
            }
            else{
                // if no of zeros more than k, decr 0s if nums[left] is 0 and move left
                if(nums[l] == 0){
                    zeros--;
                }
                l++;
            }
            r++;
        }

        return ans;
    }
};