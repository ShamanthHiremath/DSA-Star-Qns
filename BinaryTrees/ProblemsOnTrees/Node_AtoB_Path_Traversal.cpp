/*
2096. Step-By-Step Directions From a Binary Tree Node to Another

https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/

You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. You are also given an integer startValue representing the value of the start node s, and a different integer destValue representing the value of the destination node t.

Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path as a string consisting of only the uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific direction:

'L' means to go from a node to its left child node.
'R' means to go from a node to its right child node.
'U' means to go from a node to its parent node.
Return the step-by-step directions of the shortest path from node s to node t.
*/
class Solution {
    public:
    bool solve(TreeNode* root, int val, string &ans){
        if(root == NULL ){
            return false;
        }
        if(root->val == val){
            return true;
        }
        bool left = solve(root->left, val, ans);
        if(left){
            ans.push_back('L');
            cout<<root->val;
        }
        bool right = solve(root->right, val, ans);
        if(right){
            ans.push_back('R');
            cout<<root->val;

        }
        return left || right;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string startans;
        solve(root, startValue, startans);
        
        string destans;
        solve(root, destValue, destans);
        // reverse(startans.begin(), startans.end());
        // reverse(destans.begin(), destans.end());
        int i = startans.size()-1;
        int j = destans.size()-1;

        while(i>=0 && j>=0){
            if(startans[i] == destans[j]){
                startans.pop_back();
                destans.pop_back();
                i--;
                j--;
            }
            else{
                break;
            }
        }
        string ans;
        while(i>=0){
            ans.push_back('U');
            i--;      
        }
        while(j>=0){
            ans.push_back(destans[j]);
            j--;      
        }
        return ans;
    }
};