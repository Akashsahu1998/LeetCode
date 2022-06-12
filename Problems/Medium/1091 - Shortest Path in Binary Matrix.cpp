
// Question) 1091. Shortest Path in Binary Matrix


// Implementation


// BFS Traversal
// Using Queue
// Time Complexity : O(M * N)
// Space Complexity : O(M * N)

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
           
        int m = grid.size(), n = grid[0].size();
        
        // top, left, down, right, top-left, bottom-left, bottom-right, top-right
        vector<vector<int>> directions{{-1, 0}, {0, -1}, {1, 0}, {0, 1}, {-1, -1}, {1, -1}, {1, 1}, {-1, 1}};
        
        // for bfs, using queue
        queue<vector<int>> q;
        
        // x, y, distance
        // putting distance as 1 in default bcz, i.e [[0]] in this case, only 1 step is required
        q.push({0, 0, 1});
        
        // we are visiting it so marking as 1
        grid[0][0] = 1;
        
        while(!q.empty()){
            
            int size = q.size();
            
            // iterating level by level
            for(int i = 0; i < size; i++){
                auto arr = q.front();
                q.pop();
                
                // if we reached the last index(destination) of the matrix then return the total distance
                if(arr[0] == m-1 && arr[1] == n-1){
                    return arr[2];
                }
                
                // trying all possible 8 directions
                for(auto dir : directions){
                    
                    // creating new row & col
                    int row = dir[0] + arr[0];
                    int col = dir[1] + arr[1];
                    
                    // validating the border/base conditions
                    if(row >= 0 && col >= 0 && row < m && col < n && grid[row][col] == 0){
                        q.push({row, col, arr[2] + 1});
                        // we are visiting it so marking as 1
                        grid[row][col] = 1;
                    }
                }
            }           
        }
        
        return -1;
    }
};
