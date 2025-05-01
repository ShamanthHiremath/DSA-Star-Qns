/*
653. Two Sum IV - Input is a BST

https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

 
Example 1:
Input: root = [5,3,6,2,4,null,7], k = 9
Output: true

Example 2:
Input: root = [5,3,6,2,4,null,7], k = 28
Output: false
 

*/


class Solution {
public:
    void inorder(TreeNode* root, vector<int>&ans){
        if(!root){
            return ;
        }

        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int>ans;
        inorder(root, ans);

        // 2 sum algo since BST indorder is always sorted

        int i=0, j = ans.size()-1;
        
        while(i<j){
            int sum = ans[i] + ans[j];

            if(sum == k){
                return true;
            }
            else if(sum < k){
                i++;
            }
            else{
                j--;
            }
        }

        return false;

    }
};