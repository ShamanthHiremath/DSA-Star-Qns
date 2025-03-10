/*
1319. Number of Operations to Make Network Connected

https://leetcode.com/problems/number-of-operations-to-make-network-connected/

There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

 
Example 1:
Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.

CHECK IMAGE IN THE SAME FOLDER
Example 2:
Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
Output: 2

Example 3:
Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
Output: -1
Explanation: There are not enough cables.
*/

class Solution {
public:

    int findParent(vector<int>&ulti_parent, int node){
        if(ulti_parent[node] == node){
            return node;
        }
        return ulti_parent[node] = findParent(ulti_parent, ulti_parent[node]);
    }

    void unionByHeight(vector<int>&ulti_parent, vector<int>&height, int u, int v){
        int ulp_u = findParent(ulti_parent, u);
        int ulp_v = findParent(ulti_parent, v);

        if(height[ulp_u] < height[ulp_v]){
            ulti_parent[ulp_u] = ulp_v; 
        }
        else if(height[ulp_v] < height[ulp_u]){
            ulti_parent[ulp_v] = ulp_u; 
        }
        else{
            ulti_parent[ulp_v] = ulp_u;
            height[ulp_u]++;
        }


    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int>height(n, 0);
        vector<int>ulti_parent(n);
        for(int i=0; i<n; i++){
            ulti_parent[i] = i;
        }

        // check for extra edges in connections
        int extraEdge = 0;
        for(auto conn : connections){
            int u = conn[0];
            int v = conn[1];
            // now check for ulp, if same they have an extra edge,
            if(findParent(ulti_parent, u) == findParent(ulti_parent, v) ){
                extraEdge++;
            }
            //  if not they can be merged
            else{
                unionByHeight(ulti_parent, height, u, v);
            }
        }

        // check if the node is its own ulp_parent, if yes then thats one component
        // if not it is connected to one of the component
        int noOfCompo = 0;
        for(int i=0; i<n; i++){
            if(ulti_parent[i] == i){
                noOfCompo++;
            }
        }

        // a graph must have minimum n-1 edges to connect n different different components
        if(extraEdge >= noOfCompo-1){
            return noOfCompo -1;
        }

        return -1;
    }
};