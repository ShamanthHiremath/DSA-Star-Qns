/*
Children Sum in a Binary Tree

https://www.geeksforgeeks.org/problems/children-sum-parent/1

Given a binary tree having n nodes. Check whether all of its nodes have a value equal to the sum of their child nodes. Return 1 if all the nodes in the tree satisfy the given properties, else it returns 0. For every node, the data value must be equal to the sum of the data values in the left and right children. Consider the data value 0 for a NULL child. Also, leaves are considered to follow the property.

Examples:

Input:
Binary tree
       35
      /  \
     20   15
    / \   / \
   15  5 10  5

Output: 1
Explanation: 
Here, every node is sum of its left and right child.


Input:
Binary tree
       1
     /   \
    4     3
   /  
  5    
Output: 0
Explanation: 
Here, 1 is the root node and 4, 3 are its child nodes. 4 + 3 = 7 which is not equal to the value of root node. Hence, this tree does not satisfy the given condition.
*/

class Solution {
  public:
    // Function to check whether all nodes of a tree have the value
    // equal to the sum of their child nodes.
    int isSumProperty(Node *root) {
        // Add your code here
        if(!root){
            return true;
        }
        if(!root->left && !root->right){
            return true;
        }
        int sum = 0;
        if(root->left){
            sum += root->left->data;
        }
        if(root->right){
            sum += root->right->data;
        }
        
        return root->data == sum && isSumProperty(root->left) && isSumProperty(root->right);
    }
};