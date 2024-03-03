//#include<bits/stdc++.h>

#include<iostream>
#include<queue>
using namespace std;

int solve(int arr[], int n, int k){
    deque<int>maxi;
    deque<int>mini;

    //First k size window
    for(int i=0; i<k; i++){
        //REMOVAL OF ALL INDICES WITH NON MAXIMUM ELEMENT CONTAINING INDEX
        while(!maxi.empty() && arr[maxi.back()]<= arr[i]){
            maxi.pop_back();
        }
        //REMOVAL OF ALL INDICES WITH NON MINIMUM ELEMENT CONTAINING INDEX
        while(!mini.empty() && arr[mini.back()]>= arr[i]){
            mini.pop_back();
        }
        //ADD
        maxi.push_back(i);
        mini.push_back(i);
    }

    int sum=0;

    //the rest part of the array
    for(int i=k; i<n; i++){
        sum+=arr[maxi.front()]+arr[mini.front()];

        //removal of the elements not belonging too the current window k
        while(!maxi.empty() && i - maxi.front()>=k){
            maxi.pop_front();
        }
        while(!mini.empty() && i - mini.front()>=k){
            mini.pop_front();
        }
        
        //Addition of elements to the new window
        //REMOVAL OF ALL INDICES WITH NON MAXIMUM ELEMENT CONTAINING INDEX
        while(!maxi.empty() && arr[maxi.back()]<= arr[i]){
            maxi.pop_back();
        }
        //REMOVAL OF ALL INDICES WITH NON MINIMUM ELEMENT CONTAINING INDEX
        while(!mini.empty() && arr[mini.back()]>= arr[i]){
            mini.pop_back();
        }
        //ADD
        maxi.push_back(i);
        mini.push_back(i);
        
    }
    sum+=arr[maxi.front()]+arr[mini.front()];
    return sum;

}

int main(){
    int arr[]={2, 5, -1, 7, -3, -1, -2};
    int n=7;
    int k=4;
    cout<<"Sum of MAX and MIN element in a window of size k in the array: "<<solve(arr, n, k);

 return 0;
}