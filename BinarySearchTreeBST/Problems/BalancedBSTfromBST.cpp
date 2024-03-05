void inorder(TreeNode<int>* root, vector<int>&arr){
    if(root==NULL){
        return ;
    }
    inorder(root->left, arr);
    //push elements
    arr.push_back(root->data);
    
    inorder(root->right, arr);
}

TreeNode<int>* inOrderToBST(int s, int e, vector<int> &arr){
    if(s>e){
        return NULL;
    }
    int mid=s+(e-s)/2;
    TreeNode<int>* root= new TreeNode<int>(arr[mid]);
    root->left=inOrderToBST(s, mid-1, arr);
    root->right=inOrderToBST(mid+1, e, arr);

    return root;

}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
    if(root==NULL){
        return NULL;
    }
    vector<int>arr;
    inorder(root, arr);
    TreeNode<int>* newNode=inOrderToBST(0, arr.size()-1, arr);
    return newNode;
}