
// Question) 1293. Shortest Path in a Grid with Obstacles Elimination


// Implementation

// BFS Traversal
// Using Queue
// Time Complexity : O(M * N * K)
// Space Complexity : O(M * N * K)

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        // top left down right
        vector<vector<int>> directions{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(k+1)));

        // for bfs, using queue
        queue<vector<int>> q;
        q.push({0, 0, k});
        
         // we are visiting it so marking as 1
        visited[0][0][k] = true;
        
        // will store the number of steps needed to reach the destination
        int countSteps = 0;
        
        // iterating over the queue
        while(!q.empty()){
            
            int size = q.size();
            
            // iterating level by level
            for(int i = 0; i < size; i++){
                auto curArr = q.front();
                q.pop();
                
                // if we reached the destination
                if(curArr[0] == m-1 && curArr[1] == n-1) {
                    return countSteps;
                }
                
                // exploring all the possible directions
                for(auto dir : directions){
                    int newRow = dir[0] + curArr[0];
                    int newCol = dir[1] + curArr[1];
                    int obstacle = curArr[2];
                    
                    // checking the boundary/base conditions
                    if(newRow >= 0 && newCol >= 0 && newRow < m && newCol < n){
                        
                        // if there is not obstacle and that place is not visited
                        if(grid[newRow][newCol] == 0 && !visited[newRow][newCol][obstacle]){
                            q.push({newRow, newCol, obstacle});
                            visited[newRow][newCol][obstacle] = true;
                        }
                        
                        // if there is obstable
                        // then checking if obstableBalance(k) is more than 0, then only we can break that obstacle and also checking whether that place is visited or not
                        if(grid[newRow][newCol] == 1 && obstacle > 0 && !visited[newRow][newCol][obstacle-1]){
                            q.push({newRow, newCol, obstacle-1});
                            visited[newRow][newCol][obstacle-1] = true;
                        }
                    }
                }
            }
            
            // after every level increase the countSteps by 1
            countSteps++;
        }
        
        // if unable to reach destination so return -1
        return -1;
    }
};
