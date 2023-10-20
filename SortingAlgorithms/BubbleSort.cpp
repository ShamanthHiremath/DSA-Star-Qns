#include <bits/stdc++.h> 
void bubbleSort(vector<int>& arr, int n)
{   
    // Pushing the large elemnts to the end
    for(int i=0;i<n;i++){
        bool swapped=false;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }
        if(swappped=false) break;
    }
    //return arr;
}
