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

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int, list<int>>adj;
    //prepare adj list
    for(int i=0; i< E;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> ans;
    //keeps track of the visited nodes
    vector<int>visited(V, 0);
    //traverse all components i.e multiple undirected graphs and disconneced nodes
    for(int i=0; i<V; i++){
        if(!visited[i]){
            vector<int> component;
            dfs(visited, adj, component, i);
            ans.push_back(component);
        }
    }
    return ans;

}
//V=5, E=4
// 0 2
// 0 1
// 1 2
// 3 4
// Sample Output 1:
// 2
// 0 1 2
// 3 4