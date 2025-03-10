/*
1971. Find if Path Exists in Graph

https://leetcode.com/problems/find-if-path-exists-in-graph/

There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex source to vertex destination.

Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.

Example 1:
Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
Output: true
Explanation: There are two paths from vertex 0 to vertex 2:
- 0 → 1 → 2
- 0 → 2

Example 2:
Input: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5
Output: false
Explanation: There is no path from vertex 0 to vertex 5.


*/

// ONE POSSIBLE SOLUTION USING DFS

class Solution {
    public:
        bool dfsCheck(int node, int destination, vector<vector<int>>&adj, vector<bool>&visited){
            visited[node] = true;
    
            if(node == destination){
                return true;
            }
    
            for(int nbr: adj[node]){
                if(!visited[nbr]){
                    if (dfsCheck(nbr, destination, adj, visited)) {
                        return true;
                    }
                }
            }
    
            return false;
        }
    
        bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
            vector<vector<int>>adj(n);
    
            for(int i=0; i<edges.size(); i++){
                int u = edges[i][0];
                int v = edges[i][1];
    
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
    
            vector<bool>visited(adj.size());
    
            return dfsCheck(source, destination, adj, visited);
        }
};

// ANOTHER POSSIBLE SOLUTION USING UNION FIND

class Solution {
    public:
        int findParent(vector<int>&ulti_parent, int node){
            if(ulti_parent[node] == node){
                return node;
            }
            return ulti_parent[node] = findParent(ulti_parent, ulti_parent[node]);
        }
    
        void unionByHeight(vector<int>&ulti_parent, vector<int>&height, int u, int v){
            int ulp_u = findParent(ulti_parent, u);
            int ulp_v = findParent(ulti_parent, v);
    
            if(height[ulp_u] < height[ulp_v]){
                ulti_parent[ulp_u] = ulp_v; 
            }
            else if(height[ulp_v] < height[ulp_u]){
                ulti_parent[ulp_v] = ulp_u; 
            }
            else{
                ulti_parent[ulp_v] = ulp_u;
                height[ulp_u]++;
            }
    
    
        }
    
        bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
            vector<int>ulti_parent(n);
            vector<int>rank(n, 0);
    
            for(int i=0; i<n; i++){
                ulti_parent[i] = i;
            }
    
            for(auto edge: edges){
                unionByHeight(ulti_parent, rank, edge[0], edge[1]);
            }
    
            return findParent(ulti_parent, source) == findParent(ulti_parent, destination);
    
        }
    };