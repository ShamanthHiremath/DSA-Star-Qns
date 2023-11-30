/*
Floyd's Cycle Detection Algorithms

The problem is that a few linked list have a cycle within them (read about cycles in linked lists on internet), so the temp pointer never actually comes back at head or at NULL causing an infinite loop
EXAMPLE:
No of nodes = 7
1 2 5 4 3 8 5
The last 5 connects to 3rd 5

*/

bool isCircular(Node* head){
    if(head == NULL) return true;
    if(head->next == NULL) return(false); 
    Node * slow = head;
    Node * fast = head; 
    while(slow!=NULL && fast!=NULL){
        slow = slow->next;
        fast = fast->next;
        if(fast!=NULL) fast = fast->next;
        //for a LINKED LIST WITH CIRCULAR LOOPS WITHIN THEM
        // At a certain point both slow and fast points meet but u have to check if the slow or fast is pointing to the head  or not 
        if(slow == fast){
            if(slow == head) return true;
            else return false;
        }
    }
    //for NORMAL LINKED LIST
    return false;
}



//CHECK FOR STRAIGHT LINKED LIST WHICH EITHER END AT NULL OR CONNECT BACK AT HEAD

bool isCircular(Node* head){
    if(head==NULL || head->next==NULL || head->next==head)return true;
    Node* temp=head;
    while(temp->next!=head){
        if(temp->next==NULL){
            return false;
        }
        temp=temp->next;
    }
    if(temp->next==NULL)return false;
    if(temp->next!=head)return false;
    return true;
}
bool isCircular(Node* head){
    if(head==NULL )return true;
    Node* temp=head->next;
    while(temp!=head && temp!=NULL){
        // if(temp->next==NULL){
        //     return false;
        // }
        temp=temp->next;
    }
    //if(temp->next==NULL)return false;
    if(temp==head)return true;
    return false;
}