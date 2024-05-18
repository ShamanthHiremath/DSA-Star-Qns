/*
🎯Problem Explanation:
You are given a root of binary tree with n nodes and each node have node.val coins. Sum of them of all tree is n. You want to return minimum number of steps to transfer coins so every node has exactly 1 coin.

📥Input:
root of the binary tree root
📤Output:
The minimum number of steps to transfer coins

🤔 Intuition
The first thing to think about is that our tree has exactly n coins so at the end every node will have exactly one coin. What does if mean? If we encounter any node with value not equal to 1 then we know for sure that we will need to transfer coins from there.
Okay, if we understand this concept then we need to think about how to traverse tree in such way that we transfer coins through every node. In fact, it doesn't matter which child we will visit first but we really want to visit parent only after we've calculated its children so we know do we need to get coins here from its parent and so on.
If node at this moment (after evaluating nodes children) have more than 1 coin, then we will transfer them to parent, if exactly 1, then we'll do nothing. If it has < 0 number of coins that means that its children doesn't have enough coins and we want to "get" them from parent node. (word "minimum" doesn't mean much because it just means that we just don't want to pass coins back and forth (so we need some "methodic" as described above)).
In fact, understanding this is enough to write solution to this problem, and if you understand this, congratulations, if not, then I’m waiting for any questions in the comments. I would also like to clarify that since we will move coins from children to parents, we want to pass in calling our function the parent of this node.
🧠 Approach
After understanding the intuition the recursive solution is quite easy.

We want to use postorder traversal as described above so we will write dfs function (but it will have auxiliary parameter parent to keep track of parent ot his node (to transfer coins)).
For every node the number of moves we want to return is calculated as moves for left subtree + moves for right subtreee + moves from this node to parent.
Number of coins to transfer is number of coins there after evaluating children - 1 but the number of moves it takes is absolute value of this number because as you remember child can have not enough coins and so number of coins will be < 0.
After evaluating the whole tree, roots value is 1. To keep code simple I pass to function dummy parent for root and this won't impact on result since number of moves added will be 1 - 1 = 0.
*/

class Solution {
public:
    int distributeCoins(TreeNode* root) {
        TreeNode dummy;
        return dfs(root, &dummy);
    }
    
private:
    int dfs(TreeNode* cur_node, TreeNode* parent) {
        if (cur_node == nullptr) {
            return 0;
        }
        int moves = dfs(cur_node->left, cur_node) + dfs(cur_node->right, cur_node);
        int from_this = cur_node->val - 1;
        parent->val += from_this;
        moves += abs(from_this);
        return moves;
    }
};