/*
148. Sort List

https://leetcode.com/problems/sort-list/description/

Given the head of a linked list, return the list after sorting it in ascending order.


Example 1:
Input: head = [4,2,1,3]
Output: [1,2,3,4]

Example 2:
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

Example 3:
Input: head = []
Output: []
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
        ListNode* mergedList(ListNode* l1, ListNode* l2){
            ListNode* dummy = new ListNode(0);
            ListNode* sorted = dummy;
    
            while(l1 && l2){
                if(l1->val <= l2->val){
                    sorted->next = l1;
                    
                    l1 = l1->next;
                }
                else{
                    sorted->next = l2;
                    
                    l2 = l2->next;
                }
                sorted = sorted->next;
            }
    
            if(l1){
                sorted->next = l1;
            }
            if(l2){
                sorted->next = l2;
            }
    
    
            return dummy->next;
    
    
        }
        ListNode* sortList(ListNode* head) {
            if(!head or !head->next){
                return head;
            }
    
            ListNode* prev = NULL;
            ListNode* slow = head;
            ListNode* fast = head;
    
            while(fast !=NULL and fast->next != NULL){
                prev = slow;
                slow = slow->next;
                fast = fast->next->next;
            }
            prev->next = NULL;
    
            ListNode* l1 = sortList(head);
            ListNode* l2 = sortList(slow);
    
    
            return mergedList(l1, l2);
    
        }
    };