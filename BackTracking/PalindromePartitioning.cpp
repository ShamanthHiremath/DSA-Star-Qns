/*
131. Palindrome Partitioning

https://leetcode.com/problems/palindrome-partitioning/

Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

Example 1:
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]

Example 2:
Input: s = "a"
Output: [["a"]]

*/

class Solution {
public:

    bool isPalindrome(int start, int end, string s){
        while(start < end){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }

        return true;
    }
    void solve(int index, string s, vector<string>&temp, vector<vector<string>>&ans){
        if(index == s.length()){
            ans.push_back(temp);
            return ;
        }

        // checking at every position from index if there exists a palindrome starting from index to i

        for(int i=index; i<s.length(); i++){
            if(isPalindrome(index, i, s)){
                // s.substr(start posn, length);
                // this below line adds the string in to the vector of strings
                temp.push_back(s.substr(index, i - index + 1));
                solve(i+1, s, temp, ans);
                // this below line removes the last string
                temp.pop_back();
            }
        }
    }

     
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string>temp;

        solve(0, s, temp, ans);

        return ans;
    }
};