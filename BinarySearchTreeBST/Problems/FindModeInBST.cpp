/*
501. Find Mode in Binary Search Tree

https://leetcode.com/problems/find-mode-in-binary-search-tree/

Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.

If the tree has more than one mode, return them in any order.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
 
Example 1:
Input: root = [1,null,2,2]
Output: [2]

Example 2:
Input: root = [0]
Output: [0]

*/
class Solution {
    public:
        void solve(TreeNode* root, map<int, int>&mp){
            if(!root){
                return;
            }
    
            mp[root->val]++;
            solve(root->left, mp);
            solve(root->right, mp);
    
        }
        vector<int> findMode(TreeNode* root) {
            map<int, int>mp;
            solve(root, mp);
    
    
            vector<pair<int, int>>freqVec(mp.begin(), mp.end());
            sort(freqVec.begin(), freqVec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
                return a.second > b.second;
            });
            
            vector<int>modes;
            if(!freqVec.empty()){
                int maxFreq = freqVec[0].second;
                for(const auto& pair : freqVec){
                    if(pair.second == maxFreq){
                        modes.push_back(pair.first);
                    }
                    else{
                        break;
                    }
                }
            }
            
            return modes;
        }
    };