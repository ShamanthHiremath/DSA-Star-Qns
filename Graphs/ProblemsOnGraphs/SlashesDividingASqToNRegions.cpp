/*
959. Regions Cut By Slashes

https://leetcode.com/problems/regions-cut-by-slashes/

An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a '/', '\', or blank space ' '. These characters divide the square into contiguous regions.

Given the grid grid represented as a string array, return the number of regions.

Note that backslash characters are escaped, so a '\' is represented as '\\'.

Example 1:
 ----
|  /|
|/  |
 ----

Input: grid = [" /","/ "]
Output: 2
Can be converted to
0 0 0 0 0 1
0 0 0 0 1 0
0 0 0 1 0 0
0 0 1 0 0 0
0 1 0 0 0 0
1 0 0 0 0 0

Example 2:
 ----
|  /|
|   |
 ----

Input: grid = [" /","  "]
Output: 1
Can be converted to
0 0 0 0 0 1
0 0 0 0 1 0
0 0 0 1 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0

Example 3:
 -------
|  / \ |
|/    \|
|\   / |
| \/  |
-------

Input: grid = ["/\\","\\/"]
Output: 5
Can be converted to
0 0 1 1 0 0
0 1 0 0 1 0
1 0 0 0 0 1
1 0 0 0 0 1
0 1 0 0 1 0
0 0 1 1 0 0

Explanation: Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.

*/

class Solution {
public:
    void dfs(int crow, int ccol, int& n, vector<vector<int>>& matrix, vector<vector<bool>>&visited){
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
            if(nextrow < 0 || nextrow >= n*3 || nextcol < 0 || nextcol >=n*3 || matrix[nextrow][nextcol] != 0 || visited[nextrow][nextcol] == true ){
                continue;
            }
            // apply dfs to next row and next col positions of 0
            dfs(nextrow, nextcol, n, matrix, visited);
        }
    }

    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        //construction of 0,1 matrix of size n*3 x n*3
        vector<vector<int>>matrix(n*3, vector<int>(n*3, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '/'){
                    matrix[i*3][j*3 + 2] = 1;
                    matrix[i*3 + 1][j*3 + 1] = 1;
                    matrix[i*3 + 2][j*3] = 1;
                }
                else if(grid[i][j] == '\\'){
                    matrix[i*3][j*3] = 1;
                    matrix[i*3 + 1][j*3 + 1] = 1;
                    matrix[i*3 + 2][j*3 + 2] = 1;
                }
            }
        }

            //so applying dfs to find the number of different regions formed by the 0's
            //apparently each region divided by slashes shall consist of only 0's 
            //so dfs for 0's helps in finding out the regions of 0's that are disconnected components by slashes

        int cnt = 0;
        //visited matrix
        vector<vector<bool>>visited(n*3, vector<bool>(n*3, false));
        
        for(int i=0; i<n*3; i++){
            for(int j=0; j<n*3; j++){
                if(matrix[i][j] == 0 && !visited[i][j]){
                    cnt++;
                    dfs(i, j, n, matrix, visited);
                }
            }
        }
        
        return cnt;
    }
};

