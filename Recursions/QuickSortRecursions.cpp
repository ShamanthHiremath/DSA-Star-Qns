#include <bits/stdc++.h>
int partition(vector<int>& arr, int s, int e){
    int pivot=arr[s];
    int count=0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<=pivot)count++;
    }
    swap(arr[s],arr[s+count]);
    int i=s, j=e;
    while(i<s+count && j>s+count){
        while(arr[i]<=arr[s+count])i++;
        while(arr[j]>arr[s+count])j--;
        if(i<s+count && j>s+count)swap(arr[i],arr[j]);
    }
    return s+count;
}
void sorti(vector<int>& arr, int s, int e){
    if(s>=e)return;
    int p=partition(arr, s, e);
    sorti(arr, s,p-1);
    sorti(arr, p+1, e);
}
vector<int> quickSort(vector<int> arr)
{
    sorti(arr, 0, arr.size()-1);
    return arr;
}
