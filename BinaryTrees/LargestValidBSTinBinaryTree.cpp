//Class to hold the information of each node simultaneously
class info{
    public:
       int maxi;
       int mini;
       int size;
       bool isBST;
};

info solve(TreeNode* root, int& ans){
    //base case
    if(root==NULL){
        return {INT_MIN, INT_MAX, 0, true};
    }

    info left=solve(root->left, ans);
    info right=solve(root->right, ans);

    info currnode;

    currnode.maxi= max(root->data, right.maxi);
    currnode.mini= min(root->data, left.mini);
    currnode.size= left.size + right.size + 1;

    if(left.isBST && right.isBST && (left.maxi<root->data && root->data<right.mini) ){
        currnode.isBST=true;
    }
    else{
        currnode.isBST=false;
    }

    //if is BST
    if(currnode.isBST){
        ans=max(ans, currnode.size);
    }
    return currnode;
}

int largestBST(TreeNode * root){
    int ans=0;
    info xyz =solve(root, ans);
    return ans;  
}