// Input 1 :
// 1 4 5 2 -1
// Output 1 :
// 1 2 4 5
// Input 2 :
// 10 9 8 7 6 5 4 -1
// Output 2 :
// 4 5 6 7 8 9 10

//Using extra space 
//SIMPLE AND EASY TO UNDERSTAND


node* findMiddle(node *head) {
    node* shortjump=head;
    node* longjump=head->next;
    while (longjump != NULL && longjump->next!=NULL) {
      shortjump = shortjump->next;
      longjump = longjump->next->next;
    }
    return shortjump;
}

node* MergesortTwoLists(node* left, node* right)
{
    if(left==NULL){
        return right;
    }   
    if(right==NULL){
        return left;
    }
    //dummy node to connect sorted lists
    node* ans=new node(0);
    node* temp=ans;
    while(left!=NULL && right!=NULL){
        if(left->data<right->data){
            temp->next=left;
            temp=left;
            left=left->next;
        }
        else{
            temp->next=right;
            temp=right;
            right=right->next;
        }
    }
    while(left!=NULL){
        temp->next=left;
        temp=left;
        left=left->next;
    }
    while(right!=NULL){
        temp->next=right;
        temp=right;
        right=right->next;
    }
    return (ans->next);
}


node* mergeSort(node *head) {
    if(head==NULL || head->next==NULL){
        return head;
    }
    //find middle node
    node* mid=findMiddle(head);
    node* left=head;
    node* right=mid->next;
    mid->next=NULL;
    //recursive calls
    left=mergeSort(left);
    right=mergeSort(right);
    //mergesorted lists
    node* Result=MergesortTwoLists(left,right);
    return Result;
}

//A bit fussy and tricky but works
node* findMiddle(node* head) {
    node* shortjump = head;
    node* longjump = head->next;
    while (longjump != NULL && longjump->next != NULL) {
        shortjump = shortjump->next;
        longjump = longjump->next->next;
    }
    return shortjump;
}

node* sort(node* first, node* second) {
    if (first->next == NULL) {
        first->next = second;
        return first;
    }
    node* curr1 = first;
    node* forward1 = first->next;
    node* curr2 = second;
    node* forward2 = second->next;
    while (forward1 != NULL && curr2 != NULL) {
        if ((curr1->data <= curr2->data) && (curr2->data <= forward1->data)) {
            curr1->next = curr2;
            forward2 = curr2->next;
            curr2->next = forward1;
            curr1 = curr2;
            curr2 = forward2;
        } else {
            curr1 = forward1;
            forward1 = forward1->next;
            if (forward1 == NULL) {
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;
}

node* sortTwoLists(node* first, node* second) {
    if (first == NULL) {
        return second;
    }
    if (second == NULL) {
        return first;
    }
    if (first->data <= second->data) {
        return sort(first, second); // Return the smaller of the two nodes
    } else {
        return sort(second, first); // Return the smaller of the two nodes
    }
}

node* mergeSort(node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    node* mid = findMiddle(head);
    node* left = head;
    node* right = mid->next;
    mid->next = NULL;
    // recursive calls
    left = mergeSort(left);
    right = mergeSort(right);
    // merge sorted lists
    node* Result = sortTwoLists(left, right);
    return Result;
}