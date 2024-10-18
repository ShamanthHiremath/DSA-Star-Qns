/*
44. Wildcard Matching

https://leetcode.com/problems/wildcard-matching/

Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Example 1:
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:
Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
*/

class Solution {
public:
    bool solveDP(int i, int j, string text, string pattern, vector<vector<int>>&dp){
        // both pattern text exhaust
        if(i<0 && j<0){
            return true;
        }
        // only pattern exhausts
        if(i>=0 && j<0){
            return false;
        }
        // text exhuasts
        if(i<0 && j>=0){
            // pattern might have either other chars than *
            while(j>=0){
                if(pattern[j] != '*'){
                    return false;
                }
                j--;
            }
            // or just *
            return true;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        // the chars match or the pattern has  ?
        if(text[i] == pattern[j] || pattern[j] == '?'){
            return dp[i][j] = solveDP(i-1, j-1, text, pattern, dp);
        }
        // the pattern has a *, so we can either skip the char in text or the char in pattern
        else if(pattern[j] == '*'){
            return dp[i][j] = solveDP(i-1, j, text, pattern, dp) || solveDP(i, j-1, text, pattern, dp);
        }
        else{
            // teh chars dont match
            return dp[i][j] = false;
        }
    }
    bool solveTab(string s, string p) {
        int m = s.size(), n = p.size();
        vector<bool> prev(n+1, 0), curr(n+1, 0);

        prev[0] = 1; // when both strings are empty

        for(int j = 1; j <= n; j++) {
            if(p[j-1] == '*') {
                prev[j] = prev[j-1];
            }
        }

        for(int i = 1; i <= m; i++) {
            curr[0] = 0;  // text is non-empty, pattern is empty

            for(int j = 1; j <= n; j++) {
                if(s[i-1] == p[j-1] || p[j-1] == '?') {
                    curr[j] = prev[j-1];
                }
                else if(p[j-1] == '*') {
                    curr[j] = prev[j] || curr[j-1];
                }
                else {
                    curr[j] = 0;
                }
            }

            prev = curr;
        }

        return prev[n];
    }
    
    bool isMatch(string s, string p) {
        // vector<vector<int>>dp(s.length()+1, vector<int>(p.length()+1, -1));
        // return solveDP(s.length()-1, p.length()-1, s, p,dp);
        return solveTab(s, p);
    }
};