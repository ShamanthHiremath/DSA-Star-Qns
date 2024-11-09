/*
22. Generate Parentheses

https://leetcode.com/problems/generate-parentheses/description/

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]
*/

class Solution {
public:
    void solveRec(int open, int close, int n, vector<string>&ans, string temp){
        if(open == close && open+close == n*2){
            ans.push_back(temp);
            return;
        }

        if(open < n){
            solveRec(open+1, close, n, ans, temp+'(');
        }
        if(close<open){
            solveRec(open, close+1, n, ans, temp+')');
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        // int open=0, close=0;
        string temp = "";
        solveRec(0, 0, n, ans, temp);
        return ans;

    }
};