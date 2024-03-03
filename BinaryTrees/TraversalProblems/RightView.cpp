/*
Right View: A list containing elements of right view of the binary tree.
*/

class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
        if(root==NULL){
            return {};
        }
        
        vector<int>ans;
        //create a one to one mapping in such a way that if the LVL already exists, dont do anything and move forward
        //if it doesnt exist, add the node data corresponding to that HD
        map<int,int>rightnode;
            
        queue<pair<Node*, int>>q;
        q.push({root, 0});
        
        while(!q.empty()){
            pair<Node*, int>temp=q.front();
            q.pop();
            
            Node* frontNode=temp.first;
            int lvl=temp.second;
                
            if(rightnode.find(lvl)==rightnode.end()){
                rightnode[lvl]=frontNode->data;
            }
            
            //check if left exists... go left
            if(frontNode->right){
                q.push({frontNode->right, lvl+1});
            }
            //or else check if right exists... go right
            if(frontNode->left){
                q.push({frontNode->left, lvl+1});
            }
            //or else it has nothing stop there and repeat
        }
        
        //print values
        for(auto i: rightnode){
            ans.push_back(i.second);
        }
        
        return ans;
    }
};