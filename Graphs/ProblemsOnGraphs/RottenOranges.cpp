/*
994. Rotting Oranges

https://leetcode.com/problems/rotting-oranges/
https://www.geeksforgeeks.org/problems/rotten-oranges2536/1

You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

Example 1:
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

Example 2:
Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

Example 3:
Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
*/

// BFS

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>>q;
        int fresh = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1) fresh++;
                else if(grid[i][j] == 2) q.push({i, j});
            }
        }

        if(fresh==0){
            return 0;
        }

        auto validPosn = [](int newRow, int newCol, int m, int n) {
            return (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n);
        };

        
        int rotorange=0;
        int time=-1;
        //                 left,    right,    up,     down
        int dirn[4][4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; 

        while(!q.empty()){
            int size = q.size();
            for(int k=0; k<size; k++){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for(int i=0; i<4; i++){
                    int newRow = row + dirn[i][0];
                    int newCol = col + dirn[i][1];
                    if(validPosn(newRow, newCol, grid.size(), grid[0].size()) && grid[newRow][newCol]==1){
                        grid[newRow][newCol] = 2;
                        q.push({newRow, newCol});
                        rotorange++;
                    }
                }
            }
            time++;
        }

        if(rotorange == fresh){
            return time;
        }
        return -1;


    }
};