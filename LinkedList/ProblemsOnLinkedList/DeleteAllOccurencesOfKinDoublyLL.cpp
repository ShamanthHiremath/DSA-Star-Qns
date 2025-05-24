/*
Delete all occurrences of a given key in a doubly linked list

https://www.naukri.com/code360/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list_8160461?leftPanelTabValue=PROBLEM

Problem statement
A doubly-linked list is a data structure that consists of sequentially linked nodes, and the nodes have reference to both the previous and the next nodes in the sequence of nodes.

You’re given a doubly-linked list and a key 'k'.

Delete all the nodes having data equal to ‘k’.


Example:
Input: Linked List: 10 <-> 4 <-> 10 <-> 3 <-> 5 <-> 20 <-> 10 and ‘k’ = 10
Output: Modified Linked List: 4 <-> 3 <-> 5 <-> 20
Explanation: All the nodes having ‘data’ = 10 are removed from the linked list.
Detailed explanation ( Input/output format, Notes, Images )

Sample Input 1:
7
10 4 10 3 5 20 10
10

Sample Output 1:
4 3 5 20

Explanation Of Sample Input 1:
All the nodes having ‘data’ = 10 are removed from the linked list.


Sample Input 2:
7
10 4 10 3 5 20 10
30

Sample Output 2:
10 4 10 3 5 20 10


Explanation Of Sample Input 2:
The linked list does not have any node with ‘data’ = 30. So the linked list is unchanged.


Expected Time Complexity:
The expected time complexity is O(‘n’).
*/


Node * deleteAllOccurrences(Node* head, int k) {
    if(head == NULL){
        return NULL;
    }

    while(head && head->data == k){
        Node* temp = head;
        head = head->next;
        delete(temp);
    }
    // Write your code here
    Node* prev = NULL;
    Node* curr = head;

    while(curr){
        Node* forw = curr->next;
        if(curr->data == k){
            Node* delnode = curr;
            if(prev){
                prev->next = forw;
            }
            if(forw){
                forw->prev = prev;
            }
            delete(delnode);
            curr = forw;
            
            continue;
        }

        prev = curr;
        curr = forw;

    }


    return head;
    
}