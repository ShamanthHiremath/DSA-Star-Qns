#include<bits/stdc++.h>

bool isCycleDFS(int parent, int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> adj ){
    visited[node]=1;
    for(auto  neighbor: adj[node]){
        if(!visited[neighbor]){
            bool ans=isCycleDFS(node, neighbor, visited, adj);
            if(ans){
                //cycle is present
                return true;
            }
        }
        else if(visited[neighbor]==1 && parent!=neighbor){
            //cycle is present
            return true;
        }
    }
    return false;

}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    //create adjacency list
    unordered_map<int, list<int>> adj;
    for(int i=0; i<edges.size(); i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //for handling cases of disconnected graphs
    unordered_map<int, bool>visited;
    // vector<int>visited(n, 0); doesnt do good for large test cases
    for(int i=0; i<n; ++i){
        if(!visited[i]){
            bool ans=isCycleDFS(-1, i, visited, adj);
            if(ans){
                return "Yes";
            }
        }
    }
    return "No";
}