/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/
//Jump two nodes for longjump
//while 1 node for short jump
Node *findMiddle(Node *head) {
    Node* shortjump=head;
    Node* longjump=head;
    while (longjump != NULL && longjump->next!=NULL) {
      shortjump = shortjump->next;
      longjump = longjump->next->next;
    }
    return shortjump;
}

Node *findMiddle(Node *head) {
    int len=0;
    Node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        len++;
    }
    temp=head;
    for(int i=1;i<=len/2;i++){
        temp=temp->next;
    }
    return temp;
}

