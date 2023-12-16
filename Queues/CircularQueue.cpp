#include <bits/stdc++.h> 
class CircularQueue{
    int size;
    int* arr;
    int front;
    int rear;
    public:
    // Initialize your data structure.
    CircularQueue(int n){
        size=n;
        arr= new int[n];
        front=-1;
        rear=-1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        if(front==(rear+1)%size){
            // cout<<"QUEUE IS FULL"<<endl;
            return false;
        }
        //empty queue
        else if (front==-1){
            front=rear=0;
            arr[rear]=value;
        }
        //front is in middle rear is at end
        else if(rear==size-1 && front!=0){
            rear=0;
            arr[rear]=value;
        }
        //normal push
        else{
            rear++;
            arr[rear]=value;
        }
        return true;
    }


    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        //empty queue
        if(front==-1 && rear==-1){
            return -1;
        }
        int pop=arr[front];
        arr[front]=-1;
        //only one element
        if(front==rear){
            // int pop=arr[front];
            front=rear=-1;
            // return pop;
        }
        //front is at end
        else if(front==size-1){
            // int pop=arr[front];
            front=0;
            // return pop;
        }
        //normal case front anywhere in middle
        else{

            // int pop= arr[front];
            front++;
        }
        return pop;
        // Write your code here.
    }
};