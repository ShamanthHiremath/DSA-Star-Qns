/*
Morris Traversal of a Binary Tree: INORDER TRAVERSAL 

https://takeuforward.org/data-structure/morris-inorder-traversal-of-a-binary-tree/

Threaded Binary Tree :
Basically a node's (say X) left child's rightmost value, i.e the node's maximum most value has INORDER PREDECESSOR as the current node (X)
And a node's (say X) right child's leftmost value, i.e the node's minimum most value has INORDER SUCCESSOR  as the current node (X)

This helps us to avoid any recursions or use extra space when doing traversals. Bcuz the connection is already established.

Morris Traversal uses the concept of Threaded Binary Tree (Find a leaf node and connect its left child to the INORDER PREDECESSOR and the right child to its INORDER SUCCESSOR)
It only connects a node's (say X) right child's leftmost value, i.e the node's minimum most value has INORDER PREDECESSOR as the current node (X)

*/

void MorrisTraversal(Node* root){

    if(root==NULL){
        cout<<"KHAALI TREE HAIN LOUDE";
        return ;
    }
    Node* current=root;
    while(current!=NULL){
        if(current->left==NULL){
            cout<<current->data<<" ";
            current=current->right;
        }
        else{
            //Find the rightmost value of current node's left child
            // (OR)
            // Find the inorder predecessor of current 
            Node* predecessor= current->left;
            //if the right child is non null and it aint pointing to current
            while(predecessor->right!=NULL && predecessor->right!=current){
                predecessor=predecessor->right;
            }
            //If its a leaf node and there's no connection
            //Make current as the right child of its inorder predecessor
            if(predecessor->right==NULL){
                //Form a Temporary thread
                predecessor->right=current;
                //go to the left subtree of current
                current=current->left;
            }
            //Remove the existing thread
            else{
                predecessor->right=NULL;
                cout<<current->data<<" ";
                //cuz its already visited/traversed
                current=current->right;
            }
        }
    }
}