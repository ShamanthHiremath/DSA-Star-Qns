/*
1008. Construct Binary Search Tree from Preorder Traversal

https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

Example 1:


Input: preorder = [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]
Example 2:

Input: preorder = [1,3]
Output: [1,null,3]
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
    TreeNode* solve(int & i, int low, int up, vector<int>& preorder){
        if(i >= preorder.size()){
            return NULL;
        }
        if(low >= preorder[i] || up <= preorder[i]){
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[i]);
        i++;
        root->left = solve(i, low, root->val, preorder);
        root->right = solve(i, root->val, up, preorder);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        int lower_bound = INT_MIN;
        int upper_bound = INT_MAX;


        return solve(i, lower_bound, upper_bound, preorder);
    }
};