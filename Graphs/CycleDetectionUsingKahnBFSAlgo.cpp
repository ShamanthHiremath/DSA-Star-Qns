#include <bits/stdc++.h> 
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  unordered_map<int, list<int>>adj;
  // To calculate the indegrees of a node
  vector<int>indegrees(n);
  //prepare adj list
  for(int i=0; i<edges.size();i++){
      int u=edges[i].first-1;
      int v=edges[i].second-1;
      adj[u].push_back(v);
      //counts indegrees
      indegrees[v]++;
  }
  int totalNodesInTopo=0;
  queue<int>q;
  //push all the 0 indegree nodes to queue
	for(int i = 0; i<n; ++i){
       if (indegrees[i] == 0) {
          q.push(i);
       }
    }
	while(!q.empty()){
		int frontnode=q.front();
		q.pop();
		//store the ans
		totalNodesInTopo++;
		for( auto neighbor: adj[frontnode]){
      //Decrease the no of indegrees instead of marking visited
			indegrees[neighbor]--;
      //if equal to 0 then push to the queue
			if(indegrees[neighbor]==0){
				q.push(neighbor);
			}
		}
	}
  //THE TOTAL NO OF NODES IN THE TOPOLOGICAL SORT SHOULD BE EQUAL TO THE NO OF NODES
  //BECAUSE  EVERY NODE IS VISITED ONLY ONCE
  //BUT IF A CYCLE  IS PRESENT THE NO OF NODES  ARE EITHER MORE OR LESS
  if(totalNodesInTopo==n){
    return 0;
  }
  return 1;
}