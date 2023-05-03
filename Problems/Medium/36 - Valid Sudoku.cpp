
// Question) 36. Valid Sudoku


// Implementation

// https://www.youtube.com/watch?v=rJ9NFK9s_mI
// Using Unordered Set
// Time Complexity = O(N^2)
// Space Complexity = O(N^2)
class Solution{
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
                    
                    string rowValue = "row" + to_string(row) + board[row][col];
                    string colValue = "col" + to_string(col) + board[row][col];
                    string boxValue = "box" + to_string(((row/3)*3 + (col/3))) + board[row][col];
                    
                    // if any particular (row index with value) or (col index with value) or (box index with value) already visited it means that is not a valid sudoku, so directly return false
                    if(visited.find(rowValue) != visited.end() 
                        || visited.find(colValue) != visited.end()
                        || visited.find(boxValue) != visited.end()){
                    return false;
                }
                    
                    // if not visited yet, then add rowValue, colValue and boxValue into the visited unordered set
                    visited.insert(rowValue);
                    visited.insert(colValue);
                    visited.insert(boxValue);
                }
            }
        }
        
        return true;
    }
};
