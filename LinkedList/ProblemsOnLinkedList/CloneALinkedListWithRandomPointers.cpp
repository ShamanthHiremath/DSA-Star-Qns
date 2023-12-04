class Node {
public:
    int data;
    Node* next;
    Node* arb;  // Arbitrary pointer
    Node(int val) : data(val), next(nullptr), arb(nullptr) {}
};
//U can use a map<Node* ,Node*> randomPtrStore with key as the curr node and value as Arbitrary node
//Clone the List and traverse map and link random nodes
// something like this randomPtrStore[temp]
//SPACE COMP is O(n)
//TIME COMP 0(n)





//SPACE COMPL is O(1)
//TIME COMP 0(n)
class Solution
{
    public:
    Node *copyList(Node *head)
    {
        if(head==NULL || head->next==NULL){
            return (new Node(head->data));
        }
        //dummmy node for ans
        //Step1 
        //clone original singly linkedlist with data as in OG list with only next ptrs
        Node* CL=new Node(0);
        Node* clonehead=CL;
        Node* adddata=head;
        while(adddata!=NULL){
            Node* temp=new Node(adddata->data);
            CL->next=temp;
            CL=CL->next;
            adddata=adddata->next;
        }
        CL=clonehead->next;
        //Step2 
        //original list to clone in zig zag 
        //that is 1st OG node to 1st CL node and 1st CL node to 2nd OG node and 2nd OG node to 2nd CL node and so on untill NULL
        Node* OG=head;
        while(OG!=NULL && CL!=NULL){
            Node* forwOG=OG->next;
            OG->next=CL;
            Node* forwCL=CL->next;
            CL->next=forwOG;
            OG=forwOG;
            CL=forwCL;
        }
        //Step 3
        //Link Arbitary Pointers of CL by tracking OG List arb points using the
        //criss cross link made in step 2
        Node* temp=head;
        while(temp!=NULL){
            if(temp->arb!=NULL){
                temp->next->arb=temp->arb->next;
            }
            temp=temp->next->next;
        }
        //Step 4
        //Revert/Undo the changes made in step 2
        OG=head;
        CL=head->next;
        while (OG != nullptr) {
            OG->next = CL->next;
            OG = OG->next;
            if (OG != nullptr) {
                CL->next = OG->next;
                CL = CL->next;
            }
        }
        return clonehead->next;
    }

};