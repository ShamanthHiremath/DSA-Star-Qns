/*
1130. Minimum Cost Tree From Leaf Values

https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/

Given an array arr of positive integers, consider all binary trees such that:

Each node has either 0 or 2 children;
The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.
Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node. It is guaranteed this sum fits into a 32-bit integer.

A node is a leaf if and only if it has zero children.

Example 1:
Input: arr = [6,2,4]
Output: 32
Explanation: There are two possible trees shown.
The first has a non-leaf node sum 36, and the second has non-leaf node sum 32.

Example 2:
Input: arr = [4,11]
Output: 44
*/

class Solution {
public:
    int solveDP(int left, int right, vector<int>&arr, vector<vector<int>>&dp, map<pair<int, int>,int> &maxi){
        if(left>=right){
            return 0;
        }
        if (dp[left][right] != -1) {
            return dp[left][right];
        }
        int ans = INT_MAX;
        for(int k=left; k<right; k++){
            int max_it_left = maxi[{left,k}];
            int max_it_right = maxi[{k+1, right}];
            ans = min(ans, (max_it_left) * (max_it_right) + solveDP(left, k, arr, dp, maxi) + solveDP(k+1, right, arr, dp, maxi));
        }

        return dp[left][right] = ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();

        map<pair<int, int>,int>maxi;
        for(int i=0; i<n; i++){
            maxi[{i, i}] = arr[i];
            for(int j=i+1; j<n; j++){
                maxi[{i,j}] = max(maxi[{i,j-1}], arr[j]);
            }
        }
        
        vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
        return solveDP(0, n-1, arr, dp, maxi);
    }
};