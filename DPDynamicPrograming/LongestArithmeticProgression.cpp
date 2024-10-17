/*
Longest Arithmetic Subsequence

https://leetcode.com/problems/longest-arithmetic-subsequence/
https://www.geeksforgeeks.org/problems/longest-arithmetic-progression1019/1

Given an array arr[] of sorted and distinct positive integers. The task is to find the length of the longest arithmetic progression in a given array.

Note: A sequence seq is an arithmetic progression if seq[i + 1] - seq[i] are all the same value (for 0 <= i < seq.length - 1).

Examples:

Input:arr[] = [1, 7, 10, 13, 14, 19]
Output: 4
Explanation: The longest arithmetic progression is [1, 7, 13, 19].
Input:arr[] = [2, 4, 6, 8, 10]
Output: 5
Explanation: The whole array is in AP.
*/

class Solution {
  public:
    int lengthOfLongestAP(vector<int>& arr) {
        // code here
        int n = arr.size();
        if(n <= 2){
            return n;
        }
        
        int ans = 0;
        
        vector<vector<int>> dp(n,vector<int>(arr[n-1]-arr[0]+1, 0));
        for(int  i=1; i<n; i++){
            for(int j=0; j<i; j++){
                // len = 1, cuz element at i is also considered as an AP
                int len = 1;
                int diff = arr[i] - arr[j];
                // check if the difference already exists
                if(dp[j][diff]){
                    // take the answer from the subarray
                    len = dp[j][diff];
                }
                // increase the size by 1 and store it for the ith positon
                dp[i][diff] = 1 + len;
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int longestArithSeqLength(vector<int>& arr) {
        int n = arr.size();
        if(n <= 2){
            return n;
        }
        // sort(arr.begin(), arr.end());
        int ans = 2;

        unordered_map<int, int>dp[n+1];
        for(int  i=1; i<n; i++){
            for(int j=0; j<i; j++){
                // len = 1, cuz element at i is also considered as an AP
                int len = 1;
                int diff = arr[i] - arr[j];
                // check if the difference already exists
                if(dp[j][diff]){
                    // take the answer from the subarray
                    len = dp[j][diff];
                }
                // increase the size by 1 and store it for the ith positon
                dp[i][diff] = 1 + len;
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans;   
    }
};