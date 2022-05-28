
// Question) 329. Longest Increasing Path in a Matrix


// Implementation

// Using DFS & Memoization
// Time Complexity = O(M * N)
// Space Complexity = O(M * N)
class Solution {
private:
    bool isValid(vector<vector<int>> &matrix, int i, int j){
        return (i >= 0 && j >= 0 && i < matrix.size() && j < matrix[i].size());
    }
    
    int findIncreasingPath(vector<vector<int>> &cache, vector<vector<int>> &matrix, int i, int j){
        if(cache[i][j]) return cache[i][j];
        
        // Top, left, bottom, right
        int directions[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        
        int ans = 0;
        for(auto direction : directions){
            int newI = i + direction[0];
            int newJ = j + direction[1];
            
            if(isValid(matrix, newI, newJ) && matrix[i][j] < matrix[newI][newJ]){
                ans = max(ans, findIncreasingPath(cache, matrix, newI, newJ));
            }
        }
        
        return cache[i][j] = ans+1;        
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if(!row) return 0;
        
        int col = matrix[0].size(), maxPath = 0;
        
        vector<vector<int>> cache(row, vector<int>(col));
                                
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                maxPath = max(maxPath, findIncreasingPath(cache, matrix, i, j));
            }
        }
        
        return maxPath;
    }
};
