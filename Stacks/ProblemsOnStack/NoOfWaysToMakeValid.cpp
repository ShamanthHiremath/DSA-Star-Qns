#include <bits/stdc++.h> 
bool valid(string str){
  stack<char>st;
  for(int i=0; i<str.length(); i++){
    if(str[i]=='{'){
      st.push(str[i]);
    } 
    else {
      if(!st.empty()){
        st.pop();
      }
      else{
        return false;
      }
    }
  }
  return st.empty();
}
int findMinimumCost(string str) {
  if(str.length()%2==1)return -1;
  int open=0;
  int close=0;
  if(valid(str)){
    return 0;
  }
  else{
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '{') {
            open++;
        } else if (str[i] == '}') {
            if (open > 0) {
                open--;
            } else {
                close++;
            }
        }
    }
    return (open + 1) / 2 + (close + 1) / 2;
  }
}