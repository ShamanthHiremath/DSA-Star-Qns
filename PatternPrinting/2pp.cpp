//#include<bits/stdc++.h>

#include<iostream>
using namespace std;

int main(){
    int i=1,j=1;
    int n;
    cout<<"Enter the num: ";
    cin>>n;
    while(i<=n){
        while((j%n)!=0){
            cout<<j<<' ';
            j++;
        }
        j++;
        i++;
        cout<<endl;
    }


 return 0;
}