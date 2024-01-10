//FOR DIRECTED  GRAPHS WITH GIVEN ADJACENCY LIST
void bfs(vector<int> &visited, vector<vector<int>> &adj, int node, vector<int>&ans){
    queue<int>q;
    q.push(node);
    visited[node]=true;
    while(!q.empty()){
        int frontnode=q.front();
        q.pop();
        //store frontnode in answer
        ans.push_back(frontnode);
        //traverse the connected edges of frontnode//the neighbours of frontnode in adjlist
        for(auto i: adj[frontnode]){
            if(!visited[i]){
                q.push(i);
                visited[i]=1;
            }
        }
    }
}

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    // unordered_map<int, list<int> > adjList;
    // prepareAdjList( adj);
    vector<int>ans;
    //Make a visited map to keep track of all the visited/printed nodes
    vector<int>visited(n, 0);
     bfs(visited, adj, 0, ans);
    //traverse all componennts of graph and check
    //this handles  the case for disconnected nodes, i.e multiple components
    // for(int i=0; i<n; i++){
    //     if(!visited[i]){
    //         bfs(visited, adj, i, ans);
    //     }
    // }
    return ans;
}