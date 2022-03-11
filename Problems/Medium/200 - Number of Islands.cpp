
// Question) 200. Number of Islands


// Implementation

// Using DFS
// Time Complexity = O(ROW*COL), Space Complexity = O(1)
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int itr, int jtr){
        if(itr < 0 || jtr < 0 || itr == grid.size() || jtr == grid[0].size() || grid[itr][jtr] == '0') return;
        
        grid[itr][jtr] = '0';
        
        dfs(grid, itr-1, jtr); // top
        dfs(grid, itr, jtr-1); // left
        dfs(grid, itr+1, jtr); // down
        dfs(grid, itr, jtr+1); // right
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int itr = 0; itr < grid.size(); itr++){
            for(int jtr = 0; jtr < grid[itr].size(); jtr++){
                if(grid[itr][jtr] == '1'){
                    dfs(grid, itr, jtr);                    
                    count++;
                }
            }
        }
        return count;
    }
};
