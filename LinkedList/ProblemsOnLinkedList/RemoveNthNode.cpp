/*
19. Remove Nth Node From End of List

https://leetcode.com/problems/remove-nth-node-from-end-of-list/

Given the head of a linked list, remove the nth node from the end of the list and return its head.


Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            if(head == NULL){
                return head;
            }
    
            // If n equals the length of the list, fast will be nullptr after the initial loop (for (int i = 0; i < n; i++) fast = fast->next;), and fast->next will cause a segmentation fault.
            ListNode* dummy = new ListNode(0, head);
            ListNode* slow = dummy;
            ListNode* fast = dummy;
    
            // create a window of n size between slow and fast
    
            for(int i=0; i<n; i++){
                fast = fast->next;
            }
    
            // move the window with both slow and fast
            while(fast->next){
                slow = slow->next;
                fast = fast->next;
            }
    
            slow->next = slow->next->next;
    
            return dummy->next;
        }
    };