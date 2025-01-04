/*
14. Longest Common Prefix

https://leetcode.com/problems/longest-common-prefix/description/

Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
*/

// CAN BE DONE USING TRIE BUT NOT REQUIRED HERE

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string ans = "";
        string firstword = strs[0], lastword = strs[strs.size()-1];

        for(int i=0; i<firstword.size(); i++){
            if(firstword[i] != lastword[i]){
                return ans;
            }
            ans += firstword[i];
        }
        return ans;
    }
};