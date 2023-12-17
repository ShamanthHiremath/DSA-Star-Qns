#include<bits/stdc++.h>

#include<iostream>
using namespace std;

class Queue {
    int size;
    int front;
    int rear;
    int *arr;

public:
    Queue() {
        front=0;
        size=10000001;
        arr= new int[size];
        rear=0;
    }
    bool isEmpty() {
        if(front==rear){
            return 1;
        }
        else{
            return 0;
        }
    }

    void enqueue(int data) {
        if(rear==size){
            cout<<"QUEUE frontULL";
            return;
        }
        else{
            arr[rear++]=data;
            return;
        }
    }

    int dequeue() {
        if(front==rear){
            return -1;
        }
        else{
            int ans=arr[front];
            arr[front]=-1;
            front++;
            if(front==rear){
                front=0;
                rear=0;
            }
            return ans;
        }
    }

    int front() {
        if (front == rear) {
            return -1;
        }
        return arr[front];
    }
    int rear(){
        return arr[rear];
    }
};

int main(){


 return 0;
}