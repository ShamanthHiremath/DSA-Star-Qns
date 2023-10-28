#include<iostream>
using namespace std;

bool binarySearch(int arr[], int key, int  s=0 , int e=arr.size()){
    if(s>e)return false;
    int mid=s+(e-s)/2;
    if(key==arr[mid])return true;
    else if(key>arr[mid])return binarySearch(arr, key, mid+1, e);
    else return binarySearch(arr, key, s, mid-1);
}