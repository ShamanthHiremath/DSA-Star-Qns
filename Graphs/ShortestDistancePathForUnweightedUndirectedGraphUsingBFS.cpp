#include<bits/stdc++.h>
//Input 1 :
// 1
// 4 4
// 1 4
// 1 2
// 2 3
// 3 4
// 1 3
// Output 1 :
// ( 1 , 3 , 4 )

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	//create adjacenecy list
	unordered_map<int, list<int>> adj;
	for(int i=0; i<m; i++){
		int u=edges[i].first;
		int v=edges[i].second;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	//to check if the current node is visited during call
	unordered_map<int, bool>visited;
	//to track the parent nodes of the current node
	unordered_map<int, int>parentOf;
	queue<int>q;
	//Push the src node s
	q.push(s);
	//mark its  visited as 1
	visited[s]=1;
	//mark its parent as -1
	parentOf[s]=-1;
	while(!q.empty()){
		int frontnode=q.front();
		q.pop();
		for(auto i: adj[frontnode]){
			if(!visited[i]){
				visited[i]=1;
				parentOf[i]=frontnode;
				q.push(i);
			}

		}
	}
	//Prepare the shortest path vector
	vector<int>ans;
	//destination 
	int i=t;
	//Push destination
	// ans.push_back(t);
	while(i!=s){
		ans.push_back(i);
		i=parentOf[i];
	}
	ans.push_back(s);
	reverse(ans.begin(), ans.end());
	// for(auto i: ans){
	// 	cout<<i<<" ";
	// }
	return ans;

}
