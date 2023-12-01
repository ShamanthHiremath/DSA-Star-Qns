/*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/

Node *removeLoop(Node *head)
{
    bool detect=false;
    Node* slowcar=head;
    Node* fastcar=head;
    Node* meetpoint=NULL;
    while(fastcar!=NULL && slowcar!=NULL && fastcar->next!=NULL){
        slowcar=slowcar->next;
        fastcar=fastcar->next->next;
        if(slowcar==fastcar){
            detect=true;
            meetpoint=slowcar;
            break;
        }
    }
    if(meetpoint==head){
        while(meetpoint->next!=head){
            meetpoint=meetpoint->next;
        }
        meetpoint->next=NULL;
        return head;
    }
    if(detect==false)return head;
    slowcar=head;
    
    while(meetpoint->next!=slowcar->next){
        
        
        slowcar=slowcar->next;
        meetpoint=meetpoint->next;
    }
    meetpoint->next=NULL;
    return head;
}