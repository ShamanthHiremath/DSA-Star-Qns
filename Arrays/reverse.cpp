#include<bits/stdc++.h>

#include<iostream>
using namespace std;

int main(){
    stack<int> Stack;
    int arr[10]={9,8,7,6,5,4,3,2,1};
    for(int i=0; i<10; i++){
        Stack.push(arr[i]);
    }
    int i=0;
    while(!Stack.empty()){
        arr[i]=Stack.top();
        Stack.pop();
        i++;
    }
    //cout<<"HIIHIHIHIH";
    for(int i=0; i<10; i++){
        cout<<arr[i]<<" ";
    }
 return 0;
}