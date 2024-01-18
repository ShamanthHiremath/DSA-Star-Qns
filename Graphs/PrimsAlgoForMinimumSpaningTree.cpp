/*   SPANNING TREE (ST)
A Graph converted to a Spanning tree such that it contains n nodes and n-1 edges
and every node is reachable by every other node
Ex: 
No of nodes=5

0 ---- 1 ----- 2
|    / |     /
|  /   |   /
 3      4

 (to)

No of nodes=5, Edges= 4
0 ---- 1 ----- 2
     / |
   /   |
 3     4
 
 Minimum Spanning Tree (MST) is a ST with minimum total cost of weights(edge values) \
 PRIMS ALGO
*/
#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    //Create adjacency list
    unordered_map<int, list<pair<int, int>>>adj;
    for (int i = 0; i < m; i++) {
      //    g[i].       { { u  , v } , w }
      //  vector<pair<pair<int, int>, int>> &g
      int u = g[i].first.first;
      int v = g[i].first.second;
      int w = g[i].second;
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
    }

    //We need 3 DS's with 0 based indexing
    vector<int>key(n+1, INT_MAX);// to store the
    vector<bool>mst(n+1, false); // to store visited/included nodes  of the MST
    vector<int>parent(n+1, -1);

    //MAIN ALGO
    int src=1;
    key[src]=0;
    //parent[src] is already -1
    for(int i=1; i<=n; i++){

        //Take out the minimum most element index fromthe KEY array
        int mini=INT_MAX;
        int u;
        for(int j=1; j<=n; j++){
            if(mst[j]==false && key[j]<mini){
                mini=key[j];
                u=j;
            }
        }

        //Mark mst of u as true
        mst[u]=true;

        //Check for adjacent neighbors
        for(auto neighbor: adj[u]){
            int v=neighbor.first;
            int w=neighbor.second;
            if(mst[v]==false && w<key[v]){
                key[v]=w;
                parent[v]=u;
            }
        } 
    }
    //COMPLETED THE FORMING PARENT PART

    vector<pair<pair<int, int>, int>> ansMST;
    //we start from src+1 because the parent of src is itself and if pushed  it becomes a vertex
    for(int i=src+1; i<=n; i++){
        // because the parent array consists of parent of ith vertex in ith position
        ansMST.push_back({{parent[i], i}, key[i]});
    }
    return ansMST;
}
// //PARENT ARRAYfor IMG
// Values 1-1 0 1 
// Indexs 0 1 2 3 
// //KEY ARRAY
// Values 5 0 8 15
// Indexs 0 1 2 3

/*Sample Input 1 :
1
5 14
1 2 2
1 4 6
2 1 2
2 3 3
2 4 8
2 5 5
3 2 3
3 5 7
4 1 6
4 2 8
4 5 9
5 2 5
5 3 7
5 4 9
Sample Output 1 :
1 2 2
1 4 6
2 3 3
2 5 5
*/

/*O/p
Parent Array:
-1 1 2 1 2
Key Array:
0 2 3 5 5
*/

