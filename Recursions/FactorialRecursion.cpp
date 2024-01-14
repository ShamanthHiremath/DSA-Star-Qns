//#include<bits/stdc++.h>

#include<iostream>
using namespace std;

int fac(int n){
    if(n==0)return 1;
    return n*fac(n-1);
}

int main(){
    cout<<"ENTER THE NUMBER TO FIND FACTORIAL: ";
    int x;
    cin>>x;
    cout<<fac(x);
 return 0;
}