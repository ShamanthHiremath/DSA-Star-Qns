/*
61. Rotate List

https://leetcode.com/problems/rotate-list/

Given the head of a linked list, rotate the list to the right by k places.

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Example 2:
Input: head = [0,1,2], k = 4
Output: [2,0,1]
*/


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // the len of the LL is calculated first, and if k exceeds Len, then take a modulo,
        // take the last k%LEN nodes from last, and attach it to the head
        // simple
        if(!head || !head->next){
            return head;
        }

        int len = 0;
        ListNode* temp = head;
        ListNode* lastnode = NULL;
        while(temp){
            lastnode = temp;
            temp = temp->next;
            len++;
        }


        k = k%len;

        int i = 0;
        temp = head;
        while(i<len-k-1){
            temp = temp->next;
            i++;
        }

        lastnode->next = head;
        // cout<<lastnode->val;
        // cout<<temp->val;

        head = temp->next;

        temp->next = NULL;

        return head;

    }
};