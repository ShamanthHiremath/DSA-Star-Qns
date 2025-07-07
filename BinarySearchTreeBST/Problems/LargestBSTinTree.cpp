/*
Largest BST

https://www.geeksforgeeks.org/problems/largest-bst/1

You're given a binary tree. Your task is to find the size of the largest subtree within this binary tree that also satisfies the properties of a Binary Search Tree (BST). The size of a subtree is defined as the number of nodes it contains.

Note: A subtree of the binary tree is considered a BST if for every node in that subtree, the left child is less than the node, and the right child is greater than the node, without any duplicate values in the subtree.

Examples :

Input: root = [5, 2, 4, 1, 3]
Root-to-leaf-path-sum-equal-to-a-given-number-copy
Output: 3
Explanation:The following sub-tree is a BST of size 3
Balance-a-Binary-Search-Tree-3-copy
Input: root = [6, 7, 3, N, 2, 2, 4]

Output: 3
Explanation: The following sub-tree is a BST of size 3:

*/

// THE DATA STRUCTURE vector<int> stores three values
// {THE LARGEST BST SIZE, THE LARGEST VALUE IN THE LEFT SUBTREE, THE SMALLEST VAL IN RIGHT SUBTREE};
// 

class Solution {
  public:
    vector<int> solve(Node* root){
        if(!root){
            // return size, largest in left subtree, smallest in right subtree
            return {0, INT_MIN, INT_MAX};
        }
        if(!root->left and !root->right){
            return {1, root->data, root->data};
        }
        
        vector<int>  leftSubtree = solve(root->left);
        vector<int>  rightSubtree = solve(root->right);
        
        // valid BST condition check
        if(leftSubtree[1] < root->data and root->data < rightSubtree[2]){
            // add the sizes of BST in left and right subtrees to push the max to the top
            // the leftSubtree[1] indicates the LARGEST VALUE IN THE LEFT SUBTREE
            // the rightSubtree[2] indicates the SMALLEST VAL IN RIGHT SUBTREE
            return { 1 + leftSubtree[0] + rightSubtree[0], max(root->data, rightSubtree[1]), min( root->data, leftSubtree[2])};
        }
        else{
            // invalidate the largest and smallest values in the left and right subtree
            // but pass the maximum most subtree values
            return {max(leftSubtree[0], rightSubtree[0]), INT_MAX, INT_MIN};
        }
        
        
    }
    
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root) {
        // Your code here
        // returns the size of the LARGEST BST IN THE TREE
        return solve(root)[0];
    }
};

// OR

struct Info {
    int size;      // Size of the largest BST in the subtree
    int maxVal;    // Max value in the subtree
    int minVal;    // Min value in the subtree
    bool isBST;    // Whether the subtree is a BST
};

class Solution {
public:
    Info solve(Node* root) {
        if (!root)
            return {0, INT_MIN, INT_MAX, true};
        
        if (!root->left && !root->right)
            return {1, root->data, root->data, true};
        
        Info left = solve(root->left);
        Info right = solve(root->right);
        
        Info curr;
        
        // Check if the current subtree is a valid BST
        if (left.isBST && right.isBST &&
            left.maxVal < root->data && root->data < right.minVal) {
            
            curr.size = 1 + left.size + right.size;
            curr.minVal = min(root->data, left.minVal);
            curr.maxVal = max(root->data, right.maxVal);
            curr.isBST = true;
        } else {
            curr.size = max(left.size, right.size);
            curr.isBST = false;
        }
        
        return curr;
    }
    
    int largestBst(Node *root) {
        return solve(root).size;
    }
};
