//#include<bits/stdc++.h>

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int i=1;
    char ch;
    while(i<=n){
        int j=n-i;
        while(j>0){
            cout<<" ";
            j--;
        }
        int k=1;
        while(k<=i){
            cout<<"*";
            k++;
        }
        cout<<endl;
        i++;
    }



 return 0;
}