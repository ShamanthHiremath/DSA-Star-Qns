/*
M-Coloring Problem

https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

You are given an undirected graph consisting of V vertices and E edges represented by a list edges[][], along with an integer m. Your task is to determine whether it is possible to color the graph using at most m different colors such that no two adjacent vertices share the same color. Return true if the graph can be colored with at most m colors, otherwise return false.

Note: The graph is indexed with 0-based indexing.

Examples:

Input: V = 4, edges[][] = [[0, 1], [1, 3], [2, 3], [3, 0], [0, 2]], m = 3
Output: true
Explanation: It is possible to color the given graph using 3 colors, for example, one of the possible ways vertices can be colored as follows:

Vertex 0: Color 1
Vertex 1: Color 2
Vertex 2: Color 2
Vertex 3: Color 3


Input: V = 3, edges[][] = [[0, 1], [1, 2], [0, 2]], m = 2
Output: false
Explanation: It is not possible to color the given graph using only 2 colors because vertices 0, 1, and 2 form a triangle.
*/

class Solution {
  public:
    bool isColorable(int node, int clr, unordered_map<int, vector<int>>&adj, vector<int>&color){
        for(int nbr: adj[node]){
            if(color[nbr] == clr){
                return false;
            }
        }
        
        return true;
    }
    
    bool dfs(int node, int v, int m, unordered_map<int, vector<int>>&adj, vector<int>&color){
    
        
        if(node == v){
            return true;
        }
        
        // try out all coloring numbers
        for(int i=1; i<=m; i++){
            // coloring with i
            if(isColorable(node, i, adj, color)){
                color[node] = i;
                if(dfs(node+1, v, m, adj, color)){
                    return true;
                }
            // backtracking for other colors
                color[node] = 0;
            }    
        }
        
        return false;
        
        
    }
    
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        unordered_map<int, vector<int>>adj;
        for(auto &edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int>color(v, 0);
        
        return dfs(0, v, m, adj, color);
        
    }
};