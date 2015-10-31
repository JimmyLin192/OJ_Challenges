/*###############################################################
## MODULE: 37_SudokuSolver.cpp
## VERSION: 1.0 
## SINCE 2015-10-28
## AUTHOR Jimmy Lin (xl5224) - JimmyLin@utexas.edu  
## DESCRIPTION: 
##      
#################################################################
## Edited by MacVim
## Class Info auto-generated by Snippet 
################################################################*/

class Solution {
public:
    int m;
    int n;
    vector<vector<char>> solution; 
    bool isValid (vector<vector<char>>& board, int r, int c, int s) {
        char toput = s+'0';
        // check the residing row
        for (int j = 0; j < n; j ++) {
            if (board[r][j]=='.') continue;
            if (board[r][j]==toput) return false;
        }
        // check the residing col
        for (int i = 0; i < m; i ++) {
            if (board[i][c]=='.') continue;
            if (board[i][c]==toput) return false;
        }
        // check the residing block
        int i_start = r/3*3, i_end = r/3*3+3;
        int j_start = c/3*3, j_end = c/3*3+3;
        for (int i = i_start; i < i_end; i ++) {
            for (int j = j_start; j < j_end; j ++) {
                if (board[i][j]=='.') continue;
                if (board[i][j]==toput) return false;
            }
        }
        return true;
    }
    void solve(vector<vector<char>>& board, vector<pair<int,int>>& slots, int k) {
        // solution satisfaction condition
        if (k == slots.size()) {
            // store the solved sudoku
            for (int i = 0; i < board.size(); i++)
                solution.push_back(vector<char>(board[i]));
            return ;
        }
        // loop and recursion
        for (int s = 1; s <= 9; s++) {
            int i = slots[k].first, j = slots[k].second;
            if (isValid(board, i, j, s)) {
                board[i][j] = s + '0';
                solve (board, slots, k+1);
                board[i][j] = '.';
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        m = board.size();
        if (m <= 0) return;
        n = board[0].size();
        if (n <= 0) return;
        // STEP ONE: find all empty slots
        vector<pair<int,int>> slots;
        for (int i = 0; i < m; i ++) 
            for (int j = 0; j < n; j ++) 
                if (board[i][j]=='.')
                    slots.push_back(make_pair(i,j));
        // STEP TWO: invoke backtracking
        solve(board, slots, 0);
        // STEP THREE: copy the found solution back to board
        for (int i = 0; i < m; i ++) 
            board[i] = solution[i];
    }
};