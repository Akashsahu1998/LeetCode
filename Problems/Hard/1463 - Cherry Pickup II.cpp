
// Question) 1463. Cherry Pickup II


// Implementation

// Reference : https://www.youtube.com/watch?v=MiOii7Uzu8w

// Using Recursion, Backtracking, Memoization / DP
// Time Complexity : O(M*N^2), since our helper function have three variables as input, which have M, N, and N possible values respectively. In the worst case, we have to calculate them all once, so that would cost O(M * N * N) = O(M*N^2)
// Space Complexity : O(M*N^2)

class Solution {
private:
    int dfs(vector<vector<int>>& grid, vector<vector<vector<int>>> &dp, int row, int col1, int col2, vector<int> coordinates){
        
        // base condition
        if(row == grid.size() || col1 < 0 || col2 < 0 || col1 >= grid[0].size() || col2 >= grid[0].size()){
            return INT_MIN;
        }
        
        // if solution is already memoized for any coordinates
        if(dp[row][col1][col2] != -1) return dp[row][col1][col2];
        
        int maxAns = 0;
        
        // trying all 9 combination for the robots
        // if robot1 can move to 1 place, then robot2 can move to 3 place for that 1 place, likewise
        // if robot1 can move to 2nd place, then robot2 can move to 3 place for that 2nd place, likewise
        // if robot1 can move to 2rd place, then robot2 can move to 3 place for that 3rd place, likewise
        for(int robot1Col = 0; robot1Col < 3; robot1Col++){
            for(int robot2Col = 0; robot2Col < 3; robot2Col++){
                maxAns = max(maxAns, dfs(grid, dp, row+1, col1 + coordinates[robot1Col], col2 + coordinates[robot2Col], coordinates));
            }
        }
        
        // if both robots are standing on same cell, it means they are standing on same cell
        // then take any one of them, otherwise take addition of both robot cell
        maxAns += (col1 == col2) ? grid[row][col1] : grid[row][col1] + grid[row][col2];
        
        // memoize the solution and return it
        return dp[row][col1][col2] = maxAns;
    }
        
public:
    int cherryPickup(vector<vector<int>>& grid) {
        
        // getting row & col size of grid
        int rowSize = grid.size(), colSize = grid[0].size();
        
        // coordinates in which both robots can move
        // robots can move into next row previous col, next row same col, next row next col
        // in these 3 directions robots can move
        // here row will be always same, its always next
        vector<int> coordinates{-1, 0, 1};
        
        // dp to memoize the solution
        vector<vector<vector<int>>> dp(rowSize, vector<vector<int>>(colSize, vector<int>(colSize, -1)));
        
        // passing grid, dp, row, col1, col2, coordinates
        // passing only 1 row bcz both robots will always move on same row only
        // here columns can be different for both robots but not rows 
        return dfs(grid, dp, 0, 0, colSize-1, coordinates);
    }
};
