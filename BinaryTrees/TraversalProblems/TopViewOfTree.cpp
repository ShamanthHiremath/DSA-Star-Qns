/*
Top View of Binary Tree

https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1

You are given a binary tree, and your task is to return its top view. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.

Note: 

Return the nodes from the leftmost node to the rightmost node.
If two nodes are at the same position (horizontal distance) and are outside the shadow of the tree, consider the leftmost node only. 
Examples:

Input: root[] = [1, 2, 3] 
 
Output: [2, 1, 3]
Input: root[] = [10, 20, 30, 40, 60, 90, 100]
 
Output: [40, 20, 10, 30, 100]
Explanation: The root 10 is visible.
On the left, 40 is the leftmost node and visible, followed by 20.
On the right, 30 and 100 are visible. Thus, the top view is 40 20 10 30 100.
Input: root[] = [1, 2, 3, N, 4, N, N, N, 5, N, 6]
       1
     /   \
    2     3
     \   
      4
       \
        5
         \
          6
Output: [2, 1, 3, 6]
Explanation: Node 1 is the root and visible.
Node 2 is the left child and visible from the left side.
Node 3 is the right child and visible from the right side.
Nodes 4, 5, and 6 are vertically aligned, but only the lowest node 6 is visible from the top view. Thus, the top view is 2 1 3 6.
*/

/*
Top View: A list of nodes visible from the top view 
    from left to right in Binary Tree.
*/

class Solution
{
    public:
    vector<int> topView(Node *root)
    {
        if(root==NULL){
            return {};
        }
        vector<int>ans;

        //create a one to one mapping in such a way that if the HD already exists, dont do anything and move forward
        //ifit doesnt exist, add the node data corresponding to that HD
        map<int,int>topnode;
        //Node and HD
        queue<pair<Node*, int>>q;
        q.push({root, 0});
        
        while(!q.empty()){
            pair<Node*, int>temp=q.front();
            q.pop();
            
            Node* frontNode=temp.first;
            int hd=temp.second;
            //dont check this condition in BOTTOM VIEW TRAVERSAL
            if(topnode.find(hd)==topnode.end()){
                topnode[hd]=frontNode->data;
            }
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