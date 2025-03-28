/*
1219. Path with Maximum Gold

https://leetcode.com/problems/path-with-maximum-gold/

In a gold mine grid of size m x n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.

Return the maximum amount of gold you can collect under the conditions:

Every time you are located in a cell you will collect all the gold in that cell.
From your position, you can walk one step to the left, right, up, or down.
You can't visit the same cell more than once.
Never visit a cell with 0 gold.
You can start and stop collecting gold from any position in the grid that has some gold.
 
Example 1:
Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
Output: 24
Explanation:
[[0,6,0],
 [5,8,7],
 [0,9,0]]
Path to get the maximum gold, 9 -> 8 -> 7.

Example 2:
Input: grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
Output: 28
Explanation:
[[1,0,7],
 [2,0,6],
 [3,4,5],
 [0,3,0],
 [9,0,20]]
Path to get the maximum gold, 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7.
*/

class Solution {
    vector<vector<int>>dirn = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
public:
    int checkIfAllNonZeros(vector<vector<int>>& grid){
        int count = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] != 0) count += grid[i][j];
                else return 0;
            }
        }

        return count;
    }

    int dfs(int i, int j, vector<vector<int>>& grid, int m, int n){

        int currGold = grid[i][j];

        int localMaxiGold = currGold;

        // mark it as taken first
        grid[i][j] = 0;

        for(auto dir: dirn){
            int newRow = i + dir[0];
            int newCol = j + dir[1];
            // should be within boundary of matrix, and also have GOLD
            if(newRow>=0 && newRow<m && newCol>=0 && newCol<n && grid[newRow][newCol]){
                localMaxiGold = max(localMaxiGold, currGold + dfs(newRow, newCol, grid, m, n));
            }
            
        }

        // backtrack to mark it as non visited;
         grid[i][j] = currGold;

         return localMaxiGold;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int count = checkIfAllNonZeros(grid);
        if(count) {
            return count; 
        }

        int maxiGold = 0;

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]){
                    maxiGold = max(maxiGold, dfs(i, j, grid, grid.size(), grid[0].size()));
                }
            }
        }

        return maxiGold;
    }
};