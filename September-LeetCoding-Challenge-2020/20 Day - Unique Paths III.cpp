class Solution {
public:
    int nobs = 0;
    int ans = 0;
    vector<vector<bool>> visited;
    
    bool isSafe(vector<vector<int>>& grid, int i, int j){
        if(i >= 0 && j >= 0 && i < grid.size() && j < grid[i].size() && grid[i][j] != -1 && visited[i][j] == false)
            return true;
        return false;
    }
    int dfs(vector<vector<int>>& grid, int i, int j, int depth){
        visited[i][j] = true;
        
        if(grid[i][j] == 2){
            visited[i][j] = false;
            if(depth == nobs + 1){
                ans++;
            }
            return 1;
        }
        
        int res=0;
        if(isSafe(grid, i+1, j)){
            res += dfs(grid, i+1,j, depth+1);
        }
        if(isSafe(grid, i-1, j)){
            res += dfs(grid, i-1,j, depth+1);
        }
        if(isSafe(grid, i, j+1)){
            res += dfs(grid, i,j+1, depth+1);
        }
        if(isSafe(grid, i, j-1)){
            res += dfs(grid, i,j-1, depth+1);
        }
        visited[i][j]=false;
        return res;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int m = grid.size();
        if(m==0) return 0;
        int n = grid[0].size();
        
        visited.resize(m);
        for(int i = 0; i < m; i++){
            visited[i].resize(n,false);
        }
        
        int start_x, start_y;
        int end_x, end_y;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    start_x = i;
                    start_y = j;
                }
                else if(grid[i][j]==2){
                    end_x = i;
                    end_y = j;
                }
                else if(grid[i][j]==0)
                    nobs++;
            }
        }        
        
        int foo = dfs(grid, start_x, start_y,0);
        return ans;
    }
};
