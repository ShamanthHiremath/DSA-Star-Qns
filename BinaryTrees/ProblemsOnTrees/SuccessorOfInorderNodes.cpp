class Solution {
  public:
    Node* inOrder(Node* root, Node*& parent){
        if(root==NULL){
            return NULL;
        }
        Node* left = inOrder(root->left, parent);
        if(parent!=NULL){
            parent->next = root;
        }
        parent = root;
        Node* right = inOrder(root->right, parent);
        
    }
    
    void populateNext(Node *root) {
        // code here
        Node* parent = NULL;
        root = inOrder(root, parent);
    }
};