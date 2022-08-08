
// Question) 130. Surrounded Regions


// Implementation

// Using DFS
// Time Complexity = O(M*N)
// Space Complexity = O(M*N)
class Solution {
private:
    void dfs(vector<vector<char>> &board, int row, int col){
        if(row >= 0 && col >= 0 && row < board.size() && col < board[0].size() && 
           board[row][col] == 'O'){
            board[row][col] = '#';
            
            dfs(board, row-1, col); // top
            dfs(board, row, col-1); // left
            dfs(board, row+1, col); // down
            dfs(board, row, col+1); // right
        }
    }
    
public:
    void solve(vector<vector<char>>& board) {
        
        int row = board.size(), col = board[0].size();
        
        // checking for first and last row
        for(int i = 0; i < col; i++){
            
            // first row
            if(board[0][i] == 'O'){
                dfs(board, 0, i);
            }
            
            // last row
            if(board[row-1][i] == 'O'){
                dfs(board, row-1, i);
            }
        }
        
        // checking for first and last column
        for(int i = 0; i < row; i++){
            
            // first row
            if(board[i][0] == 'O'){
                dfs(board, i, 0);
            }
            
            // last row
            if(board[i][col-1] == 'O'){
                dfs(board, i, col-1);
            }
        }
        
        // traversing over whole matrix
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                
                if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};

// Algo Steps
// 1) Firstly check boundary (first row, last row, first col & last col) if they are having O then explore all the 4 directions if they are also having O then do the same, sorround it again and convert them into #.
// 2) # means we can't convert them into X.
// 3) the values which will remains O those we can easily convert them into X, because they are not connected with any border which are having O.
