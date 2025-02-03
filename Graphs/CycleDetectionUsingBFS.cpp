class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj){
        int v = adj.size();
        vector<bool> visited(v, false);
        for(int i = 0; i < v; i++){
            if(!visited[i]){
                if(bfsCycleCheck(i, adj, visited)){
                    return true;
                }
            }
        }
        return false;
    }

  private:
    bool bfsCycleCheck(int start, vector<vector<int>>& adj, vector<bool>& visited) {
        vector<int> parent(adj.size(), -1);
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int nbr : adj[node]){
                if(!visited[nbr]){
                    visited[nbr] = true;
                    q.push(nbr);
                    parent[nbr] = node;
                }
                else if(parent[node] != nbr){
                    return true;
                }
            }
        }
        return false;
    }
};

#include<bits/stdc++.h>
bool hasCycle(int src, unordered_map<int, bool> &visited , unordered_map<int, list<int> > &adj){
    unordered_map<int, int> childparent;
    //MAPS AS CHILD -> PARENT
    //KEY IS CHILD AND PARENT IS VALUE, because multiple nodes(keys) can have one Parent(value)
    childparent[src]=-1;
    visited[src]=1;
    queue<int>q;
    q.push(src);
    while(!q.empty()){
        int frontnode= q.front();
        q.pop();
        //i is actually the neighbours or adjacent nodes of that very node
        for(auto i: adj[frontnode]){
            //MAIN IMPORTANT CONDITION FOR CYCLE DETECTION
            if(visited[i]==1 && i!= childparent[frontnode]){
                return true;
            }
            else if(!visited[i]){
                q.push(i);
                visited[i]=1;
                childparent[i]=frontnode;
            }
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
            bool ans=hasCycle(i, visited, adj);
            if(ans){
                return "Yes";
            }
        }
    }
    return "No";
}
