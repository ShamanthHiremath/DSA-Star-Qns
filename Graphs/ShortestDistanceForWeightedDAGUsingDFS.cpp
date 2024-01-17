#include<bits/stdc++.h>
class Solution {
  public:

    //Calculation of Shortest Distance array
    void calShortestDist(vector<int> &dist, stack<int> &s, unordered_map<int, list<pair<int, int> > > &adj, int src){
        dist[src]=0;
        while(!s.empty()){
            int top=s.top();
            s.pop();
            if(dist[top]!=INT_MAX){
                for(auto i: adj[top]){
                    //DISTANCE FROM THE  PARENT NODE + THE EDGE DISTANCE if lesser than the DISTANCE OF THE CURRENT NODE
                    if(dist[top]+i.second<dist[i.first]){
                        dist[i.first]=dist[top]+i.second;
                    }
                }
            }
        }
    }

    //Creation of TopoLogical Sort 
    void Topodfs(int node, stack<int> &s, unordered_map<int, bool> &visited, unordered_map<int, list<pair<int, int> > > &adj){
        visited[node]=1;
        for(auto i: adj[node]){
            if(!visited[i.first]){
                Topodfs(i.first, s, visited, adj);
            }
        }
        s.push(node);
        return ;
    }
     
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        
        //Create adjacenecy list with Vertices and its weights/distances
        unordered_map<int, list<pair<int, int> > > adj;
        for(int i=0; i<M; i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int d=edges[i][2];
            adj[u].push_back({ v , d });
        }
        unordered_map<int, bool> visited;
        stack<int>s;
        for(int i=0; i<N; i++){
            if(!visited[i]){
                Topodfs(i, s, visited, adj);
            }
        }
        
        //Calculating the distance array
        int src=0;
        vector<int> dist(N, INT_MAX);
        calShortestDist(dist, s, adj, src);
        
        //THIS PART IS USEFUL ONLY IF THE QN MENTIONS TO RETURN -1 FOR UNREACHABLE VERTEXs

        // for(int i=0; i<N; i++){
        //     if(dist[i]==INT_MAX){
        //         dist[i]=-1;
        //     }
        // }
        return dist;
    }
};