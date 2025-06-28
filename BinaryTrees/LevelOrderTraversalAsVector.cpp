/*
LEVEL ORDER TRAVERSAL OF A BINARY TREE AS A VECTOR

https://leetcode.com/problems/binary-tree-level-order-traversal/
https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/

Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root).


Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[15,7],[9,20],[3]]

Example 2:
Input: root = [1]
Output: [[1]]

Example 3:
Input: root = []
Output: []
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<vector<int>> ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            vector<int>level;
            int i=0;
            int currlevelSize = q.size();

            // prcesses the current level
            while(i < currlevelSize){
                TreeNode* frontNode = q.front();
                q.pop();
                level.push_back(frontNode->val);
                if(frontNode->left){
                    q.push(frontNode->left);
                }
                if(frontNode->right){
                    q.push(frontNode->right);
                }
                i++;
            }
            ans.push_back(level);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};


// ANOTHER APPROACH USING LEVEL MARKER
// This approach uses a level marker (NULL) to indicate the end of a level, which

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return {}; // Return an empty vector if the tree is empty.
        }

        vector<vector<int>> ans;    // Final result
        vector<int> level;          // Current level nodes
        queue<TreeNode*> q;         // Queue for BFS traversal
        q.push(root);
        q.push(NULL);               // Level marker

        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();

            if (front == NULL) {    // End of a level
                if (!level.empty()) {
                    ans.push_back(level); // Add the level to the result
                    level.clear();        // Clear the current level
                }
                if (!q.empty()) {
                    q.push(NULL); // Add marker for the next level
                }
            } else {
                level.push_back(front->val); // Add current node's value
                if (front->left) q.push(front->left);  // Add left child
                if (front->right) q.push(front->right); // Add right child
            }
        }

        return ans;
    }
};



// *****************OR********************


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return {}; 
        }

        vector<vector<int>> ans;  
        queue<TreeNode*> q;       
        q.push(root);             

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> level;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* front = q.front();
                q.pop();
                level.push_back(front->val);

                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            }

            ans.push_back(level); 
        }

        return ans;

    }
};