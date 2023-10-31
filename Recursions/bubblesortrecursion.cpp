#include<bits/stdc++.h>

#include<iostream>
using namespace std;

void bubblesort(int *arr, int n=//arr.size){
    //if(n==-1)n=(sizeof(arr)/4)-1;
    if(n==0 || n==1) return ;
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }
    bubblesort(arr, n-1);
}

int main(){
    int arr[]={9,5,2,7,2,1,75,0};
    bubblesort(arr, 8);
    cout<<*arr;


 return 0;
}