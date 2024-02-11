class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
        if(root==NULL){
            return {};
        }
        vector<int>ans;
        
    	queue<Node*>q;
    	q.push(root);
    	
    	//flag for left to right or right to left
    	bool leftToRight=true;
    	
    	while(!q.empty()){
    	    int levelsize= q.size();
    	    vector<int>level(levelsize);
    	    for(int i=0; i<levelsize; i++){
    	        
    	        Node* frontnode= q.front();
    	        q.pop();
    	        
    	        level[i]=frontnode->data;
    	        if(frontnode->left){
    	            q.push(frontnode->left);
    	        }
    	        if(frontnode->right){
    	            q.push(frontnode->right);
    	        }
    	    }
    	    
    	    if(leftToRight){
    	        for(auto i: level){
    	            ans.push_back(i);
    	        }
    	    }
    	    else{
    	        for(int i=level.size()-1; i>=0; i--){
    	            ans.push_back(level[i]);
    	        }
    	    }
    	    //change the direction
    	    leftToRight=!leftToRight;
    	}
    	return ans;
    	
    	
    	
    }
};