#include<bits/stdc++.h>

#include<iostream>
using namespace std;

void linearsearch(int arr[], int key, int pos=0 ){
    if(pos==arr.size()){
        cout<<"Element not found";
        return ; 
    }
    if(arr[pos]==key){
        cout<<"Element found";
        return ;
    }
    linearsearch(arr, key, pos+1);
    return ;
}