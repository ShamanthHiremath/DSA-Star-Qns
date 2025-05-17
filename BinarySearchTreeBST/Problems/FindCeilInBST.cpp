/*
Ceil in BST

https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1


Given a BST and a number X, find Ceil of X.
Note: Ceil(X) is a number that is either equal to X or is immediately greater than X.

If Ceil could not be found, return -1.

Example 1:

Input: root = [5, 1, 7, N, 2, N, N, N, 3], X = 3
      5
    /   \
   1     7
    \
     2 
      \
       3

Output: 3
Explanation: We find 3 in BST, so ceil of 3 is 3.

Example 2:

Input: root = [10, 5, 11, 4, 7, N, N, N, N, N, 8], X = 6
     10
    /  \
   5    11
  / \ 
 4   7
      \
       8
Output: 7
Explanation: We find 7 in BST, so ceil of 6 is 7.

*/
// this one is similar to Binary Search,
// if found return
// if the val is small, serach in the right side
// if the val is large, find in the left side, return either the s

// Function to return the ceil of given number in BST.
int findCeil(Node* root, int input) {
    if (root == NULL)
        return -1;

    if(root->data == input){
        return root->data;
    }

    
    // the root's data is less than input so it means that the ceil can be found in the right subtree
    if(root->data < input){
        return findCeil(root->right, input);
    }
    
    // if the root->data is greater then the ceil might be in the left subtree since it can be smaller, or the root data is itself the ceil
    int ceil = findCeil(root->left, input);
    return (ceil >= input)? ceil : root->data;
    
}