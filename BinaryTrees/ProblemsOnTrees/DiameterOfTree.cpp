/* It is said to be the largest distance between any two leafnodes in the tree
(isnt a neccesity such that the distance path should traverse through the root node )
*/

//  O(n) Time Complexity Solution
class Solution {
public:
    int solve(TreeNode* root, int& maxi){
        if(root == NULL){
            return 0;
        }
        int left = solve(root->left, maxi);
        int right = solve(root->right, maxi);
        maxi = max(maxi, left+right);
        return 1+ max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        solve(root, maxi);
        return maxi;
    }
};


//Faster code
//TIME COMPLEXITY O(n)
class Solution {
  public:
  
  //Pair stores <diameter of that root, height of that root>
  
    pair<int, int> diameterFast (Node* root){
        if(root==NULL){
            return {0,0};
        }
        
        //find diameter in left and right
        pair<int, int>leftTree=diameterFast(root->left);
        pair<int, int>rightTree=diameterFast(root->right);
        
        //for a node, the diameter is either in the left subtree, or the right subtree, or its the height.
        int leftDia=leftTree.first;
        int rightDia=rightTree.first;
        int height=leftTree.second+ rightTree.second+1;
        
        //ans pair
        pair<int, int> ans;
        
        //Update diameter here
        ans.first=max(leftDia, max(rightDia, height));
        
        //Update height here
        ans.second=max(leftTree.second, rightTree.second)+1;
        
        return ans;
        
        
    }
  
  
    int diameter(Node* root) {
        return diameterFast(root).first;
    }
};


//works but slow  
//TIME COMPLEXITY O(n^2)
class Solution {
  public:
    int height(Node *root){
        if(root==NULL)return 0;
        return max(height(root->left), height(root->right))+1;
        
    }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        if(root==NULL){
            return 0;
        }
        int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // Calculate the diameter passing through the current node
    int currentDiameter = leftHeight + rightHeight + 1;

    // Recursively find the diameter in left and right subtrees
    int leftDiameter = diameter(root->left);
    int rightDiameter = diameter(root->right);

    // Return the maximum of the three diameters
    return max(currentDiameter, max(leftDiameter, rightDiameter));
    }
};