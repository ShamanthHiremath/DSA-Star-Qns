/*
LeftView: A list containing elements of left view of the binary tree.
*/

//EASIER APPROACH
class Solution
{
    public:
    void solve(Node *root, vector<int>&ans, int lvl){
        if(root==NULL)return;
        if(lvl==ans.size()){
            ans.push_back(root->data);
        }
        solve(root->left, ans, lvl+1);
        solve(root->right, ans, lvl+1);
    }
    //Function to return list containing elements of right view of binary tree.
    vector<int> leftView(Node *root)
    {
        if(root==NULL){
            return {};
        }
        
        vector<int>ans;
        solve(root, ans, 0);
        
        return ans;
    }
};

vector<int> leftView(Node *root)
{
    if(root==NULL){
        return {};
    }
        
    vector<int>ans;
    //create a one to one mapping in such a way that if the LVL already exists, dont do anything and move forward
    //if it doesnt exist, add the node data corresponding to that HD
    map<int,int>leftnode;
        
    queue<pair<Node*, int>>q;
    q.push({root, 0});
    
    while(!q.empty()){
        pair<Node*, int>temp=q.front();
        q.pop();
        
        Node* frontNode=temp.first;
        int lvl=temp.second;
        
        if(leftnode.find(lvl)==leftnode.end()){
            leftnode[lvl]=frontNode->data;
        }
        
        //check if left exists... go left
        if(frontNode->left){
            q.push({frontNode->left, lvl+1});
        }
        //or else check if right exists... go right
        if(frontNode->right){
            q.push({frontNode->right, lvl+1});
        }
        //or else it has nothing stop there and repeat
    }
    
    //print values
    for(auto i: leftnode){
        ans.push_back(i.second);
    }
    
    return ans;
}