/*
516. Longest Palindromic Subsequence

https://leetcode.com/problems/longest-palindromic-subsequence/

Given a string s, find the longest palindromic subsequence's length in s.
A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

Example 1:
Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".

Example 2:
Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
*/
class Solution {
public:
    int solveTab(string str, string revstr){
        vector<int>curr(str.length()+1, 0);
        vector<int>next(str.length()+1, 0);


        // ******************************************************
        // Same logic like LongestCommonSubsequenceIn2Strings.cpp qn
        //  Optimised  to curr (dp[i]), and next(dp[i+1]) dp vectors
        // ******************************************************

        for(int indbig=str.length()-1; indbig>=0; indbig--){
            for(int indsmall=revstr.length()-1; indsmall>=0; indsmall--){
                int ans = 0;
                if(str[indbig] == revstr[indsmall]){
                    ans = 1 + next[indsmall+1];
                }
                else{
                    ans = max(next[indsmall], curr[indsmall+1]);
                }
                curr[indsmall] = ans;
            }
            next = curr;
        }
        return curr[0];

    }

    int longestPalindromeSubseq(string str) {
        string revstr = str;
        reverse(revstr.begin(), revstr.end());
        return solveTab(str, revstr);
    }
};