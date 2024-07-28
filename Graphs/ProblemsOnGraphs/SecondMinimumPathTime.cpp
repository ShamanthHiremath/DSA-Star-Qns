/*
2045. Second Minimum Time to Reach Destination

https://leetcode.com/problems/second-minimum-time-to-reach-destination/

A city is represented as a bi-directional connected graph with n vertices where each vertex is labeled from 1 to n (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself. The time taken to traverse any edge is time minutes.

Each vertex has a traffic signal which changes its color from green to red and vice versa every change minutes. All signals change at the same time. You can enter a vertex at any time, but can leave a vertex only when the signal is green. You cannot wait at a vertex if the signal is green.

The second minimum value is defined as the smallest value strictly larger than the minimum value.

For example the second minimum value of [2, 3, 4] is 3, and the second minimum value of [2, 2, 4] is 4.
Given n, edges, time, and change, return the second minimum time it will take to go from vertex 1 to vertex n.

Notes:

You can go through any vertex any number of times, including 1 and n.
You can assume that when the journey starts, all signals have just turned green.

Example 1:
       
Input: n = 5, edges = [[1,2],[1,3],[1,4],[3,4],[4,5]], time = 3, change = 5
Output: 13
Explanation:
The figure on the left shows the given graph.
The blue path in the figure on the right is the minimum time path.
The time taken is:
- Start at 1, time elapsed=0
- 1 -> 4: 3 minutes, time elapsed=3
- 4 -> 5: 3 minutes, time elapsed=6
Hence the minimum time needed is 6 minutes.

The red path shows the path to get the second minimum time.
- Start at 1, time elapsed=0
- 1 -> 3: 3 minutes, time elapsed=3
- 3 -> 4: 3 minutes, time elapsed=6
- Wait at 4 for 4 minutes, time elapsed=10
- 4 -> 5: 3 minutes, time elapsed=13
Hence the second minimum time is 13 minutes.

Example 2:

Input: n = 2, edges = [[1,2]], time = 3, change = 2
Output: 11
Explanation:
The minimum time path is 1 -> 2 with time = 3 minutes.
The second minimum time path is 1 -> 2 -> 1 -> 2 with time = 11 minutes.
*/

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        // to store the all path ans from vertex 1 to n
        vector<int>ans;
        // total
        int totaltime = 0;
        // traffic light changes every change minutes
        // traffic light is red when totaltime % change == 1, so when u arrive between the
        // multiple and the even multiples of change...ex: change is 3, so u arrive at a vertex
        // between 3-5 ull have to wait at a traffic signal, untill green

        unordered_map<int, list<int>> adj;
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        // Dijkstra's algorithm
        // PQ to store values as time and node
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>>pq;
        // push the node into the pq
        pq.push({0, 1});

        // to track the visit of each node
        vector<int>visitedcount(n+1, 0);
        // minimum time needed  to reach each node
        vector<int>mintime(n+1, -1);
        while(!pq.empty()){
            int curr_node = pq.top().second;
            int curr_time = pq.top().first;
            pq.pop();

            if(mintime[curr_node] == curr_time || visitedcount[curr_node]>=2){
                // Skipping if already visited once or relaxed twice
                continue;
            }

            visitedcount[curr_node]++;
            mintime[curr_node] = curr_time;

            if(curr_node == n && visitedcount[curr_node] == 2){
                return mintime[curr_node];
            }
            // the curr time is between odd multiple to even multiple range, so traffic signal
            // is red
            if((curr_time / change) % 2 != 0){
                curr_time = (curr_time/change + 1) * change;
            }

            for(int neigh: adj[curr_node]){
                // wheter green or red  curr_time + time(to travel node to node)
                pq.push({curr_time + time, neigh});
            }
        }

        return -1;
    }
};