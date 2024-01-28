//belo code doesnt work because there of runtime error
// void inorder(BinaryTreeNode<int> *root, vector<int> &ans){
//     if(root == nullptr){
//         return;
//     }
//     inorder(root->left, ans);
//     ans.push_back(root->data);
//     inorder(root->right, ans);
// }

// bool validateBST(BinaryTreeNode<int> *root) {
//     if(root == nullptr) {
//         return true; // An empty tree is a valid BST
//     }

//     vector<int> ans;
//     inorder(root, ans);
//     for(int i = 0; i < ans.size() - 1; i++) {
//         if(ans[i] >= ans[i + 1]) {
//             return false;
//         }
//     }
//     return true;
// }


//OPTIMAL SOLN
bool RangeChecker(BinaryTreeNode<int> *root, int minVal, int maxVal){
    if(root==NULL){
        return true;
    }
    //check if the given node data is lesser than its parent node if left child or larger than its parent node if right child 
    if(root->data>=minVal && root->data<=maxVal){
        bool leftside =RangeChecker(root->left, minVal, root->data);
        bool rightside=RangeChecker(root->right, root->data,  maxVal);
        return leftside && rightside;
    }
    else{
    return false;
    }
    
    
}

bool validateBST(BinaryTreeNode<int> *root) {
    return RangeChecker(root, INT_MIN,INT_MAX);
}
