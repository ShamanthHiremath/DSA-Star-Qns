/*

987. Vertical Order Traversal of a Binary Tree

https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/

Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.


Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation:
Column -1: Only node 9 is in this column.
Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
Column 1: Only node 20 is in this column.
Column 2: Only node 7 is in this column.

Example 2:
Input: root = [1,2,3,4,5,6,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation:
Column -2: Only node 4 is in this column.
Column -1: Only node 2 is in this column.
Column 0: Nodes 1, 5, and 6 are in this column.
          1 is at the top, so it comes first.
          5 and 6 are at the same position (2, 0), so we order them by their value, 5 before 6.
Column 1: Only node 3 is in this column.
Column 2: Only node 7 is in this column.

Example 3:
Input: root = [1,2,3,4,6,5,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation:
This case is the exact same as example 2, but with nodes 5 and 6 swapped.
Note that the solution remains the same since 5 and 6 are in the same location and should be ordered by their values.
 


Vertical Order Traversal:
A tree divided vertically into columns andlisting them down column after column

            root
|   |   |   |   |   |   |
|   |   |   |   |   |   |
|   |   |   |   |   |   |
|   |   |   |   |   |   |
|   |   |   |   |   |   |
|   |   |   |   |   |   |
|   |   |   |   |   |   |

*/

class Solution
{
    public:
    
    vector<int> verticalOrder(Node *root)
    {
        if(root==NULL){
            return {};
        }
        //to store the final answer
        vector<int>ans;
        
        //to represent a mapping b/w the Horizontal No Line distance from the root to the mapping of level and the nodes in that level
        map<int,map<int, vector<int> > > nodes;
        
        //queues with the Node and a pair representing the HD and the level
        queue<pair<Node*, pair<int, int> > > q;
        //first node has 0th hd and 0th level
        q.push({root, {0,0} });
        
        while(!q.empty()){
            pair<Node*, pair<int, int> > temp=q.front();
            q.pop();
            
            Node* frontNode=temp.first;
            int hd=temp.second.first;
            int lvl=temp.second.second;
            
            nodes[hd][lvl].push_back(frontNode->data);
            
            if(frontNode->left){
                q.push({frontNode->left, {hd-1, lvl+1}});
            }
            if(frontNode->right){
                q.push({frontNode->right, {hd+1, lvl+1}});
            }
        }
        
        for(auto i: nodes){
            for(auto j: i.second){
                for(auto k: j.second){
                    ans.push_back(k);
                }
            }
        }
        
        return ans;
    }
};


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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root == NULL){
            return {};
        }

        // hd -> {level -> [vals]}
        map<int, map<int, vector<int>>> mp;
        queue<pair<TreeNode*, pair<int, int>>> q;
        // {root, {hd, level}}
        q.push({root, {0, 0}});
        
        while(!q.empty()){
            auto frontNode = q.front();
            q.pop();

            TreeNode* node = frontNode.first;
            int hd = frontNode.second.first;
            int level = frontNode.second.second;

            // include in the map data structure
            mp[hd][level].push_back(node->val);

            if(node->left){
                q.push({node->left, {hd-1, level+1}});
            }
            if(node->right){
                q.push({node->right, {hd+1, level+1}});
            }
        }

        vector<vector<int>> ans;

        for(auto& hd_entry : mp){
            vector<int> col;
            for(auto& level_entry : hd_entry.second){
                auto& vals = level_entry.second;
                sort(vals.begin(), vals.end());
                col.insert(col.end(), vals.begin(), vals.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};