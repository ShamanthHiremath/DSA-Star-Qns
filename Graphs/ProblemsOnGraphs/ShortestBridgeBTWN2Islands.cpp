/*
934. Shortest Bridge

https://leetcode.com/problems/shortest-bridge/

You are given an n x n binary matrix grid where 1 represents land and 0 represents water.
An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.
You may change 0's to 1's to connect the two islands to form one island.
Return the smallest number of 0's you must flip to connect the two islands. 

Example 1:
Input: grid = [[0,1],[1,0]]
Output: 1

Example 2:
Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
Output: 2

Example 3:
Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
Output: 1
 
STEPS:

1. **Locate the first island**: Identify the first occurrence of '1' in the graph to mark the starting point of the island search.

2. **Mark the starting point**: Add the coordinates of the first '1' to the queue and mark it as visited by updating its value to '2'. This eliminates the need for a separate visited 2D array, thus conserving space.

3. **Explore the island**: Traverse through all neighboring cells of the current cell. If a neighboring cell is part of the same island (i.e., its value is '1'), mark it as visited by updating its value to '2' and add its coordinates to the queue.

4. **Run BFS to find the nearest bridge**: Use Breadth-First Search (BFS) starting from the first island to find the shortest path (bridge) that connects to the nearest '1' (another island).
*/

class Solution {
    queue<vector<int>>q;
public:
    int bfsManhattanSearch(int m, int n, vector<vector<int>>&grid, vector<vector<int>>&dirn){
        int min_d = INT_MAX;

        int level = 0;

        while(!q.empty()){
            int q_size = q.size();

            while(q_size>0){
                auto cell = q.front();
                q.pop();
                q_size--;


                for(auto dir: dirn){

                    int newrow = cell[0] + dir[0];
                    int newcol = cell[1] + dir[1];

                    if(newrow >= 0 && newrow < m && newcol >= 0 && newcol <n){
                        // when the new island is found, update the distance
                        if(grid[newrow][newcol] == 1){
                            min_d = min(min_d, level);
                        }
                        // if that cell is a water cell, convert it island and then push that into the newly processed level of island cells
                        else if(grid[newrow][newcol] == 0){
                            q.push({newrow, newcol});
                            grid[newrow][newcol] = 2;
                        }


                    }
                    
                }

            }

            // after every node from the current island is processed, it means that we are now jumping to the newly added 0 CONVERTED to 2 adjacent cells.
            level++;
        }

        return min_d;

        
    }

    void dfs(int i, int j, int m, int n, vector<vector<int>>&grid, vector<vector<int>>& dirn){
        // out of bounds or not island or island again
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j] == 2 || grid[i][j] == 0){
            return ;
        }

        grid[i][j] = 2; // mark them visited/color them as 1st island
        q.push({i,j}); // push to queue


        for(auto dir: dirn){
            dfs(i+dir[0], j+dir[1], m, n, grid, dirn);
        }
    }


    int shortestBridge(vector<vector<int>>& grid) {

        // 1st find the part of one island and mark all of its island parts as 2 (visited) (or colored)
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dirn = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};


        bool flag = false;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1 && flag == false){
                    dfs(i, j, m, n, grid, dirn);
                    // 1st island marked/colored as 2
                    flag = true;
                    break;
                }
            }
            if(flag){
                break;
            }
        }


        return bfsManhattanSearch(m, n, grid, dirn);
    }
};