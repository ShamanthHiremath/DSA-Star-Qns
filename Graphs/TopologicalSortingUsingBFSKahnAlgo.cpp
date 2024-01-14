#include <bits/stdc++.h> 
void TopoSortBFS(unordered_map<int, list<int>> &adj, vector<int> &indegrees, vector<int> &ans){
	queue<int>q;
    //push all the 0 indegree nodes to queue
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
            //Decrease the no of indegrees instead of marking visited
			indegrees[neighbor]--;
            //if equal to 0 then push to the queue
			if(indegrees[neighbor]==0){
				q.push(neighbor);
			}
		}
	}
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int, list<int>>adj;
    // To calculate the indegrees of a node
    vector<int>indegrees(v);
    //prepare adj list
    for(int i=0; i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        //counts indegrees
        indegrees[v]++;
    }
    // for(auto i: adj){
	// 	for (auto j: i.second){
	// 		indegrees[j]++;
	// 	}
	// }
    //To store ans for topo order
    vector<int> ans;
	TopoSortBFS(adj, indegrees, ans);
	return ans;
}