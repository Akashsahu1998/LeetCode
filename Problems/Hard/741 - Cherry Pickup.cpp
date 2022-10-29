
// Question) 741. Cherry Pickup


// Implementation

// Reference : https://leetcode.com/problems/cherry-pickup/discuss/329945/Very-easy-to-follow-%3A-step-by-step-recursive-backtracking-with-memoization-N4.

// Approach - 1
// Will give TLE
// Using Recursion & Backtracking
// Time Complexity : O(4^N*N)
// Space Complexity : O(4^N*N)

class Solution {
private:
    int dfs(vector<vector<int>>& grid, int r1, int c1, int r2, int c2){
        int n = grid.size();
        
        // since we're only going down and to the right, no need to check for < 0
        // if we went out of the grid or hit a thorn, discourage this path by returning Integer.MIN_VALUE
        if(r1 >= n || c1 >= n || r2 >= n || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1){
            return INT_MIN;
        }
        
        // if person 1 reached the bottom right, return what's in there (could be 1 or 0)
        if(r1 == n-1 && c1 == n-1){
            return grid[r1][c1];
        }
        
        // if person 2 reached the bottom right, return what's in there (could be 1 or 0)
        if(r2 == n-1 && c2 == n-1){
            return grid[r2][c2];
        }
        
        int cherries;
        
        // if both persons standing on the same cell, don't double count and return what's in this cell (could be 1 or 0)
        if(r1 == r1 && c1 == c2){
            cherries = grid[r1][c1];
        }
        
        // otherwise, number of cherries collected by both of them equals the sum of what's on their cells
        else{
            cherries = grid[r1][c1] + grid[r2][c2];
        }
        
        // since each person of the 2 person can move only to the bottom or to the right, then the total number of cherries
        // equals the max of the following possibilities:
        //    P1     |      P2
        //   DOWN    |     DOWN
        //   DOWN    |     RIGHT
        //   RIGHT   |     DOWN
        //   RIGHT   |     RIGHT
        
        int downDown = dfs(grid, r1+1, c1, r2+1, c2);
        int downRight = max(downDown, dfs(grid, r1+1, c1, r2, c2+1));
        int rightDown = max(downRight, dfs(grid, r1, c1+1, r2+1, c2));
        int rightRight = max(rightDown, dfs(grid, r1, c1+1, r2, c2+1));
        
        cherries += rightRight;
        
        return cherries;
    }
    
public:
    int cherryPickup(vector<vector<int>>& grid) {
        // for person1 = its r1 & c1
        // for person2 = its r2 & c2
        // r1, c1, r2, c2
        return max(0, dfs(grid, 0, 0, 0, 0));
    }
};


// Approach - 2
// Using Recursion, Backtracking, Memoization / DP
// Time Complexity : O(N^4)
// Space Complexity : O(N^4)

class Solution {
private:
    int dfs(vector<vector<int>>& grid, int r1, int c1, int r2, int c2, vector<vector<vector<vector<int>>>> &dp){
        int n = grid.size();
        
        // since we're only going down and to the right, no need to check for < 0
        // if we went out of the grid or hit a thorn, discourage this path by returning Integer.MIN_VALUE
        if(r1 >= n || c1 >= n || r2 >= n || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1){
            return INT_MIN;
        }
        
        if(dp[r1][c1][r2][c2] != -1) return dp[r1][c1][r2][c2];
        
        // if person 1 reached the bottom right, return what's in there (could be 1 or 0)
        if(r1 == n-1 && c1 == n-1){
            return grid[r1][c1];
        }
        
        // if person 2 reached the bottom right, return what's in there (could be 1 or 0)
        if(r2 == n-1 && c2 == n-1){
            return grid[r2][c2];
        }
        
        int cherries;
        
        // if both persons standing on the same cell, don't double count and return what's in this cell (could be 1 or 0)
        if(r1 == r2 && c1 == c2){
            cherries = grid[r1][c1];
        }
        
        // otherwise, number of cherries collected by both of them equals the sum of what's on their cells
        else{
            cherries = grid[r1][c1] + grid[r2][c2];
        }
        
        // since each person of the 2 person can move only to the bottom or to the right, then the total number of cherries
        // equals the max of the following possibilities:
        //    P1     |      P2
        //   DOWN    |     DOWN
        //   DOWN    |     RIGHT
        //   RIGHT   |     DOWN
        //   RIGHT   |     RIGHT
        
        int downDown = dfs(grid, r1+1, c1, r2+1, c2, dp);
        int downRight = max(downDown, dfs(grid, r1+1, c1, r2, c2+1, dp));
        int rightDown = max(downRight, dfs(grid, r1, c1+1, r2+1, c2, dp));
        int rightRight = max(rightDown, dfs(grid, r1, c1+1, r2, c2+1, dp));
        
        cherries += rightRight;
        
        dp[r1][c1][r2][c2] = cherries;
        
        return dp[r1][c1][r2][c2];
    }
    
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Memoization
        vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n, -1))));
        
        // for person1 = its r1 & c1
        // for person2 = its r2 & c2
        // r1, c1, r2, c2
        return max(0, dfs(grid, 0, 0, 0, 0, dp));
    }
};
