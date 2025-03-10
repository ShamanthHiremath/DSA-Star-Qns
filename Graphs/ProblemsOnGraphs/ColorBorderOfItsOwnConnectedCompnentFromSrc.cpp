/*
1034. Coloring A Border

https://leetcode.com/problems/coloring-a-border/

You are given an m x n integer matrix grid, and three integers row, col, and color. Each value in the grid represents the color of the grid square at that location.

Two squares are called adjacent if they are next to each other in any of the 4 directions.

Two squares belong to the same connected component if they have the same color and they are adjacent.

The border of a connected component is all the squares in the connected component that are either adjacent to (at least) a square not in the component, or on the boundary of the grid (the first or last row or column).

You should color the border of the connected component that contains the square grid[row][col] with color.

Return the final grid.

Example 1:
Input: grid = [[1,1],[1,2]], row = 0, col = 0, color = 3
Output: [[3,3],[3,2]]

Example 2:
Input: grid = [[1,2,2],[2,3,2]], row = 0, col = 1, color = 3
Output: [[1,3,3],[2,3,3]]

Example 3:
Input: grid = [[1,1,1],[1,1,1],[1,1,1]], row = 1, col = 1, color = 2
Output: [[2,2,2],[2,1,2],[2,2,2]]
 
*/

// says travel the borders of the component in grid[r][c] only and color the border of that component with color

// employ a dfs, 
// can start with the src, and if the node is not 4 directionally connected to a color color 
// it, or else just call it visited, then move

// its better to have a differnent isBorder matrix, cuz changing the grid itself might just affect the other adjacemnt cells, since it can act like a border in dfs traversal

class Solution {
    public:
        void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& visited, int srcColor, vector<vector<bool>>& isBorder) {
            int rows = grid.size(), cols = grid[0].size();
            visited[r][c] = true;
    
            int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            bool isBorderCell = false;
    
            for (auto& dir : directions) {
                int nextRow = r + dir[0];
                int nextCol = c + dir[1];
    
                if (nextRow < 0 || nextRow >= rows || nextCol < 0 || nextCol >= cols || grid[nextRow][nextCol] != srcColor) {
                    isBorderCell = true;  // It's a border
                } 
                else if (!visited[nextRow][nextCol]) {
                    dfs(nextRow, nextCol, grid, visited, srcColor, isBorder);
                }
            }
    
            if (isBorderCell) {
                isBorder[r][c] = true;
            }
        }
    
        vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
            int rows = grid.size(), cols = grid[0].size();
            vector<vector<bool>> visited(rows, vector<bool>(cols, false));
            vector<vector<bool>> isBorder(rows, vector<bool>(cols, false));
            int srcColor = grid[row][col];
    
            dfs(row, col, grid, visited, srcColor, isBorder);
    
            // Only modify border cells
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (isBorder[i][j]) {
                        grid[i][j] = color;
                    }
                }
            }
    
            return grid;
        }
    };