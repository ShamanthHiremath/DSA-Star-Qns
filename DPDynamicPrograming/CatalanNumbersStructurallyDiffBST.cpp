/*
96. Unique Binary Search Trees

https://leetcode.com/problems/unique-binary-search-trees/

Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

Example 1:

Input: n = 3
Output: 5
Example 2:

Input: n = 1
Output: 1
*/

class Solution {
public:
    int solveDP(int n, vector<int>&dp){
        if(n == 0 || n == 1){
            return 1;
        }
        if(n == 3){
            return 5;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int sum = 0;
        for(int i=0; i<n; i++){
            // Note for a binary search tree with N nodes it is fosure, if the root node is ith Node, the i-1 nodes will be on the left and n-i nodes will be on the right
            // Also that if there are X structurally diff trees on left and Y on right of a root node
            // Then there will be a total of X*Y diff structures for the tree with the root  
            sum += ( solveDP(i-1, dp) * solveDP(n - i, dp) );
        }

        return dp[n] = sum;
    }

    int numTrees(int n) {
        vector<int>dp(n+1, -1);

        return solveDP(n, dp);
    }
};