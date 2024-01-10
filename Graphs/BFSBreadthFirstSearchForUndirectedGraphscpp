#include<bits/stdc++.h>
//FOR UNDIRECTED AND DISCONNECTED GRAPHS
void prepareAdjList(unordered_map<int, list<int> > &adjList, vector<vector<int>> &adj ){
    for(int i=0; i<adj.size(); i++){
        int u=adj[i][0];
        int v=adj[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

void bfs(unordered_map<int, bool> &visited, unordered_map<int, list<int> > &adjList, int node, vector<int>&ans){
    queue<int>q;
    q.push(node);
    visited[node]=true;
    while(!q.empty()){
        int frontnode=q.front();
        q.pop();
        //store frontnode in answer
        ans.push_back(frontnode);
        //traverse the connected edges of frontnode//the neighbours of frontnode in adjlist
        for(auto i: adjList[frontnode]){
            if(!visited[i]){
                q.push(i);
                visited[i]=1;
            }
        }
    }
}

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    unordered_map<int, list<int> > adjList;
    prepareAdjList(adjList, adj);
    vector<int>ans;
    //Make a visited map to keep track of all the visited/printed nodes
    unordered_map<int, bool>visited;
    //traverse all componennts of graph and check
    for(int i=0; i<n; i++){
        if(!visited[i]){
            bfs(visited, adjList, i, ans);
        }
    }
    return ans;
}