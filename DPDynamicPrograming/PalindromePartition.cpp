/*
132. Palindrome Partitioning II

https://leetcode.com/problems/palindrome-partitioning-ii/description/

Given a string s, partition s such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.

Example 1:
Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.

Example 2:
Input: s = "a"
Output: 0

Example 3:
Input: s = "ab"
Output: 1
*/

class Solution {
public:
    bool isPalindrome(string x){
        int i=0;
        while(i<x.size()){
            if(x[i] != x[x.size()-1-i]){
                return false;
            }
            i++;
        }
        return true;
    }

    int solveDP(int ind, string s, vector<int>&dp){
        if(ind == s.size()){
            return 0;
        }

        if(dp[ind] != -1){
            return dp[ind];
        }

        int mini = s.size();

        string temp = "";
        for(int partition=ind; partition<s.size(); partition++){
            temp += s[partition];
            if(isPalindrome(temp)){
                int cost = 1 + solveDP(partition+1, s, dp);
                mini = min(mini, cost);
            }
        }

        return dp[ind] = mini;
    }

    bool isPalindrome(const string &s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    int minCut(string s) {
        int n = s.size();
        // vector<int>dp(n+1, -1);
        // return solveDP(0, s, dp) - 1;
        // int n = s.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[n] = 0; // Base case: no cuts needed for empty string

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (isPalindrome(s, i, j)) {
                    if (j + 1 <= n) {
                        dp[i] = min(dp[i], 1 + dp[j + 1]);
                    }
                }
            }
        }

        return dp[0] - 1;
    }
};