
// Question) 348. Design Tic-Tac-Toe


// Implementation

// 1st Approach, Naive Approach
// Using Matrix
// Time Complexity : O(4*N) => O(N)
// Space Complexity : O(N^2)

class TicTacToe {
private:
    vector<vector<int>> board;
    int n;
    
    bool checkRow(int row, int player){
        for(int col = 0; col < n; col++){
            if(board[row][col] != player) return false;
        }
        
        return true;
    }
    
    bool checkCol(int col, int player){
        for(int row = 0; row < n; row++){
            if(board[row][col] != player) return false;
        }
        
        return true;
    }
    
    bool checkDiagonal(int player){
        for(int row = 0, col = 0; row < n; col++, row++){
            if(board[col][row] != player) return false;
        }
        
        return true;
    }
    
    bool checkAntiDiagonal(int player){
        for(int row = 0, col = n-1; row < n; col--, row++){
            if(board[col][row] != player) return false;
        }
        
        return true;
    }
    
public:
    TicTacToe(int n) {
        board.assign(n, vector<int>(n, 0));
        this->n = n;
    }
    
    int move(int row, int col, int player) {
        board[row][col] = player;
        
        if(checkRow(row, player)
                || checkCol(col, player)
                || (row == col && checkDiagonal(player))
                || (col == n-row-1 && checkAntiDiagonal(player))){
            return player;
        }
        
        return 0;
    }
};
