/*
200. Number of Islands

https://leetcode.com/problems/number-of-islands/description/

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
*/

class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& grid){
        if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size() || grid[row][col]!='1'){
            return ;
        }
        grid[row][col] = 'V';
        dfs(row, col+1, grid);
        dfs(row, col-1, grid);
        dfs(row+1, col, grid);
        dfs(row-1, col, grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        if(!grid.size()){
            return 0;
        }

        int islands = 0;

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    dfs(i, j, grid);
                    islands++;
                }
            }
        }
        return islands;
    }
};