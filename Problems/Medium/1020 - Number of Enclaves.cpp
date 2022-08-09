
// Question) 1020. Number of Enclaves


// Implementation

// Using DFS
// Time Complexity = O(M*N)
// Space Complexity = O(M*N)

// Link : Same as this que : https://leetcode.com/problems/surrounded-regions

class Solution {
private:
    void dfs(vector<vector<int>> &grid, int row, int col){
        
        // case condition
        if(row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size() && grid[row][col] == 1){
            grid[row][col] = 0;
            
            dfs(grid, row-1, col); // top
            dfs(grid, row, col-1); // left
            dfs(grid, row+1, col); // down
            dfs(grid, row, col+1); // right
        }
    }
    
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int rowSize = grid.size(), colSize = grid[0].size();
        
        
        // first row & last row
        for(int i = 0; i < colSize; i++){
            
            // first row
            if(grid[0][i] == 1){
                dfs(grid, 0, i);
            }
            
            // last row
            if(grid[rowSize-1][i] == 1){
                dfs(grid, rowSize-1, i);
            }
        }
        
        // first col & last col
        for(int i = 0; i < rowSize; i++){
            
            // first col
            if(grid[i][0] == 1){
                dfs(grid, i, 0);
            }
            
            // last col
            if(grid[i][colSize-1] == 1){
                dfs(grid, i, colSize-1);
            }
        }
        
        int cnt = 0;
        for(int i = 0; i < rowSize; i++){
            for(int j = 0; j < colSize; j++){
                if(grid[i][j]) cnt++;
            }
        }
        
        return cnt;
    }
};

// Algo Steps
// 1) Firstly check boundary (first row, last row, first col & last col) if they are having 1 then explore all the 4 directions if they are also having 1 then do the same, check again and convert them into 0.
// 2) Now just count the frequency of 1 in the grid.
