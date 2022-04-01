
// Question) 79. Word Search


// Implementation

// Using DFS + Backtracking
// Time Complexity = O(ROW*COL), Space Complexity = O(1)
class Solution {
private:    
    bool dfs(vector<vector<char>>& board, string word, int itr, int jtr, int index){
        if(index == word.size()) return true;
        
        if(itr >= 0 && itr < board.size() && jtr >= 0 && jtr < board[0].size() && board[itr][jtr] == word[index]){
            
            char backup = board[itr][jtr];
            board[itr][jtr] = '*';
            
            int result = (dfs(board, word, itr-1, jtr, index+1)) ||
                         (dfs(board, word, itr, jtr-1, index+1)) ||
                         (dfs(board, word, itr+1, jtr, index+1)) ||
                         (dfs(board, word, itr, jtr+1, index+1));
            
            // backtrack
            board[itr][jtr] = backup;
            
            return result;
        }
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int itr = 0; itr < board.size(); itr++){
            for(int jtr = 0; jtr < board[0].size(); jtr++){
                if(board[itr][jtr] == word[0]){
                    if(dfs(board, word, itr, jtr, 0)) return true;
                }
            }
        }
        
        return false;
    }
};
