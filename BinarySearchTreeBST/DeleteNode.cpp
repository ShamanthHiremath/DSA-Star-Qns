/*
450. Delete Node in a BST

https://leetcode.com/problems/delete-node-in-a-bst/

Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
 
Example 1:
Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

Example 2:
Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.

Example 3:
Input: root = [], key = 0
Output: []
 
*/

class Solution {
public:
    TreeNode* minNode(TreeNode* root){
        TreeNode* temp = root;

        while(temp->left){
            temp = temp->left;
        }

        return temp;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root){
            return root;
        }
        if(key < root->val){
            root->left = deleteNode(root->left, key);
        }
        else if(key > root->val){
            root->right = deleteNode(root->right, key);
        }
        // key found
        else{
            if(!root->left and !root->right){
                delete(root);
                return NULL;
            }
            else if(!root->left and root->right){
                TreeNode* next = root->right;
                delete(root);
                return next;
            }
            else if(!root->right and root->left){
                TreeNode* next = root->left;
                delete(root);
                return next;
            }
            // if both are present
            TreeNode* smallest_right_node = minNode(root->right);
            root->val = smallest_right_node->val;
            root->right = deleteNode(root->right, smallest_right_node->val);
        }

        return root;
    }
};