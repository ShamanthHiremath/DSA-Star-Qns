/*
1. This algo can be used for -ve weights in D and UnD Graphs as well
2. Cannot be used in negative cycle
3. But can be used for -ve cycle detection 
*/
vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    vector<int>dist(n+1, 1e8);
    dist[src]=0;
    //run the cycle for n-1 times
    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            int u=edges[j][0];
            int v=edges[j][1];
            int weight=edges[j][2];
            if(dist[v] > (dist[u]+weight) ){
                dist[v]=dist[u]+weight;
            }
        }
    }
    //the nth time is the -ve cycle check
    //WE ARE DONE HERE.. BUT WE'll CHECK IF WE HAVE -ve CYCLES
    bool flag=0;
    for(int j=0; j<m; j++){
        int u=edges[j][0];
        int v=edges[j][1];
        int weight=edges[j][2];
        if( dist[u]!=1e8 && dist[v] > (dist[u]+weight) ){
        //IF NEGATIVE CYCLE IS PRESENT then it wont update any dist nodes
            flag=1;
        }
    }
    if (flag == 0) {
    return dist;
    }
    // -ve cycle exists
    //return {0};

}