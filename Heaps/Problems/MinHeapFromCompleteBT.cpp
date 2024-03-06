
class Solution {
public:
    // Function to perform inorder traversal and store values in an array
    void inorderTraversal(TreeNode* root, vector<int>& inorder) {
        if (root == nullptr)
            return;
        
        inorderTraversal(root->left, inorder);
        inorder.push_back(root->data);
        inorderTraversal(root->right, inorder);
    }

    // Function to perform preorder traversal and populate nodes with values from the array
    void preorderTraversal(TreeNode* root, const vector<int>& inorder, int& index) {
        if (root == nullptr)
            return;

        // Populate current node with value from the array
        root->data = inorder[index++];

        // Traverse left subtree
        preorderTraversal(root->left, inorder, index);

        // Traverse right subtree
        preorderTraversal(root->right, inorder, index);
    }

    // Function to convert a complete binary tree to a min heap
    void convertToMinHeap(TreeNode* root) {
        // Step 1: Perform inorder traversal and store values in an array
        vector<int> inorder;
        inorderTraversal(root, inorder);

        // Step 2: Perform preorder traversal and populate nodes with values from the array
        int index = 0;
        preorderTraversal(root, inorder, index);
    }
};