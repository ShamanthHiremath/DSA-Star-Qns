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


class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj){
        int v = adj.size();
        vector<bool> visited(v, false);
        vector<int> parent(adj.size(), -1);
        for(int i = 0; i < v; i++){
            if(!visited[i]){
                if(dfsCycleCheck(i, adj, visited, parent)){
                    return true;
                }
            }
        }
        return false;
    }

  private:
    bool dfsCycleCheck(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>&parent) {
        
        visited[node] = true;

        for(int nbr: adj[node]){
            if(!visited[nbr]){
                parent[nbr] = node;
                bool ans = dfsCycleCheck(nbr, adj, visited, parent);
                if(ans){
                    return true;
                }
            }
            else if(visited[nbr] && parent[node]!=nbr){
                return true;
            }
        }
        return false;
    }
};