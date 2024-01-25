/*
If removing a vertex and its related edges causes the graph to become disconnected, the vertex is considered to be an ARTICULATION POINT in the graph.
*/
//MAIN BASE CASE CONDITION: low[neighbor]>=disc[node]&&parent!=-1
//which denotes that the lowest possible time to reach the neighbour edge is greater than or equal to the discovery/topological ordering time of parent node, so an ARTIC PT may exist, indicating a linear graph
//or say low[neighbor]<disc[node]
//which means that the lowest possible time to reach the neighbour edge is lesser than the discovery/topological ordering time
//of parent node, which is false, which indicates a back edge or a connection/path that takes lesser time to traverse from
//root, instead ffrom the parent node  
// (or) indicates that the nbr node is connected to a node that comes before parent node,
//so removing parent node doesnt form a disconnected component

#include<bits/stdc++.h>

// #include<iostream>
using namespace std;

void dfs(int &node, int &parent, int &timer, unordered_map<int, list<int>>&adj, vector<int>&lowtime, vector<int>&disctime, unordered_map<int, bool> &visited, vector<int>&artPts){
    visited[node]=1;
    disctime[node]=lowtime[node]=timer++;
    int child=0;
    for(int nbr: adj[node]){
        if(nbr==parent){
            //means the dfs call returned back to parent , and it makes no sense
            continue;
        }
        if(!visited[nbr]){
            dfs(nbr,parent, timer, adj, lowtime, disctime, visited, artPts);
            //check for bacedges
            lowtime[node]=min(lowtime[node], lowtime[nbr]);
            
            //CONDITION Check for ArtPts 
            if(lowtime[nbr]>=disctime[node]&& parent!=-1){
                artPts[node]=1;
            }
            //increment child
            child++;
        }
        else{
            lowtime[node]=min(lowtime[node], disctime[nbr]);
        }
    }
    //Condition for root node
    if(parent=-1 &&child>1){
        artPts[node]=1;
    }

}

int main(){
    int v=6;
    int e=6;
    vector<pair<int, int>> edges;
    //formation of edge pairs
    edges.push_back(make_pair(0, 3));
    edges.push_back(make_pair(3, 4));
    edges.push_back(make_pair(0, 4));
    edges.push_back(make_pair(0, 1));
    edges.push_back(make_pair(1, 2));
    edges.push_back(make_pair(2, 5));

    //Creation of Adj List
    unordered_map<int, list<int>>adj;
    for(int i=0; i<e; i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //DS needed
    int timer=0;
    int parent=-1;
    vector<int>lowtime(v, -1);
    vector<int>disctime(v, -1);
    unordered_map<int, bool> visited;
    vector<int>artPts(v, 0);

    //Tarjan's Algo
    for(int i=0; i<v; i++){
        if(!visited[i]){
            dfs(i, parent, timer, adj, lowtime, disctime, visited, artPts);
        }
    }

    //Printing Art Pts
    for(int i=0; i< artPts.size(); i++){
        if(artPts[i]==1){
            cout<<i<<" ";
        }
    }


 return 0;
}