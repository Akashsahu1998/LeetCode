
// Question) 200. Number of Islands


// Implementation

// Using DFS
// Time Compexity : O(M*N)
// Space Compexity : O(M*N), bcz of the recursion stack strace

class Solution {
private:
    void dfs(vector<vector<char>>& grid, int i, int j){
        
        // base case
        if(i >= 0 && i < grid.size() && j >= 0 && j < grid[i].size() && grid[i][j] == '1'){
            grid[i][j] = '0';
            
            // top
            dfs(grid, i-1, j);
            
            // left
            dfs(grid, i, j-1);
            
            // down
            dfs(grid, i+1, j);
            
            // right
            dfs(grid, i, j+1);
        }
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        
        return count;
    }
};
