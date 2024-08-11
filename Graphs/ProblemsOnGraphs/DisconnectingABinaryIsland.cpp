/*
1568. Minimum Number of Days to Disconnect Island

https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/

You are given an m x n binary grid grid where 1 represents land and 0 represents water. An island is a maximal 4-directionally (horizontal or vertical) connected group of 1's.

The grid is said to be connected if we have exactly one island, otherwise is said disconnected.
In one day, we are allowed to change any single land cell (1) into a water cell (0).
Return the minimum number of days to disconnect the grid.

Hint 1
Return 0 if the grid is already disconnected.
Hint 2
Return 1 if changing a single land to water disconnect the island.
Hint 3
Otherwise return 2.
Hint 4
We can disconnect the grid within at most 2 days.

Example 1:
0 1 1 0        0 1 0 0
0 1 1 0   ->   0 0 1 0
0 0 0 0        0 0 0 0 

Input: grid = [[0,1,1,0],[0,1,1,0],[0,0,0,0]]

Output: 2
Explanation: We need at least 2 days to get a disconnected grid.
Change land grid[1][1] and grid[0][2] to water and get 2 disconnected island.
Example 2:
1 1   ->  0 0

Input: grid = [[1,1]]
Output: 2
Explanation: Grid of full water is also disconnected ([[1,1]] -> [[0,0]]), 0 islands.

Example 3:
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1

->

1 1 1 1        1 1 0 1
1 1 1 1   or   1 1 1 0
0 1 1 1        1 1 1 1
1 0 1 1        1 1 1 1

*/

class Solution {
public:
    void dfs(int crow, int ccol, int& n, int&m, vector<vector<int>>& matrix, vector<vector<bool>>&visited){
        visited[crow][ccol] = true;
        
        // so there can be 4 combinations to move upon to the next vertex/node or 0
        // they are (up) (down) (left) (right)
        // so let dirnrow denote -1 for up, +1 for down, 0 for current row
        // and dircol denote -1 for left, +1 for right, 0 for current col
        // so (-1, 0) indicates up, (0, -1) left, (1, 0) down, (0, 1) right
        vector<int>dirnrow = {-1, 0, 1, 0};
        vector<int>dirncol = {0, -1, 0, 1};

        for(int i=0; i<4; i++){
            int nextrow = crow + dirnrow[i];
            int nextcol = ccol + dirncol[i];
            if(nextrow < 0 || nextrow >= m || nextcol < 0 || nextcol >=n || matrix[nextrow][nextcol] != 1 || visited[nextrow][nextcol] == true ){
                continue;
            }
            // apply dfs to next row and next col positions of 0
            dfs(nextrow, nextcol, n, m, matrix, visited);
        }
    }

    int countIslands(int&m, int&n, vector<vector<int>>&grid){
        vector<vector<bool>>visited(m, vector<bool>(n, false));
        int count = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1 && visited[i][j] != true){
                    dfs(i, j, n, m, grid, visited);
                    count++;
                }
            }
        }
        return count;
    }
    int minDays(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // checking if there are more than 1 or 0 islands or not
        int initialIslandCount = countIslands(m, n, grid);

        // there are no islands or there are more than one islands
        if(initialIslandCount != 1){
            return 0;
        }

        // Case 1: We can diconnect the islands in 1 day
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    //change it to water 0
                    grid[i][j] = 0;

                    int newIslandCount = countIslands(m, n, grid);

                    if(newIslandCount != 1){
                        return 1;
                    }
                    // if not backtrack and change the block to island 1
                    grid[i][j] = 1;
                }
            }
        }
        // Case 2; If the newIslandCount is 1 throughout, we need 2 days
        return 2;
    }
};