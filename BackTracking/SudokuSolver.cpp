/*
37. Sudoku Solver

https://leetcode.com/problems/sudoku-solver/

Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.


Example 1:
Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
Explanation: The input board is shown above and the only valid solution is shown below:


*/
class Solution {
public:
    bool isSafe(char num, int row, int col, vector<vector<char>>& board){
        // check for row and col if they have the same num
        int i = 0;
        for(int i=0; i<board.size(); i++){
            if(board[row][i] == num || board[i][col] == num){
                return false;
            }
        }
        
        // now check for the SQUARE of that row and col
        int st_sq_row = row/3 * 3, st_sq_col = col/3 * 3;

        for(int i=st_sq_row; i<st_sq_row+3; i++){
            for(int j=st_sq_col; j<st_sq_col+3; j++){
                if(board[i][j] == num){
                    return false;
                }
            }
        }

        return true;
    }
    bool solveSudokuHelper(vector<vector<char>>& board) {
        for(int row=0; row<9; row++){
            for(int col=0; col<9; col++){
                if(board[row][col] == '.'){
                    for(char num='1'; num<='9'; num++){
                        if(isSafe(num, row, col, board)){
                            board[row][col] = num;
                            if(solveSudokuHelper(board)){
                                    return true;
                            }
                            board[row][col] = '.';
                        }
                    }
                    return false;
                    
                }
            }
        }

        return true;

    }
    void solveSudoku(vector<vector<char>>& board) {
        solveSudokuHelper(board);
    }
};