class Solution
{
    public:
    struct Node* reverselist(Node* &head){
    //base case
    if(head==NULL || head->next==NULL){
        return head;
    }
    struct Node* smalllist= reverselist(head->next);
    head->next->next=head;
    head->next=NULL;
    return smalllist;
}
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        struct Node* ans= new Node(0);
        struct Node* storeanshead=ans;
        first=reverselist(first);
        second=reverselist(second);
        int carry=0;
        while(first!=NULL || second!=NULL || carry==1){
            int sum=0;
            if(first!=NULL){
                sum+=first->data;
                first=first->next;
            }
            if(second!=NULL){
                sum+=second->data;
                second=second->next;
            }
            sum+=carry;
            carry=sum/10;
            struct Node* temp =new Node(sum%10);
            ans->next=temp;
            ans=ans->next;
        }
        ans=reverselist(storeanshead->next);
        return ans;
    }
};