class Solution
{
    public:
    void searchAtDepth(struct Node* root, int k, int i, vector<int>&ans){
        if(root!=NULL && i==k){
            ans.push_back(root->data);
            return;
        }
        if(root==NULL){
            return;
        }
        if(root->left){
            searchAtDepth(root->left, k, i+1, ans);
        }
        if(root->right){
            searchAtDepth(root->right, k, i+1, ans);
        }
        
    }
    
    vector<int> Kdistance(struct Node *root, int k)
    {
        vector<int>ans;
        searchAtDepth(root, k, 0, ans);
        return ans;
    }
};