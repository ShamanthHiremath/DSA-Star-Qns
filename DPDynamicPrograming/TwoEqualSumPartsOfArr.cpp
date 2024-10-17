/*
Partition Equal Subset Sum

https://www.geeksforgeeks.org/problems/subset-sum-problem2014/1

Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

Example 1:

Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explanation: 
The two parts are {1, 5, 5} and {11}.
*/

class Solution{
public:
    bool solveDP(int index, int n, int arr[], int target, vector<vector<int>>&dp){
        if(target == 0){
            return true;
        }
        if(index >= n){
            return false; 
        }
        if(target < 0){
            return false;
        }
        
        if(dp[index][target] != -1){
            return dp[index][target];
        }
        
        bool incl = false;
        if(target - arr[index] >= 0){
            incl = solveDP(index+1, n, arr, target - arr[index], dp);
        }
        bool excl = solveDP(index+1, n,arr, target, dp);
        
        return dp[index][target] = incl or excl;
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for(int i=0; i<N; i++){
            sum += arr[i];
        }
        if(sum%2 == 1){
            return 0;
        }
        
        int target = sum/2;
        vector<vector<int>>dp(N+1, vector<int>(target+1, -1));
        return solveDP(0, N, arr, target, dp);
        
    }
};