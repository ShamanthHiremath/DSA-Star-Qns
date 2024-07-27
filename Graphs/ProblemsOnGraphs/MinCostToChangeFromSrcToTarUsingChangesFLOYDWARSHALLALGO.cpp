/*
2976. Minimum Cost to Convert String I

You are given two 0-indexed strings source and target, both of length n and consisting of lowercase English letters. You are also given two 0-indexed character arrays original and changed, and an integer array cost, where cost[i] represents the cost of changing the character original[i] to the character changed[i].

You start with the string source. In one operation, you can pick a character x from the string and change it to the character y at a cost of z if there exists any index j such that cost[j] == z, original[j] == x, and changed[j] == y.

Return the minimum cost to convert the string source to the string target using any number of operations. If it is impossible to convert source to target, return -1.

Note that there may exist indices i, j such that original[j] == original[i] and changed[j] == changed[i].

source, target consist of lowercase English letters.

Example 1:

Input: source = "abcd", target = "acbe", original = ["a","b","c","c","e","d"], changed = ["b","c","b","e","b","e"], cost = [2,5,5,1,2,20]
Output: 28
Explanation: To convert the string "abcd" to string "acbe":
- Change value at index 1 from 'b' to 'c' at a cost of 5.
- Change value at index 2 from 'c' to 'e' at a cost of 1.
- Change value at index 2 from 'e' to 'b' at a cost of 2.
- Change value at index 3 from 'd' to 'e' at a cost of 20.
The total cost incurred is 5 + 1 + 2 + 20 = 28.
It can be shown that this is the minimum possible cost.
Example 2:

Input: source = "aaaa", target = "bbbb", original = ["a","c"], changed = ["c","b"], cost = [1,2]
Output: 12
Explanation: To change the character 'a' to 'b' change the character 'a' to 'c' at a cost of 1, followed by changing the character 'c' to 'b' at a cost of 2, for a total cost of 1 + 2 = 3. To change all occurrences of 'a' to 'b', a total cost of 3 * 4 = 12 is incurred.
Example 3:

Input: source = "abcd", target = "abce", original = ["a"], changed = ["e"], cost = [10000]
Output: -1
Explanation: It is impossible to convert source to target because the value at index 3 cannot be changed from 'd' to 'e'.
*/

// FLOYD WARSHALL ALGORITHM

#include <vector>
#include <string>
#include <algorithm>

class Solution {
private:
    static constexpr int CHAR_COUNT = 26;
    static constexpr int INF = 1e9;

    std::vector<std::vector<int>> buildConversionGraph(const std::vector<char>& original, const std::vector<char>& changed, const std::vector<int>& cost) {
        std::vector<std::vector<int>> graph(CHAR_COUNT, std::vector<int>(CHAR_COUNT, INF));
        for (int i = 0; i < CHAR_COUNT; i++) {
            graph[i][i] = 0;
        }
        for (size_t i = 0; i < cost.size(); i++) {
            int from = original[i] - 'a';
            int to = changed[i] - 'a';
            graph[from][to] = std::min(graph[from][to], cost[i]);
        }
        return graph;
    }

    void optimizeConversionPaths(std::vector<std::vector<int>>& graph) {
        for (int k = 0; k < CHAR_COUNT; k++) {
            for (int i = 0; i < CHAR_COUNT; i++) {
                if (graph[i][k] < INF) {
                    for (int j = 0; j < CHAR_COUNT; j++) {
                        if (graph[k][j] < INF) {
                            graph[i][j] = std::min(graph[i][j], graph[i][k] + graph[k][j]);
                        }
                    }
                }
            }
        }
    }

    long long computeTotalConversionCost(const std::string& source, const std::string& target, const std::vector<std::vector<int>>& graph) {
        long long totalCost = 0;
        for (size_t i = 0; i < source.length(); i++) {
            int sourceChar = source[i] - 'a';
            int targetChar = target[i] - 'a';
            if (sourceChar != targetChar) {
                if (graph[sourceChar][targetChar] == INF) {
                    return -1;
                }
                totalCost += graph[sourceChar][targetChar];
            }
        }
        return totalCost;
    }

public:
    long long minimumCost(std::string source, std::string target, std::vector<char>& original, std::vector<char>& changed, std::vector<int>& cost) {
        auto conversionGraph = buildConversionGraph(original, changed, cost);
        optimizeConversionPaths(conversionGraph);
        return computeTotalConversionCost(source, target, conversionGraph);
    }
};

// MY SOLUTION

class Solution {
public:
    int dijkstras(char src, char dest, const unordered_map<char, unordered_map<char, int>>& adj,  vector<vector<int>>&dp) {
        vector<int> dist(26, INT_MAX);
        dist[src - 'a'] = 0;
        priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;

        pq.push({0, src});

        while(!pq.empty()){
            char u = pq.top().second;
            int dist_u = pq.top().first;

            pq.pop();

            if(u == dest){
                return dist_u;
            }
            if(adj.find(u) == adj.end()){
                continue;
            }
            for(const auto& [v, wt_v] : adj.at(u)){
                if(dist[v - 'a'] > wt_v + dist_u){
                    dist[v - 'a'] = wt_v + dist_u;
                    pq.push({dist[v - 'a'], v});
                }
            }
        }

        // for(int i=0; i<26; i++){
        //     if(dist[i] != INT_MAX){
        //         dp[src-'a'][i] = dist[i];
        //         // dp[i][src-'a'] = dist[i];
        //     }
        // }

        return (dist[dest - 'a'] != INT_MAX) ? dist[dest - 'a'] : -1;
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        unordered_map<char, unordered_map<char, int>> adj;
        for(int i = 0; i < original.size(); i++){
            char u = original[i];
            char v = changed[i];
            int d = cost[i];
        
            // Update edge (u, v) if it doesn't exist or new cost is lower
            if(adj[u].count(v) == 0 || d < adj[u][v]){
                adj[u][v] = d;
            }
        }

        vector<vector<int>>dp(26, vector<int>(26, -1));

        long long mincost = 0;
        for(int i = 0; i < source.size(); i++){
            if(source[i] == target[i]){
                dp[source[i]-'a'][target[i]-'a'] = 0;
                continue;
            }
            if(dp[source[i]-'a'][target[i]-'a'] != -1){
                mincost += dp[source[i]-'a'][target[i]-'a'];
                continue;
            }
            int src_tar_dest = dijkstras(source[i], target[i], adj, dp);

            if(src_tar_dest == -1){
                return -1;
            }
            else{
                dp[source[i] - 'a'][target[i] - 'a'] = src_tar_dest;
                // dp[target[i] - 'a'][source[i] - 'a'] = src_tar_dest;
                mincost += src_tar_dest;
            }
        }

        return mincost;
    }
};