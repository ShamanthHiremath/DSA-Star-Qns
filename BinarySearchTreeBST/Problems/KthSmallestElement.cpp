void solveUsingInorderTrav(BinaryTreeNode<int>* root, int &i, int k, int &ans){
    if(root==NULL){
        return ;
    }
    solveUsingInorderTrav(root->left, i, k, ans);
    i++;
    if(i==k){
        ans=root->data;
        return ;
    }
    solveUsingInorderTrav(root->right, i, k, ans);
}

int kthSmallest(BinaryTreeNode<int>* root, int k) {
    int ans = -1;
    int i = 0;
    solveUsingInorderTrav(root, i, k, ans);
    return ans;
}