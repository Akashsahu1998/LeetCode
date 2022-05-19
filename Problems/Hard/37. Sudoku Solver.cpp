
// Question) 37. Sudoku Solver


// Implementation

// Using Recursion & Backtracking
class Solution {
private:
    bool solve(vector<vector<char>>& board) {
        
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                
                if(board[i][j] == '.'){
                 
                    for(char ch = '1'; ch <= '9'; ch++){
                        
                        if(isValid(i, j, board, ch)){
                            board[i][j] = ch;
                         
                            if(solve(board)){
                                return true;
                            }
                            else {
                                // backtracking
                                board[i][j] = '.';
                            }
                        }                         
                    }                    
                    return false;                    
                }                
            }
        }
        return true;
    }
    
    bool isValid(int row, int col, vector<vector<char>>& board, char ch){
        
        for(int i = 0; i < board.size(); i++){
            
            // for row
            if(board[row][i] == ch) return false;
            
            // for col
            if(board[i][col] == ch) return false;
            
            // for the group of the 3*3
            int newRow = (3*(row/3)) + (i/3);
            int newCol = (3*(col/3)) + (i%3);
            if(board[newRow][newCol] == ch) return false;
        }
            
        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
