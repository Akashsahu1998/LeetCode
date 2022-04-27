
// Question) 994. Rotting Oranges


// Implementation

// Using Queue
// Time Complexity = O(M*N)
// Space Complexity = O(M*N)
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int row = grid.size(), col = grid[0].size(), cnt = 0, fresh = 0;
        queue<pair<int, int>> q;
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 2) q.push({i, j});
                if(grid[i][j] == 1) fresh++;    // counting the number of fresh oranges there
            }
        }
        
        if(fresh == 0) return 0;
        
        while(!q.empty()){
            
            int size = q.size();
            
            for(int k = 0; k < size; k++){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
            
                // top
                if(((i-1) >= 0) and (grid[i-1][j] == 1)){
                    grid[i-1][j] = 2;
                    q.push({i-1, j});
                    fresh--;
                } 
                
                // left
                if(((j-1) >= 0) and (grid[i][j-1] == 1)){
                    grid[i][j-1] = 2;
                    q.push({i, j-1});
                    fresh--;
                }
                
                // down
                if(((i+1) < row) and (grid[i+1][j] == 1)){
                    grid[i+1][j] = 2;
                    q.push({i+1, j});
                    fresh--;
                }
                
                // right
                if(((j+1) < col) and (grid[i][j+1] == 1)){
                    grid[i][j+1] = 2;
                    q.push({i, j+1});
                    fresh--;
                }   
            }
            cnt++;
        }

        return fresh ? -1 : cnt-1;
    }
};
