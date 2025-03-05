/*
130. Surrounded Regions

https://leetcode.com/problems/surrounded-regions/

You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.


Example 1:
Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Explanation:
In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.

Example 2:
Input: board = [["X"]]
Output: [["X"]]
*/

// All the "O" that are not directly/indirectly connected to the "O" on the boundary line, will be captured and converted into "X"

class Solution {
    private: 
    // employs dfs on the O cells and converts every adjacent O cell attached to it to Safe State 'S'
        void dfsSafe(int i, int j, vector<vector<char>>& board){
            int m = board.size();
            int n = board[0].size();
    
            
            board[i][j] = 'S';
    
            int dirn[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
            for(auto [r, c]: dirn){
                int nextrow = r + i;
                int nextcol = c + j;
                if(nextrow>=0 && nextrow<m && nextcol>=0 && nextcol<n){
                    if(board[nextrow][nextcol] == 'O'){
                        dfsSafe(nextrow, nextcol, board);
                    }
                }
            }
        }
    public:
        void solve(vector<vector<char>>& board) {
    
            // col 0, n-1 boundary check for O cells and employ dfsSafe
            for(int i=0; i<board.size(); i++){
                if(board[i][0] == 'O'){
                    dfsSafe(i, 0, board);
                }
                if(board[i][board[0].size()-1] == 'O'){
                    dfsSafe(i, board[0].size()-1, board);
                }
            }
    
            // row 0, m-1 boundary check for O cells and employ dfsSafe
            for(int j=0; j<board[0].size(); j++){
                if(board[0][j] == 'O'){
                    dfsSafe(0, j, board);
                }
                if(board[board.size()-1][j] == 'O'){
                    dfsSafe(board.size()-1, j, board);
                }
            }
    
    
            // CONVERT unsafe Os to X,        safe Ss to Os
            for(int i=0; i<board.size(); i++){
                for(int j=0; j<board[0].size(); j++){
                    if(board[i][j]=='S') board[i][j] = 'O';
                    else board[i][j] = 'X';
                }
            }
    
        }
    };