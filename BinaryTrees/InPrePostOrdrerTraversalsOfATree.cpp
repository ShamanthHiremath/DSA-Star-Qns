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

void LevelOrderTraversal(TreeNode* root){
    if(root==NULL){
        return;
    }

    int height=getHeight(root);
    for(int i=1; i<=height; ++i){
        //print given nodes at current level
        printGivenLevel(root, i);
        cout<<endl;
    }
}

void QLevelOrderTraversal(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        TreeNode* curr=q.front();
        q.pop();
        if(curr==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<curr->data<<" ";
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
    }
}
//in main function
/*
    cout<<"\nPRINTING BINARY TREE IN ORDERS"<<endl;
    QLevelOrderTraversal(root);
    cout<<"Height of the given tree: "<<getHeight(root)<<endl;
    LevelOrderTraversal(root);
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