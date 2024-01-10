vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>> &edges) {
    //1 <= N <= 5000
    // 1 <= M <= min(5000, (N * (N - 1)) / 2)
    // 0 <= edges[i][0], edges[i][1] <= N-1
    
    vector<vector<int>>adj(n);
    vector<int>neighbour[n];
    //forms a 2D Matrix to store the neighbour elements of ith node in ith row
    for (int i = 0; i < m; i++){
        int u=edges[i][0];
        int v=edges[i][1];
        neighbour[u].push_back(v);
        neighbour[v].push_back(u);
    }
    for(int i=0;i<n; i++){
        adj[i].push_back(i);
        // for(auto j: neighbour[i]){
        //     adj[i].push_back(j);
        // }
        for(int j=0; j<neighbour[i].size(); j++){
            adj[i].push_back(neighbour[i][j]);
        }
    }
    return adj;
}
/*GIVEN
If 'N' = 3 and edges = {{2,1}, {2,0}}.
So, the adjacency list of the graph is stated below.
0 → 2
1 → 2
2 → 0 → 1

I/p

n=4 m=3
1 2
0 3
2 3
O/p

0 3
1 2
2 1 3
3 0 2
*/