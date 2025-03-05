/*
1091. Shortest Path in Binary Matrix

https://leetcode.com/problems/shortest-path-in-binary-matrix/description/

Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.
A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:
All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.


Example 1:
Input: grid = [[0,1],[1,0]]
Output: 2

Example 2:
Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4


Example 3:
Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
Output: -1

*/
class Solution {
    public:
        int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
            int n = grid.size();
            if (n == 0) return -1;
            int m = grid[0].size();
            
            // Check if the starting or ending cell is blocked
            if (grid[0][0] != 0 || grid[n-1][m-1] != 0) {
                return -1;
            }
            
            // Directions for 8 possible movements
            vector<vector<int>> dirn = {{1,0}, {0,1}, {-1,0}, {0,-1}, {1,1}, {-1,-1}, {1,-1}, {-1,1}};
            
            // Queue for BFS
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
            pq.push({0, 0});
            
            // Distance matrix
            vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
            dist[0][0] = 1;  // Starting cell is part of the path
            
            while (!pq.empty()) {
                auto current = pq.top();
                pq.pop();
                int i = current.first;
                int j = current.second;
                
                // Check all 8 directions
                for (auto dir : dirn) {
                    int row = i + dir[0];
                    int col = j + dir[1];
                    
                    if (row >= 0 && row < n && col >= 0 && col < m && grid[row][col] == 0) {
                        if (dist[row][col] > dist[i][j] + 1) {
                            dist[row][col] = dist[i][j] + 1;
                            pq.push({row, col});
                        }
                    }
                }
            }
            
            return dist[n-1][m-1] == INT_MAX ? -1 : dist[n-1][m-1];
        }
    };