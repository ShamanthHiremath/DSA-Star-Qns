/*
98. Validate Binary Search Tree

https://leetcode.com/problems/validate-binary-search-tree/

Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 
Example 1:
Input: root = [2,1,3]
Output: true

Example 2:
Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
*/

//below code doesnt work because there of runtime error
// void inorder(BinaryTreeNode<int> *root, vector<int> &ans){
//     if(root == nullptr){
//         return;
//     }
//     inorder(root->left, ans);
//     ans.push_back(root->data);
//     inorder(root->right, ans);
// }

// bool validateBST(BinaryTreeNode<int> *root) {
//     if(root == nullptr) {
//         return true; // An empty tree is a valid BST
//     }

//     vector<int> ans;
//     inorder(root, ans);
//     for(int i = 0; i < ans.size() - 1; i++) {
//         if(ans[i] >= ans[i + 1]) {
//             return false;
//         }
//     }
//     return true;
// }


//OPTIMAL SOLN

class Solution {
    public:
        bool solveInRanges(TreeNode* root, long maxVal, long minVal){
            if(!root){
                return true;
            }
    
            if(root->val <= minVal || root->val >= maxVal){
                return false;
            }
    
            return solveInRanges(root->left, root->val, minVal) and solveInRanges(root->right, maxVal, root->val);
        }
        bool isValidBST(TreeNode* root) {
            return solveInRanges(root, LONG_MAX, LONG_MIN);
        }
    };
    
    
    /*
    THIS SOLUTION DOESNT WORK BECAUSE IF THERE'S A TREE LIKE THIS:
    
       5
    4    6
       3    7
    
    class Solution {
    public:
        bool isValidBST(TreeNode* root) {
            if(!root){
                return true;
            }
    
            bool check = true;
    
            if(root->left){
                check = root->val > root->left->val;
            }
            if(root->right){
                check = check and root->val < root->right->val;
            }
    
            bool left = isValidBST(root->left);
            bool right = isValidBST(root->right);
    
            return left and right and check;
    
        }
    };
    */
