/*
33. Search in Rotated Sorted Array

https://leetcode.com/problems/search-in-rotated-sorted-array/

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int e = nums.size()-1;
        int s = 0;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid]<nums[e]){
                if(target >= nums[mid] && target <= nums[e]){
                    s = mid + 1;
                }
                else{
                    e = mid - 1;
                }
            }
            else{
                if(target <= nums[mid] && target >= nums[s]){
                    e = mid - 1;
                }
                else{
                    s = mid + 1;
                }
            }
        }
        return -1;
    }
};