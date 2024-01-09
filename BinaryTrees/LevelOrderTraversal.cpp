void printGivenLevel(TreeNode* root, int level){
    if(root==NULL){
        return;
    }
    if(level==1){
        cout<<root->data<<" ";
    }
    else if (level>1){
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}
int getHeight(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    int leftheight=getHeight(root->left);
    int rightheight=getHeight(root->right);
    if(leftheight>rightheight){
        return leftheight+1;
    }
    else{
        return rightheight+1;
    }
}

void LevelOrderTraversal(TreeNode* root){
    if(root==NULL){
        return;
    }

    int height=getHeight(root);
    for(int i=1; i<=height; ++i){
        //print given nodes at current level
        printGivenLevel(root, i);
        cout<<endl;
    }
}

void QLevelOrderTraversal(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        TreeNode* curr=q.front();
        q.pop();
        if(curr==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<curr->data<<" ";
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
    }
}