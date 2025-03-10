/*
695. Max Area of Island

https://leetcode.com/problems/max-area-of-island/

You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.


Example 1:
Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.

Example 2:
Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0
*/

class Solution {
    public:
        void dfsIsland(int &area, int r, int c, vector<vector<int>>& grid){
            grid[r][c] = 0;
            area++;
            int dirn[4][2] = {{-1, 0} ,{+1, 0} ,{0, -1} ,{0, +1}};
    
            for(auto dir: dirn){
                int nextrow = r + dir[0];
                int nextcol = c + dir[1];
                
                
                if(nextrow >= 0 && nextrow<=grid.size()-1 && nextcol>=0 && nextcol<=grid[0].size()-1 && grid[nextrow][nextcol] == 1){
                    dfsIsland(area, nextrow, nextcol, grid);
                }
            }
    
        }
    
        int maxAreaOfIsland(vector<vector<int>>& grid) {
            if(!grid.size()){
                return 0;
            }
    
            int ans = 0;
    
            for(int i=0; i<grid.size(); i++){
                for(int j=0; j<grid[0].size(); j++){
                    if(grid[i][j]){
                        int area = 0;
                        dfsIsland(area, i, j, grid);
                        ans = max(ans, area);
                    }
                }
            }
            
            return ans;
        }
    };
    
    