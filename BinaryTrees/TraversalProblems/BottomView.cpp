/*
Bottom View of Binary Tree

https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

Given a binary tree, return an array where elements represent the bottom view of the binary tree from left to right.

Note: If there are multiple bottom-most nodes for a horizontal distance from the root, then the latter one in the level traversal is considered. For example, in the below diagram, 3 and 4 are both the bottommost nodes at a horizontal distance of 0, here 4 will be considered.

                      20
                    /    \
                  8       22
                /   \     /   \
              5      3 4     25
                     /    \      
                 10       14

For the above tree, the output should be 5 10 4 14 25.

Examples :

Input:
       1
     /   \
    3     2
Output: 3 1 2
Explanation: First case represents a tree with 3 nodes and 2 edges where root is 1, left child of 1 is 3 and right child of 1 is 2.

Thus bottom view of the binary tree will be 3 1 2.
Input:
         10
       /    \
      20    30
     /  \
    40   60
Output: 40 20 60 30
Input:
        1
       /   
      2
Output: 2 1
*/

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        if(root==NULL){
            return {};
        }
        
        vector<int>ans;
        //create a one to one mapping in such a way that if the HD already exists, add the node data corresponding to that HD
        map<int,int>topnode;
        
        queue<pair<Node*, int>>q;
        q.push({root, 0});
        
        while(!q.empty()){
            pair<Node*, int>temp=q.front();
            q.pop();
            
            Node* frontNode=temp.first;
            int hd=temp.second;
            //do not check this condition here, bcuz we need the ones available at the last
            //the overalapping elements will ensure that the most recent in that vertical column from the bottom order is seen
            //check it in TOP VIEW PROBLEM
            // if(topnode.find(hd)==topnode.end()){
            topnode[hd]=frontNode->data;
            // }
            if(frontNode->left){
                q.push({frontNode->left, hd-1});
            }
            if(frontNode->right){
                q.push({frontNode->right, hd+1});
            }
        }
        for(auto i: topnode){
            ans.push_back(i.second);
        }
        return ans;
    }
};