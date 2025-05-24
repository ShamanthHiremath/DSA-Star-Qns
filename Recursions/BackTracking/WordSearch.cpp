/*
79. Word Search

https://leetcode.com/problems/word-search/

Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once. 

Example 1:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Example 3:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 
*/

class Solution {
public:
    vector<vector<int>>dirn = {{-1, 0}, {+1, 0}, {0, -1}, {0, +1}};
    bool isSafe(int row, int col, int m, int n){
        if(row<m && row>=0 && col<n && col>=0){
            return true;
        }
        return false;
    }

    bool solve(int row, int col, int wordInd, vector<vector<char>>& board, string word){
        if(wordInd == word.size()){
            return true;
        }
        // BACKTRACKING IS NEEDED
        // because if the nextrow matches the word[wordInd], then when solving the for loop part for the next indexes using dirn,
        //  the nextrow, nextcol will still have access to the previous row, previous col, which called the function, so to avoid MARK IT.
        char temp = board[row][col];
        board[row][col] = '#';

        for(auto dir: dirn){
            int nextrow = row + dir[0];
            int nextcol = col + dir[1];
            if(isSafe(nextrow, nextcol, board.size(), board[0].size()) && board[nextrow][nextcol] == word[wordInd]){
                if(solve(nextrow, nextcol, wordInd+1, board, word)){
                    return true;
                }
            }
        }
        board[row][col] = temp; // backtrack
        return false;

    }

    bool exist(vector<vector<char>>& board,const string& word) {

        unordered_map<char, int> boardCount, wordCount;

        for (auto& row : board)
            for (char c : row)
                boardCount[c]++;
        for (char c : word)
            wordCount[c]++;

        for (auto& [ch, cnt] : wordCount) {
            if (boardCount[ch] < cnt)
                return false;
        }

        int wordInd = 0;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == word[0] && solve(i, j, wordInd+1, board, word)){
                    return true;
                }
            }
        }

        return false;
    }
};