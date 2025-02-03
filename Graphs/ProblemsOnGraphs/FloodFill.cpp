/*
733. Flood Fill

https://leetcode.com/problems/flood-fill/

You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill:

Begin with the starting pixel and change its color to color.
Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
The process stops when there are no more adjacent pixels of the original color to update.
Return the modified image after performing the flood fill.

Example 1:
Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation:
From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not horizontally or vertically connected to the starting pixel.

Example 2:
Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
Output: [[0,0,0],[0,0,0]]
Explanation:
The starting pixel is already colored with 0, which is the same as the target color. Therefore, no changes are made to the image.
*/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        if(grid[sr][sc] == color){
            return grid;
        }
        queue<pair<int, int>>q;
        q.push({sr, sc});
        
        int startcolor = grid[sr][sc];
        grid[sr][sc] = color;

        auto validPosn = [](int newRow, int newCol, int m, int n) {
            return (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n);
        };

        
        //                 left,    right,    up,     down
        int dirn[4][4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; 

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int i=0; i<4; i++){
                int newRow = row + dirn[i][0];
                int newCol = col + dirn[i][1];
                if(validPosn(newRow, newCol, grid.size(), grid[0].size()) && grid[newRow][newCol]==startcolor){
                    grid[newRow][newCol] = color;
                    q.push({newRow, newCol});
                }
            }
        }

        return grid;
    }
};