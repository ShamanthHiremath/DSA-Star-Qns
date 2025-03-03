/*
210. Course Schedule II

https://leetcode.com/problems/course-schedule-ii/

THIS IS PURELY A TOPOLOGICAL SORT PROBLEM WHERE WE HAVE TO FIND THE ORDER OF THE COURSES TO BE TAKEN, AND TOPOLOGICAL SORT IS APPLICABLE ONLY ON DIRECTED ACYCLIC GRAPHS, SO WE HAVE TO CHECK FOR CYCLES IN THE GRAPH THIS CAN BE DONE USING 3 STATES OF A NODE IN A GRAPH, 0-> NOT VISITED, 1-> VISITED AND NOT PROCESSED, 2-> VISITED AND PROCESSED (EXPLORED ALL NBRS, WHILE EXITING THE RECURSION for that node), IF WE ENCOUNTER A NODE WHICH IS VISITING WHILE TRAVERSING THE GRAPH THEN WE HAVE A CYCLE IN THE GRAPH, SO WE RETURN AN EMPTY VECTOR IN THAT CASE.   

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.


Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].

Example 2:
Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].

Example 3:
Input: numCourses = 1, prerequisites = []
Output: [0]
*/

class Solution {
private: 
    bool TopoSortdfs(vector<int>&visited, unordered_map<int, list<int>>&adj, stack<int>&st, int node){
        // cycle detected
        if(visited[node]==1){
            return true;
        }
        //processed and into the topo order
        if(visited[node]==2){
            return false;
        }
        // Mark the node as visiting (part of the current DFS stack)
        visited[node]=true;
        //do the same for all the neighbour/adjacent nodes for the NODE in adj[node]
        for(auto i: adj[node]){
          
            //recursion for every element in adj[node]
            if(TopoSortdfs(visited, adj, st, i)){
                return true;
            }
        }
        //IMPORTANT PART IF VISITED IS TRUE
        // Mark the node as fully processed
        visited[node]=2;
        st.push(node);
        return false;
    }
public:
// topological sort
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>>adj;
        //prepare adj list
        for(int i=0; i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[v].push_back(u);
        }
        vector<int> ans;
        vector<int>visited(numCourses, 0);
        stack<int>st;
        for(int i=0; i<numCourses; i++){
            if(!visited[i]){
                if(TopoSortdfs(visited, adj, st, i)){
                    return {};
                }
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};