/*
Sort a linked list of 0s, 1s and 2s

https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

Given the head of a linked list where nodes can contain values 0s, 1s, and 2s only. Your task is to rearrange the list so that all 0s appear at the beginning, followed by all 1s, and all 2s are placed at the end.

Examples:

Input: head = 1 → 2 → 2 → 1 → 2 → 0 → 2 → 2

Output: 0 → 1 → 1 → 2 → 2 → 2 → 2 → 2

Explanation: All the 0s are segregated to the left end of the linked list, 2s to the right end of the list, and 1s in between.
Input: head = 2 → 2 → 0 → 1

Output: 0 → 1 → 2 → 2

Explanation: After arranging all the 0s, 1s and 2s in the given format, the output will be 0 → 1 → 2 → 2.
*/

// Input: 1 -> 0 -> 2 -> 1 -> 0 -> 2 -> 1

// Output: 0 -> 0 -> 1 -> 1 -> 1 -> 2 -> 2

//IF DATA MANIPULATION/EDITING IS ALLOWED
Node* sortList(Node *head){
    Node *temp=head;
    int count0=0, count1=0, count2=0;
    while(temp!=NULL){
        if(temp->data==0){
            count0++;
        }
        else if(temp->data==1){
            count1++;
        }
        else{
            count2++;
        }
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        if(count0!=0){
            temp->data=0;
            count0--;
        }
        else if(count1!=0){
            temp->data=1;
            count1--;
        }
        else{
            temp->data=2;
            count2--;
        }
        temp=temp->next;
    }
    return head;
}

//IF DATA MANIPULATION IS NOT ALLOWED BUT POINTER MANIPULATION IS
Node* sortList(Node *head){
    Node *temp=head;
    int count0=0, count1=0, count2=0;
    Node* zero=NULL;
    Node* one=NULL;
    Node* two=NULL;
    Node* zerohead=NULL;
    Node* onehead=NULL;
    Node* twohead=NULL;
    while(temp!=NULL){
        int val=temp->data;
        if(val==0){
            if(count0==0){
                zerohead=temp;
                zero=temp;
                count0++;
                temp=temp->next;
                continue;
            }
            zero->next=temp;
            zero=zero->next;
        }
        else if(val==1){
            if(count1==0){
                onehead=temp;
                one=temp;
                count1++;
                temp=temp->next;
                continue;
            }
            one->next=temp;
            one=one->next;
        }
        else{
            if(count2==0){
                twohead=temp;
                two=temp;
                count2++;
                temp=temp->next;
                continue;
            }
            two->next=temp;
            two=two->next;
        }
        temp=temp->next;
    }
    head=zerohead;
    zero->next=onehead;
    one->next=twohead;
    two->next=NULL;
    return head;
}