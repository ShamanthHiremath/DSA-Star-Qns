#include <bits/stdc++.h>

using namespace std;

// In this version, I've replaced the set with a priority_queue, which allows for efficient retrieval of the minimum distance node.
/*
In the context of the priority queue declaration priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;, let's break down each part:

pair<int, int>: This specifies the type of elements that the priority queue will store. Each element is a pair of integers.

vector<pair<int, int>>: This specifies the underlying container used by the priority queue. In this case, it's a vector holding pairs of integers. The elements in the vector will be managed in a way that maintains the priority queue property.

greater<pair<int, int>>: This is a comparison function that determines the order of elements in the priority queue. The greater function ensures that the smallest element comes to the top of the priority queue. For pairs, it compares based on the first element, and if there is a tie, it uses the second element for comparison.
*/
//The comparison function greater<pair<int, int>> ensures that the priority queue always gives the smallest distance node at the top.//

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Create adjacency list with Vertices and their weights/distances
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < edges; i++) {
        int u = vec[i][0];
        int v = vec[i][1];
        int d = vec[i][2];
        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }

    // Vector to store distances from the source node
    vector<int> dist(vertices, INT_MAX);
    dist[source] = 0;

    // Priority queue to keep track of the minimum distance nodes
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        // Extract the node with the minimum distance from the priority queue
        int u = pq.top().second;
        int dist_u = pq.top().first;
        pq.pop();

        // Traverse neighbors/adj nodes
        for (auto i : adj[u]) {
            int v = i.first;
            int weight_uv = i.second;

            // Relaxation step
            if (dist[v] > dist_u + weight_uv) {
                // Update distance
                dist[v] = dist_u + weight_uv;
                // Insert the newly updated pair into the priority queue
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}
