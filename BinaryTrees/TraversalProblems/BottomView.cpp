class Solution {
  public:
    vector <int> bottomView(Node *root) {
        if(root==NULL){
            return {};
        }
        
        vector<int>ans;
        //create a one to one mapping in such a way that if the HD already exists, dont do anything and move forward
        //ifit doesnt exist, add the node data corresponding to that HD
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