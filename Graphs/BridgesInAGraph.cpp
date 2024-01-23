/*
A bridge in any graph is defined as an edge which, when removed, makes the graph disconnected (or more precisely, increases the number of connected components in the graph).
*/
#include<bits/stdc++.h>

void dfssolve(int node, int &timer, unordered_map<int, list<int>> &adj, vector<int>& disctime,
              vector<int>& lowtime, int &parent, unordered_map<int, bool>& visited, vector<vector<int>>& result) {
    // Mark the current node as visited
    visited[node] = true;

    // Initialize discovery time and low time for the current node
    disctime[node] = lowtime[node] = timer++;

    // Iterate through the neighbors of the current node
    for (auto nbr : adj[node]) {
        // Skip the neighbor if it is the parent of the current node
        if (nbr == parent) {
            continue;
        }

        // If the neighbor is not visited, recursively visit it
        if (!visited[nbr]) {
            dfssolve(nbr, timer, adj, disctime, lowtime, node, visited, result);

            // Update the low time of the current node based on the low time of the neighbor
            // Because there might be a back edge for its neighbors and hence cheeck if there is a better low time and update 
            lowtime[node] = min(lowtime[node], lowtime[nbr]);

            // Check if there is a bridge edge
            if (lowtime[nbr] > disctime[node]) {
                // Edge found between node and nbr that can act as a bridge
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        } 
        // If the neighbor is already visited, update the low time of the current node
        else {
            lowtime[node] = min(lowtime[node], disctime[nbr]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Create an adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Requisite data structures
    int timer = 0;
    vector<int> disctime(v, -1);  // Discovery time for each node
    vector<int> lowtime(v, -1);   // Low time for each node
    int parent = -1;              // Parent of the current node during DFS
    unordered_map<int, bool> visited;  // Keep track of visited nodes
    
    vector<vector<int>> result;  // Store the bridges

    // Start DFS process
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            dfssolve(i, timer, adj, disctime, lowtime, parent, visited, result);
        }
    }

    return result;
}
