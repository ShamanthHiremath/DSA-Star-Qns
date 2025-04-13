/*
34. Find First and Last Position of Element in Sorted Array

https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:
Input: nums = [], target = 0
Output: [-1,-1]
*/

class Solution {
    public:
        int upper_bound(vector<int>& nums,  int target){
            int s = 0;
            int e = nums.size()-1;
            int ans = -1;
            while(s<=e){
                int mid = s + (e-s)/2;
                if(nums[mid] == target){
                    ans = mid;
                    s = mid + 1;
                }
                else if(nums[mid] > target){
                    e = mid-1;
                }
                else{
                    s = mid+1;
                }
            }
    
            return ans;
        }
    
        int lower_bound(vector<int>& nums, int target){
            int s = 0;
            int e = nums.size()-1;
            int ans = -1;
            while(s<=e){
                int mid = s + (e-s)/2;
                if(nums[mid] == target){
                    ans = mid;
                    e = mid - 1;
                }
                else if(nums[mid] > target){
                    e = mid-1;
                }
                else{
                    s = mid+1;
                }
            }
    
            return ans;
        }
    
        vector<int> searchRange(vector<int>& nums, int target) {
    
            return {lower_bound(nums,target), upper_bound(nums, target)};
    
        }
    };