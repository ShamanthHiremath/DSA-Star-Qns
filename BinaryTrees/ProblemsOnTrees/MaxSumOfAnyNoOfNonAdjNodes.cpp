/*
Input:
        1
      /   \
     2     3
    /     /  \
   4     5    6
Output: 16
Explanation: The maximum sum is sum of
nodes 1 4 5 6 , i.e 16. These nodes are
non adjacent.
*/

class Solution{
  public:
//pair< included sum, excluded sum >
  pair<int, int> solve(Node* root){
      if(root==NULL){
          return {0, 0};
          
      }
      pair<int, int> left = solve(root->left);
      pair<int, int> right= solve(root->right);
      
      pair<int,int>currNode;
      
      //if lower levels left and right parts excluded data are considered, take the data of root 
      currNode.first=root->data + left.second + right.second;
      //if lower levels left and right parts included data are considered, dont take the data of root 
      currNode.second=max(left.first, left.second) + max(right.first, right.second);
      
      return currNode;
  }
  
  int getMaxSum(Node *root) 
    {
        pair<int, int> ans=solve(root);
        return max(ans.first, ans.second);
    }
};