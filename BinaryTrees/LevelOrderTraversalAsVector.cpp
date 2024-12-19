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