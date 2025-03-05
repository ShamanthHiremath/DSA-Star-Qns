
/*

APPROACH 1
An undirected graph is a tree if it has the following properties. 

There is no cycle. 
The graph is connected.
For an undirected graph, we can either use BFS or DFS to detect the above two properties.

How to detect cycles in an undirected graph? 
We can either use BFS or DFS. For every visited vertex ‘v’, if there is an adjacent ‘u’ such that u is already visited and u is not the parent of v, then there is a cycle in the graph. If we don’t find such an adjacent for any vertex, we say that there is no cycle (See Detect cycle in an undirected graph for more details).

How to check for connectivity? 
Since the graph is undirected, we can start BFS or DFS from any vertex and check if all vertices are reachable or not. If all vertices are reachable, then the graph is connected, otherwise not.

Approach 2:

However if we observe carefully the definition of tree and its structure we will deduce that if a graph is connected and has n – 1 edges exactly then the graph is a tree.

Proof: 

Since we have assumed our graph of n nodes to be connected, it must have at least n – 1 edges inside it. Now if we try to add one more edge than the n – 1 edges already the graph will end up forming a cycle and thus will not satisfy the definition of tree. Therefore, it is necessary for a connected graph to have exactly n – 1 edges to avoid forming cycle. 
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to check if the graph contains a cycle (DFS approach)
    bool isCyclicUtil(int v, vector<vector<int>>& adj, vector<bool>& visited, int parent) {
        visited[v] = true;
        
        for (int u : adj[v]) {
            if (!visited[u]) {
                if (isCyclicUtil(u, adj, visited, v)) 
                    return true;
            } 
            else if (u != parent) {
                return true; // If visited and not the parent, cycle detected
            }
        }
        return false;
    }

    // Function to check if the graph is connected (DFS approach)
    void dfsTraversal(int v, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[v] = true;
        for (int u : adj[v]) {
            if (!visited[u]) {
                dfsTraversal(u, adj, visited);
            }
        }
    }

    // Approach 1: Check if the graph is a tree using cycle detection and connectivity
    bool isTree_Approach1(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> visited(V, false);
        
        // Check if there is a cycle
        if (isCyclicUtil(0, adj, visited, -1)) return false;
        
        // Check if all vertices are reachable (i.e., graph is connected)
        for (int i = 0; i < V; i++) {
            if (!visited[i]) return false;
        }
        return true;
    }

    // Approach 2: Check if graph is a tree using the V-1 edges condition
    bool isTree_Approach2(int V, vector<vector<int>>& edges) {
        if (edges.size() != V - 1) return false; // A tree must have exactly V-1 edges
        
        vector<vector<int>> adj(V);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> visited(V, false);
        dfsTraversal(0, adj, visited);
        
        // Check if all vertices are reachable (graph is connected)
        for (int i = 0; i < V; i++) {
            if (!visited[i]) return false;
        }
        return true;
    }
};

// Driver Code
int main() {
    Solution obj;
    int V = 5;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {1, 4}}; 
    
    cout << "Using Approach 1: " << (obj.isTree_Approach1(V, edges) ? "Tree" : "Not a Tree") << endl;
    cout << "Using Approach 2: " << (obj.isTree_Approach2(V, edges) ? "Tree" : "Not a Tree") << endl;
    
    return 0;
}
