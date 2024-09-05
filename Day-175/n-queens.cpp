class Solution {
public:
    vector<vector<string>> answer;
    unordered_map<int, bool> rowChk;
    unordered_map<int, bool> upperLDiagChk;
    unordered_map<int, bool> lowerLDiagChk;

    bool isSafe(int row, int col, vector<string> board, int n) {

        if (rowChk[row] == true || upperLDiagChk[n - 1 + col - row] == true ||
            lowerLDiagChk[row + col] == true) {
            return false;
        }

        return true;
    }

    void solve(vector<string> board, int col, int n){

        // base case
        if(col>=n){
            answer.push_back(board);
            return;
        }

        for(int row = 0; row<n; row++){
            if(isSafe(row,col,board,n)){

                board[row][col] = 'Q';

                rowChk[row] = true;
                upperLDiagChk[n-1+col-row] = true;
                lowerLDiagChk[row+col] =  true;

                // Recursion to solve rem. cases
                solve(board,col+1,n);

                // Backtracking
                board[row][col] = '.';
                rowChk[row] = false;
                upperLDiagChk[n-1+col-row] = false;
                lowerLDiagChk[row+col] =  false;

            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        if (n == 1) {
            return {{"Q"}};
        }
        if (n == 2 || n == 3) {
            return {};
        }

        vector<string> board(n, string(n, '.'));
        int col = 0;
        solve(board, col, n);

        return answer;
    }

};
