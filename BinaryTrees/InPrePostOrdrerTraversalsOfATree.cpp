// In TRAVERSALs focus on printing the N node 
//Apply recursions for LEFT and RIGHT node
//But print the Current Node
//Ex: NLR first N so print it, recursions for l and r
// Ex: LNR first recursion, print N and recursion for R 

// LNR is In Order Traversal
void inOrderTraversal(TreeNode* root){
    if(root==NULL){
        return ;
    }
    //got to the leftmost node
    inOrderTraversal(root->left);
    //print the leftmost node
    cout<<root->data<<" ";
    //check LNR condition
    inOrderTraversal(root->right);
}

//NLR is Pre Order Traversal
void preOrderTraversal(TreeNode* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);

}

//LRN is Post Order Tarversal
void postOrderTraversal(TreeNode* root){
    if(root==NULL){
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<< " ";
} 
//in main function
/*
    cout<<"\nPRINTING BINARY TREE IN ORDERS"<<endl;
    cout<<"The InOrder Traversal is: ";
    inOrderTraversal(root);
    cout<<endl;
    cout<<"The PreOrder Traversal is: ";
    preOrderTraversal(root);
    cout<<endl;
    cout<<"The PostOrder Traversal is: ";
    postOrderTraversal(root);
    cout<<endl;

*/