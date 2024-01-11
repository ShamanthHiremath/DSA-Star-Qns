// A Directed Acyclic Graph (DAG) is a DIRECTED graph that contains no CYCLES.

// Topological Sorting of DAG is a LINEAR ORDERING of vertices such that 
// for every directed edge from vertex ‘u’ to vertex ‘v’, vertex ‘u’ appears before ‘v’ in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.

//So basically it can be used  to detect CYCLES in a graph, since a valid Topological Sort will be a DAG 

#include <bits/stdc++.h> 
void TopoSortdfs(vector<int>&visited, unordered_map<int, list<int>>&adj, stack<int>&st, int node){
    visited[node]=true;
    //do the same for all the neighbour/adjacent nodes for the NODE in adj[node]
    for(auto i: adj[node]){
        if(!visited[i]){
            //recursion for every element in adj[node]
            TopoSortdfs(visited, adj, st, i);
        }
    }
    //IMPORTANT PART IF VISITED IS TRUE
    st.push(node);
    return;
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int, list<int>>adj;
    //prepare adj list
    for(int i=0; i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
    }
    vector<int> ans;
    vector<int>visited(v, 0);
    stack<int>st;
    for(int i=0; i<v; i++){
        if(!visited[i]){
            TopoSortdfs(visited, adj, st, i);
        }
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;

}