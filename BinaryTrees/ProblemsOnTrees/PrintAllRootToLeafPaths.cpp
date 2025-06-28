/*
257. Binary Tree Paths

https://leetcode.com/problems/binary-tree-paths/

Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.


Example 1:
Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]

Example 2:
Input: root = [1]
Output: ["1"]
*/


class Solution {
public:
    void preorder(TreeNode* root, string path,  vector<string>&ans){
        if(!root){
            return;
        }
        if(root and !root->left and !root->right){
            path += to_string(root->val);
            ans.push_back(path);
            return;
        }
        path += to_string(root->val) + "->";
        preorder(root->left, path, ans);
        preorder(root->right, path, ans);

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string path = "";
        preorder(root, path, ans);

        return ans;
    }
};