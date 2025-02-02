/*
Subset Sum Problem

https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

Given an array of positive integers arr[] and a value target, determine if there is a subset of the given array with sum equal to given target. 

Examples:

Input: arr[] = [3, 34, 4, 12, 5, 2], target = 9
Output: true 
Explanation: Here there exists a subset with target sum = 9, 4+3+2 = 9.

Input: arr[] = [3, 34, 4, 12, 5, 2], target = 30
Output: false
Explanation: There is no subset with target sum 30.

Input: arr[] = [1, 2, 3], sum = 6
Output: true
Explanation: The entire array can be taken as a subset, giving 1 + 2 + 3 = 6.
*/

class Solution {
  public:
    bool solveDP(int index, vector<int>& arr, int target, vector<vector<int>>&dp){
        if(target==0){
            return true;
        }
        if(index >= arr.size()){
            return false;
        }
        
        if(dp[index][target] != -1){
            return dp[index][target];
        }
        
        bool incl = false;
        if(arr[index] <= target){
            incl = solveDP(index+1, arr, target-arr[index], dp);
        }
        bool excl = solveDP(index+1, arr, target, dp);
        
        return dp[index][target] = incl || excl;
    }
    
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        vector<vector<int>>dp(arr.size(), vector<int>(target+1, -1));
        return solveDP(0, arr, target, dp);
    }
};