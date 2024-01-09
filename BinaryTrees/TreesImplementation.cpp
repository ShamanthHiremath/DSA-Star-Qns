/*
Node:

A node is a fundamental building block of a binary tree. It contains data and may have links (pointers or references) to zero, one, or two child nodes.
Root:

The root is the topmost node in a binary tree. It serves as the starting point for traversing the tree. Every binary tree has exactly one root node.
Child:

In a binary tree, a child is a node that is directly connected to another node (its parent) below it. A node can have zero, one, or two children.
Parent:

A parent is a node that has one or more child nodes directly connected below it. A node with a child is considered the parent of that child.
Ancestors:

An ancestor of a node is any node on the path from the root to that node. All nodes on the path from the root to a particular node, excluding the node itself, are its ancestors.
Descendants:

A descendant of a node is any node in the subtree rooted at that node. All nodes in the subtree rooted at a particular node, excluding the node itself, are its descendants.
Leaf:

A leaf (or terminal node) is a node in a binary tree that has no children. In other words, it is a node with a degree of 0, meaning it has no outgoing edges.
Siblings:

Siblings are nodes in a binary tree that share the same parent. If two nodes have the same parent, they are considered siblings. In a binary tree, a parent node can have zero, one, or two children, and any two children of the same parent are siblings.
*/

#include<bits/stdc++.h>
// #include<iostream>
using namespace std;

class TreeNode{
    public:
        int data; 
        TreeNode* left;
        TreeNode* right;
        TreeNode(int num){
            data=num;
            this->left=NULL;
            this->right=NULL;
        }
};

TreeNode* buildTree(TreeNode* root){
    cout<<"Enter the data: ";
    int x;
    cin>>x;
    if(x==-1){
        return NULL;
    }
    root=new TreeNode(x);
    cout<<"Inserting in the left side of data "<<x<<endl;
    root->left=buildTree(root->left);
    cout<<"Inserting in the right side of data "<<x<<endl;
    root->right=buildTree(root->right);
    return root;
}

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
int main(){
    TreeNode* root=NULL;
    root=buildTree(root);
    //1 2 4 -1 -1 3 5 -1 -1 6 -1 -1 -1
    //      1
    //   2    3
    // 4  5  6 -1
    //end

    //  INPUTS 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 -1

    root=buildTreeFromLevelOrder(root);
    //give inputs as levels
    return 0;
}