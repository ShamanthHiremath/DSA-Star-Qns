#include<bits/stdc++.h>

#include<iostream>
using namespace std;

void reversestring(string& s, int i, int j){
    if(i>=j)return ;
    swap(s[i], s[j]);
    return reversestring(s,i+1,j-1);
}

int main(){
    string s1="abcdef";
    reversestring(s1, 0, s1.size()-1);
    cout<<s1;


 return 0;
}

