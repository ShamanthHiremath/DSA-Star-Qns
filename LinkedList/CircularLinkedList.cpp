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
        ~Node(){
            if(this->next=NULL){
                delete next;
                next=NULL;
            }
        }
};
void insertNode(Node* &tail, int data, int elementval=0){
    //emptylist
    if(tail==NULL){
        Node* newnode= new Node(data);
        tail=newnode;
        newnode->next=newnode;
        return;
    }
    else{
        //element is present in the list
        Node* temp=tail;
        while(temp->data!=elementval){
            temp=temp->next;
        }
        Node* newnode=new Node(data);
        newnode->next=temp->next;
        temp->next=newnode;
    }
}
void deletenode(Node* &tail, int value){
    //empty
    if(tail==NULL){
        cout<<"empty list";
        return;
    }
    else{
        Node* prevnode=tail;
        Node* delnode=prevnode->next;
        while(delnode->data!=value){
            prevnode=delnode;
            delnode=delnode->next;
        }
        prevnode->next=delnode->next;
        if(tail==delnode){
            tail=prevnode;
        }
        delnode->next=NULL;
        delete delnode;
    }
}
void printLinkedList(Node* &tail){
    Node* temp= tail;
    do{
        cout<<tail->data<<" ";
        tail=tail->next;
     } while(tail!=temp);
    
    cout<<endl;

}

int main(){
    Node* tail=NULL;
    insertNode(tail, 3, 5);
    printLinkedList(tail);
    insertNode(tail, 10,3);
    printLinkedList(tail);
    insertNode(tail, -1,3);
    printLinkedList(tail);
    deletenode(tail, 3);
    printLinkedList(tail);



 return 0;
}