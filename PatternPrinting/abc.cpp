//#include<bits/stdc++.h>

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int i=1;
    while(i<=n){
        int j=1;
        while(j<=n){
            char  ch = 'A'+j-2+i;
            cout<<ch;
            j++;
        }
        i++;
        cout<<endl;
    }
 return 0;
}