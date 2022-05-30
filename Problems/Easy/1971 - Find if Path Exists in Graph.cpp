
// Question) 1971. Find if Path Exists in Graph


// Implementation

// Using BFS
// Time Complexity = O(N)
// Space Complexity = O(N)

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        
        for(int i = 0; i < edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int> visited(n);
        
        queue<int> q;
        q.push(source);
        visited[source] = 1;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            if(node == destination) return true;
            
            for(auto a : graph[node]){
                if(!visited[a]){
                    visited[a] = 1;
                    q.push(a);
                }
            }
        }
        
        return false;
    }
};
