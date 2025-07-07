/*
2385. Amount of Time for Binary Tree to Be Infected

https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/


You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.

Each minute, a node becomes infected if:

The node is currently uninfected.
The node is adjacent to an infected node.
Return the number of minutes needed for the entire tree to be infected.


Example 1:

Input: root = [1,5,3,null,4,10,6,9,2], start = 3
Output: 4
Explanation: The following nodes are infected during:
- Minute 0: Node 3
- Minute 1: Nodes 1, 10 and 6
- Minute 2: Node 5
- Minute 3: Node 4
- Minute 4: Nodes 9 and 2
It takes 4 minutes for the whole tree to be infected so we return 4.

Example 2:

Input: root = [1], start = 1
Output: 0
Explanation: At minute 0, the only node in the tree is infected so we return 0.
*/


class Solution {
public:
    void dfs(TreeNode* root, unordered_map<TreeNode*, bool>&vis, unordered_map<TreeNode*, TreeNode*>&parent, int currTime, int &maxTime){
        if (!root || vis[root]){
            return;
        }
        
        vis[root] = true;
        maxTime = max(maxTime, currTime);

        // to parent
        if(parent[root] != root){
            dfs(parent[root], vis, parent, currTime + 1, maxTime);
        }
            

        // to left
        if(root->left){
            dfs(root->left, vis, parent, currTime + 1, maxTime);
        }

        // to right

        if(root->right){
            dfs(root->right, vis, parent, currTime + 1, maxTime);
        }

    }

    int amountOfTime(TreeNode* root, int start) {
        // parent node storing map using bfs
        // dfs for time calculation 

        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*>q;
        q.push(root);
        parent[root] = root;
        // storing the start node
        TreeNode* src;

        while(!q.empty()){
            int levelsize = q.size();
            for(int i=0; i<levelsize; i++){
                TreeNode* frontnode = q.front();
                q.pop();
                // handling src node
                if(frontnode->val == start) src = frontnode;

                // adding other nodes into q
                if(frontnode->left){
                    q.push(frontnode->left);
                    parent[frontnode->left] = frontnode;
                }

                if(frontnode->right){
                    q.push(frontnode->right);
                    parent[frontnode->right] = frontnode;
                }
            }
        }

        unordered_map<TreeNode*, bool>vis;
        int maxitime = 0, currtime = 0;
        dfs(src, vis, parent, currtime, maxitime);
        return maxitime;
    }
};