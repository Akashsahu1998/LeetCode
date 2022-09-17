
// Question) 79. Word Search


// Implementation

// Using DFS + Backtracking
// Time Complexity = O(ROW * COL * 3^L), where L is the length of the word to be matched
// Space Complexity = O(L), where L is the length of the word to be matched
class Solution {
private:
    bool dfs(vector<vector<char>>& board, string word, int row, int col, int index){
        if(index == word.size()) return true;
        
        // checking whether row & col is inside the boundary or not
        if(row >= 0 && col >= 0 && row < board.size() && col < board[0].size() && board[row][col] == word[index]){
            
            // backtracking
            // creating the backup of current char & putting * into it, bcz we don't want to check it again when we proceed further to find another char of word
            char backup = board[row][col];
            board[row][col] = '*';
            bool result = (dfs(board, word, row-1, col, index+1) ||
                        dfs(board, word, row, col-1, index+1) ||
                        dfs(board, word, row+1, col, index+1) ||
                        dfs(board, word, row, col+1, index+1));
                
            board[row][col] = backup;
            return result;
        }
        
        return false;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int row = 0; row < board.size(); row++){
            for(int col = 0; col < board[row].size(); col++){
                if(dfs(board, word, row, col, 0)) return true;
            }
        }
        
        return false;
    }
};
