// The problem can be modeled as a directed graph, where each course is a node, and prerequisites are directed edges.

// Here's a breakdown of the code:

// Create a vector of vectors (v) to represent the graph, where v[i] contains the courses that depend on course i.
// Create a vector (degree) to store the in-degree of each node (course).
// Iterate through the prerequisites to build the graph and calculate the in-degrees.
// Initialize a queue (q) with courses having an in-degree of 0, as these are the courses that can be taken initially.
// Perform a BFS traversal using the queue, updating in-degrees and enqueueing courses that become eligible to be taken.
// After the BFS traversal, check if there are any remaining courses with non-zero in-degrees. If yes, return false, indicating that it's not possible to finish all courses. Otherwise, return true.

//DFS CYCLE DETECTION CAN ALSO BE USED
// IF A CYCLE EXISTS THEN WE CANT FINISH ALL THE COURSES ELSE WE CAN
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Create a graph and in-degree vector
        vector<vector<int>> v(numCourses);
        vector<int> degree(numCourses);
        
        // Build the graph and calculate in-degrees
        for (int i = 0; i < prerequisites.size(); i++) {
            v[prerequisites[i][1]].push_back(prerequisites[i][0]); 
            degree[prerequisites[i][0]]++;
        }
        
        // Initialize a queue with courses having in-degree 0
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (!degree[i])
                q.push(i);
        }
        
        // Perform BFS traversal
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i = 0; i < v[cur].size(); i++) {
                if (--degree[v[cur][i]] == 0)
                    q.push(v[cur][i]);
            }
        }
        
        // Check if there are remaining courses with non-zero in-degrees
        for (int i = 0; i < numCourses; i++) {
            if (degree[i])
                return false;
        }
        
        // All courses can be finished
        return true;
    }
};
