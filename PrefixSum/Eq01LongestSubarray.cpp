/*
525. Contiguous Array

https://leetcode.com/problems/contiguous-array/description/

Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.
A contiguous subarray is defined as a subarray that is non-empty and consists of elements that are consecutive in the original array.

Example 1:
Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.

Example 2:
Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

Example 3:
Input: nums = [0,1,1,1,1,1,0,0,0]
Output: 6
Explanation: [1,1,1,0,0,0] is the longest contiguous subarray with equal number of 0 and 1.
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        map<int,int>prefixSum;
        /*
        
              |         |
        0 1 1 1 1 1 0 0 0
       -1 0 1 2 3 4 3 2 1

          |           | 
        1 1 0 0 1 1 0 1 1
        1 2 1 0 1 2 1 2 3 
        
        */

        // edge case for 0
        // if the sum is 0, then it alwasy indicates taht the subarray had equal 1s and 0s
        // so add a prefix sum[0] as -1
        prefixSum[0] = -1;
        int sum = 0;
        int len = 0;
        for(int i=0; i<n; i++){
            if(nums[i]){
                // increase sum by 1 if its 1
                sum += 1;
            }
            else{
            // reduce the sum by -1, if its 0
                sum -= 1;
            }
            if(prefixSum.find(sum) != prefixSum.end()){
                len = max(len, i-prefixSum[sum]);
            }
            else{
                prefixSum[sum] = i;
            }
        }


        return len;

    }
};