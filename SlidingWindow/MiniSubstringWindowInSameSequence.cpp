/*
Minimum Window Substring

https://www.geeksforgeeks.org/problems/minimum-window-subsequence/1v

You are given two strings, s1 and s2. Your task is to find the smallest substring in s1 such that s2 appears as a subsequence within that substring.

The characters of s2 must appear in the same sequence within the substring of s1.
If there are multiple valid substrings of the same minimum length, return the one that appears first in s1.
If no such substring exists, return an empty string.
Note: Both the strings contain only lowercase letters.

Examples:

Input: s1 = "geeksforgeeks", s2 = "eksrg"
Output: "eksforg"
Explanation: "eksforg" satisfies all required conditions. s2 is its subsequence and it is longest and leftmost among all possible valid substrings of s1.
Input: s1 = "abcdebdde", s2 = "bde" 
Output: "bcde"
Explanation:  "bcde" is the answer and "deb" is not a smaller window because the elements in the window must occur in order.
Input: s1 = "ad", s2 = "b" 
Output: ""
Explanation: There is no substring exists.
*/


class Solution {
  public:
    string minWindow(string& s1, string& s2) {
        
        int n = s1.size();
        int m = s2.size();
        
        int mini = INT_MAX;
        int subStart = -1;
        
        int r=0;
        int k=0;
        
        while(r<n and k<m){
            if(s1[r] == s2[k]){
                k++;
            }
            // the substring has been found
            if(k == m){
                // minimise the window, so  use left to track back, and k to track back
                int l = r;
                k = m-1;
                
                while(l>=0 and k>=0){
                    if(s1[l] == s2[k]){
                        k--;
                    }
                    l--;
                }
                // go to the next index (since loop ends at a index when loop condition fails)
                l++;
                
                if(mini > r-l+1){
                    mini = r-l+1;
                    subStart = l;
                }
                // setting to check for further posssiblities
                r = l+1;
                k = 0;
            }
            
            r++;
        }
        
        return subStart==-1? "": s1.substr(subStart, mini);
        
    }
};