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
    TreeNode* preorder(TreeNode* root, int target){
        if(!root){
            return NULL;
        }
        if(root->val == target){
            return root;
        }
        TreeNode* leftResult = preorder(root->left, target);
        if(leftResult){
            return leftResult;
        }
        return preorder(root->right, target);

    }

    void dfs(TreeNode* root, int dist, int k, unordered_map<TreeNode*, bool>&vis, unordered_map<TreeNode*, TreeNode*>&parent, vector<int>&ans){
        if(!root){
            return;
        }
        if(vis[root]){
            return;
        }

        vis[root] = true;
        if(dist == k){
            ans.push_back(root->val);
            return;
        }

        // dfs
        // parent traverse
        if(!vis[parent[root]]){
            dfs(parent[root], dist+1, k, vis, parent, ans);
        }

        // left
        if(!vis[root->left]){
            dfs(root->left, dist+1, k, vis, parent, ans);
        }
        // right
        if(!vis[root->right]){
            dfs(root->right, dist+1, k, vis, parent, ans);
        }

    }



    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // make a visited set for TreeNode*
        // traverse level order and maintain a parentNode map
        // parentNode map will map the parent of a node

        // find the node using Preorder, postorder, inorder traversal
        // start DFS readially, to the parentNode, as well as left, right
        // visit unvisited nodes only
        // increment distance untill k and store all nodes when dis = k

        unordered_map<TreeNode*, bool>vis;
        unordered_map<TreeNode*, TreeNode*>parent;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int levelSize = q.size();
            // process that level
            for(int i=0; i<levelSize; i++){
                auto node = q.front();
                q.pop();      

                if(node->left){
                    q.push(node->left);
                    parent[node->left] = node;
                }
                if(node->right){
                    q.push(node->right);
                    parent[node->right] = node;
                }
            }
        }

        // preorder to find node
        // TreeNode* target = preorder(root, target);
    


        // dfs
        vector<int>ans;
        dfs(target, 0, k, vis, parent, ans);
        
        return ans;
    }
};


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