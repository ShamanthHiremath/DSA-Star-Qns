/*
SUM OF LEFT AND RIGHT SUBTREE == ROOT->DATA for all nodes
*/


class Solution
{
    public:
    // int sumoftree(Node* root){
    //     if(root->left==NULL && root->right==NULL){
    //         return root->data;
    //     }
    //     return sumoftree(root->left)+sumoftree(root->right)+root->data;
    // }
    
    pair<bool, int> sumTree(Node* root){
        
        // Base case for NULL node
        if (root == NULL) {
            return {true, 0}; 
        }
        
        if(root->left == NULL && root->right == NULL){
            return {true, root->data};
        }
        
        //recursive call
        pair<bool, int>leftTree=sumTree(root->left);
        pair<bool, int>rightTree=sumTree(root->right);
        
        bool left=leftTree.first;
        bool right=rightTree.first;
        
        //checking condition
        bool check=(root->data == (leftTree.second+rightTree.second));
        
        pair<bool, int> ans;
        
        //sum of that tree
        ans.second=(leftTree.second + rightTree.second)+root->data;
        
        //condition check
        if(left && right && check){
            ans.first=true;
        }
        else{
            ans.first=false;
        }
        return ans;
        
    }
    bool isSumTree(Node* root) {
        if (root == NULL) {
            return true;  // Base case: an empty tree is a Sum Tree
        }
        
        if (root->left == NULL && root->right == NULL) {
            return true;  // Base case: a single node is a Sum Tree
        }
        
        return sumTree(root).first;
    }
};