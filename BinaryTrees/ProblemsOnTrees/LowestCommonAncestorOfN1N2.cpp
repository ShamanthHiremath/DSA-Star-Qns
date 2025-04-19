/*
236. Lowest Common Ancestor of a Binary Tree

https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.

Example 2:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
Example 3:

Input: root = [1,2], p = 1, q = 2
Output: 1


 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
Recursive Soln
*/

class Solution {
public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if(root == NULL){
                return root;
            }
    
            if(root->val == p->val || root->val == q->val){
                return root;
            }
    
            TreeNode* leftScan = lowestCommonAncestor(root->left, p, q);
            TreeNode* rightScan = lowestCommonAncestor(root->right, p, q);
            
            // A node/root is a LCA only if one of them is from left and other is from right
            if(leftScan and rightScan){
                return root;
            }
            // If not, if only leftScan was successful we need to search for the other node (the one that failed in rightScan in the left subtree), so we return the successfully found out LCA from the left subtree only.
            if(leftScan and !rightScan){
                return leftScan;
            }
            else{
                return rightScan;
            }
    
        }
    };


class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
        if(root==NULL){
            return NULL;
        }
        // If either of the nodes is found, return the node itself
        if(root->data==n1 || root->data==n2){
            return root;
        }
        
        Node* left=lca(root->left, n1, n2);
        Node* right=lca(root->right, n1, n2);
        
        //answer found
        // If both nodes lie in the left and right subtrees,
        // then the current node is the LCA
        if(left!=NULL && right!=NULL){
            return root;
        }
         // Otherwise, return the non-null LCA (if found) from left or right subtree
        else if(left!=NULL && right==NULL){
            return left;
        }
        else{
            return right;
        }
        
    }
};



//TIME CONSUMING but works
/*
MAPPING Soln O(N)
*/
class Solution
{
    public:
    
    void createMapping(map<int, Node*> &parent, Node* root){
        if(root==NULL){
            return;
        }
        if(root->left){
            parent[root->data]=root;
            createMapping(parent, root->left);
        }
        if(root->right){
            parent[root->data]=root;
            createMapping(parent, root->right);
        }
    }
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
        if(root==NULL){
            return NULL;
        }
        map<int, Node*> parent;
        parent[root->data]=NULL;
        createMapping(parent, root);
        // Node* lca;
        Node* n1parent=parent[n1];
        Node* n2parent=parent[n2];
        while(n1parent!=n2parent && n1parent!=NULL && n2parent!=NULL){
            n1parent=parent[n1parent->data];
            n2parent=parent[n2parent->data];            
        }
        if(n1parent!=NULL && n2parent!=NULL){
            return n1parent;
        }
        else{
            return root;
        }
    }
};