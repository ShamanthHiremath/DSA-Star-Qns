/*
40. Combination Sum II

https://leetcode.com/problems/combination-sum-ii/description/

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

Example 2:
Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
*/

class Solution {
public:
    void solve(int index, vector<int>& temp, vector<vector<int>>& ans, vector<int>& arr, int target) {
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(target < 0 || index >= arr.size()){
            return;
        }
        for(int i = index; i < arr.size(); ++i){
            if(i > index && arr[i] == arr[i - 1]){
                continue;            
            }
            if(arr[i] > target){
                break; // Early exit if the current number exceeds target
            }
            temp.push_back(arr[i]);
            solve(i + 1, temp, ans, arr, target - arr[i]);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0, temp, ans, candidates, target);
        return ans;
    }
};