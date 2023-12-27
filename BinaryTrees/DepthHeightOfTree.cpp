class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int leftheight=maxDepth(root->left);
        int rightheight=maxDepth(root->right);
        // if(leftheight>rightheight){
        //     return leftheight+1;
        // }
        // else{
        //     return rightheight+1;
        // }
        return 1+max(leftheight,rightheight);
    }
};