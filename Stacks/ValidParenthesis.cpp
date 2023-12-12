bool match(char ch, char top){
    if((ch==')'&& top=='(')){
        return true;
    }
    else if (ch == ']' && top == '['){
        return true;
    }
    else if (ch == '}'&& top=='{'){
        return true;
    }
    else{
        return false;
    }
}

bool isValidParenthesis(string s)
{
    stack<char>brackets;
    for(int i=0; i<s.size(); i++){
        char ch=s[i];
        if(ch=='('|| ch=='{'|| ch=='['){
            brackets.push(ch);
        }
        else{
            if(!brackets.empty()){
                char top=brackets.top();
                if(match(ch, top)){
                    brackets.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
    if(brackets.empty()){
        return true;
    }
    else{
        return false;
    }
}