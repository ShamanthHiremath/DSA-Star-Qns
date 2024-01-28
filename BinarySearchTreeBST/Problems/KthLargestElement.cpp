class Solution
{
    public:
    void solveUsingReverseInorderTrav(Node* root, int &i, int k, int &ans){
    if(root==NULL){
        return ;
    }
    //Traverse right node first R
    solveUsingReverseInorderTrav(root->right, i, k, ans);
    i++;
    //Node N
    if(i==k){
        ans=root->data;
        return ;
    }
    //Traverse left node L
    solveUsingReverseInorderTrav(root->left, i, k, ans);
}

    int kthLargest(Node *root, int K)
    {
        int ans = -1;
    int i = 0;
    ///DO REVERSE INORDER
    solveUsingReverseInorderTrav(root, i, K, ans);
    return ans;
    }
};