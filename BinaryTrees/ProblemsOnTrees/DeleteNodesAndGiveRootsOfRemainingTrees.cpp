/*
1110. Delete Nodes And Return Forest

https://leetcode.com/problems/delete-nodes-and-return-forest/

Given the root of a binary tree, each node in the tree has a distinct value.
After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).
Return the roots of the trees in the remaining forest. You may return the result in any order.

Example 1:

        1
      /   \
    2     3
   / \   / \
  4   5 6   7

Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
Output: [[1,2,null,4],[6],[7]]

Example 2:

Input: root = [1,2,4,null,3], to_delete = [3]
Output: [[1,2,4]]
*/




// easy deleting of nodes using postorder dfs
class Solution {
private:
    void dfsdelete(TreeNode*& root, unordered_map<int, bool>&mp, vector<TreeNode*>&ans){
        if(root==NULL){
            return;
        }
        dfsdelete(root->left, mp, ans);
        dfsdelete(root->right, mp, ans);
        if(mp[root->val]){
            if(root->left){
                ans.push_back(root->left);
            }
            if(root->right){
                ans.push_back(root->right);
            }
            root = NULL;
            delete root;
        }
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*>ans;
        unordered_map<int, bool>mp;
        for(int node: to_delete){
            mp[node] = true;
        }
        dfsdelete(root, mp, ans);
        if(root){
            ans.push_back(root);
        }

        return ans;
    }
};


// hard one but the right approach is to use postorder traversal and then check if the node is to be deleted or not
class Solution {
private:
    bool del_node[1001] = {};
    void dfs(TreeNode* &root, bool rootflag, vector<TreeNode*>&ans){
        if(root == NULL){
            return;
        }
        dfs(root->left, del_node[root->val], ans);
        dfs(root->right, del_node[root->val], ans);
        if(!del_node[root->val] && rootflag){
            ans.push_back(root);
        }
        if(del_node[root->val]){
            root = NULL;
        }
        
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*>ans;
        for(int node: to_delete){
            del_node[node] = true;
        }
        dfs(root, true, ans);
        for(TreeNode* temp: ans){
            cout<<temp->val;
        }
        return ans;
    }
};