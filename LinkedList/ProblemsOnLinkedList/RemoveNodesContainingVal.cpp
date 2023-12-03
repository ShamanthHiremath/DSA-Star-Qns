class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        //for empty list
        if(head==NULL){
            return head;
        }
        //skip nodes with val==val and increment head
        while(head!=nullptr && head->val==val){
            head = head->next;
        }
        //for normal removal cases
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode* forward=curr->next;
            if(curr->val==val){
                prev->next=forward;
                curr=forward;
            }
            else{
                prev=curr;
                curr=curr->next;
            }
        }
        return head;  
    }
};