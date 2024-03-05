
TreeNode* sortedDLLToBST(TreeNode* head) {
    if (head == nullptr)
        return nullptr;
    
    // Find the middle node of the DLL
    TreeNode* slow = head;
    TreeNode* fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Create a new TreeNode with the value of the middle node
    TreeNode* root = new TreeNode(slow->val);

    // If there's only one node in the DLL, return the root
    if (slow == head)
        return root;

    // Recursively construct the left subtree
    slow->prev->next = nullptr; // Break the DLL at the middle node
    root->left = sortedDLLToBST(head);

    // Recursively construct the right subtree
    root->right = sortedDLLToBST(slow->next);

    return root;
}