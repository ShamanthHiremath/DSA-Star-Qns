/*
Used to detect strongly connected components of a graph
A directed graph is said to be strongly connected if every vertex is reachable from every other vertex. The strongly connected components of a graph are the subgraphs which are themselves strongly connected.
*/
#include<unordered_map>
#include<list>
#include<stack>

void dfssolve(int node, unordered_map<int, list<int>>& adj, unordered_map<int, bool>&visited, stack<int> &st){
	visited[node]=1;
	for(auto i: adj[node]){
		if(!visited[i]){
			dfssolve(i, adj, visited, st);
		}
	}
	st.push(node);
	return;
}

void revDFS(int node, unordered_map<int, list<int>>& transposeAdj, unordered_map<int, bool>&visited){
	visited[node]=1;
	for(auto i: transposeAdj[node]){
		if(!visited[i]){
			revDFS(i, transposeAdj, visited);
		}
	}
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	unordered_map<int, list<int>> adj;
	for(int i=0; i<edges.size(); i++){
		int u=edges[i][0];
		int v=edges[i][1];
		adj[u].push_back(v);
	}
	//Create Topological ordering
	stack<int> st;
	unordered_map<int, bool>visited;
	for(int i=0; i<v; i++){
		if(!visited[i]){
			dfssolve(i, adj, visited, st);
		}
	}
	//TRANSPOSE THE GRAPH, meaning change the edge dirn
    unordered_map<int, list<int>> transposeAdj;
	//The following piece of code is only for directed graph, not for undirected
	// for(int i=0; i<edges.size(); i++){
	// 	//mark all the vivited  nodes as 0 for reverse topo
	// 	visited[i]=0;
	// 	int u=edges[i][0];
	// 	int v=edges[i][1];
	// 	transposeAdj[v].push_back(u);
	// }
	// This is the TRANSPOSED ADJ code
    for(int i = 0; i< v; i++) {
		// mark all the vivited  nodes as 0 for reverse topo
		visited[i]=0;
        for (int v : adj[i]) {
            transposeAdj[v].push_back(i);
        }
    }
	
	//Now apply revDFS on the topological order such that it forms different components of the graph
	//pick each node from stack/topo order and apply revDFS and increment coun if they form segments/components
	int noOfComponents=0;
	while(!st.empty()){
		int node=st.top();
		st.pop();
		if(!visited[node]){
			noOfComponents++;
			revDFS(node, transposeAdj, visited);
		}
	}
	return noOfComponents;
}