class Solution {
public:
    void solve(TreeNode* root, int &count){
        if(root==NULL){
            return ;
        }
        count++;
        solve(root->left, count);
        solve(root->right, count);
    }
    int countNodes(TreeNode* root) {
        int count=0;
        solve(root, count);
        return count;
    }
};