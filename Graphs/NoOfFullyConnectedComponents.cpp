/*
Given an undirected graph with v vertices(numbered from 1 to v) and e edges. Find the number of good components in the graph.
A component of the graph is good if and only if the component is fully connected.
Note: A fully connected component is a subgraph of a given graph such that there's an edge between every pair of vertices in the component, the given graph can be a disconnected graph. 
*/

class Solution {
  public:
  
    void dfs(vector<int>&visited, unordered_map<int, list<int>>&adj, vector<int> &component, int node){
        component.push_back(node);
        visited[node]=true;
        //do the same for all the neighbour/adjacent nodes for the NODE in adj[node]
        for(auto i: adj[node]){
            if(!visited[i]){
                //recursion for every element in adj[node]
                dfs(visited, adj, component, i);
            }
        }
    }
  
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        
        unordered_map<int, list<int>>adj;
        //prepare adj list
        for(int i=0; i< edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int noOfComponents = 0;
        //keeps track of the visited nodes
        vector<int>visited(v+1, 0);
        //traverse all components i.e multiple undirected graphs and disconneced nodes
        for(int i=1; i<=v; i++){
            if(!visited[i]){
                vector<int> component;
                dfs(visited, adj, component, i);
                
                bool flag = false;
                for(int i=0; i<component.size(); i++){
                    if(adj[component[i]].size()<component.size()-1){
                        flag = true;
                        break;
                    }
                }
                if(flag == false){
                    noOfComponents++;
                }
            }
        }
            
        return noOfComponents;
    }
};