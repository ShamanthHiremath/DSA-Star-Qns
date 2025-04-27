/*
410. Split Array Largest Sum

https://leetcode.com/problems/split-array-largest-sum/description/

Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.

 

Example 1:
Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.

Example 2:
Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.
 
*/

class Solution {
    public:
        int countSum(vector<int>& nums, int sum){
            int cnt = 1;
            int windowSum = 0; 
            for(int i=0; i<nums.size(); i++){
                if(windowSum + nums[i] <= sum){
                    windowSum += nums[i];
                }
                else{
                    cnt++;
                    windowSum = nums[i];
                }
            }
    
            return cnt;
        }
        int splitArray(vector<int>& nums, int k) {
            // because that maxi element will always stay inside the sum of partition
            int s = *max_element(nums.begin(), nums.end());
            // largest sum of the entire array
            int e = accumulate(nums.begin(), nums.end(), 0);
    
            int mid  = s + (e-s)/2;
              
              while(s<=e){
                  int cnt = countSum(nums, mid);
                  
                  if(cnt > k){
                      s = mid + 1;
                  }
                  else{
                      e = mid - 1;
                  }
                  
                  
                  mid  = s + (e-s)/2;
              }
              
              return s;
        }
    };