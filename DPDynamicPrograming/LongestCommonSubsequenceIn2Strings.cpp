/*
1143. Longest Common Subsequence

https://leetcode.com/problems/longest-common-subsequence/

Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.


Example 1:
Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.

Example 2:
Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.

Example 3:
Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
*/
class Solution {
public:
    int solveDP(int indbig, int indsmall, string big, string small, vector<vector<int>>&dp){
        if(indbig == big.length() || indsmall == small.length()){
            return 0;
        }
        if(dp[indbig][indsmall] != -1){
            return dp[indbig][indsmall];
        }
        int ans = 0;
        if(big[indbig] == small[indsmall]){
            ans = 1 + solveDP(indbig+1, indsmall+1, big, small, dp);
        }
        else{
            ans = max(solveDP(indbig+1, indsmall, big, small, dp), solveDP(indbig, indsmall+1, big, small, dp));
        }
        return dp[indbig][indsmall] = ans;
    }

    int solveTab(string text1, string text2){
        vector<vector<int>>dp(text1.length()+1, vector<int>(text2.length()+1 ,0));

        // ******************************************************
        //  Can be optimised  to curr (dp[i]), and next(dp[i+1]) dp vectors
        // ******************************************************

        for(int indbig=text1.length()-1; indbig>=0; indbig--){
            for(int indsmall=text2.length()-1; indsmall>=0; indsmall--){
                int ans = 0;
                if(text1[indbig] == text2[indsmall]){
                    ans = 1 + dp[indbig+1][indsmall+1];
                }
                else{
                    ans = max(dp[indbig+1][indsmall], dp[indbig][indsmall+1]);
                }
                dp[indbig][indsmall] = ans;
            }
        }

        return dp[0][0];

    }

    int longestCommonSubsequence(string text1, string text2) {
        
        // vector<vector<int>>dp(text1.length()+1, vector<int>(text2.length()+1 ,-1));
        // return solveDP(0, 0, text1, text2, dp);
        return solveTab(text1, text2);
    }
};