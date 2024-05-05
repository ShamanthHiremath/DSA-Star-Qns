/*
Input: SUM ALL THE NODE DATA IN VERTICAL COLUMN FASHION
       1
    /    \
  2      3
 /  \    /  \
4   5  6   7
Output: 
4 2 12 3 7
*/

class Solution{
  public:
  
    vector<int> verticalOrder(Node *root)
    {
        if(root==NULL){
            return {};
        }
        //to store the final answer
        vector<int>ans;
        
        //to represent a mapping b/w the Horizontal No Line distance from the root to the mapping of level and the nodes in that level
        map<int,map<int, vector<int> > > nodes;
        
        //queues with the Node and a pair representing the HD and the level
        queue<pair<Node*, pair<int, int> > > q;
        //first node has 0th hd and 0th level
        q.push({root, {0,0} });
        
        while(!q.empty()){
            pair<Node*, pair<int, int> > temp = q.front();
            q.pop();
            
            Node* frontNode=temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;
            
            nodes[hd][lvl].push_back(frontNode->data);
            
            if(frontNode->left){
                q.push({frontNode->left, {hd-1, lvl+1}});
            }
            if(frontNode->right){
                q.push({frontNode->right, {hd+1, lvl+1}});
            }
        }
        
        for(auto i: nodes){
            int sum = 0;
            for(auto j: i.second){
                for(auto k: j.second){
                    sum += k;
                    // cout<<k<<" ";
                }
                // cout<<endl;
            }
            ans.push_back(sum);
        }
        
        return ans;
    }
  
    vector<int> verticalSum(Node *root) {
        vector<int>ans = verticalOrder(root);
        return ans;
    }
};