/*
Add 1 to a Linked List Number

https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

You are given a linked list where each element in the list is a node and have an integer data. You need to add 1 to the number formed by concatinating all the list node numbers together and return the head of the modified linked list. 

Note: The head represents the first element of the given array.

Examples :

Input: LinkedList: 4->5->6
Output: 457
Explanation: 4->5->6 represents 456 and when 1 is added it becomes 457. 

Input: LinkedList: 1->2->3
Output: 124
Explanation:  1->2->3 represents 123 and when 1 is added it becomes 124. 

*/
class Solution {
  public:
    int solve(Node* temp){
        // go to the end 
        if(!temp->next){
            int carry = 0;
            temp->data += 1;
            if(temp->data == 10){
                temp->data = 0;
                carry = 1;
            }
    
            return carry; 
        }
    
        temp->data += solve(temp->next);
        int carry = 0;
        if(temp->data == 10){
            temp->data = 0;
            carry = 1;
        }
    
        return carry; 
    }
    
    Node* addOne(Node* head) {
        // Your Code here
        
        int carry = solve(head);
        if(carry){
            Node* newHead = new Node(1);
            newHead->next = head;
            return newHead;
        }
    
        return head;
    }
};