Node<int>* sort(Node<int>* first, Node<int>* second){
    if(first->next==NULL){
        first->next=second;
        return first;
    }
    Node<int>* curr1=first;
    Node<int>* forward1=first->next;
    Node<int>* curr2=second;
    Node<int>* forward2=second->next;
    while(forward1!=NULL && curr2!=NULL){
        if((curr1->data<=curr2->data) && (curr2->data<=forward1->data)){
            curr1->next=curr2;
            forward2=curr2->next;
            curr2->next=forward1;
            curr1=curr2;
            curr2=forward2;
        }
        else{
            curr1=forward1;
            forward1=forward1->next;
            if(forward1==NULL){
                curr1->next=curr2;
                return first;
            }
        }

    }
    return first;

    
}
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(first==NULL){
        return second;
    }   
    if(second==NULL){
        return first;
    }
    if(first->data<=second->data){
        return sort(first, second);
    }
    else{
        return sort(second, first);
    }
}