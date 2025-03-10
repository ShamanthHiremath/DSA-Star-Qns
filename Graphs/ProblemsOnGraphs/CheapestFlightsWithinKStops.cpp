/*
787. Cheapest Flights Within K Stops

https://leetcode.com/problems/cheapest-flights-within-k-stops/

There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.
 

Example 1:
Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.

Example 2:
Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.


Example 3:
Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation:
The graph is shown above.
The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.
*/


class Solution {
    public:
        int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
            // Create adjacency list
            unordered_map<int, vector<pair<int, int>>> adj;
            for (auto& flight : flights) {
                adj[flight[0]].push_back({flight[1], flight[2]});
            }
    
            // Distance array initialized to max
            vector<int> dist(n, INT_MAX);
            dist[src] = 0;
    
            // BFS queue (cost, node, stops)
            queue<tuple<int, int, int>> q;
            q.push({0, src, 0});
    
            while (!q.empty()) {
                auto [cost, u, stops] = q.front();
                q.pop();
    
                // Stop if we exceed allowed stops
                if (stops > k) continue;
    
                for (auto [v, price] : adj[u]) {
                    if (cost + price < dist[v]) {
                        dist[v] = cost + price;
                        q.push({dist[v], v, stops + 1});
                    }
                }
            }
    
            return dist[dst] == INT_MAX ? -1 : dist[dst];
        }
    };
    