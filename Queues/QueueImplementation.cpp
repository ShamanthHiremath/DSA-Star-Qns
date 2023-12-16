#include<bits/stdc++.h>

#include<iostream>
using namespace std;

class Queue {
    int size;
    int start;
    int end;
    int *arr;

public:
    Queue() {
        start=0;
        size=10000001;
        arr= new int[size];
        end=0;
    }
    bool isEmpty() {
        if(start==end){
            return 1;
        }
        else{
            return 0;
        }
    }

    void enqueue(int data) {
        if(end==size){
            cout<<"QUEUE startULL";
            return;
        }
        else{
            arr[end++]=data;
            return;
        }
    }

    int dequeue() {
        if(start==end){
            return -1;
        }
        else{
            int ans=arr[start];
            arr[start]=-1;
            start++;
            if(start==end){
                start=0;
                end=0;
            }
            return ans;
        }
    }

    int front() {
        if (start == end) {
            return -1;
        }
        return arr[start];
    }
    int rear(){
        return arr[end];
    }
};

int main(){


 return 0;
}