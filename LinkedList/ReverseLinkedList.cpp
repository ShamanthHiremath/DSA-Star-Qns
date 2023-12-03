#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/
//Recursions

void reverselist(LinkedListNode<int>* &head, LinkedListNode<int>* curr, LinkedListNode<int>*prev){
    //base case
    if (curr == NULL) {
      head = prev;
      return;
    }
        LinkedListNode<int>* forward=curr->next;
        reverselist(head, forward, curr);
        curr->next=prev;
}

LinkedListNode<int>* reverse3(LinkedListNode<int>* &head){
    //base case
    if(head==NULL || head->next==NULL){
        return head;
    }
    LinkedListNode<int> *smalllist= reverse3(head->next);
    head->next->next=head;
    head->next=NULL;
    return smalllist;
}
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp=NULL;
        while(head!=NULL){
            ListNode* forward=head->next;
            head->next=temp;
            temp=head;
            head=forward;
        }
        return temp;
    }
};
//the above code is same as below one but it efficiently uses forward and temp without the need for prev and curr and uses less memory beacausethe forward node dies after the while loop scopw

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    if(head==NULL || head->next==NULL){
        return head;
    }
    LinkedListNode<int>* prev=NULL;
    LinkedListNode<int>* curr=head;
    LinkedListNode<int>* forward=NULL;
    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    head=prev;
    return head;
}