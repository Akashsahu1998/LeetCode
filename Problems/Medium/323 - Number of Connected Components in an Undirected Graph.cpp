
// Question) 323. Number of Connected Components in an Undirected Graph


// Implementation

// 1st Approach
// Using DFS
// Time Complexity = O(V + E)
// Space Complexity = O(V + E)
// where V is number of vertices and E is number of edges.

class Solution {
private:
    void dfs(vector<int> graph[], vector<int> &visited, int node){
        visited[node] = 1;
        
        for(auto adjacentNode : graph[node]){
            if(!visited[adjacentNode]){
                dfs(graph, visited, adjacentNode);
            }
        }
    }
    
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        
        vector<int> visited(n, 0);
        vector<int> graph[n];
        
        for(int i = 0; i < edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        int countComponents = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(graph, visited, i);
                countComponents++;
            }
        }
        
        return countComponents;
    }
};


// 2nd Approach
// Using Disjoint Set Union
// Time Complexity = O(E * a(N)), where a is the Inverse Ackermann Function and N will never go higher than 4 in the universe.
// Space Complexity = O(V)
// where E is number of edges and V is number of vertices

class Solution {
private:
    int findParent(vector<int> &parent, int node){
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent, parent[node]);
    }
    
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        
        int countComponents = n;
        for(int i = 0; i < edges.size(); i++){
            int sourceParent = findParent(parent, edges[i][0]);
            int destinationParent = findParent(parent, edges[i][1]);
            
            if(sourceParent != destinationParent){
                parent[destinationParent] = sourceParent;
                countComponents--;
            }
        }
        
        return countComponents;
    }
};
