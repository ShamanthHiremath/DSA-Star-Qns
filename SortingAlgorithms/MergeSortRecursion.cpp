//#include<bits/stdc++.h>

#include<iostream>
using namespace std;

void merge(int* arr, int s, int e){
    int mid=s+(e-s)/2;
    //find the lengths of the left and the right array
    int length1=mid-s+1;
    int length2= e-mid;

    //create those two arrays
    int* left=new int[length1];
    int* right=new int[length2];

    //copy the elements from main array to these array
    int mainarrayindex=s;
    for(int i=0; i<length1; i++){
        left[i]=arr[mainarrayindex++];
    }
    mainarrayindex=mid+1;
    for(int i=0; i<length2; i++){
        right[i]=arr[mainarrayindex++];
    }

    //mergesort these two arrays
    int i=0, j=0, k=s;
    while(i<length1 && j<length2){
        if(left[i]<=right[j]){
            arr[k]=left[i];
            i++;
            k++;
        }
        else{
            arr[k]=right[j];
            j++;
            k++;
        }
    }
    while(i<length1){
        arr[k]=left[i];
        i++;
        k++;
    }
    while(j<length2){
        arr[k]=right[j];
        j++;
        k++;
    }

}

void mergeSort(int* arr, int s, int e){
    //Base Case, when the elements form single units
    if(s>=e){
        return;
    }
    int mid=s+(e-s)/2;
    //divide the given array into two arrays untill theyform single units and merge them

    //left array
    mergeSort(arr, s, mid);
    //right array
    mergeSort(arr, mid+1, e);
    //merge the left and  the right array
    merge(arr, s, e);
}

int main(){
    int arr[10]={90, 40, 10, 50, 100, 30, 70, 60, 20, 80};
    int n=10;
    mergeSort(arr, 0, n-1);
    for(auto i: arr){
        cout<<i<<" ";
    }
 return 0;
}



////VECTORSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
void merge(vector<int>&arr, int s, int e){
    int mid=s+(e-s)/2;
    //find the lengths of the left and the right array
    int length1=mid-s+1;
    int length2= e-mid;

    //create those two arrays
    vector<int>left(length1);
    vector<int>right(length2);

    //copy the elements from main array to these array
    int mainarrayindex=s;
    for(int i=0; i<length1; i++){
        left[i]=arr[mainarrayindex++];
    }
    mainarrayindex=mid+1;
    for(int i=0; i<length2; i++){
        right[i]=arr[mainarrayindex++];
    }

    //mergesort these two arrays
    int i=0, j=0, k=s;
    while(i<length1 && j<length2){
        if(left[i]<=right[j]){
            arr[k]=left[i];
            i++;
            k++;
        }
        else{
            arr[k]=right[j];
            j++;
            k++;
        }
    }
    while(i<length1){
        arr[k]=left[i];
        i++;
        k++;
    }
    while(j<length2){
        arr[k]=right[j];
        j++;
        k++;
    }

}

void mergesort(vector<int>&arr, int s, int e){
    if(s>=e){
        return;
    }
    int mid=s+(e-s)/2;
    mergesort(arr, s, mid);
    mergesort(arr, mid+1, e);
    merge(arr, s, e);

}


void mergeSort(vector < int > & arr, int n) {
    mergesort(arr, 0, n-1);
}