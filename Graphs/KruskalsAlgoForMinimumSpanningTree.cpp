/*
KRUSKAL's ALGORITHM
Uses Disjoint Sets, to form Union by Rank and Path Comparision
Forms a PARENT ROOT array,
And a RANK array to store  the no of child nodes connected to PARENT Node
Therefore forms the disjoint set of Nodes according to the connections, and builds a Minimum Spanning Tree for comparison using union by ranks and comparision

USING KRUSKAL's ALGO

Compare if two nodes have the same parent....
If  yes, IGNORE
If no, add theminimum weights
*/
/*
PSEUDO CODE
Sort Edges: Sort all the edges in the graph in non-decreasing order of their weights.

Initialize Disjoint Sets: Assign each vertex to its own disjoint set. This can be done using an array (often called parent or parentRoot), where initially each element is its own parent.

Iterate Through Edges: Starting from the smallest weighted edge, iterate through each edge.



*/


#include<bits/stdc++.h>
// compares the elements in two arrays
bool cmp(vector<int>&a, vector<int>&b){
  return a[2]<b[2];
}

void makeDisjointSet(vector<int>&parentRoot){
  int j=0;
  //initialises ultimate parent roots as themselve, cuz the nodes are assumed to be disconnected
  for(auto& i: parentRoot){
    i=j;
    j++;
  }
}

// here the findParent function is used to find the ultimate parent of the node
// and also to update the parentRoot array with the ultimate parent of the node

int findParent(int node, vector<int>&parentRoot){
  if(parentRoot[node]==node){
    return node;
  }
  // path compression
  // here the parentRoot[node] is updated with the ultimate parent of the node, instead of just returning the ultimate parent
  return parentRoot[node]=findParent(parentRoot[node], parentRoot);
}

void unionSet(int u, int v, vector<int>&parentRoot, vector<int>&rank){
  //fetch ultimate parent (up) roots of u and v
  up_u=findParent(u, parentRoot);
  up_v=findParent(v, parentRoot);

  //no updation of rank
  // instead join the lower ranked node to the higher ranked node
  // because the lower rank node, when connected to the higher rank node will have a lower height when connected to the higher ranked node
  if(rank[up_u]<rank[up_v]){
    parentRoot[up_u]=up_v;
  }
  //no updation of rank
  // instead join the lower ranked node to the higher ranked node
  else if(rank[up_v]<rank[up_u]){
    parentRoot[up_v]=up_u;
  }
  //have equal ranks, connect any two nodes taking any node as parent and increase the rank of the parent node 
  else{
    parentRoot[up_v]=up_u;
    rank[up_u]++;
  }
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  //No need of creating adj list
  //Just Sort the Tree on the basis of weights, min to max
  //Sorting based on weights (Careful its 2-D Array)
  sort(edges.begin(), edges.end(), cmp);

  // ULTIMATE PARENT ROOT ARRAY
  vector<int>parentRoot(n);

  // RANK IS NOTHING BUT THE HEIGHT OF THE TREE WITH RESPECT TO THE ULTIMATE PARENT ROOT NODE
  vector<int>rank(n, 0);
  //Create the Disjoint Sets
  makeDisjointSet(parentRoot);

  int minimumWeight=0;
  //Kruskal's Algo
  for(int i=0; i<edges.size(); i++){
    int u= findParent(edges[i][0], parentRoot);
    int v= findParent(edges[i][1], parentRoot);
    int wt= edges[i][2];
    //if u=v then u ignore
    //MERGE EDGES if they dont have the same parent
    if(u!=v){
      unionSet(u, v, parentRoot, rank);
      //add wts of merged edges for the tree
      minimumWeight+=wt;
    }
  }
  return minimumWeight;

}
/*
Sort Edges: Sort all the edges in the graph in non-decreasing order of their weights.

Initialize Disjoint Sets: Assign each vertex to its own disjoint set. This can be done using an array (often called parent or parentRoot), where initially each element is its own parent.

Iterate Through Edges: Starting from the smallest weighted edge, iterate through each edge.

Check for Cycle: For each edge, check if including that edge in the minimum spanning tree would create a cycle. This can be done by checking if the two vertices of the edge belong to the same disjoint set. If they do, including the edge would create a cycle, so skip to the next edge.

Merge Disjoint Sets: If the vertices of the edge belong to different disjoint sets, include the edge in the minimum spanning tree and merge the disjoint sets of the two vertices. This is typically done using the union operation in a disjoint-set data structure.

Repeat: Repeat steps 3-5 until there are n-1 edges in the minimum spanning tree, where n is the number of vertices in the graph.

The algorithm ensures that the included edges form a tree without any cycles, and it selects edges with the smallest weights first. The final result is the minimum spanning tree of the given graph.
*/