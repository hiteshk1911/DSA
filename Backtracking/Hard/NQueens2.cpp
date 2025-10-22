Count of all possible ways to place N queens on an N x N chessboard.

class Solution {
    bool isSafe(int row,int col,vector<vector<int>> &board,int n){
         // Check column
        for (int i = 0; i < row; ++i) {
            if (board[i][col] == 1)
                return false;
        }

        // Check upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 1)
                return false;
        }

        // Check upper-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
            if (board[i][j] == 1)
                return false;
        }

        return true;
    }
    void totalNQueensHelper(int row,vector<vector<int>> &board,int& count,int n){
        if(row>=n){
            count++;
            return ;
        }

        for(int j=0;j<n;j++){
            if(isSafe(row,j,board,n)){
                board[row][j]=1;
                totalNQueensHelper(row+1,board,count,n);
                board[row][j]=0;
            }
        }

    }
public:
    int totalNQueens(int n) {
        vector<vector<int>> board(n,vector<int>(n,0));

        int count = 0;
        totalNQueensHelper(0,board,count,n);
        return count;

    }
};