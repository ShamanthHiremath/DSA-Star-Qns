#include <bits/stdc++.h> 
void insertionSort(int n, vector<int> &arr){
    // Write your code here.
    // The left side of the ith index is considered as sorted
    // The righ side of the jth index is considered as unsorted
    // The ith index is taken as a key and inserted into the left side
    // The jth index is assigned the value of i-1 and the left elemnts are pushed to the right untill j becomes 0 or j has a value greater than key
    int key,j;
    for(int i=1;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
