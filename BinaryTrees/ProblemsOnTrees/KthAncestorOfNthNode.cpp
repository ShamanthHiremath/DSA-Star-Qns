

void createMapping(map<int, Node*> &parent, Node* root){
    if(root==NULL){
        return;
    }
    if(root->left){
        parent[root->left->data]=root;
        createMapping(parent, root->left);
    }
    if(root->right){
        parent[root->right->data]=root;
        createMapping(parent, root->right);
    }
}

int kthAncestor(Node *root, int k, int node)
{
    if(root == NULL){
        return -1; // Indicate that the node doesn't exist
    }
    
    map<int, Node*> parent;
    createMapping(parent, root); // Create parent mapping
    
    Node* ans = parent[node];
    int i = 1; // Start from 1 since ans is already set to parent[node]
    while(ans != NULL && i != k){
        ans = parent[ans->data]; // Update ans to its parent node
        i++;
    }
    if (i != k || ans == NULL) {
        return -1; // Indicate that the kth ancestor doesn't exist
    }
    return ans->data;
}

//COMPLEX RECURSION
Node* solve(Node* root, int &k, int node){
    if(root==NULL){
        return NULL;
    }
    if(root->data==node){
        return root;
    }
    Node* left=solve(root->left, k, node);
    Node* right= solve(root->right, k, node);
    
    if(left!=NULL && right==NULL){
        k--;
        if(k<=0){
            //FOR LOCKING THAT ROOT VALUE
            k=INT_MAX;
            return root;
        }
        return left;
    }
    
    if(left==NULL && right!=NULL){
        k--;
        if(k<=0){
            //FOR LOCKING THAT ROOT VALUE
            k=INT_MAX;
            return root;
        }
        return right;
    }
    return NULL;
}

int kthAncestor(Node *root, int k, int node)
{
    Node* ans=solve(root, k, node);
    if(ans == NULL || ans->data==node){
        return -1; // Indicate that the node doesn't exist
    }
    return ans->data;
    
    
}