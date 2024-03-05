void createDLLfromTree(TreeNode* root, TreeNode*& head) {
    if (root == nullptr) {
        return;
    }

    createDLLfromTree(root->right, head);

    root->right = head;

    if (head != nullptr) {
        head->left = root;
    }
    head = root;

    createDLLfromTree(root->left, head);
}

