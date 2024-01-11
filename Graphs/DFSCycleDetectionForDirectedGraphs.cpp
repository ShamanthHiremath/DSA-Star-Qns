#include<bits/stdc++.h>
bool hasCycleDFS(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, unordered_map<int, bool>&dfsvisited, int node ){
  visited[node]=1;
  dfsvisited[node]=1;
  for(auto neighbor: adj[node]){
    if(!visited[neighbor]){
      bool cycleDetected= hasCycleDFS(adj, visited, dfsvisited, neighbor);
      if(cycleDetected){
        return true;
      }
    }
    //MAIN IMPORTANT LOGIC
    else if( visited[neighbor] && dfsvisited[neighbor]==1){
      return true;
    }
  }
  //mark the returned dfs fn node as false/ unvisited before returning
  dfsvisited[node]=0;
  return false;

}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges){

  //create adjacency list
  unordered_map<int, list<int>> adj;
  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i].first;
    int v=edges[i].second;
    adj[u].push_back(v);
    // adj[v].push_back(u);
  }
  //keeps track of the visited nodes
  unordered_map<int, bool>visited;
  //MUST NEEDED  DS
  //keeps track of the function calls of dfs and if a fn is returned back makes it as 0 and if present marks it as 1
  unordered_map<int, bool>dfsvisited;

  for(int i=0; i<=n; i++){
    if(!visited[i]){
      if(hasCycleDFS(adj, visited, dfsvisited, i )){
        return true;
      }
    }
  }
  return false;

}