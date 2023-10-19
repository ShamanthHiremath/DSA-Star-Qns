//#include<bits/stdc++.h>

#include<iostream>
using namespace std;

int main(){
    int n;
    int i=1;
    cin>>n;
    while(i<=n){
        int j=n-i;
        while(j>0){
            cout<<" ";
            j--;
        }
        j=1;
        while(j<=i-1){
            cout<<j;
            j++;
        }
        // cout<<"_";
        j=i;
        while(j>0){
            cout<<j;
            j--;
        }
        cout<<endl;
        i++;



    }


 return 0;
}/*
___1___
__121__
_12321_
1234321


*/