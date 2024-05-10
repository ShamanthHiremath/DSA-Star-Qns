/*
Given an array of integers arr, the length of the array n, and an integer k, find all the unique combinations in arr where the sum of the combination is equal to k. Each number can only be used once in a combination.
Return the combinations in the lexicographically sorted order, where each combination is in non-decreasing order.
Input: 
n = 5, k = 7
arr[] = { 1, 2, 3, 3, 5 }
Output:
{ { 1, 3, 3 }, { 2, 5 } }
*/

class Solution {
public:
    void backtrack(vector<vector<int>>& ans, vector<int>& output, vector<int>& nums, int index, int target) {
        if (target == 0) {
            ans.push_back(output);
            return;
        }
        if (index >= nums.size() || target < 0) {
            return;
        }
        // Include the current element
        output.push_back(nums[index]);
        backtrack(ans, output, nums, index + 1, target - nums[index]);
        output.pop_back();
        // Skip duplicates
        while (index < nums.size() - 1 && nums[index] == nums[index + 1]) {
            index++;
        }
        // Exclude the current element
        backtrack(ans, output, nums, index + 1, target);
    }

    vector<vector<int>> subsets(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        vector<int> output;
        sort(nums.begin(), nums.end()); // Sort the input array
        backtrack(ans, output, nums, 0, k);
        return ans;
    }

    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k) {
        return subsets(arr, k);
    }
};