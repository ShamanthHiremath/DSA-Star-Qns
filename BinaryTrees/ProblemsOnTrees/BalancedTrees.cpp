/*A tree's height is balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree. 
also check for right and left sub-trees
*/



//Faster code
//TIME COMPLEXITY O(n)
class Solution{
    public:
    
    pair<bool,int> balancedFast(Node* root){
        if(root==NULL){
            return {true, 0};
        }
        
        
        pair<bool, int> leftTree=balancedFast(root->left);
        pair<bool, int> rightTree=balancedFast(root->right);
        
        bool left=leftTree.first;
        bool right=rightTree.first;
        bool diff=abs(leftTree.second - rightTree.second)<=1;
        
        pair<bool, int> ans;
        ans.second=max(leftTree.second, rightTree.second)+1;
        
        if(left && right && diff){
            ans.first=true;
        }
        else{
            ans.second=false;
        }
        return ans;
    }
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        if(root==NULL){
            return true;
        }
         return balancedFast(root).first;
    }
};

//works but slow  
//TIME COMPLEXITY O(n^2)

class Solution{
    public:
    
    int height(Node* root) {
        if(root==NULL){
            return 0;
        }
        int leftheight=height(root->left);
        int rightheight=height(root->right);
        // if(leftheight>rightheight){
        //     return leftheight+1;
        // }
        // else{
        //     return rightheight+1;
        // }
        return 1+max(leftheight,rightheight);
    }
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        if(root==NULL){
            return true;
        }
        int leftHeight=height(root->left);
        int rightHeight=height(root->right);
        
        return (abs(leftHeight - rightHeight) <= 1) && isBalanced(root->left) && isBalanced(root->right);
    }
};