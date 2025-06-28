/*
238. Product of Array Except Self

https://leetcode.com/problems/product-of-array-except-self/

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.

Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefixPro(n, 1);
        vector<int>suffixPro(n, 1);
        
        prefixPro[0] = 1;
        suffixPro[n-1] = 1;

        for(int i=1; i<n; i++){
            prefixPro[i] = prefixPro[i-1] * nums[i-1];
            suffixPro[n-i-1] = suffixPro[n-i] * nums[n-i]; 
        }
        for(int i=0; i<n; i++){
            nums[i] = prefixPro[i] * suffixPro[i];
        }

        return nums;
    }
};

// 1 1 2 6
// 24 12 4  1