class Solution {
public:

    bool isCompleteBinaryTree(Node* root) {
        if (root == nullptr)
            return true;

        queue<Node*> q;
        q.push(root);

        bool endReached = false;

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            // If the end has been reached, all nodes from this point onwards must be leaf nodes
            if (endReached && (curr->left || curr->right))
                return false;

            if (curr->left) {
                if (endReached)
                    return false;
                q.push(curr->left);
            } else {
                endReached = true;
            }

            if (curr->right) {
                if (endReached)
                    return false;
                q.push(curr->right);
            } else {
                endReached = true;
            }
        }

        return true;
    }
};