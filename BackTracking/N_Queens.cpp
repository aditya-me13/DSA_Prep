class Solution {
public:
    void helper(int col, int n, vector<string> &board, vector<vector<string>> &ans, vector<bool> &leftRow, vector<bool> &upperDiagonal, vector<bool> &lowerDiagonal){
        if(col == n){
            ans.push_back(board);
            return;
        }
        
        for(int row = 0; row<n; row++){
            if(!leftRow[row] && !upperDiagonal[row+col] && !lowerDiagonal[n-1+col-row]){
                board[row][col] = 'Q';
                leftRow[row] = true;
                upperDiagonal[row+col] = true;
                lowerDiagonal[n-1+col-row] = true;
                helper(col+1, n, board, ans, leftRow, upperDiagonal, lowerDiagonal);
                board[row][col] = '.';
                leftRow[row] = false;
                upperDiagonal[row+col] = false;
                lowerDiagonal[n-1+col-row] = false;
            }
        }
    }
        
        
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for(int i = 0; i<n; i++){
            board[i] = s;
        }
        vector<bool> leftRow(n, false), upperDiagonal(2*n -1, false), lowerDiagonal(2*n - 1, false);
        helper(0, n, board, ans, leftRow, upperDiagonal, lowerDiagonal);
        return ans;
    }
};