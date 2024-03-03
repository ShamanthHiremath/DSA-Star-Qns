/*
go from the root...
to all the left tree and print the leftmost side nodes
untill the leaf node
then traverse all leaf nodes
then traverse the rightmost side nodes from bottom to the root and stop
*/

class Solution {
public:
    void leftB(vector<int>& ans, Node* root) {
        if (!root)
            return;
        if (root->left) {
            ans.push_back(root->data);
            leftB(ans, root->left);
        }
        else if (root->right) {
            ans.push_back(root->data);
            leftB(ans, root->right);
        }
    }

    void leafNode(vector<int>& ans, Node* root) {
        if (!root)
            return;
        if (!root->left && !root->right) {
            ans.push_back(root->data);
            return;
        }
        if (root->left)
            leafNode(ans, root->left);
        if (root->right)
            leafNode(ans, root->right);
    }

    void rightB(vector<int>& ans, Node* root) {
        if (!root)
            return;
        if (!root->left && !root->right) {
            //ans.push_back(root->data);
            return;
        }
        if (root->right)
            rightB(ans, root->right);
        else if (root->left)
            rightB(ans, root->left);
        ans.push_back(root->data);
    }

    vector<int> boundary(Node* root) {
        vector<int> ans;
        if (!root)
            return ans;
        ans.push_back(root->data);
        if (root->left)
            leftB(ans, root->left);
        if(!root->left && !root->right){
            return ans;
        }
        leafNode(ans, root);
        if (root->right)
            rightB(ans, root->right);
        return ans;
    }
};