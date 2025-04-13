/*


*/

class Solution
{
    public:
    void flatten(Node *root)
    {
        Node* current=root;
        while(current!=NULL){
            //if cuurent->left exists
            if(current->left){
                //Find the INORDER PREDECESSOR
                Node* pred=current->left;
                while(pred->right!=NULL){
                    pred=pred->right;
                }
                //connect pred's right and current's right
                pred->right=current->right;
                //connect the right of current to its left child
                //this eliminates double pointerism and flattens it
                current->right=current->left;
            }
            //move to the right part
            current=current->right;
        }
        
        //since there are two ptrs left and right
        //NULL all the left ptrs
        current=root;
        while(current){
            current->left=NULL;
            current=current->right;
        }
    }
};