
// Question) 51. N-Queens


// Implementation

// Using Recursion & Backtracking
class Solution {
private:
    bool canWeFillQueen(int row, int col, vector<string> board, int n){
        int rowBackup = row, colBackup = col;
        
        // checking diagonal on upper side
        while(row >=0 && col >= 0){
            if(board[row--][col--] == 'Q') return false;
        }
        
        // checking left side
        row = rowBackup;
        col = colBackup;
        while(row >=0 && col >= 0){
            if(board[row][col--] == 'Q') return false;
        }
        
        // checking diagonal on lower side
        row = rowBackup;
        col = colBackup;
        while(row < n && col >= 0){
            if(board[row++][col--] == 'Q') return false;
        }        
        
        return true;
    }
    
    void fillQueen(vector<string> board, vector<vector<string>> &res, int n, int col){
        if(col == n){
            res.push_back(board);
            return;
        }
        
        for(int row = 0; row < n; row++){
            if(canWeFillQueen(row, col, board, n)){
                board[row][col] = 'Q';
                fillQueen(board, res, n, col+1);
                board[row][col] = '.'; // backtracking
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n);
        string str(n, '.');
        for(int i = 0; i < n; i++){
            board[i] = str;
        }
        
        fillQueen(board, res, n, 0);
        
        return res;
    }
};
