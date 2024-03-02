/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */
/*

EXAMPLE:

4  ->  5  ->  7  ->  11  ->  14
|      |      |      |       | 
6      71     8      12      5
              |      |       |
              9      19      17

OUTPUT:

4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 11 -> 12 -> 14 -> 15 -> 17 -> 19 -> 71   

*/

Node* sort(Node* first, Node* second){
    if(first->child==NULL){
        first->child=second;
        return first;
    }
    Node* curr1=first;
    Node* forward1=first->child;
    Node* curr2=second;
    Node* forward2=second->child;
    while(forward1!=NULL && curr2!=NULL){
        if((curr1->data<=curr2->data) && (curr2->data<=forward1->data)){
            curr1->child=curr2;
            forward2=curr2->child;
            curr2->child=forward1;
            curr1=curr2;
            curr2=forward2;
        }
        else{
            curr1=forward1;
            forward1=forward1->child;
            if(forward1==NULL){
                curr1->child=curr2;
                return first;
            }
        }

    }
    return first;    
}

Node* sortTwoLists(Node* first, Node* second)
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

Node* flattenLinkedList(Node* head) 
{
    if(!head){
        return NULL;
    }
    if(head->next==NULL){
        return head;
    }
    Node* l1=head;
    Node* l2=head->next;
    Node* l1andl2 =NULL;
    while(l2!=NULL){
        l1andl2= sortTwoLists(l1, l2);
        l1=l1andl2;
        l2=l2->next;
    }
    return l1andl2;
}




///RECURSIVE CALL
Node* merge(Node* first, Node* second) {
    if (!first)
        return second;
    if (!second)
        return first;

    if (first->data <= second->data) {
        first->child = merge(first->child, second);
        return first;
    } else {
        second->child = merge(first, second->child);
        return second;
    }
}

Node *flattenLinkedList(Node *head) {
    if (!head || !head->next){
        return head;
    }
    head->next = flattenLinkedList(head->next);
    return merge(head, head->next);
}
