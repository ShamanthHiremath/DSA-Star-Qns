/*
1043. Partition Array for Maximum Sum

https://leetcode.com/problems/partition-array-for-maximum-sum/

Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

Example 1:
Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]

Example 2:
Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
Output: 83

Example 3:
Input: arr = [1], k = 1
Output: 1
*/
class Solution {
public: 
    int maxElement(int s, int e, vector<int>&arr){
        int maxi = INT_MIN;
        int i = s;
        while(i<=e){
            maxi = max(maxi, arr[i]);
            i++;
        }

        return maxi;
    }
    int solveDP(int ind, vector<int>&arr, int k, vector<int>&dp){
        if(ind == arr.size()){
            return 0;
        }

        if(dp[ind] != -1){
            return dp[ind];
        }

        int maxi = INT_MIN;
        int end = min(static_cast<int>(arr.size()), ind + k);
        for(int parti=ind; parti < end; parti++){
            int maxiElem = maxElement(ind, parti, arr);
            int sum = maxiElem * (parti - ind + 1) + solveDP(parti + 1, arr, k, dp);

            maxi = max(maxi, sum); 
        }

        return dp[ind] = maxi;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size()+1, -1);
        return solveDP(0, arr, k, dp);
    }
};