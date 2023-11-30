
    /*
    REFERENCES 
    https://www.codingninjas.com/studio/library/floyds-cycle-finding-algorithm
    */

   /* detect if there is a loop
    in the linked list*/
    bool detectLoop(Node* head)
    {
        Node *slowPointer = head,
             *fastPointer = head;
 
        while (slowPointer != NULL
               && fastPointer != NULL
               && fastPointer->next != NULL) {
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next->next;
            if (slowPointer == fastPointer)
                return 1;
        }
 
        return 0;
    }
    //USING MAPS TO STORE VISITS OF EACH NODES
    bool detectLoop(Node* head){
        if(head==NULL)return false;
        map<Node* , bool> visittracker;
        Node* temp=head;
        while(temp!=NULL){
            if(visittracker[temp]==true){
                return true;
            }
            visittracker[temp]=true;
            temp=temp->next;
        }
        return false;

    }