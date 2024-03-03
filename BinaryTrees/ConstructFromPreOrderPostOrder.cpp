class Solution {
public:
    Node* buildTreeUtil(vector<int>& preorder, vector<int>& postorder, int& preIndex, int postStart, int postEnd) {
        if (preIndex >= preorder.size() || postStart > postEnd)
            return nullptr;
        
        Node* root = new Node(preorder[preIndex++]);
        
        if (postStart == postEnd)
            return root;
        
        int postIndex = postStart;
        while (postorder[postIndex] != preorder[preIndex]) {
            postIndex++;
        }
        
        root->left = buildTreeUtil(preorder, postorder, preIndex, postStart, postIndex);
        root->right = buildTreeUtil(preorder, postorder, preIndex, postIndex + 1, postEnd - 1);
        
        return root;
    }
    
    Node* buildTree(vector<int>& preorder, vector<int>& postorder) {
        int preIndex = 0;
        int postStart = 0;
        int postEnd = postorder.size() - 1;
        
        return buildTreeUtil(preorder, postorder, preIndex, postStart, postEnd);
    }
};
