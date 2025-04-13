/*
114. Flatten Binary Tree to Linked List

https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

Given the root of a binary tree, flatten the tree into a "linked list":

REFER IMAGE

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
 
Example 1:
REFER IMAGE
Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]

Example 2:
Input: root = []
Output: []

Example 3:
Input: root = [0]
Output: [0]
 
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
        // NLR
        TreeNode* preOrder(TreeNode* root){
            if(!root){
                return NULL;
            }
    
            if(!root->right && !root->left){
                return root;
            }
    
            TreeNode* leftTreeFlatten =  preOrder(root->left);
            TreeNode* rightTreeFlatten = preOrder(root->right);
    
            // TreeNode* rootRightchild = root->right;
            if(leftTreeFlatten){
                // attach the flattened tree's right from leftside to the existing right of the root
                leftTreeFlatten->right = root->right;
                // attach the right of the root to the root's left, since it starts there
                root->right = root->left;
                // root of left should be null
                root->left = NULL;
                // leftTreeFlatten->left = NULL;  
    
            }
            return rightTreeFlatten? rightTreeFlatten : leftTreeFlatten;
        }
    
        void MorrisTraversal(TreeNode* root){
            if(!root){
                return ;
            }
            TreeNode* currNode = root;
    
            while(currNode){
                // find the rightmost node in the Curr's left subtree
                if(currNode->left){
                    TreeNode* rightMostNodeInCurrLeft = currNode->left;
                    while(rightMostNodeInCurrLeft->right){
                        rightMostNodeInCurrLeft = rightMostNodeInCurrLeft->right;
                    }
    
                    // now attach the rightmost node to the right side of root/curr
                    rightMostNodeInCurrLeft->right = currNode->right;
                    // now curr->right to curr->left 
                    currNode->right = currNode->left;
                    // now cyur->left = NULL
                    currNode->left = NULL;
                }
                currNode = currNode->right;
                
            }
        }
    
        void flatten(TreeNode* root) {
            // preOrder(root);
            MorrisTraversal(root);
        }
    };