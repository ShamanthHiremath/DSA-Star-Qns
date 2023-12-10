#include<bits/stdc++.h>

#include<iostream>
using namespace std;

class Stack{
    public:
        int top;
        int size;
        int *arr;
    
    Stack(int size){
        this->size=size;
        arr=new int[size];
        top=-1;
    }
    void push(int element){
        if(top<size-1){
            top++;
            arr[top]=element;
        }
        else{
            cout<<"STACK OVERFLOW!!!";
        }
    }
    void pop(){
        if(top!=-1){
            top--;
        }
        else{
            cout<<"STACK UNDERFLOWS!!!";
        }
    }
    int peek(){
        if(top>=0 && top<size){
            return arr[top];
        }
        else{
            cout<<"STACK IS EMPTY";
        }
    }
    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){
    Stack STACK(4);
    STACK.push(1);
    STACK.push(10);
    STACK.pop();
    STACK.push(5);
    STACK.push(4);
    STACK.pop();
    cout<<STACK.peek();
    STACK.pop();
    STACK.pop();
    //STACK.pop();
    //STACK.pop();




 return 0;
}