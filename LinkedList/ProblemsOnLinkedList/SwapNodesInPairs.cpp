/*
24. Swap Nodes in Pairs

https://leetcode.com/problems/swap-nodes-in-pairs/

Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

Example 1:
Input: head = [1,2,3,4]
Output: [2,1,4,3]

Example 2:
Input: head = []
Output: []

Example 3:
Input: head = [1]
Output: [1]

Example 4:
Input: head = [1,2,3]
Output: [2,1,3]
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
    ListNode* swapPairs(ListNode* head) {
        if(!head){
            return head;
        }
        if(!head->next){
            return head;
        }

        ListNode* curr = head;
        head = curr->next;
        while(curr->next){
            ListNode* forw = curr->next;
            ListNode* nextCurr = forw->next;
            if(nextCurr and nextCurr->next){
                curr->next = nextCurr->next;
            }
            else{
                curr->next = nextCurr;
            }
            forw->next= curr;
            curr = nextCurr;
            if(!curr) break;
        }

        return head;
    }
};


/*

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution(object):
    def swapPairs(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        if head is None:
            return None
        if head.next is None:
            return head

        curr = head
        head = head.next

        while curr.next is not None:
            forw = curr.next
            nextCurr = forw.next
            if nextCurr is not None and nextCurr.next is not None:
                curr.next = nextCurr.next
            else:
                curr.next = nextCurr
            forw.next = curr
            curr = nextCurr
            if(curr is None):
                break

        return head

        
        
*/