/*
n = 8
in[] = {4, 8, 2, 5, 1, 6, 3, 7}
post[] = {8, 4, 5, 2, 6, 7, 3, 1}
Output: 
1 2 4 8 5 3 6 7
Explanation: 
For the given postorder and inorder traversal of tree the  resultant binary tree will be
          1
       /      \
     2        3
   /  \      /  \
  4   5    6   7
   \
    8


    CAREFULLY OBSERVE THE POSITION INDEXES OF POST-ORDER AND IN-ORDER WHEN U FIND THEROOT AND SEPARATE ARRAYS BASED ON ROOT NODE
*/

class Solution
{
    public:
    Node* buildTreeHelper(int in[], int post[], int inStart, int inEnd, int postStart, int postEnd, unordered_map<int, int>& mp) {
        if (inStart > inEnd || postStart > postEnd)
            return NULL;
    
        int rootVal = post[postEnd];
        Node* root = new Node(rootVal);
    
        int rootIndexInInorder = mp[rootVal]; // Find the index of the root in inorder array
    
        // Calculate the size of left subtree
        int leftSubtreeSize = rootIndexInInorder - inStart;
    
        // Recursively build left and right subtrees
        root->left = buildTreeHelper(in, post, inStart, rootIndexInInorder - 1, postStart, postStart + leftSubtreeSize - 1, mp);
        root->right = buildTreeHelper(in, post, rootIndexInInorder + 1, inEnd, postStart + leftSubtreeSize, postEnd - 1, mp);
    
        return root;
    }   

    //Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int in[], int post[], int n) {
        if(n==1){
            Node* root = new Node(in[0]);
            return root;
        }
        unordered_map<int, int> mp;
        for(int i=0; i<n ; i++){
            mp[in[i]] = i;
        }
        return buildTreeHelper(in, post, 0, n - 1, 0, n - 1, mp);
        
    }
};