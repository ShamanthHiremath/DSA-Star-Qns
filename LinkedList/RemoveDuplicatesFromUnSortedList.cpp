Node *removeDuplicates(Node *head)
{
    if(head==NULL||head->next==NULL){
        return head;
    }
    Node* temp=head;
    Node* prev=NULL;
    unordered_map<int, bool> tracker;
    while(temp!=NULL){
        if(tracker[temp->data]==true){
            Node *delnode=temp;
            if (prev == NULL) {
                // Duplicate found at the beginning of the list
                head = temp->next;
                temp = head;
            }
            else if(temp->next==NULL){
                prev->next=NULL;
            }
            else {
                // Duplicate found elsewhere in the list
                prev->next = temp->next;
                temp = prev->next;
            }
            delete delnode;
            continue;
        }
        tracker[temp->data]=true;
        prev = temp;
        temp=temp->next;
        //prev=prev->next;
    }
    return head;
}