/*
542. 01 Matrix

https://leetcode.com/problems/01-matrix/description/

Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two cells sharing a common edge is 1.

Example 1:
Input: mat = [[0,0,0],
              [0,1,0],
              [0,0,0]]
Output: [[0,0,0],
         [0,1,0],
         [0,0,0]]


         Example 2:
Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]
*/

class Solution {
    public:
        vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
            if(mat.empty() || mat[0].empty()){
                return {};
            }
    
            int m = mat.size();
            int n = mat[0].size();
    
            queue<vector<int>>q;
    
            int maxiDist = m*n;
    
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    if(mat[i][j] == 0){
                        // adding only 0's bcuz they need to be processed first for cell containin g 1 to be processed
                        q.push({i, j});
                    }
                    else{
                        // initiliased with a larger dist, might well use INFINITY bbut maxidist iss more practical
                        mat[i][j] = maxiDist;
                    }
                }
            }
    
    
    
            int dirn[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    
            while(!q.empty()){
                // auto [noderow, nodecol] = q.front();
                int noderow = q.front()[0];
                int nodecol = q.front()[1];
    
                q.pop();
    
                for(auto [r, c]: dirn){
                    int nextrow = r + noderow;
                    int nextcol = c + nodecol;
                    if(nextrow>=0 && nextrow<m && nextcol>=0 && nextcol<n){
                        // check if the distance to reach 0 is minimised
                        if(mat[nextrow][nextcol] > mat[noderow][nodecol] + 1){
                            mat[nextrow][nextcol] = mat[noderow][nodecol] + 1;
                            // add processed into queue
                            q.push({nextrow, nextcol});
                        }
                    }
                }
            }
    
            
            return mat; 
    
        }
    };