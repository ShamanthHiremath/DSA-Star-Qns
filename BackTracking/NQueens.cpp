/*
51. N-Queens

https://leetcode.com/problems/n-queens/

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

Example 1:
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

Example 2:
Input: n = 1
Output: [["Q"]]
 
*/

class Solution {
    public:
        bool isSafe(int row, int col, int n, vector<string>& board) {
            // Check the column
            for(int i = 0; i < row; i++){
                if(board[i][col] == 'Q'){
                    return false;
                }
            }
            // Check diagonal (upper-left)
            for(int i = row, j = col; i >= 0 && j >= 0; i--, j--){
                if(board[i][j] == 'Q'){
                    return false;
                }
            }
            // Check diagonal (upper-right)
            for(int i = row, j = col; i >= 0 && j < n; i--, j++){
                if(board[i][j] == 'Q'){
                    return false;
                }
            }
            return true;
        }
    
        void solve(int row, int n, vector<string>& board, vector<vector<string>>& result) {
            if(row == n){ 
                result.push_back(board);
                return;
            }
    
            for(int col = 0; col < n; col++){
                if(isSafe(row, col, n, board)){
                    board[row][col] = 'Q';
                    solve(row + 1, n, board, result);
                    board[row][col] = '.'; // Backtracking
                }
            }
        }
    
        vector<vector<string>> solveNQueens(int n) {
            // backtracking + recursion
            vector<vector<string>> result;
            vector<string> board(n, string(n, '.'));
            solve(0, n, board, result);
            return result;
        }
    };