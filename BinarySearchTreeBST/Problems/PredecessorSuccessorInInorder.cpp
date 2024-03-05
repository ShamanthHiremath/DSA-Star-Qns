TreeNode* findNode(TreeNode* root, int key, int& PredVal, int &SuccVal) {
    if(root == NULL) {
        return NULL;
    }
    
    if(root->data == key) {
        return root;
    }
    
    if(root->data > key) {
        SuccVal = root->data;
        return findNode(root->left, key, PredVal, SuccVal);
    } else {
        PredVal = root->data;
        return findNode(root->right, key, PredVal, SuccVal);
    }
} 

pair<int, int> predecessorSuccessor(TreeNode *root, int key) {
    if(root == NULL) {
        return {-1, -1};
    }
    
    int PredVal = -1;
    int SuccVal = -1;
    
    //this qn is weird, it wants the possible Pred and Succ Val even if the key is not found
    TreeNode* curr = findNode(root, key, PredVal, SuccVal);

    //if the key is found
    if(curr) {

        TreeNode* inOPred = curr->left;
        while(inOPred) {
            PredVal = inOPred->data;
            inOPred = inOPred->right;
        }

        TreeNode* inOSucc = curr->right;
        while(inOSucc) {
            SuccVal = inOSucc->data;
            inOSucc = inOSucc->left;
        }
    }
    

    return {PredVal, SuccVal};
}