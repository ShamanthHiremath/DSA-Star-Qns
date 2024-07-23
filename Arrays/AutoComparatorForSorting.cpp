/*
1636. Sort Array by Increasing Frequency

https://leetcode.com/problems/sort-array-by-increasing-frequency/

Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.

Return the sorted array.

Example 1:

Input: nums = [2,3,1,3,2]
Output: [1,3,3,2,2]
Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.

*/

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> count;

        // Count the frequency of each number
        for(int i: nums){
            count[i]++;
        }

        // Custom comparator for sorting
        auto cmp = [&count](int a, int b) {
            if (count[a] == count[b]) {
                return a > b; // If frequencies are equal, sort in decreasing order of number
            }
            return count[a] < count[b]; // Sort by increasing frequency
        };

        // Sort the nums vector using the custom comparator
        sort(nums.begin(), nums.end(), cmp);

        return nums;
    }
};