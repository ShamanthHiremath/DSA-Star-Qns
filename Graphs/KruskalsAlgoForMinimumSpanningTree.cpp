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

#include<bits/stdc++.h>
// compares the elements in two arrays
bool cmp(vector<int>&a, vector<int>&b){
  return a[2]<b[2];
}

void makeDisjointSet(vector<int>&parentRoot){
  int j=0;
  //initialises parentroots as themselve, cuz the nodes are assumed to be disconnected
  for(auto& i: parentRoot){
    i=j;
    j++;
  }
}

int findParent(int node, vector<int>&parentRoot){
  if(parentRoot[node]==node){
    return node;
  }
  return parentRoot[node]=findParent(parentRoot[node], parentRoot);
}

void unionSet(int u, int v, vector<int>&parentRoot, vector<int>&rank){
  //fetch parentroots of u and v
  u=findParent(u, parentRoot);
  v=findParent(v, parentRoot);

  //no updation of rank
  if(rank[u]<rank[v]){
    parentRoot[u]=v;
  }
  //no updation of rank
  else if(rank[v]<rank[u]){
    parentRoot[v]=u;
  }
  //have equal ranks, connect any two nodes taking any node as parent and increase the rank of the parent node 
  else{
    parentRoot[v]=u;
    rank[u]++;
  }
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  //No need of creating adj list
  //Just Sort the Tree on the basis of weights, min to max
  //Sorting based on weights (Careful its 2-D Array)
  sort(edges.begin(), edges.end(), cmp);
  vector<int>parentRoot(n);
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