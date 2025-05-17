/*
Floor in BST

https://www.geeksforgeeks.org/problems/floor-in-bst/0

You are given a BST(Binary Search Tree) with n number of nodes and value x. your task is to find the greatest value node of the BST which is smaller than or equal to x.
Note: when x is smaller than the smallest node of BST then returns -1.

Examples:

Input:
n = 7               2
                     \
                      81
                    /     \
                 42       87
                   \       \
                    66      90
                   /
                 45
x = 87
Output: 87
Explanation: 87 is present in tree so floor will be 87.

Input:
n = 4                     6
                           \
                            8
                          /   \
                        7       9
x = 11
Output: 9

Input:
n = 4                     6
                           \
                            8
                          /   \
                        7       9
x = 5
Output: -1
*/
class Solution {

  public:
    int floor(Node* root, int x) {
        // Code here
        
        if (root == NULL)
            return -1;
            
        int res = -1;
        while(root){
            if(root->data == x){
                return x;
            }
            // answer can be found in the right side, possible ones whcih are close values
            else if(root->data < x){
                res = root->data;
                root = root-> right;
                
            }
            // if its greater then we need to find in the left side
            else{
                root = root->left;
            }
            
        }
        
        return res;
            
    }
};