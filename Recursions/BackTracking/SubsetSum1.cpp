/*
78. Subsets

https://leetcode.com/problems/subsets/description/

Given an integer array nums of unique elements, return all possible 
subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
Input: nums = [0]
Output: [[],[0]]
*/

class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>&ans, vector<int>& temp, int index){
        if(index == nums.size()){
            ans.push_back(temp);
            return;
        }
        //include that element
        temp.push_back(nums[index]);
        solve(nums, ans, temp, index+1);

        //exclude the element
        temp.pop_back();
        solve(nums, ans, temp, index+1);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(nums, ans, temp, 0);
        return ans;
    }
};