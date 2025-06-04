/*
76. Minimum Window Substring

https://leetcode.com/problems/minimum-window-substring/

Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
*/

class Solution {
public:
    string minWindow(string s, string t) {
        int mini = INT_MAX;
        int l=0, r=0;
        int substart = -1;
        map<char, int>mp;
        int cnt = 0;

        for(auto ch:t){
            mp[ch]++;
        }

        int n = s.size();
        int m = t.size();

        while(r<n){
            // begin the r part if the count in map is +ve
            if(mp[s[r]] > 0){
                cnt++;
            }
            // reduce from map since counted
            mp[s[r]]--;

            // valid substring, but shrink to find mini
            while(cnt == m){
                if(r-l+1 < mini){
                    mini = r-l+1;
                    substart = l;
                }
                // re add thos eused chars in map substring
                mp[s[l]]++;
                if(mp[s[l]] > 0){
                    cnt--;
                }
                l++; 
            }

            r++;
        }

        return substart == -1 ? "" : s.substr(substart, mini);

    }
};