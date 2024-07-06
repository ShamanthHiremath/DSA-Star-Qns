class Solution {
  public:
    void solve(struct Node *root, int target, vector<int>&ans, bool& found){
        if(root==NULL){
            return;
        }
        if(root->data == target){
            found = true;
            return;
        }
        solve(root->left, target, ans, found);
        if(found){
            ans.push_back(root->data);
            return ;
        }
        solve(root->right, target, ans, found);
        if(found){
            ans.push_back(root->data);
            return;
        }
        
    }
  
    // Function should return all the ancestor of the target node
    vector<int> Ancestors(struct Node *root, int target) {
        // Code here
        vector<int>ans;
        bool found = false;
        solve(root, target, ans, found);
        return ans;
    }
};