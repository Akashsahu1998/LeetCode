
// Question) 547. Number of Provinces


// Implementation

// Using DFS
// Time Complexity = O(N * N)
// Space Complexity = O(N)

class Solution {
private:
    void dfs(vector<vector<int>> &isConnected, vector<int> &visited, int i){
        for(int j = 0; j < isConnected.size(); j++){
            if(isConnected[i][j] && !visited[j]){
                visited[j] = 1;
                dfs(isConnected, visited, j);
            }
        }
    }
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> visited(isConnected.size());
        
        int resCount = 0;
        for(int i = 0; i < isConnected.size(); i++){
            if(!visited[i]){
                dfs(isConnected, visited, i);
                resCount++;
            }
        }
        
        return resCount;
    }
};
