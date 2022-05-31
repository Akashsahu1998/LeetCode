
// Question) 785. Is Graph Bipartite?


// Implementation


// 1st Approach
// Using BFS
// Time Complexity = O(N+E)
// Space Complexity = (O(N) + O(N)) => O(N)
// Where N is the nunber of vertices in the graph and E is the number of edges

class Solution {
private:
    bool bfs(int src, vector<vector<int>>& graph, vector<int> color){
        // giving 1 color to first node
        color[src] = 1;
        
        queue<int> q;
        q.push(src);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto a : graph[node]){
                if(color[a] == -1){
                    
                    // if node is 1 so 0 will go into color with the help of this equation, (1-1 = 0)
                    // if node is 0 so 1 will go into color with the help of this equation, (1-0 = 1)
                    color[a] = 1 - color[node];
                    q.push(a);
                } 
                else{
                    if(color[node] == color[a]) return false;
                }
            }
        }
        
        return true;
    }
        
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        // -1 means not visited & no color given
        // assuming two color as 1 & 0
        vector<int> color(graph.size(), -1);
        
        for(int i = 0; i < graph.size(); i++){
            if(color[i] == -1){
                if(!bfs(i, graph, color)) return false;
            }
        }
        
        return true;
    }
};



// 2nd Approach
// Using DFS
// Time Complexity = O(N+E)
// Space Complexity = (O(N) + O(N)) => O(N)
// Where N is the nunber of vertices in the graph and E is the number of edges

class Solution {
private:
    bool DFS(int src, vector<vector<int>> &graph, vector<int> &color){
        // giving 1 color to first node
        if(color[src] == -1) color[src] = 1;
            
        for(auto a : graph[src]){
            if(color[a] == -1){

                // if parent is 1 so 0 will go into color with the help of this equation, (1-1 = 0)
                // if parent is 0 so 1 will go into color with the help of this equation, (1-0 = 1)
                color[a] = 1 - color[src];
                if(!DFS(a, graph, color)) return false;
            } 
            else{
                if(color[src] == color[a]) return false;
            }
        }
        
        return true;
    }
        
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        // -1 means not visited & no color given
        // assuming two color as 1 & 0
        vector<int> color(graph.size(), -1);
        
        for(int i = 0; i < graph.size(); i++){
            if(color[i] == -1){
                if(!DFS(i, graph, color)) return false;
            }
        }
        
        return true;
    }
};
