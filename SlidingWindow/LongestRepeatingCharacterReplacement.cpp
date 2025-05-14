/*
424. Longest Repeating Character Replacement

https://leetcode.com/problems/longest-repeating-character-replacement/

You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

Example 1:
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

Example 2:
Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.
*/

class Solution {
public:
    int solve(string s, int k){
        int l=0, r=0;
        int ans = 0;
        map<char, int>freq;

        int maxfreq = 0;
        int window_len = 0;
        while(r<s.length()){
            freq[s[r]]++;
            maxfreq = max(maxfreq, freq[s[r]]);
            window_len = r - l + 1;
            // window_len - maxfreq is actually the no of changes that can be made in that window ( r - l + 1 )
            while(window_len - maxfreq > k){
                freq[s[l]]--;
                l++;
                window_len = r - l + 1;
            }
            ans = max(ans, r - l + 1);
            r++;

        }

        return ans;
    }
    int characterReplacement(string s, int k) {
        return solve(s, k);
    }
};