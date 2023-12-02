//U CAN STORE THE REVERSED LIST IN A NEW LIST AND COMPARE THE VALUES OF OG LIST TO REV LIST

//OR U CAN BASICALLY TRAVERSE TILL MIDDLE REVERSE THE SECOND HALF AND COMPARE THE VALUES OF FIRST HALF AND REV SECOND HALF

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