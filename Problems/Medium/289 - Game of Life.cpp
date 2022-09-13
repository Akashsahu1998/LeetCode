
// Question) 289. Game of Life


// Implementation

// Time Complexity = O(M * N * 8) => O(M * N)
// Space Complexity = O(1)

class Solution {
private:
	// check whether its a valid cell or not
    bool isValidNeighbour(int newRow, int newCol, vector<vector<int>>& board){
        return (newRow >= 0 && newCol >= 0 && newRow < board.size() && newCol < board[0].size());
    }

public:
    void gameOfLife(vector<vector<int>>& board) {
        int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
        
        for(int row = 0; row < board.size(); row++){
            for(int col = 0; col < board[row].size(); col++){
                int countLiveNeighbours = 0;
                
                for(int dir = 0; dir < 8; dir++){
                    int newRow = dx[dir] + row;
                    int newCol = dy[dir] + col;
                    
                    if(isValidNeighbour(newRow, newCol, board) && abs(board[newRow][newCol]) == 1){
                        countLiveNeighbours++;
                    }
                }
                
                // if its live cell
                // and its fulfilling conditions
                // then make it dead cell by converting it into -1
                if(board[row][col] == 1 && (countLiveNeighbours < 2 || countLiveNeighbours > 3)){
                   board[row][col] = -1; 
                }
                
                // if its dead cell
                // and its fulfilling conditions
                // then make it live cell by converting it into 2
                if(board[row][col] == 0 && countLiveNeighbours == 3){
                   board[row][col] = 2;
                }
            }
        }
        
        for(int row = 0; row < board.size(); row++){
            for(int col = 0; col < board[row].size(); col++){
                if(board[row][col] >= 1){
                    board[row][col] = 1;
                }
                else{
                    board[row][col] = 0;
                }
            }
        }
    }
};


// Algo Step's
//1) Go into all 8 directions, and check the condition
//2) Convert dead cell into -1, and live cell into 2, and later convert back to its respective dead/cell number
