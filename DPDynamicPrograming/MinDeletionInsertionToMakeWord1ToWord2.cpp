/*
583. Delete Operation for Two Strings

https://leetcode.com/problems/delete-operation-for-two-strings/

Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string. 

Example 1:
Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".

Example 2:
Input: word1 = "leetcode", word2 = "etco"
Output: 4
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
    
        int minDistance(string word1, string word2) {
            if(word1.length()<word2.length()){
                string temp = word1;
                word1 = word2;
                word2 = temp;
            }
            vector<vector<int>>dp(word1.length()+1, vector<int>(word2.length()+1 ,-1));
            
            int LongestCommonSubsequence = solveDP(0, 0, word1, word2, dp);        
            // "abcd"     "anc"
            // LCS is "ac"
            // "bd" delete in "abcd",     "n" insert from anc
            return word1.size() - LongestCommonSubsequence + word2.size() - LongestCommonSubsequence;
        }
    };