/*Procedure ShortestPathInDAG(Graph G, Src):
___________________________________________________________________

1.   Shortest_path_distances ← empty list  # final list that will be returned
2.    for each vertex v in G.V do
3.       List_of_all_possible_path_dists ← computeAllDistances(G, Src, v)  
4.       If  List_of_all_possible_path_dists is not empty do
5.              Shortest_path_distances[v] ← min(List_of_all_possible_path_dists)
6.       end if 
7.       else 
8.       Shortest_path_distances[v] ← INF
9.       end else if
10.   return Shortest_path_distances
11.   end procedure*/
#include <bits/stdc++.h>
using namespace std;

// Graph class implemented using an adjacency list
class Graph{
public:
    int V;  // Number of Vertices
    int E;  // Number of Edges
    vector<pair<int, int>> *adj; // adjacency list
    Graph(int num_vertices, int num_edges){
        this->V = num_vertices;
        this->E = num_edges;
        this->adj = new vector<pair<int, int>>[num_vertices];
    }
    
    // function to add Edge
    void addEdge(int u, int v, int w){
        adj[u].push_back({v, w});
    }
    
    // function that returns the topSort ordering of nodes in a graph
    vector<int> topSort(int src){

        //inDegree vector
        vector<int> indegree(V, 0);

        // update the indegree of each node in the graph
        for(int i=0;i<V;++i){
            for(pair<int, int> node:this->adj[i]){
                indegree[node.first]++;
            }
        }

        // queue 
        queue<int> q;
        
        // push all nodes with 0 in degree in the queue
        for(int i=0;i<V;++i){
            if(indegree[i]==0)
                q.push(i);
        }
        
        // vector to store topSortOrdering        
        vector<int> topSortOrdering;
        
        // run until queue is empty
        while(!q.empty()){
            
            // pop the front node
            int u = q.front();
            q.pop();

            // since it has 0 indegree it will occur before all elements 
            // with non-0 indegree currently
            topSortOrdering.push_back(u);
            
            // decrement the indegree of adjacent nodes of the popped node 
            // by 1
            for(pair<int, int> node:this->adj[u]){
                indegree[node.first]--;
                
                // if the indegree of the node is 0
                if(indegree[node.first]==0){
                    
                    // push it to the queue
                    q.push(node.first);
                }
            }
            
        }
        // return the topSortOrdering        
        return topSortOrdering;
    }
    
    //find all the shortest path distances
    void findShortestPathInDAG(int src){
        
        // distance vector from the src node
        vector<int> distances(V, INT_MAX);
        
        // find the topSort ordering        
        vector<int> topSortOrdering = topSort(src);
        
        // initially mark the distance from the source node to itself as 0
        distances[src]=0;
        
        // for each vertex in topSortOrdering
        for(int x:topSortOrdering){
            
            // if current vertex weight is not INT_MAXinity
            if(distances[x]!=INT_MAX){
                
                // traverse all the adjacent Edges
                for(pair<int, int> adjNode : this->adj[x]){
                    
                    // relax the edges
                    if(distances[adjNode.first] > distances[x]+adjNode.second){
                        distances[adjNode.first] = distances[x]+adjNode.second;
                    }
                }   
            }
        }
        
        // print the final distances
        
        cout<<"The distances from the src node are: ";
        for(int i=0;i<V;++i){
            if(distances[i]==INT_MAX) cout<<"INF ";
            else cout<<distances[i]<<" ";
        }
    }
    
};
int main() {
    // Number of Edges and Vertices
    int num_vertices = 6;
    int num_edges = 9;

    Graph G(num_vertices, num_edges); // Graph G
    
    // add all edges to graph
    G.addEdge(1, 3, 6);
    G.addEdge(1, 2, 2);
    G.addEdge(0, 1, 5);
    G.addEdge(0, 2, 3);
    G.addEdge(3, 4, -1);
    G.addEdge(2, 4, 4);
    G.addEdge(2, 5, 2);
    G.addEdge(2, 3, 7);
    G.addEdge(4, 5, -2);

    // compute the Shortest_path
    int src = 1; 
    G.findShortestPathInDAG(src);
    return 0;
}

// Output
// The distances from the src node are: INF 0 2 6 5 3 