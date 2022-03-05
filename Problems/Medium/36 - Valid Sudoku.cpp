
// Question) 36. Valid Sudoku


// Implementation

// Using Unordered Set
// Time Complexity = O(N^2)
// Space Complexity = O(N^2)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        // store the row index and value of that particular row index
        // store the col index and value of that particular col index
        // store the particular box index and value in the particular box index
        // we will store the row, col & box index and their value into this visited unordered set
        unordered_set<string> visited;
        
        for(int row = 0; row < 9; row++){
            for(int col = 0; col < 9; col++){
                
                // if the current index value if dot(.) then we don't need to do anything 
                if(board[row][col] != '.'){
                    
                    // if any particular (row index with value) or (col index with value) or (box index with value) already visited it means that is not a valid sudoku, so we will directly return false
                    if(visited.find("Row" + to_string(row) + to_string(board[row][col])) != visited.end()
                       || visited.find("Col" + to_string(col) + to_string(board[row][col])) != visited.end()
                       || visited.find("Box" + to_string(((row/3) * 3 + (col/3))) + to_string(board[row][col])) != visited.end()){
                        return false;
                    }
                    
                    // if not visited yet, then add (row index & value) and (col index & value) and (box index & value) into the visited unordered set
                    visited.insert("Row" + to_string(row) + to_string(board[row][col]));
                    visited.insert("Col" + to_string(col) + to_string(board[row][col]));
                    visited.insert("Box" + to_string((row/3)*3 + (col/3)) + to_string(board[row][col]));
                }
            }
        }
        
        return true;
    }
};