/*
113. Path Sum II

https://leetcode.com/problems/path-sum-ii/

Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

 

Example 1:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22

Example 2:
Input: root = [1,2,3], targetSum = 5
Output: []

Example 3:
Input: root = [1,2], targetSum = 0
Output: []
*/

class Solution {
public:
    void dfs(TreeNode* root, int sum, vector<int>& temp, vector<vector<int>>& ans, int targetSum) {
        if(!root){
            return;
        }

        sum += root->val;
        temp.push_back(root->val);

        if(!root->left && !root->right && sum == targetSum){
            ans.push_back(temp);
        }
        else{
            dfs(root->left, sum, temp, ans, targetSum);
            dfs(root->right, sum, temp, ans, targetSum);
        }

        temp.pop_back(); // backtracking
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        // map<int, int>visited;
        // dfs(root, )
        vector<int>temp;
        dfs(root, 0, temp, ans, targetSum);
        return ans;
    }
};


/* OOORRRRRR  */


class Solution {
public:
    void preOrder(TreeNode* root, int sum, vector<int>temp, vector<vector<int>>&ans, int targetSum){
        if(!root){
            return ;
        }
        sum = root->val + sum;
        temp.push_back(root->val);
        if(!root->left && !root->right && sum == targetSum){
            ans.push_back(temp);
            return;
        }
        preOrder(root->left, sum, temp, ans, targetSum);
        preOrder(root->right, sum, temp, ans, targetSum);
        temp.pop_back();


    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        // map<int, int>visited;
        // dfs(root, )
        vector<int>temp;
        preOrder(root, 0, temp, ans, targetSum);
        return ans;
    }
};