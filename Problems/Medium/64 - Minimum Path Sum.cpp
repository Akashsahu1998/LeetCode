
// Question) 64. Minimum Path Sum


// Implementation

// https://www.youtube.com/watch?v=_rgTlyky1uQ

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



// 2nd Approach
// Recursive DP Approach / Memoization
// Time Complexity : O(M.N)
// Space Complexity : O(M.N + M.N) => O(M.N), bcz of stack trace

class Solution {
private:
    int dfs(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp){
        if(i == 0 && j == 0) return grid[i][j];
        if(i < 0 || j < 0) return 1e9;
        
        if(dp[i][j]) return dp[i][j];
        
        int up = grid[i][j] + dfs(grid, i-1, j, dp);
        int left = grid[i][j] + dfs(grid, i, j-1, dp);
        
        return dp[i][j] = min(up, left);
    }
    
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        return dfs(grid, m-1, n-1, dp);
    }
};




// 3rd Approach
// Iterative DP Approach / Tabulation
// Time Complexity : O(M.N)
// Space Complexity : O(M.N)

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    dp[i][j] = grid[i][j];
                }                
                else{
                    int up = grid[i][j];
                    if(i > 0){
                        up += dp[i-1][j];
                    }
                    else{
                        up += 1e9;
                    }
                    
                    int left = grid[i][j];
                    if(j > 0){
                        left += dp[i][j-1];
                    }
                    else{
                        left += 1e9;
                    }

                    dp[i][j] = min(up, left);
                }
            }
        }
        return dp[m-1][n-1];
    }
};



// 4th Approach
// Space Optimization in Iterative DP Approach / Tabulation
// Time Complexity : O(M*N)
// Space Complexity : O(N)

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> prev(n);
        
        for(int i = 0; i < m; i++){
            vector<int> cur(n);
            
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    cur[j] = grid[i][j];
                }                
                else{
                    int up = grid[i][j];
                    if(i > 0){
                        up += prev[j];
                    }
                    else{
                        up += 1e9;
                    }
                    
                    int left = grid[i][j];
                    if(j > 0){
                        left += cur[j-1];
                    }
                    else{
                        left += 1e9;
                    }

                    cur[j] = min(up, left);
                }
            }
            prev = cur;
        }
        return prev[n-1];
    }
};
