#include <bits/stdc++.h>
int precedence(char oper){
    if(oper == '^'){
        return 3;
    }
    else if(oper == '*' || oper == '/'){
        return 2;
    }
    else if(oper == '+' || oper == '-'){
        return 1;
    }
    else{
        return 0;
    }
}

string infixToPostfix(string exp){
	string postfix;
    stack<char>st;

    for (int i = 0; i < exp.length(); i++){
        //if s[i] is either a number or an variable
        if (isalnum(exp[i])) {
            postfix.push_back(exp[i]);
        }
        //if there is an opening bracket
        else if (exp[i] == '('){
            st.push(exp[i]);
        }
        //for closing brackets
        else if (exp[i] == ')'){
            //add all operand elements inside the brackets to the postfix and 
            //empty the stack untill the operand inside the brackets are added to the postfix exprsion
            
            while (!st.empty() && st.top() != '('){
                postfix.push_back(st.top());
                st.pop();
            }
            st.pop(); // Pop '('
        }
        else{
            //for lower precedence s[i] remove from top and keep adding untill top is of higher order
            while (!st.empty() && precedence(exp[i]) <= precedence(st.top())){
                postfix.push_back(st.top());
                st.pop();
            }
            //for higher precendence s[i] push to stack
            st.push(exp[i]);
        }
    }

    while(!st.empty()){
        postfix.push_back(st.top());
        st.pop();
    }

    return postfix;
}