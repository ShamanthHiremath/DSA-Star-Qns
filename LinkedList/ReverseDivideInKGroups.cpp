/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node* kReverse(Node* head, int k) {
    if(head==NULL || head->next==NULL){
        return head;
    }
    //this part prevents u from reversing the smaller list at the end of given linkedlist which has less nodes than k 
    int count=1;
    Node* travel=head;
    while(travel->next!=NULL){
        travel=travel->next;
        count++;
    }
    if(count<k) return head;
    //untill here
    count=1;
    Node* prev=NULL;
    Node* curr=head;
    Node* forward=NULL;
    
    while(curr!=NULL && count<=k){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
        count++;
    }
    if(forward!=NULL){
        head->next=kReverse(forward, k);
    }
    return prev;
}