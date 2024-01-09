TreeNode* buildTreeFromLevelOrder(TreeNode* root){
    queue<TreeNode*> q;
    cout<<"Enter data for Root Node: ";
    int data;
    cin>>data;
    root= new TreeNode(data);
    q.push(root);
    while(!q.empty()){
        TreeNode* temp=q.front();
        q.pop();
        cout<<"Enter the leftNode data for Node "<<temp->data<< ": ";
        int x;
        cin>>x;
        if(x!=-1){
            temp->left= new TreeNode(x);
            q.push(temp->left);
        }
        cout<<"Enter the rightNode data for Node "<<temp->data<<": ";
        int y;
        cin>>y;
        if(y!=-1){
            temp->right= new TreeNode(y);
            q.push(temp->right);
        }
    }

}