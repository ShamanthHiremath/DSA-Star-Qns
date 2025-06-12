//U CAN STORE THE REVERSED LIST IN A NEW LIST AND COMPARE THE VALUES OF OG LIST TO REV LIST

//OR U CAN BASICALLY TRAVERSE TILL MIDDLE REVERSE THE SECOND HALF AND COMPARE THE VALUES OF FIRST HALF AND REV SECOND HALF

/*
234. Palindrome Linked List

https://leetcode.com/problems/palindrome-linked-list/

Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

Example 1:
Input: head = [1,2,2,1]
Output: true

Example 2:
Input: head = [1,2]
Output: false
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
    ListNode* reverse(ListNode* &head){
        //base case
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode*smalllist= reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return smalllist;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* rev = reverse(slow);

        ListNode* l1 = head;
        while(l1 && rev){
            if(l1->val != rev->val){
                return false;
            }
            l1= l1->next;
            rev= rev->next;
        }

        return true;
    }
};

class Solution{
  public:
  Node* reverse(Node* &head){
    //base case
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node*smalllist= reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return smalllist;
}
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        if(head->next==NULL)return true;
        if(head==NULL)return false;
        
            Node* temp=head;
            int count=1;
            //cal length
            while(temp!=NULL){
                temp=temp->next;
                count++;
            }
            //traverse till middle
            temp=head;
            Node*prev=NULL;
            for(int i=1;i<=count/2;i++){
                prev=temp;
                temp=temp->next;
            }
            //found middle element
            Node* mid=temp;
            //rev second half
            mid=reverse(mid);
            // equate first half to null
            prev->next=NULL;
            //temp back to first half head
            temp=head;
            //compare first half and second half
            while(temp!=NULL&&mid!=NULL){
                if(temp->data!=mid->data){
                    return false;
                }
                temp=temp->next;
                mid=mid->next;
            }
            return true;
    }
};