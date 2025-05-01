/*
230. Kth Smallest Element in a BST

https://leetcode.com/problems/kth-smallest-element-in-a-bst/

Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.


Example 1:
Input: root = [3,1,4,null,2], k = 1
Output: 1

Example 2:
Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
*/

class Solution {
public:
    void inorder(TreeNode* root, int& ans, int& cnt, int k){
        if(!root || cnt>=k){
            return ;
        }

        inorder(root->left, ans, cnt, k);
        if(cnt < k){
            cnt++;
            if(cnt == k){
                ans = root->val;
                return;
            }
            inorder(root->right, ans, cnt, k);
        }
    }

    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        int ans = 0;
        inorder(root, ans, cnt, k);

        return ans;

    }
};