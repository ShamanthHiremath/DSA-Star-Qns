/*
235. Lowest Common Ancestor of a Binary Search Tree

https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”


Example 1:
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.

Example 2:
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

Example 3:
Input: root = [2,1], p = 2, q = 1
Output: 2
 
*/

 class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if(root==NULL){
                return NULL;
            }
            // If either of the nodes is found, return the node itself
            if(root==p || root==q){
                return root;
            }
            
            TreeNode* left=lowestCommonAncestor(root->left, p, q);
            TreeNode* right=lowestCommonAncestor(root->right, p, q);
            
            //answer found
            // If both nodes lie in the left and right subtrees,
            // then the current node is the LCA
            if(left!=NULL && right!=NULL){
                return root;
            }
            // Otherwise, return the non-null LCA (if found) from left or right subtree
            else if(left!=NULL && right==NULL){
                return left;
            }
            else {
                return right;
            }
        }
    };