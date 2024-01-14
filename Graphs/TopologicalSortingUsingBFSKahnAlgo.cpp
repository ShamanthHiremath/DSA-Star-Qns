#include <bits/stdc++.h> 
void TopoSortBFS(unordered_map<int, list<int>> &adj, vector<int> &indegrees, vector<int> &ans){
	queue<int>q;
	for(int i = 0; i < indegrees.size(); ++i){
        if (indegrees[i] == 0) {
            q.push(i);
        }
    }
	while(!q.empty()){
		int frontnode=q.front();
		q.pop();
		//store the ans
		ans.push_back(frontnode);
		for( auto neighbor: adj[frontnode]){
			indegrees[neighbor]--;
			if(indegrees[neighbor]==0){
				q.push(neighbor);
			}
		}
	}
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int, list<int>>adj;
    vector<int>indegrees(v);
    //prepare adj list
    for(int i=0; i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        indegrees[v]++;
    }
    // for(auto i: adj){
	// 	for (auto j: i.second){
	// 		indegrees[j]++;
	// 	}
	// }
    vector<int> ans;
	TopoSortBFS(adj, indegrees, ans);
	return ans;
}