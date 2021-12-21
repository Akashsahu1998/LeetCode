
// Question) 329. Longest Increasing Path in a Matrix


// Implementation

// DFS
// Memoization Approach
// Time Complexity = O(M*N), Space Complexity = O(M*N)
class Solution {
public:
    int direction[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    
    int dfs(vector<vector<int>>& matrix, int itr, int jtr, vector<vector<int>> &visited){
        if(visited[itr][jtr] > 0) return visited[itr][jtr];
        
        int ans = 0;
        for(int ktr = 0; ktr < 4; ktr++){
            int newItr = itr + direction[ktr][0];
            int newJtr = jtr + direction[ktr][1];
            if(newItr >= 0 && newJtr >= 0 && newItr < matrix.size() && newJtr < matrix[0].size() &&
               matrix[newItr][newJtr] > matrix[itr][jtr]){
                ans = max(ans, dfs(matrix, newItr, newJtr, visited));
            }
        }
        
        visited[itr][jtr] = ans+1;
        return ans+1;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int maxAns = 0, row = matrix.size(), col = matrix[0].size();        
        
        vector<vector<int>> visited;        
        for(int itr = 0; itr < row; itr++){
            vector<int> temp;
            for(int jtr = 0; jtr < col; jtr++){              
                temp.push_back(0);
            }
            visited.push_back(temp);
        }
        
        for(int itr = 0; itr < row; itr++){
            for(int jtr = 0; jtr < col; jtr++){              
                int ans = dfs(matrix, itr, jtr, visited);
                maxAns = max(maxAns, ans);
            }
        }
        return maxAns;
    }
};
