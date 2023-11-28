//#include<bits/stdc++.h>

#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;
        Node(int data){
            this->data=data;
            this->next=NULL;
            this->prev=NULL;
        }
};
void insertAtHead(Node* &head, int data){
    Node* temp=new Node(data);
    temp->next=head;
    head->prev=temp;
    head=temp;
}

void insertAtTail(Node* &tail, int data){
    Node* temp=new Node(data);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}
void insertAtPosition(Node* &head, Node* &tail, int position, int data){
    if(position==1){
        insertAtHead(head, data);
        return;
    }
    Node* temp=head;
    //temp=head;
    int count=1;
    while(count<position-1){
        temp=temp->next;
        count++;
    }
    if(temp->next==NULL){
        insertAtTail(tail, data);
        return;
    }
    Node* newnode= new Node(data);
    newnode->next=temp->next;
    temp->next->prev=newnode;
    temp->next=newnode;
    newnode->prev=temp;
}

//Traveral
void printLinkedList(Node* head){
    Node* temp= head;
    int len=0;
    cout<<"The Linked List is: ";
    while(temp!=NULL){
        len++;
        cout<< temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl<<"Linked List Length = "<< len<<endl<<endl;

}

//deletion
void deletenode(Node* &head,Node* &tail, int position){
    if(position==1){
        Node* delnode=head;
        head=delnode->next;
        delnode->next->prev=NULL;
        delnode->next=NULL;
        delete delnode;
    }
    else{
        Node* prevnode=head;
        Node* delnode=head->next;
        int count=1;
        while(count<position-1){
        if(delnode->next==NULL){
            delnode->prev=NULL;
            prevnode->next=NULL;
            tail=prevnode;
            delete delnode;
            return;
        }
        count++;
        prevnode=prevnode->next;
        delnode=delnode->next;
    }
    prevnode->next=delnode->next;
    delnode->prev=NULL;
    delnode->next=NULL;
    delete(delnode);
        // Node* prevnode= NULL;
        // Node* delnode=head;
        // int count=1;
        // while(count<position){
        //     prevnode=delnode;
        //     delnode=delnode->next;
        //     count++;
        // }
        // prevnode->next=delnode->next;
        // delnode->next=NULL;
        // delnode->prev=NULL;
        // delete delnode;
    }
    //This also should work

    // while(count<position-1){
    //     if(delnode->next==NULL){
    //         delnode->prev=NULL;
    //         prevnode->next=NULL;
    //         tail=prevnode;
    //         delete delnode;
    //         return;
    //     }
    //     count++;
    //     prevnode=prevnode->next;
    //     delnode=delnode->next;
    // }
    // prevnode->next=delnode->next;
    // delnode->prev=NULL;
    // delnode->next=NULL;
    // delete(delnode);

}

int main(){
    Node* n1 = new Node(5);
    Node* head=n1;
    Node* tail=n1;
    printLinkedList(head);
    insertAtHead(head, 29);
    insertAtHead(head, -9);
    printLinkedList(head);
    insertAtTail(tail, 9);
    insertAtTail(tail, 33);
    printLinkedList(head);
    insertAtPosition(head, tail, 3, 69);
    printLinkedList(head);
    deletenode(head, tail, 6
    );
    printLinkedList(head);


    cout<<"HEAD IS "<<head->data<<endl<<"TAIL IS "<<tail->data;
 return 0;
}