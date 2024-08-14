/*
719. Find K-th Smallest Pair Distance

https://leetcode.com/problems/find-k-th-smallest-pair-distance/

The distance of a pair of integers a and b is defined as the absolute difference between a and b.

Given an integer array nums and an integer k, return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.

 

Example 1:

Input: nums = [1,3,1], k = 1
Output: 0
Explanation: Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.
Example 2:

Input: nums = [1,1,1], k = 2
Output: 0
Example 3:

Input: nums = [1,6,1], k = 3
Output: 5
*/
class Solution {
public:
    int countDistLessThan(int val, vector<int>&nums){
        int count=0;
        int small=0;
        for(int large=1; large<nums.size(); large++){
            while(small<large && nums[large] - nums[small] > val){
                small++;
            }
            count += large-small;
        }
        return count;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int s = 0;
        int e = nums[n-1] - nums[0];
        while(s<=e){
            int mid = s + (e-s)/2;
            if(countDistLessThan(mid, nums) < k){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        return s;

    }
};