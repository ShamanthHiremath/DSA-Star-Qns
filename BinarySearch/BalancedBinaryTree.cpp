/*
110. Balanced Binary Tree

https://leetcode.com/problems/balanced-binary-tree/

Given a binary tree, determine if it is height-balanced.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: true

Example 2:
Input: root = [1,2,2,3,3,null,null,4,4]
Output: false

Example 3:
Input: root = []
Output: true
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
        int height(TreeNode* root){
            if(!root){
                return 0;
            }
    
            return max(height(root->left), height(root->right)) + 1;
        }
        bool isBalanced(TreeNode* root) {
            if(!root){
                return true;
            }
    
            int leftHeight = height(root->left);
            int rightHeight = height(root->right);
            if(abs(leftHeight - rightHeight) > 1){
                return false;
            }
            bool leftTree = isBalanced(root->left);
            bool rightTree = isBalanced(root->right);
    
            return leftTree && rightTree;
        }
    };