/*
Minimum number of conversions to make a string of parentheses valid
Given a string s consisting of only '(' and ')', find the minimum number of conversions required to make the string valid. A valid string is one where every opening parenthesis has a corresponding closing parenthesis and they are properly nested.

Example 1:
Input: s = "(()))("
Output: 2
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;


    stack<char> st;
    for(char ch: s){
        if(ch == '('){
            st.push(ch);
        }
        else if(ch == ')'){
            if(!st.empty() && st.top() == '('){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
    }

    cout<<st.size() << endl;

    return 0;
}