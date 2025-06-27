/*
560. Subarray Sum Equals K

https://leetcode.com/problems/subarray-sum-equals-k/description/

Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [1,1,1], k = 2
Output: 2

Example 2:
Input: nums = [1,2,3], k = 3
Output: 2

*/


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumFreq; // Store frequency of prefix sums
        int sum = 0, count = 0;

        // Initialize with prefix sum 0 occurring once (important for cases where subarray starts from index 0)
        prefixSumFreq[0] = 1;

        for (int num : nums) {
            sum += num;

            // Check if (sum - k) exists in map, meaning there is a subarray ending at current index with sum k
            if (prefixSumFreq.find(sum - k) != prefixSumFreq.end()) {
                count += prefixSumFreq[sum - k];
            }

            // Store/update the frequency of the current prefix sum
            prefixSumFreq[sum]++;
        }

        return count;
    }
};