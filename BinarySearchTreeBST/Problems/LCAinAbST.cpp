TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{
    if(root==NULL){
        return NULL;
    }
    // If either of the nodes is found, return the node itself
    if(root==P || root==Q){
        return root;
    }
    
    TreeNode* left=LCAinaBST(root->left, P, Q);
    TreeNode* right=LCAinaBST(root->right, P, Q);
    
    //answer found
    // If both nodes lie in the left and right subtrees,
    // then the current node is the LCA
    if(left!=NULL && right!=NULL){
        return root;
    }
     // Otherwise, return the non-null LCA (if found) from left or right subtree
    else if(left!=NULL && right==NULL){
        return left;
    } else {
        return right;
    }
}