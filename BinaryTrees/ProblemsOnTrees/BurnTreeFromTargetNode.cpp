/*
Given a binary tree and a node data called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.
Note: The tree contains unique values.

Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      6
       / \      \
      7   8      9
                   \
                   10
Target Node = 8
Output: 7
Explanation: If leaf with the value 
8 is set on fire. 
After 1 sec: 5 is set on fire.
After 2 sec: 2, 7 are set to fire.
After 3 sec: 4, 1 are set to fire.
After 4 sec: 3 is set to fire.
After 5 sec: 6 is set to fire.
After 6 sec: 9 is set to fire.
After 7 sec: 10 is set to fire.
It takes 7s to burn the complete tree.
*/

class Solution {
  public:
  
    void createMapping(map<Node*,Node*>& parent, Node* root, Node* &targetNode, int target){
        if(root==NULL){
            return ;
        }
        if (root->data == target) {
            targetNode=root;
        }
        if(root->left){
            parent[root->left]=root;
            createMapping(parent, root->left, targetNode, target);
        }
        if(root->right){
            parent[root->right]=root;
            createMapping(parent, root->right, targetNode, target);
        }
    }
    
    int burnTree(map<Node*,Node*>& parent, Node* &targetNode ){
        
        int timer=0;
        
        map<Node*, bool>visited;
        //by default the bool values are 0
        
        visited[targetNode]=1;
        
        queue<Node*>q;
        q.push(targetNode);
        
        while(!q.empty()){
            
            bool flag=0;
            int size=q.size();
            
            for(int i=0; i<size; i++){
                Node* frontNode=q.front();
                q.pop();
                
                if(frontNode->left && visited[frontNode->left]!=1){
                    flag=1;
                    q.push(frontNode->left);
                    visited[frontNode->left]=1;
                }
                
                if(frontNode->right && visited[frontNode->right]!=1){
                    flag=1;
                    q.push(frontNode->right);
                    visited[frontNode->right]=1;
                }
                
                if(parent[frontNode] && visited[parent[frontNode]]!=1){
                    flag=1;
                    q.push(parent[frontNode]);
                    visited[parent[frontNode]]=1;
                }
            }
            if(flag==1){
                timer++;
            }
        }
        return timer;
    }

    
    int minTime(Node* root, int target) 
    {
        if(root==NULL){
            return 0;
        }
        
        Node* targetNode;
        
        map<Node*,Node*> parent;
        parent[root]=NULL;
        createMapping(parent, root, targetNode, target);
        
        return burnTree(parent, targetNode);
        
    }
};