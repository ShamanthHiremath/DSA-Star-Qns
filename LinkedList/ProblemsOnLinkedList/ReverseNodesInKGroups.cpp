/*
25. Reverse Nodes in k-Group

https://leetcode.com/problems/reverse-nodes-in-k-group/

Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Example 2:
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
*/
class Solution{
public:
    ListNode* reverseKGroup(ListNode* head, int k){
        if(!head || k == 1) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prevGroupEnd = dummy;
        
        while(true){
            // Check if there are at least k nodes to reverse
            ListNode* temp = prevGroupEnd;
            for(int i = 0; i < k && temp; i++){
                temp = temp->next;
            }
            if(!temp) break; // Not enough nodes left
            
            // Reverse k nodes
            ListNode* prev = nullptr, *curr = prevGroupEnd->next;
            for(int i = 0; i < k; i++){
                ListNode* forward = curr->next;
                curr->next = prev;
                prev = curr;
                curr = forward;
            }
            
            // Connect reversed segment
            ListNode* nextGroupStart = prevGroupEnd->next;
            prevGroupEnd->next = prev;
            nextGroupStart->next = curr;
            prevGroupEnd = nextGroupStart;
        }
        
        return dummy->next;
    }
};