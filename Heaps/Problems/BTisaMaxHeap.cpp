class Solution {
  public:
  
    bool isCompleteBinaryTree(struct Node* root) {
        if (root == nullptr)
            return true;

        queue<struct Node*> q;
        q.push(root);

        bool endReached = false;

        while (!q.empty()) {
            struct Node* curr = q.front();
            q.pop();

            // If the end has been reached, all nodes from this point onwards must be leaf nodes
            if (endReached && (curr->left || curr->right)){
                return false;
            }

            if (curr->left) {
                if (endReached){
                    return false;
                }
                q.push(curr->left);
            }
            else {
                endReached = true;
            }

            if (curr->right) {
                if (endReached){
                    return false;
                }
                q.push(curr->right);
            }
            else {
                endReached = true;
            }
        }

        return true;
    }

    bool isMaxHeap(struct Node* root, int parent_value = INT_MAX) {
        if (root == nullptr)
            return true;

        if (root->data > parent_value)
            return false;

        return isMaxHeap(root->left, root->data) && isMaxHeap(root->right, root->data);
    }

    
    bool isHeap(struct Node* tree) {
        return isMaxHeap(tree) && isCompleteBinaryTree(tree);
    }
};