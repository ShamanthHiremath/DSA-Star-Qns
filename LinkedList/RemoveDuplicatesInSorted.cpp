Node * removeDuplicates(Node *head)
{
    Node* temp= head;
    //Node* forward=head->next;
    while(temp->next!=NULL){
        if(temp->data==temp->next->data){
            Node* curr=temp->next;
            delete curr;
            //curr=forward;
            temp->next=temp->next->next;
            //forward=forward->next;
            temp->next->next->prev=temp;
        }
        else{
            temp=temp->next;
        }
    }
    return head;
}
Node * removeDuplicates(Node *head)
{
    if(head==NULL||head->next==NULL){
        return head;
    }
    Node* temp=head;
    while(temp->next!=NULL){
    if(temp->data==temp->next->data){
        Node *delnode=temp->next;
        delete delnode;
        if(temp->next->next!=NULL){
            temp->next->next->prev=temp;
            temp->next=temp->next->next;
        }
        else{
            temp->next=NULL;
        }

    }
    else{
        temp=temp->next;
    }
    }
    return head;
}

class Solution {
  public:
    Node* removeAllDuplicates(struct Node* head) {
        // code here
        if(head == NULL || head->next==NULL){
            return head;
        }
        
        Node dummy(0);
        dummy.next = head;
        Node* prev = &dummy;
        Node* curr = head;

        while (curr != NULL && curr->next != NULL) {
            if (curr->data != curr->next->data) {
                prev = curr;
                curr = curr->next;
            } else {
                int dup = curr->data;
                while (curr != NULL && curr->data == dup) {
                    Node* temp = curr;
                    curr = curr->next;
                    delete temp;
                }
                prev->next = curr;
            }
        }

        return dummy.next;
    }
};