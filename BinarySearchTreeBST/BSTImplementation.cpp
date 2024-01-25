#include<bits/stdc++.h>

// #include<iostream>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int num){
        this->data=num;
        this->left=NULL;
        this->right=NULL;
    }
};

//Fn for inserting values in a BST
//O(log n)
TreeNode* insert(TreeNode* &root, int x) {
    if (root == NULL) {
        root= new TreeNode(x);
        return root;
    }
    if(x<root->data){
        root->left=insert(root->left, x);
    }
    else{
        root->right=insert(root->right, x);
    }

    
    return root;
}

//Starts building the tree
void buildTree(TreeNode* &root) {
    cout<<"Enter the data: ";
    int value ;
    cin>>value;
    while(value!=-1){
        root = insert(root, value);
        cout<<"Enter the data: ";
        cin>>value;
    }
}

//searchInBST
bool searchRecursive(TreeNode* node, int value) {
    if (node == nullptr) {
        return false;
    }
    if (value == node->data) {
        return true;
    } else if (value < node->data) {
        return searchRecursive(node->left, value);
    } else {
        return searchRecursive(node->right, value);
    }
}

//Traversal
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

//INORDER gives the traversal in SORTED MANNER

// LNR is In Order Traversal
void inOrderTraversal(TreeNode* root){
    if(root==NULL){
        return ;
    }
    //got to the leftmost node
    inOrderTraversal(root->left);
    //print the leftmost node
    cout<<root->data<<" ";
    //check LNR condition
    inOrderTraversal(root->right);
}

//To help find the min node in a tree/subtree
TreeNode* minNode(TreeNode* root){
    TreeNode* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}
//To help find the max node in a tree/subtree
TreeNode* maxNode(TreeNode* root){
    TreeNode* temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}
//Most asked  in Interviews
//delete a node with val x
// Delete a node with val x
TreeNode* deleteNode(TreeNode *root, int x) {
    if (root == NULL) {
        return root;
    }
    if(x < root->data) {
        root->left = deleteNode(root->left, x);
    }
    else if (x > root->data) {
        root->right = deleteNode(root->right, x);
    }
     else{
        //leaf node
        if(root->left==NULL && root->right==NULL){
            delete(root);
            return NULL;
        }
        //Only Left Node
        if(root->right==NULL && root->left!=NULL){
            TreeNode* temp=root->left;
            delete(root);
            return temp;
        }
        //Only right Node
        if(root->left==NULL && root->right!=NULL){
            TreeNode* temp=root->right;
            delete(root);
            return temp;
        }
        //Both nodes are present
        //if(root->left!=NULL && root->right!=NULL){
            TreeNode* temp = minNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
            /*
            TreeNode* temp = maxNode(root->left);
            root->data = temp->data;
            root->left = deleteNode(root->left, temp->data);
            */
           
        }
        return root;
}




int main(){
    TreeNode* root=NULL;
    buildTree(root);
    cout<<endl;
    root=insert(root, 4);
    QLevelOrderTraversal(root);
    inOrderTraversal(root);
    root=deleteNode(root, 4);
    cout<<endl;
    inOrderTraversal(root);

 return 0;
}