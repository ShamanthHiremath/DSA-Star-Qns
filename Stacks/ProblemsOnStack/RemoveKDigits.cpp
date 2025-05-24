/*
402. Remove K Digits

https://leetcode.com/problems/remove-k-digits/

Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

 

Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
 
*/
class Solution {
public:
    string removeKdigits(string num, int k){
        if(k >= num.size()){
            return "0";
        }

        stack<char> st;
        for(char digit : num){
            while(!st.empty()&& k > 0 && st.top()> digit){
                st.pop(); // remove larger digits greedily
                k--;
            }
            st.push(digit);
        }

        // remove remaining digits if needed
        while(k-- > 0 && !st.empty()){
            st.pop();
        }
        
        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        // removing leading zeros
        int idx = 0;
        while(idx < ans.size()&& ans[idx] == '0'){
            idx++;
        }

        ans = ans.substr(idx);

        return ans.empty()? "0" : ans;
    }
};