void inorder(TreeNode<int>* root, vector<int> &arr) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

TreeNode<int>* flatten(TreeNode<int>* root) {
    if (root == nullptr) {
        return nullptr;
    }
    
    vector<int> arr;
    inorder(root, arr);
    
    TreeNode<int>* newRoot = new TreeNode<int>(arr[0]);
    TreeNode<int>* curr= newRoot;
    for (int i = 1; i < arr.size(); i++) {
        TreeNode<int>* newNode = new TreeNode<int>(arr[i]);
        curr->right = newNode;
        curr = newNode;
    }
    return newRoot;
}