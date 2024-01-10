#include<bits/stdc++.h>

// #include<iostream>
using namespace std;
class Graph{
    public:
    //(Key is INT VALUE or Node, Values are the Connected Nodes)
    unordered_map<int, list<int> > adj;
    void addEdge(int u, int v, bool direction){
        adj[u].push_back(v);
        //undirected edge
        if(direction==0){
            adj[v].push_back(u);
        }
    }
    void printAdjList(){
        for(auto i: adj){
            cout<<i.first<<" -> ";
            for(auto j: i.second){
                cout<<j<<",  ";
            }
            cout<<endl;
        }
    }
};

void CreateGraph(Graph &g, int n, int m){
    cout<<"\nENTER THE GRAPH AS A PAIR OF NODE ->NODE: "<<endl; 
    for(int i=0; i<m; i++){
        int u, v;
        cout<<"Pair "<<i+1<<": "<<endl;
        cin>>u;
        cout<<"  -> ";
        cin>>v;
        bool dirn;
        cout<<endl<<"DIRECTED?? (1/0) :  ";
        cin>>dirn;
        g.addEdge(u, v, dirn);
    }
}

int main(){
    int n, m;
    cout<<"ENTER  THE NUMBER OF VERTEX/NODES: ";
    cin>>n;
    cout<<"ENTER  THE NUMBER OF EDGES: ";
    cin>>m;
    Graph g;
    // cout<<"\nENTER THE GRAPH AS A PAIR OF NODE ->NODE: "<<endl; 
    CreateGraph(g, n, m);
    //         (OR)
    /*
    for(int i=0; i<m; i++){
        int u, v;
        cout<<"Pair "<<i+1<<": "<<endl;
        cin>>u;
        cout<<" -> ";
        cin>>v;
        bool dirn;
        cout<<endl<<"DIRECTED?? (1/0) :  ";
        cin>>dirn;
        g.addEdge(u, v, dirn);
    }*/
    g.printAdjList();
 return 0;
}
/*
ENTER  THE NUMBER OF VERTEX/NODES: 5
ENTER  THE NUMBER OF EDGES: 6

ENTER THE GRAPH AS A PAIR OF NODE ->NODE: 
Pair: 1
0
 -> 1

DIRECTED?? (1/0) :  0
Pair: 2
1
 -> 2

DIRECTED?? (1/0) :  0
Pair: 3
2
 -> 3

DIRECTED?? (1/0) :  0
Pair: 4
3
 -> 1

DIRECTED?? (1/0) :  0
Pair: 5
3
 -> 4

DIRECTED?? (1/0) :  0
Pair: 6
0
 -> 4

DIRECTED?? (1/0) :  0
4 -> 3,  0,  
0 -> 1,  4,
1 -> 0,  2,  3,
2 -> 1,  3,
3 -> 2,  1,  4,
*/