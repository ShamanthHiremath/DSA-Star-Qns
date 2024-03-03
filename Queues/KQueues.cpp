//#include<bits/stdc++.h>

#include<iostream>
using namespace std;


class KQueue{
     
    int* arr;
    int* next;
    int* rear;
    int* front;
    int freespot;
    int n;
    int k;
    public:
    KQueue(int n, int k){
        this->n=n;
        this->k=k;

        arr= new int[n];

        next= new int[n];
        for(int i=0; i<n-1; i++){
            next[i]=i+1;
        }
        next[n-1]=-1;

        front= new int[k];
        rear= new int[k];
        for(int i=0; i<n; i++){
            rear[i]=front[i]=-1;
        }
        freespot=0;
    }

    void enqueue(int data, int qn){
        //Overflow condition
        if(freespot==-1){
            cout<<"STACK "<<qn<<" OVERFLOWs"<<endl;
            return;
        }
        //take out the available index in freespot
        int index=freespot;
        //make freespot equal to the next available index
        freespot=next[index];

        //first element to be inserted
        if(front[qn-1]==-1){
            front[qn-1]=index;
        }
        //linking of 
        else{
            next[rear[qn-1]]=index;
        }
        //update next[index]
        next[index]=-1;
        //update rear[qn-1] to the available index
        rear[qn-1]=index;
        //insert element
        arr[index]=data;
    }

    int dequeue(int qn){
        if(front[qn-1]==-1){
            cout<<"STACK "<<qn<<" UNDERFLOWS\n";
            return -1;
        }
        int index=front[qn-1];
        int element=arr[index];
        front[qn-1]=next[index];
        next[index]=freespot;
        freespot=index;
        return element;
    }
    void displayQ(){
        for(int i=0; i<n; i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }

};

int main(){
    KQueue q(9, 3);
    q.enqueue(10, 1);
    q.enqueue(20, 2);
    q.enqueue(30, 3);
    q.enqueue(40, 1);
    q.enqueue(50, 1);
    q.displayQ();
    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(1)<<endl;

    q.displayQ();

    return 0;
}