
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



// 2nd Approach, Efficient Approach
// Using Single Dimensional Array
// Time Complexity : O(1)
// Space Complexity : O(N)

class TicTacToe {
private:
    vector<int> rows, cols;
    int diagonal = 0, anitDiagonal = 0, n;
    
public:
    TicTacToe(int n) {
        this->n = n;
        rows.assign(n, 0);
        cols.assign(n, 0);
    }
    
    int move(int row, int col, int player) {
        int curPlayer = (player == 1) ? 1 : -1;
        
        rows[row] += curPlayer;
        cols[col] += curPlayer;
        
        if(row == col) diagonal += curPlayer;
        if(n-row-1 == col) anitDiagonal += curPlayer;
        
        if(abs(rows[row]) == n
               || abs(cols[col]) == n
               || abs(diagonal) == n
               || abs(anitDiagonal) == n){
            return player;
        }
        
        else return 0;
    }
};


// **1st Approach**
// 1) insert the player on row & col
// 2) check row, col, diagonal and anti-diagonal
// 3) if whole row is having same player, then true, same for all cases


// **2nd Approach**
// 1) Take 2 array for row & col, if player one will come then increment the value by 1, if player      2 will come then decrement the value by 1, if any time row or col reaches n so player 1 will win, or reaches -n then player 2 will win.
// 2) Similarly take 2 variable for diagonal & antidiagonal, and do the same 


/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
