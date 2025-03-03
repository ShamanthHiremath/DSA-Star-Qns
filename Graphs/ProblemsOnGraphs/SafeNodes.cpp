/*
802. Find Eventual Safe States

BASCICALLY WE HAVE TO FIND THE NODES WHICH DO NOT HAVE CYCLE IN THEM
so THE NODES WHICH DO NOT HAVE CYCLE IN THEM ARE SAFE NODES

https://leetcode.com/problems/find-eventual-safe-states/

There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

 

Example 1:
Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]
Explanation: The given graph is shown above.
Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.

Example 2:
Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
Output: [4]
Explanation:
Only node 4 is a terminal node, and every path starting at node 4 leads to node 4.
 
*/

class Solution {
    private: 
        bool DAGCycleCheckDFS(vector<int>&state, vector<vector<int>>&adj, int node){
            // cycle detected
            if(state[node]==1){
                return true;
            }
            //processed and into the topo order
            if(state[node]==2){
                return false;
            }
            // Mark the node as visiting (part of the current DFS stack)
            state[node]=1;
            //do the same for all the neighbour/adjacent nodes for the NODE in adj[node]
            for(auto i: adj[node]){
              
                //recursion for every element in adj[node]
                if(DAGCycleCheckDFS(state, adj, i)){
                    return true;
                }
            }
            //IMPORTANT PART IF state IS TRUE
            // Mark the node as fully processed
            state[node]=2;
    
            return false;
        }
    
    public:
        vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
            int n=graph.size();
            vector<int>state(n, 0); // 0: unvisited, 1: visiting, 2: safe/processed.
            vector<int>safe;
    
            for(int i=0; i<n; i++){
                if(!DAGCycleCheckDFS(state, graph, i)){
                    safe.push_back(i);
                }
            }
    
            return safe;
        }
    };


    // ORRRROORRRRROORRRR


class Solution {
    public:
        bool dfsCycle(vector<bool>&visited, vector<vector<int>>&adj, vector<bool>&dfsVisited, int node){
            
            visited[node]=true;
            // This indicates that the node is part of the current path of the Depth-First Search (DFS).
            dfsVisited[node] = true;
            //do the same for all the neighbour/adjacent nodes for the NODE in adj[node]
            for(auto nbr: adj[node]){
                if(!visited[nbr]){
                    if(dfsCycle(visited, adj, dfsVisited, nbr)){
                        return true;
                    }
                }
                // As we continue to explore the neighbors of the node,
                // we check if any of these neighbors are already marked as true in dfsVisited.
                // If we find such a neighbor, it means we have encountered a node that is already in the current path, indicating a cycle.
                else if (visited[nbr] && dfsVisited[nbr]){
                    return true;   
                }
            }
            // mark it as false in dfsVisited to indicate that we are no longer considering this node as part of the current path.
            dfsVisited[node] = false;
            return false;
        }
    
        vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
            vector<bool>visited(adj.size(), false);
            vector<bool>dfsVisited(adj.size(), false);
    
            vector<int>safe;
            for(int i=0; i<adj.size(); i++){
                // the nodes which do not have a cycle in them are safe
                if(!dfsCycle(visited, adj, dfsVisited, i)){
                    safe.push_back(i);
                }
            }
    
            return safe;
        }
    };