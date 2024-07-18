/*
1530. Number of Good Leaf Nodes Pairs

https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/

You are given the root of a binary tree and an integer distance. A pair of two different leaf nodes of a binary tree is said to be good if the length of the shortest path between them is less than or equal to distance.
Return the number of good leaf node pairs in the tree.

Input: root = [1,2,3,null,4], distance = 3
Output: 1
Explanation: The leaf nodes of the tree are 3 and 4 and the length of the shortest path between them is 3. This is the only good pair.

Input: root = [1,2,3,4,5,6,7], distance = 3
Output: 2
Explanation: The good pairs are [4,5] and [6,7] with shortest path = 2. The pair [4,6] is not good because the length of ther shortest path between them is 4.

*/
class Solution {
public:
    vector<int> dfs(TreeNode* root, int dist, int& cnt) {
        if (root == NULL) {
            return {};
        }
        
        if (!root->left && !root->right) {
            return {1};  // Leaf node, return distance 1
        }
        
        vector<int> left = dfs(root->left, dist, cnt);
        vector<int> right = dfs(root->right, dist, cnt);
        
        // Count pairs
        for (int l : left) {
            for (int r : right) {
                if (l + r <= dist) {
                    cnt++;
                }
            }
        }
        
        // Prepare distances for parent
        vector<int> result;
        for (int l : left) {
            if (l < dist) result.push_back(l + 1);
        }
        for (int r : right) {
            if (r < dist) result.push_back(r + 1);
        }
        
        return result;
    }
    
    int countPairs(TreeNode* root, int distance) {
        int count = 0;
        dfs(root, distance, count);
        return count;
    }
};

// class Solution {
// public:
//     void dfs(TreeNode* root, int dist, int& cnt, int& path, bool& first){
//         if(root==NULL){
//             return;
//         }
        
//         dfs(root->left, dist, cnt, path, first);
//         if(path != -1){
//             path++;
//         }
//         cout<<path<<"   ";
//         dfs(root->right, dist, cnt, path, first);
        
//         //leaf node
//         if(!root->left && !root->right){
//             first = !first;
//             if(first){
//                 cnt++;
//                 path = 0;
//             }
//             else if(path<=dist){
//                 cnt++;
//             }
//             else if(path> dist){
//                 first != first;
//                 path = -1;
//             }
//             return;
//         }

        

//     } 
//     int countPairs(TreeNode* root, int distance) {
//         int count = 0;
//         bool first = false;
//         int path = -1;
//         dfs(root, distance, count, path, first);

//         return count/2;
//     }
// };