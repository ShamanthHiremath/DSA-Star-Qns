/*Sample Input 1 :
2
(a+b)
(a+c*b)+(c))
Sample Output 1 :
No
Yes
Sample Input 2 :
2
(a*b+(c/d))
((a/b))
Sample Output 2 :
No
Yes
*/
#include <bits/stdc++.h> 
bool checkRedundant(stack<char>& st){
    bool check=true;
    //run the loop untill the top of the stack is an opening bracket
    while(st.top()!='('){
        char top=st.top();
        if(top == '/' ||top == '*' ||top == '-' ||top == '+'){
            //if an operand is encountered... it is non redundant... so check is false
            check= false;
        }
        st.pop();
    }
    //return check value TRUE if no operand was found in the middle
    //false if opernads were found
    return check;
}
bool findRedundantBrackets(string &s)
{
    //to store (, +,-, \, * 
    stack<char> st;
    for(int i=0; i<s.length(); i++){
        char ch=s[i];
        //push all opening brackets and operands into stack
        if(ch == '(' || ch == '/' ||ch == '*' ||ch == '-' ||ch == '+'){
            st.push(ch);
        }
        //else check for redundancy
        else{
            //ignore alphabets
            if(ch==')'){
                if(checkRedundant(st)){
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;
}
