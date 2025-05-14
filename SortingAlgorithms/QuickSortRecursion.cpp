//#include<bits/stdc++.h>

#include<iostream>
using namespace std;

int partition(int* arr, int s, int e){
    //count the no of elements smaller than the element in position s
    int count=0;
    for(int i=s+1; i<=e; i++){
        if(arr[i]<=arr[s]){
            count++;
        }
    }
    int pivotIndex=s+count;
    //bring the element in s at correct position that is count
    swap(arr[pivotIndex], arr[s]);

    //check if the elements at the left and right side of count are lesser and greater than the countTH element rply
    int i=s, j=e;
    while(i < pivotIndex && j > pivotIndex){
        //if the element is smaller than the pivot element, then move to the next element
        while(arr[i] < arr[pivotIndex]){
            i++;
        }
        // if the element is greater than the pivot element, then move to the previous element
        while(arr[j] > arr[pivotIndex]){
            j--;
        }
        //if the right element is smaller than the pivot element and the left element is greater than the pivot element, then swap them
        //and move to the next element
        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return pivotIndex;

}

void quickSort(int* arr, int s, int e){
    if(s>=e){
        return ;
    }
    //find the place of inserting that element, which is the partition
    int p=partition(arr, s, e);

    //apply recursion for left side of sorted part
    quickSort(arr, s, p-1);
    //Right side
    quickSort(arr, p+1, e);

}

int main(){
    int arr[10]={90, 40, 10, 50, 100, 30, 70, 60, 20, 80};
    int n=10;
    quickSort(arr, 0, n-1);
    for(auto i: arr){
        cout<<i<<" ";
    }

    return 0;
}





//THIS ONE ALSO WORKS






int partition(int* arr, int s, int e){
    int pivot = arr[e]; // Choose the last element as the pivot
    int i = s - 1; // Index of the smaller element

    for (int j = s; j < e; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[e]);
    return i + 1; // Return the partition index
}

void quickSort(int* arr, int s, int e){
    if (s < e) {
        int p = partition(arr, s, e);
        quickSort(arr, s, p - 1);
        quickSort(arr, p + 1, e);
    }
}