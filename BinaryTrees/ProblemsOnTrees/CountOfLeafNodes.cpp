int solve(BinaryTreeNode<int> *root, int count){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        count++;
        return count+solve(root->left, count)+solve(root->right, count);
    }
    else{
        return solve(root->left,count)+solve(root->right, count);
    }
}
int noOfLeafNodes(BinaryTreeNode<int> *root){
    int count=0;
    return solve(root, 0);
}

///OR
void solve(BinaryTreeNode<int> *root, int & count){
    if(root==NULL){
        return;
    }
    solve(root->left, count);
    if(root->left==NULL && root->right==NULL){
        count++;
    }
    solve(root->right, count);
}
int noOfLeafNodes(BinaryTreeNode<int> *root){
    int count=0;
    solve(root, count);
    return count;
}