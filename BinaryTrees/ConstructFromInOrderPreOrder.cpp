//Function to return a tree created from preorder and inorder traversals.

class Solution{
    public:
    int findposition(int data, int in[], int inoStart, int n){
        for(int i=inoStart; i<n; i++){
            if(in[i]==data){
                return i;
            }
        }
        return -1;
    }
    
    Node* InOrderPreOrder(int in[], int pre[], int inoStart, int inoEnd, int& index, int n){
        if(index>=n || inoStart>inoEnd){
            return NULL;
        }
        
        int data=pre[index];
        index++;
        Node* root= new Node(data);
        int rootPosition = findposition(data, in, inoStart, n);
        
        root->left=InOrderPreOrder(in, pre, inoStart, rootPosition-1, index, n);
        root->right=InOrderPreOrder(in, pre, rootPosition+1, inoEnd, index, n);
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        int preorderindex=0;
        Node* root=InOrderPreOrder(in, pre, 0, n-1, preorderindex, n);
        return root;
    }
};