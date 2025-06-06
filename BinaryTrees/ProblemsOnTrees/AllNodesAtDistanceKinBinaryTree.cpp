/*
863. All Nodes Distance K in Binary Tree

https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.

Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.

Example 2:
Input: root = [1], target = 1, k = 3
Output: []
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 class Solution {
    public:
    // find the k bottom nodes from the right subtree
        void findBottomKDistNodes(TreeNode* root, int k,  vector<int>&ans){
            if(!root || k<0){
                return;
            }
            if(k==0){
                ans.push_back(root->val);
                return;
            }
    
            findBottomKDistNodes(root->left, k-1, ans);
            findBottomKDistNodes(root->right, k-1, ans);
    
        }
        int findKDistNodes(TreeNode* root, TreeNode* target, int k,  vector<int>&ans){
            // if null return -1;
            if(!root){
                return -1;
            }
            // if root found, find the kbottom ones 
            if(root == target){
                findBottomKDistNodes(root, k, ans);
                return 0;
            }
    
            // to find the topside/other side k dist nodes,
            //  just apply recursion over the left side to find the target, if found inm left subtree  find the topside/other side k dist nodes,
            int left_dist = findKDistNodes(root->left, target, k, ans);
            if(left_dist != -1){
                // the root's left node is only target, so left_dist + 1 is k
                // , then check if the immediate left node is target if yes, then just add that node and continue
                if(left_dist + 1 == k){
                    ans.push_back(root->val);
                }
                else{
                    // find the k distance nodes in the right subtree, and dist from left to right is 2
                    findBottomKDistNodes(root->right,  k - left_dist - 2, ans);
                }
                // because left is one dist below parent
                return left_dist + 1;
            }
    
    
            // same as of left
    
            int right_dist = findKDistNodes(root->right,  target, k, ans);
            if(right_dist != -1){
                // the root's left node is only target, so right_dist + 1 is k
                if(right_dist + 1 == k){
                    ans.push_back(root->val);
                }
                else{
                    // find the k distance nodes in the left subtree, and dist from left to right is 2
                    findBottomKDistNodes(root->left, k - right_dist - 2, ans);
                }
                // because left is one dist below parent
                return right_dist + 1;
            }
    
            return -1;
        }
        vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
            vector<int>ans;
    
            findKDistNodes(root, target, k, ans);
            return ans;
        }
    };