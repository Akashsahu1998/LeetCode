
// Question) 547. Number of Provinces


// Implementation

// 1st Approach
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



// 2nd Approach
// Using Union Find with Path Compression
// Time Complexity = O(N * N)
// Space Complexity = O(N)

class Solution {
private:
    int findParent(int x, vector<int> &parent){
        if(x == parent[x]){
            return x;
        }
        
        return parent[x] = findParent(parent[x], parent);
    }
    
    void findUnion(int u, int v, vector<int> &parent, vector<int> &rank, int &res){
        int rootU = findParent(u, parent);
        int rootV = findParent(v, parent);
        
        if(rootU != rootV){
            if(rank[rootU] > rank[rootV]){
                parent[rootV] = rootU;
            }
            else if(rank[rootU] < rank[rootV]){
                parent[rootU] = rootV;
            }
            else{
                parent[rootV] = rootU;
                rank[rootU]++;
            }
            
            res--;
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> rank(n), parent(n);
        
        for(int i = 0; i < n; i++){
            parent[i] = i;
            rank[i] = 0;
        }
        
        int res = n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j]){
                    findUnion(i, j, parent, rank, res);
                }
            }
        }
        
        return res;
    }
};
