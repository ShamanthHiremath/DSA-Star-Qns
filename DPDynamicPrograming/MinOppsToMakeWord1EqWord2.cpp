/*
72. Edit Distance

https://leetcode.com/problems/edit-distance/description/

Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
You have the following three operations permitted on a word:
Insert a character
Delete a character
Replace a character

Example 1:
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Example 2:
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
*/

class Solution {
public:
    int solveDP(int ind1, int ind2, string word1, string word2, vector<vector<int>>&dp){
        if(ind1 == word1.length() ){
            return word2.length() - ind2;
        }
        if(ind2 == word2.length()){
            return word1.length() - ind1;
        }

        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }
        int ans = INT_MAX;
        if(word1[ind1] == word2[ind2]){
            ans = solveDP(ind1+1, ind2+1, word1, word2, dp);
        }
        else{
            int insert_ans = 1 + solveDP(ind1, ind2+1, word1, word2, dp);
            int delete_ans = 1 + solveDP(ind1+1, ind2, word1 , word2, dp);
            int replace_ans = 1 + solveDP(ind1+1, ind2+1, word1, word2,dp);

            ans =  min({insert_ans, delete_ans, replace_ans});
        }

        return dp[ind1][ind2] = ans;
    }

    int solveTab(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        // ******************************************************
        //  Can be optimised  to curr (dp[i]), and next(dp[i+1]) dp vectors
        // ******************************************************
        
        for(int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }

        for(int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min({dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + 1});
                }
            }
        }

        return dp[m][n];
    }

    int minDistance(string word1, string word2) {
        // vector<vector<int>>dp(word1.size(), vector<int>(word2.size(), -1));
        // return solveDP(0, 0, word1, word2, dp);
        return solveTab( word1, word2);
    }
};