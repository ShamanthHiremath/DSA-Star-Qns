/*
1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance

https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.

Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.

Example 1:


Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
Output: 3
The neighboring cities at a distanceThreshold = 4 for each city are:
City 0 -> [City 1, City 2] 
City 1 -> [City 0, City 2, City 3] 
City 2 -> [City 0, City 1, City 3] 
City 3 -> [City 1, City 2] 
Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 since it has the greatest number.
Example 2:


Input: n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]], distanceThreshold = 2
Output: 0
The neighboring cities at a distanceThreshold = 2 for each city are:
City 0 -> [City 1] 
City 1 -> [City 0, City 4] 
City 2 -> [City 3, City 4] 
City 3 -> [City 2, City 4]
City 4 -> [City 1, City 2, City 3] 
The city 0 has 1 neighboring city at a distanceThreshold = 2.
*/
class Solution {
public:
    int dijkstras(int src, int &distanceThreshold, int &n, unordered_map<int, list<pair<int, int>>> &adj){
        vector<int>dist(n, INT_MAX);
        dist[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, src});

        while (!pq.empty()){
            int u = pq.top().second;
            int dist_u = pq.top().first;

            pq.pop();

            for(auto neigh: adj[u]){
                int v = neigh.first;
                int wt_v = neigh.second;

                if(dist[v] > wt_v + dist_u){
                    dist[v] = wt_v + dist_u;
                    pq.push({dist[v], v});
                }

            }
        }

        int noOfCities = 0;
        for(int dist_u: dist){
            if(dist_u <= distanceThreshold){
                noOfCities++;
            }
        }

        return noOfCities;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        unordered_map<int, list<pair<int, int>>> adj;
        for (int i = 0; i <edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int d = edges[i][2];
            adj[u].push_back({v, d});
            adj[v].push_back({u, d});
        }

        // vector<int>ans;
        int minicities = INT_MAX;
        int curr = -1;
        //  dijkstra's for  each of the city that gives the no of cities with cities lesser than threshold
        for(int i=0; i<n; i++){
            int eligiblecities = dijkstras(i, distanceThreshold, n, adj);
            cout<<"City: "<<i<<" Cities: "<<eligiblecities<<endl;
            if(eligiblecities <= minicities){
                minicities = eligiblecities;
                if(i > curr){
                    curr = i;
                }
            }
        }
        return curr;
    }
};