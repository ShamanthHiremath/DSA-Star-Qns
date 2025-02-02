/*
678. Valid Parenthesis String

https://leetcode.com/problems/valid-parenthesis-string/

Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
 
Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "(*)"
Output: true

Example 3:
Input: s = "(*))"
Output: true
*/

class Solution {
public:
    bool checkValidString(string s) {
        int leftbracmin = 0, leftbracmax=0;

        for(char ch:s){
            if(ch == '('){
                leftbracmin++;
                leftbracmax++;
            }
            else if(ch == ')'){
                leftbracmin--;
                leftbracmax--;
            }
            else{
                leftbracmin--;
                leftbracmax++;
            }
            if(leftbracmax < 0){
                return false;
            }
            if(leftbracmin < 0){
                leftbracmin = 0;
            }
        }

        return leftbracmin == 0;
    }
};