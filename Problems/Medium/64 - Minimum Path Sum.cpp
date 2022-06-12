
// Question) 64. Minimum Path Sum


// Implementation


// 1st Approach
// Recursive Approach
// Will give TLE
// Time Complexity : O(2^n)
// Space Complexity : O(2^n)

class Solution {
private:
    int dfs(vector<vector<int>> &grid, int i, int j){        
        if(i == 0 && j == 0) return grid[i][j];
        if(i < 0 || j < 0) return 1e9;
        int up = grid[i][j] + dfs(grid, i-1, j);
        int left = grid[i][j] + dfs(grid, i, j-1);
        return min(up, left);
    }
    
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        return dfs(grid, m-1, n-1);
    }
};
