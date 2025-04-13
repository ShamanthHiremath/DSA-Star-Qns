/*
1312. Minimum Insertion Steps to Make a String Palindrome

https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

Given a string s. In one step you can insert any character at any index of the string.
Return the minimum number of steps to make s palindrome.
A Palindrome String is one that reads the same backward as well as forward.


Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we do not need any insertions.
Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
Example 3:

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".

*/

// ************************
// HINTTT
// ***********************

// If we know the longest palindromic sub-sequence is x and the length of the string is n 
// then, what is the answer to this problem? It is n - x as we need n - x insertions to make the remaining characters also palindrome.
// mbadm - this is original str, longest palindromic subsequence is m a m, so we need b and d to be inserted
// mdabm this is revstr, 

// If we know the longest palindromic sub-sequence is x and the length of the string is n 
// then, what is the answer to this problem? It is n - x as we need n - x insertions to make the remaining characters also palindrome.
// mbadm - this is original str, longest palindromic subsequence is m a m, so we need b and d to be inserted
// mdabm this is revstr, 

class Solution {
    public:
        int solveDP(int ind1, int ind2, string s, string r, vector<vector<int>>&dp){
            if(ind1 >=s.length() or ind2 >= r.length()){
                return 0;
            }
    
            if(dp[ind1][ind2] != -1){
                return dp[ind1][ind2];
            }
            int ans = 0;
            if(s[ind1] == r[ind2]){
                ans = 1 + solveDP(ind1+1, ind2+1, s, r, dp);
            }
            else{
                ans = max( solveDP(ind1+1, ind2, s, r, dp),  solveDP(ind1, ind2+1, s, r, dp) );
            }
    
            return dp[ind1][ind2] = ans;
        }
    
        int minInsertions(string s) {
            string revstring = s;
            reverse(revstring.begin(), revstring.end());
            vector<vector<int>>dp(s.length()+1, vector<int>(revstring.length()+1, -1));
            
            int LongestPalindromicSubSequence = solveDP(0, 0, s, revstring, dp);
    
            int minNoOfInsertion = s.length() - LongestPalindromicSubSequence;
    
            return minNoOfInsertion;
    
            string r = s;
            reverse(r.begin(), r.end());
            int n = s.size();
    
            vector<int> curr(n + 1, 0), next(n + 1, 0);
    
            for (int i = n - 1; i >= 0; i--) {
                for (int j = n - 1; j >= 0; j--) {
                    if (s[i] == r[j]) {
                        curr[j] = 1 + next[j + 1];
                    } else {
                        curr[j] = max(next[j], curr[j + 1]);
                    }
                }
                next = curr;
            }
    
            return n - curr[0];
        }
    };