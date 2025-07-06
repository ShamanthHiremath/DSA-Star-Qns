/*
662. Maximum Width of Binary Tree

https://leetcode.com/problems/maximum-width-of-binary-tree/

Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.


Example 1:
Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).

Example 2:
Input: root = [1,3,2,5,null,null,9,6,null,7]
Output: 7
Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).

Example 3:
Input: root = [1,3,2,5]
Output: 2
Explanation: The maximum width exists in the second level with length 2 (3,2).
*/

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        // the concept of this problem is to assume that we have a COMPLETE BINARY TREE
        // In COMPLETE BINARY TREE: if the root index is i, we have left as 2*i+1, and right as 2*i + 2
        // we imagine that it is a COMPLETE BIN TREE and assign its position index,
        // when traversing a level, the WIDTH of PATH will be the difference between the LEFT MOST NODE POSITION VAL and RIGHT MOST NODE POSITION VAL
        
        long long maxiWidth = INT_MIN;
        // stores NODE, NODE POSITION VAL
        queue<pair<TreeNode*, long long >>q;
        q.push({root, 0});

        while(!q.empty()){
            
            int levelSize = q.size();
            // the leftmost node's index of the level
            long long startNodePos = q.front().second;
            long long leftmost, rightmost;
            // process that level
            for(int i=0; i<levelSize; i++){
                auto [parent_node, parent_position] = q.front();
                q.pop();

                // this is to ensure that we index each level's node from 0 and calcualte distance
                parent_position = parent_position - startNodePos;
                if(i == 0){
                    leftmost = parent_position;
                }
                if(i == levelSize-1){
                    rightmost = parent_position;
                }

                if(parent_node->left){
                    q.push({parent_node->left, 2*parent_position+1});
                }
                if(parent_node->right){
                    q.push({parent_node->right, 2*parent_position+2});
                }
            }

            // after every level compare maxi width
            maxiWidth = max(maxiWidth, rightmost - leftmost + 1);
        }

        return maxiWidth;
    
    }
};