/*
115. Distinct Subsequences

https://leetcode.com/problems/distinct-subsequences/

Given two strings s and t, return the number of distinct subsequences of s which equals t.

The test cases are generated so that the answer fits on a 32-bit signed integer.

Example 1:

Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s.
rabbbit
rabbbit
rabbbit
Example 2:

Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from s.
babgbag
babgbag
babgbag
babgbag
babgbag
*/
class Solution {
    public:
        int solveDP(string s, string t, int i, int j, vector<vector<int>>&dp){
            // the matching index for t ie j gets over the length
            if(j >= t.size()){
                // found 1
                return 1;
            }
            // s's i exhausts/goes beyond boundry
            if(i>= s.size()){
                // didnt find any
                return 0;
            }
    
            if(dp[i][j] != -1){
                return dp[i][j];
            }
            // when they match, u wither include that position of match at i and j both or u move one slider of i hoping to expect another match later with j
            if(s[i] == t[j]){
                //                include for both i and j      dont include instead hope to later find jth char of t in s, so u slide i further.
                // Ex: s = rrabbbbit t = rabbit
                //  i=0, t=0, r matches: u have two optns: include, or hope gfor futire include (s has r again at i = 1)
                return dp[i][j] = solveDP(s, t, i+1, j+1, dp) + solveDP(s, t, i+1, j, dp);
            }
            else{
                return dp[i][j] = solveDP(s, t, i+1, j, dp);
            }
        }
    
        int numDistinct(string s, string t) {
            vector<vector<int>>dp(s.size()+1, vector<int>(t.size()+1, -1));
            return solveDP(s, t, 0, 0, dp);
        }
    };