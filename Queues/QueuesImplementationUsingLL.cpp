//#include<bits/stdc++.h>

#include<iostream>
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
class Queue{
    public:
        Node* front;
        Node* rear;
        // int count;
        // int size;
        Queue(){
            this->front=NULL;
            this->rear=NULL;
            // count=-1;
        }
        // Queue(int size){
        //     this->front=NULL;
        //     this->rear=NULL;
        //     this->size=size;
        //     count=-1;
        // }
        //push to the back
        void enqueue(int num){
            //queue is empty
            Node* newnode=new Node(num);
            if(isEmpty()){
                // newnode->next=front;
                rear=front=newnode;
            }
            else{
                rear->next=newnode;
                rear=newnode;
            }
            cout<<num<<" ENQUEUED to the QUEUE"<<endl;
        }
        void dequeue(){
            if(isEmpty()){
                cout<<"QUEUE UNDERFLOWS: EMPTY"<<endl;
                return ;
            }
            else{
                Node* delnode=front;
                front=front->next;
                int popdata=delnode->data;
                if(front==NULL){
                    rear=NULL;
                }
                cout<<"POPPED VALUE IS "<<popdata<<endl;
                delete delnode;
                return;
            }
        }
        bool isEmpty(){
            // return front==rear==NULL;
            if(front==NULL&& rear==NULL){
                return true;
            }
            else{
                return false;
            }
        }
        bool isFull(){
            Node* newnode=new (nothrow) Node(0);
            if(newnode==NULL){
                cout<<"QUEUE OVERFLOWS is FULL"<<endl;
                return true;
            }
            delete newnode;
            return false;
        }
        int getFront(){
            if(isEmpty()){
                cout<<"QUEUE is EMPTY";
                return -1;
            }
            else{
                return front->data;
            }
        }
        int getRear(){
            if(isEmpty()){
                cout<<"QUEUE is EMPTY";
                return -1;
            }
            else{
                return rear->data;
            }
        }
        void traverseQueue(){
            if(isEmpty()){
                cout<<"QUEUE is EMPTY\n";
                return ;
            }
            else{
                Node* temp=front;
                int i=1;
                cout<<"QUEUE is as follows: \n\n";
                while(temp!=NULL){
                    cout<<"Element "<<i<<" is "<<temp->data<<endl;
                    temp=temp->next;
                    i++;
                }
            }
        }
};

int main() {
    Queue myQueue;

    // Enqueue elements
    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    // Display front and rear elements
    cout << "Front element: " << myQueue.getFront() << endl;
    cout << "Rear element: " << myQueue.getRear() << endl;

    // Dequeue an element
    myQueue.dequeue();

    // Display front and rear elements after dequeue
    cout << "Front element after dequeue: " << myQueue.getFront() << endl;
    cout << "Rear element after dequeue: " << myQueue.getRear() << endl;

    // Enqueue more elements
    myQueue.enqueue(40);
    myQueue.enqueue(50);

    // Display front and rear elements after enqueue
    cout << "Front element after enqueue: " << myQueue.getFront() << endl;
    cout << "Rear element after enqueue: " << myQueue.getRear() << endl;

    // Traverse and display all elements in the queue
    myQueue.traverseQueue();

    return 0;
}
