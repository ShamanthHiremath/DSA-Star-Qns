/*
152. Maximum Product Subarray

https://leetcode.com/problems/maximum-product-subarray/

Given an integer array nums, find a subarray that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer. 

Example 1:
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:
Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 
*/

class Solution {
public:

// KADANE's ALGORITHM

    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN;

        int product = 1;

        for(int num: nums){
            product *= num;
            maxi = max(maxi, product);

            if(product == 0){
                product = 1;
            }
        }

        // checking products from the back of the array
        product = 1;

        for(int i=nums.size()-1; i>=0; i--){
            product *= nums[i];
            maxi = max(maxi, product);

            if(product == 0){
                product = 1;
            }
        }

        return maxi;

    }
};