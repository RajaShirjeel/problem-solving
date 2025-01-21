class Solution {
public:

    bool isSafe(int row, int col, vector<string>&board, int n){
        int dupRow = row;
        int dupCol = col;

        while (row >= 0 && col >= 0){
            if (board[row][col] == 'Q'){
                return false;
            }
            row --;
            col --;
        }

        row = dupRow;
        col = dupCol;

        while (col >= 0){
            if (board[row][col] == 'Q'){
                return false;
            }
            col--;
        }

        row = dupRow;
        col = dupCol;

        while (row < n && col >= 0){
            if (board[row][col] == 'Q'){
                return false;
            }

            row ++;
            col --;
        }

        return true;
    }

    void solve(int col, vector<string>&board, vector<vector<string>>&res, int n){
        if (col == n){
            res.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++){
            if (isSafe(row, col, board, n)){
                board[row][col] = 'Q';
                solve(col + 1, board, res, n);
                board[row][col] = '.';

            }
        }

    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        vector<string>board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++){
            board[i] = s;
        }
        solve(0, board, res, n);
        return res;
    }
};