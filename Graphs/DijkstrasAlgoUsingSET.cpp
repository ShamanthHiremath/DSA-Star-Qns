#include <bits/stdc++.h> 
/*
an undirected graph of ‘V’ vertices (labeled 0,1,..., V-1) and ‘E’ edges. Each edge connecting two nodes (‘X’,’Y’) will have a weight denoting the distance between node ‘X’ and node ‘Y’.

Your task is to find the shortest path distance from the source node, which is the node labeled as 0, to all vertices given in the graph.

Example:

Input:
4 5
0 1 5
0 2 8
1 2 9
1 3 2
2 3 6

Output:
The number of vertices is 4, and the number of edges is 5.

In the input, following the number of vertices and edges, three numbers are given. The first number denotes node ‘X’, the second number denotes node ‘Y’ and the third number denotes the distance between node ‘X’ and ‘Y’.

As per the input, there is an edge between node 0 and node 1 and the distance between them is 5.

The vertices 0 and 2 have an edge between them and the distance between them is 8.
The vertices 1 and 2 have an edge between them and the distance between them is 9.
The vertices 1 and 3 have an edge between them and the distance between them is 2.
The vertices 2 and 3 have an edge between them and the distance between them is 6.
*/
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    //Create adjacenecy list with Vertices and its weights/distances
    unordered_map<int, list<pair<int, int> > > adj;
    for(int i=0; i<edges; i++){
        int u=vec[i][0];
        int v=vec[i][1];
        int d=vec[i][2];
        adj[u].push_back({ v , d });
        adj[v].push_back({ u , d });

    }
    vector<int>dist(vertices, INT_MAX);
    dist[source]=0;
    // SET to store pairs as {Dist and Node}
    set<pair<int, int>>st;
    st.insert({0, source});
    while(!st.empty()){
        //fetch minimum most record
        auto top=*(st.begin());

        //separate minimum dist pair elements
        int topnode=top.second;
        int distnode=top.first;

        //remove topmost minimum dist node
        st.erase(st.begin());

        //traverse neighbors/ adj nodes
        for(auto i: adj[topnode]){
            if(dist[i.first] > distnode + i.second){

                //Check if the node pair already exists in the set
                auto alreadynodeexists=st.find({dist[i.first], i.first});
                //if yes, erase it, (finf returns a ptr to the end of the set if not found)
                if(alreadynodeexists!=st.end()){
                    st.erase(alreadynodeexists);
                }
                
                //Update distance
                dist[i.first] = distnode + i.second;
                //insert the newly updated pair
                st.insert({dist[i.first], i.first});
            }
        }
    }
    return dist;
}

//             ORRRR

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
    vector<int>dist(V, INT_MAX);
    dist[S]=0;
    // SET to store pairs as {Dist and Node}
    set<pair<int, int>>st;
    st.insert({0, S});
    while(!st.empty()){
        //fetch minimum most record
        auto top=*(st.begin());

        //separate minimum dist pair elements
        int topnode=top.second;
        int distnode=top.first;

        //remove topmost minimum dist node
        st.erase(st.begin());

        //traverse neighbors/ adj nodes
        for(auto i: adj[topnode]){
            if(dist[i[0]] > distnode + i[1]){

                //Check if the node pair already exists in the set
                auto alreadynodeexists=st.find({dist[i[0]], i[0]});
                //if yes, erase it, (finf returns a ptr to the end of the set if not found)
                if(alreadynodeexists!=st.end()){
                    st.erase(alreadynodeexists);
                }
                
                //Update distance
                dist[i[0]] = distnode + i[1];
                //insert the newly updated pair
                st.insert({dist[i[0]], i[0]});
            }
        }
    }
    return dist;
    }
};