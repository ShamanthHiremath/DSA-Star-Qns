//Function to return a tree created from postorder and inorder traversals.

int findposition(int data, int in[], int inoStart, int n){
    for(int i=inoStart; i<n; i++){
        if(in[i]==data){
            return i;
        }
    }
    return -1;
}

Node* InOrderPostOrder(int in[], int pre[], int inoStart, int inoEnd, int& index, int n){
        if(index<0 || inoStart>inoEnd){
            return NULL;
        }
        
        int data=pre[index];
        index--;
        Node* root= new Node(data);
        int rootPosition = findposition(data, in, inoStart, n);
        
        root->right=InOrderPostOrder(in, pre, rootPosition+1, inoEnd, index, n);
        root->left=InOrderPostOrder(in, pre, inoStart, rootPosition-1, index, n);
        return root;
    }
    
Node *buildTree(int in[], int post[], int n) {
    int postorderindex=n-1;
    Node* root=InOrderPostOrder(in, post, 0, n-1, postorderindex, n);
    return root;
}