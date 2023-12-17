#include <bits/stdc++.h> 
class Deque
{
    int size;
    int* arr;
    int front;
    int rear;
public:
    // Initialize your data structure.
    Deque(int n)
    {
        size=n;
        arr= new int[n];
        front=-1;
        rear=-1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        if(isFull()){
            return false;
        }
        else if(front==-1){
            front=rear=0;
            arr[front]=x;
        }
        else if(front==0 && rear!=size-1){
            front=size-1;
            arr[front]=x;

        }
        else{
            front--;
            arr[front]=x;

        }
        // arr[front]=x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        if(front==(rear+1)%size){
            // cout<<"QUEUE IS FULL"<<endl;
            return false;
        }
        //empty queue
        else if (front==-1){
            front=rear=0;
            arr[rear]=x;
        }
        //front is in middle rear is at end
        else if(rear==size-1 && front!=0){
            rear=0;
            arr[rear]=x;
        }
        //normal push
        else{
            rear++;
            arr[rear]=x;
        }
        return true;
        
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        //empty queue
        if(isEmpty()){
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
        
    }
    // 0 1 2 3 4 5 6 
    //     f       r 
    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        //empty queue
        if(isEmpty()){
            return -1;
        }
        int pop=arr[rear];
        arr[rear]=-1;
        //only one element
        if(front==rear){
            // int pop=arr[front];
            front=rear=-1;
            // return pop;
        }
        //rear is at end
        else if(rear==0 ){
            // int pop=arr[front];
            rear=size-1;
            // return pop;
        }
        //normal case front anywhere in middle
        else{
            // int pop= arr[front];
            rear--;
        }
        return pop;
        // Write your code here.
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if(front!=-1){
            return arr[front];
        }
        else{
            return -1;
        }
        // Write your code here.
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if(front!=-1){
            return arr[rear];
        }
        else{
            return -1;
        }
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        if(front==-1){
            return true;
        }
        else{
            return false;
        }
    }

    // Returns true if the deque is full. Otherwise returns false.
         
    bool isFull()
    {
        if(front==(rear+1)%size){
            return true;
        }
        else{
            return false;
        }
    }
};