/*
153. Find Minimum in Rotated Sorted Array

https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/


Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.

 

Example 1:

Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
Example 2:

Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
Example 3:

Input: nums = [11,13,15,17]
Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times. 
*/
// minimum element is the separator
class Solution {
    public:
        int findMin(vector<int>& nums) {
            int e = nums.size()-1;
            int s = 0;
            int mini = INT_MAX;
            while(s<=e){
                int mid = s + (e-s)/2;
                if(nums[mid]<mini){
                    mini = nums[mid];
                }
                // since the mid element is smaller than last element, the minimim can be still found on the left side
                if(nums[mid] < nums[e]){
                    e = mid - 1;
                }
                // since the last element is smaller than the mid, go to right side
                else {
                    s = mid + 1;
                }
            }
            return mini;
        }
    };