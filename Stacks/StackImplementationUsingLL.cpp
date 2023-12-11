#include<bits/stdc++.h>

// #include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node(int data){
            this->data=data;
            this->next=NULL;
        }
        // Node(int value) : data(value), next(nullptr) {}
};
class Stack{
    private:
        Node* top;
        int size;
        int count;
    public:

    Stack(int size){
        this->size=size;
        top=NULL;
        count=0;
    }

    void push(int num){
        if(count<size){
            Node* newnode= new Node(num);
            newnode->next=top;
            top=newnode;
            count++;
            cout << num << " pushed to the stack.\n";
        }
        else{
            cout<<"STACK OVERFLOWS\n";
        }
    }

    void pop(){
        if(count>0){
            Node* delnode= top;
            top=top->next;
            int popdata= delnode->data;
            delete delnode;
            cout << popdata << " popped to the stack.\n";
            count--;
        }
        else{
            cout<<"STACK UNDERFLOWS\n";
        }
    }

    int peek(){
        cout<<"TOP ELEMENT IS: "<<top->data<<"\n";
        return top->data;
    }

    bool isEmpty() {
        return top ==NULL;
    }

    bool isFull() {
        return count == size;
    }
};
int main(){
    Stack stack(3); // Initialize a stack with a size of 3

    stack.push(5);
    stack.push(10);
    stack.push(15);
    stack.push(20); // Trying to push into a full stack

    cout<< stack.peek() << endl;

    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    cout<<endl<<stack.isEmpty(); // Trying to pop from an empty stack


 return 0;
}