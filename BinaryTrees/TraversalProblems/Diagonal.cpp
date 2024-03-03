/*
Diagonal tracing
*/
vector<int> diagonal(Node *root) {
    vector<int> ans;
    if(root == nullptr){
        return ans;
    }
    
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        Node* current = q.front();
        q.pop();
        
        // Process all nodes in the current diagonal line
        while(current) {
            ans.push_back(current->data);
            if(current->left) {
                q.push(current->left);
            }
            current = current->right;
        }
    }
    
    return ans;
}