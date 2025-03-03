/*
Cycle in a Directed Graph

https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
The graph is represented as an adjacency list, where adj[i] contains a list of vertices that are directly reachable from vertex i. Specifically, adj[i][j] represents an edge from vertex i to vertex j.

Example 1:
Input:
V = 2
adj = {{1},{0}}
Output: 1
Explanation: The graph contains a cycle.

*/

class Solution {
    public:
      bool dfsCycle(vector<bool>&visited, vector<vector<int>>&adj, vector<bool>&dfsVisited, int node){
          
          visited[node]=true;
          // This indicates that the node is part of the current path of the Depth-First Search (DFS).
          dfsVisited[node] = true;
          //do the same for all the neighbour/adjacent nodes for the NODE in adj[node]
          for(auto nbr: adj[node]){
              if(!visited[nbr]){
                  if(dfsCycle(visited, adj, dfsVisited, nbr)){
                      return true;
                  }
              }
              // As we continue to explore the neighbors of the node,
              // we check if any of these neighbors are already marked as true in dfsVisited.
              // If we find such a neighbor, it means we have encountered a node that is already in the current path, indicating a cycle.
              else if (visited[nbr] && dfsVisited[nbr]){
                  return true;   
              }
          }
          // mark it as false in dfsVisited to indicate that we are no longer considering this node as part of the current path.
          dfsVisited[node] = false;
          return false;
      }
    
      // Function to detect cycle in a directed graph.
      bool isCyclic(int V, vector<vector<int>> adj) {
          // code here
          vector<bool>visited(adj.size(), false);
          vector<bool>dfsVisited(adj.size(), false);
  
          for(int i=0; i<adj.size(); i++){
              if(!visited[i]){
                  if(dfsCycle(visited, adj, dfsVisited, i)){
                      return true;
                  }
              }
          }
          
          return false;
          
          
          
      }
  };
  
  
  class Solution {
      private: 
          bool DAGCycleCheckDFS(vector<int>&state, vector<vector<int>>&adj, int node){
              // cycle detected
              if(state[node]==1){
                  return true;
              }
              //processed and into the topo order
              if(state[node]==2){
                  return false;
              }
              // Mark the node as visiting (part of the current DFS stack)
              state[node]=1;
              //do the same for all the neighbour/adjacent nodes for the NODE in adj[node]
              for(auto i: adj[node]){
                
                  //recursion for every element in adj[node]
                  if(DAGCycleCheckDFS(state, adj, i)){
                      return true;
                  }
              }
              //IMPORTANT PART IF state IS TRUE
              // Mark the node as fully processed
              state[node]=2;
      
              return false;
          }
      
      public:
          vector<int> DAGhasCycle(vector<vector<int>>& graph) {
              int n=graph.size();
              vector<int>state(n, 0); // 0: unvisited, 1: visiting, 2: safe/processed.
              vector<int>safe;
      
              for(int i=0; i<n; i++){
                  if(DAGCycleCheckDFS(state, graph, i)){
                      return true;
                  }
              }
              return false;
          }
      };