/*
Recursive Soln
*/


class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
        if(root==NULL){
            return NULL;
        }
        // If either of the nodes is found, return the node itself
        if(root->data==n1 || root->data==n2){
            return root;
        }
        
        Node* left=lca(root->left, n1, n2);
        Node* right=lca(root->right, n1, n2);
        
        //answer found
        // If both nodes lie in the left and right subtrees,
        // then the current node is the LCA
        if(left!=NULL && right!=NULL){
            return root;
        }
         // Otherwise, return the non-null LCA (if found) from left or right subtree
        else if(left!=NULL && right==NULL){
            return left;
        }
        else{
            return right;
        }
        
    }
};



//TIME CONSUMING but works
/*
MAPPING Soln O(N)
*/
class Solution
{
    public:
    
    void createMapping(map<int, Node*> &parent, Node* root){
        if(root==NULL){
            return;
        }
        if(root->left){
            parent[root->data]=root;
            createMapping(parent, root->left);
        }
        if(root->right){
            parent[root->data]=root;
            createMapping(parent, root->right);
        }
    }
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
        if(root==NULL){
            return NULL;
        }
        map<int, Node*> parent;
        parent[root->data]=NULL;
        createMapping(parent, root);
        // Node* lca;
        Node* n1parent=parent[n1];
        Node* n2parent=parent[n2];
        while(n1parent!=n2parent && n1parent!=NULL && n2parent!=NULL){
            n1parent=parent[n1parent->data];
            n2parent=parent[n2parent->data];            
        }
        if(n1parent!=NULL && n2parent!=NULL){
            return n1parent;
        }
        else{
            return root;
        }
    }
};