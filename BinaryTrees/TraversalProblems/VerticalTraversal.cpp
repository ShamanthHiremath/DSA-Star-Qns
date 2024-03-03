/*
Vertical Order Traversal:
A tree divided vertically into columns andlisting them down column after column

            root
|   |   |   |   |   |   |
|   |   |   |   |   |   |
|   |   |   |   |   |   |
|   |   |   |   |   |   |
|   |   |   |   |   |   |
|   |   |   |   |   |   |
|   |   |   |   |   |   |

*/

class Solution
{
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
            pair<Node*, pair<int, int> > temp=q.front();
            q.pop();
            
            Node* frontNode=temp.first;
            int hd=temp.second.first;
            int lvl=temp.second.second;
            
            nodes[hd][lvl].push_back(frontNode->data);
            
            if(frontNode->left){
                q.push({frontNode->left, {hd-1, lvl+1}});
            }
            if(frontNode->right){
                q.push({frontNode->right, {hd+1, lvl+1}});
            }
        }
        
        for(auto i: nodes){
            for(auto j: i.second){
                for(auto k: j.second){
                    ans.push_back(k);
                }
            }
        }
        
        return ans;
    }
};