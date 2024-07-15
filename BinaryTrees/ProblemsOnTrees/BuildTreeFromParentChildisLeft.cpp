/*
2196. Create Binary Tree From Descriptions

https://leetcode.com/problems/create-binary-tree-from-descriptions/

You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti] indicates that parenti is the parent of childi in a binary tree of unique values. Furthermore,

If isLefti == 1, then childi is the left child of parenti.
If isLefti == 0, then childi is the right child of parenti.
Construct the binary tree described by descriptions and return its root.
*/

class Solution {
public:
    TreeNode* solve(int rootData, unordered_map<int, pair<int, int>>& childof) {
        if (rootData == -1) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(rootData);
        if (childof.find(rootData) != childof.end()) {
            root->left = solve(childof[rootData].first, childof);
            root->right = solve(childof[rootData].second, childof);
        }
        return root;
    }

    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, pair<int, int>> childof;
        unordered_map<int, bool> isChild;

        for (const auto& desc : descriptions) {
            int parent = desc[0];
            int childnode = desc[1];
            int isLeft = desc[2];

            if (childof.find(parent) == childof.end()) {
                childof[parent] = { -1, -1 };
            }
            if (isLeft) {
                childof[parent].first = childnode;
            }
            else {
                childof[parent].second = childnode;
            }
            isChild[childnode] = true;
        }

        // Finding the root node the only one without parent
        int rootData = 0;
        for (const auto& desc : descriptions) {
            if (isChild.find(desc[0]) == isChild.end()) {
                rootData = desc[0];
                break;
            }
        }

        return solve(rootData, childof);
    }
};