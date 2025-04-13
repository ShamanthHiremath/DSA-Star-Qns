/*
1092. Shortest Common Supersequence 

https://leetcode.com/problems/shortest-common-supersequence/

Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

Example 1:
Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.

Example 2:
Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output: "aaaaaaaa"
*/

class Solution {
    public:
    // top down approach
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
    // bottom up approach
        int solveDP(string& s1, string& s2, vector<vector<int>>& dp){
            int n = s1.size(), m = s2.size();
            for(int i = 0; i <= n; i++){
                for(int j = 0; j <= m; j++){
                    if(i == 0 || j == 0){
                        dp[i][j] = 0;
                    }
                    else if(s1[i - 1] == s2[j - 1]){
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                    }
                    else{
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }
            return dp[n][m];
        }
    
        string computeString(string s1, string s2, vector<vector<int>>&dp){
            // u start from the bottom right of the dp, beacuse that has the answer to length of LCS
            string ans = "";
    
            int i = s1.length();
            int j = s2.length();
    
            while(i>0 && j>0){
                if(s1[i-1] == s2[j-1]){
                    ans += s1[i-1];
                    i--;
                    j--;
                }
                // if the strings dont match on a character, u have 2 conditions, 
                // 1. if s1[i-1] doesnt match with s2[j-1], dp[i-1][j] > dp[i][j-1] which means that the maximum value considered was from dp[i-1][j] which is basically from the s1[i-1]
                // so add that and move away from that index, i.e, i--;
                else if(dp[i-1][j] > dp[i][j-1]){
                    ans += s1[i-1];
                    i--;
                }
                else{
                    ans += s2[j-1];
                    j--;
                }
            }
    
            //  a case that i and j might still be greater than 0, so we have to include those non added chars
            while(i>0){
                ans += s1[i-1];
                i--;
            }
            while(j>0){
                ans += s2[j-1];
                j--;
            }
    
            // bcuz we start from the bottom right of the DP, and from last indexes of strings
            reverse(ans.begin(), ans.end());
    
            return ans;
        }
    
        string shortestCommonSupersequence(string word1, string word2) {
            if(word1.length()<word2.length()){
                string temp = word1;
                word1 = word2;
                word2 = temp;
            }
            vector<vector<int>>dp(word1.length()+1, vector<int>(word2.length()+1 ,-1));
    
            solveDP(word1, word2, dp);  
    
            return computeString(word1, word2, dp);
        }
    };