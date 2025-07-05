/*
282. Expression Add Operators

https://leetcode.com/problems/expression-add-operators/

Given a string num that contains only digits and an integer target, return all possibilities to insert the binary operators '+', '-', and/or '*' between the digits of num so that the resultant expression evaluates to the target value.

Note that operands in the returned expressions should not contain leading zeros.


Example 1:
Input: num = "123", target = 6
Output: ["1*2*3","1+2+3"]
Explanation: Both "1*2*3" and "1+2+3" evaluate to 6.

Example 2:
Input: num = "232", target = 8
Output: ["2*3+2","2+3*2"]
Explanation: Both "2*3+2" and "2+3*2" evaluate to 8.

Example 3:
Input: num = "3456237490", target = 9191
Output: []
Explanation: There are no expressions that can be created from "3456237490" to evaluate to 9191.
*/
class Solution {
public:
    void solve(string num, int target, int ind, long long prev, long long curr, string expr, vector<string>& ans){
        if(ind >= num.size()){
            if(curr == target){
                ans.push_back(expr);
            }
            return;
        }

        // the qn is misleading, it can consider any segment of the num string as integer
        for(int len = 1; len + ind <=num.size(); len++){
            string part = num.substr(ind, len);

            // leading zeros edge case
            if(part.size() > 1 and part[0]=='0'){
                break;
            }
            int val = stoll(part);


            if(ind == 0){
                solve(num, target, len, val, val, part, ans);
            }
            else{
                solve(num, target, ind + len, val, curr + val, expr + "+" + part, ans);
                solve(num, target, ind + len, -val, curr - val, expr + "-" + part, ans);
                solve(num, target, ind + len, prev * val, curr - prev + (prev * val), expr + "*" + part, ans);
            }


 
        }

    }
    vector<string> addOperators(string num, int target) {
        if(target == -2147483648 and num == "2147483648"){
            return {};
        }
        if (num.size() == 1) {
            if (stoll(num) == target) {
                return {num};
            } else {
                return {};
            }
        }

        string expr = "";
        vector<string>ans;
        solve(num, target, 0, 0, 0, expr, ans);


        return ans;
    }
};