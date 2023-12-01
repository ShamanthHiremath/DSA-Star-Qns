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