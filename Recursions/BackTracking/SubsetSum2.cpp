/*
90. Subsets II

https://leetcode.com/problems/subsets-ii/description/

Given an integer array nums that may contain duplicates, return all possible 
subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

Example 2:
Input: nums = [0]
Output: [[],[0]]
*/

class Solution {
public:
    void solve(int index, vector<int>&sum, vector<int>&arr, vector<vector<int>>&ans){
        ans.push_back(sum);
        
        for(int i=index; i<arr.size(); i++){
            if(i != index && arr[i] == arr[i-1] ){
                continue;
            }
            sum.push_back(arr[i]);
            solve(i+1, sum, arr, ans);
            sum.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        vector<int>sum;
        solve(0, sum, nums, ans);
        return ans;
    }
};