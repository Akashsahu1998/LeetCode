
// Question) 1192. Critical Connections in a Network


// Implementation

// 1st Approach
// Using DFS
// Time Complexity = O(N+E)
// Space Complexity = (O(N+E) + O(N) + O(N) + O(N) + O(N)) => O(N+E)
// Where N is the nunber of vertices in the graph and E is the number of edges

class Solution {
private:
    void dfs(vector<vector<int>> &graph, int node, int parent, vector<int> &visited, vector<int> &lowTime, vector<int> &insertionTime, int &timer, vector<vector<int>> &res){
        visited[node] = 1;
        lowTime[node] = insertionTime[node] = timer++;
        
        for(auto adjacentNode : graph[node]){
            if(adjacentNode == parent) continue;
            
            if(!visited[adjacentNode]){
                dfs(graph, adjacentNode, node, visited, lowTime, insertionTime, timer, res);
                lowTime[node] = min(lowTime[node], lowTime[adjacentNode]);

                if(lowTime[adjacentNode] > insertionTime[node]){
                    res.push_back({node, adjacentNode});
                }
            }
            else{
                lowTime[node] = min(lowTime[node], insertionTime[adjacentNode]);
            }
        }
    }
    
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<vector<int>> graph(n);
        
        for(auto a : connections){
            graph[a[0]].push_back(a[1]);
            graph[a[1]].push_back(a[0]);
        }
        
//         for(int i = 0; i < connections.size(); i++){
//             graph[connections[i][0]].push_back(connections[i][1]);
//             graph[connections[i][1]].push_back(connections[i][0]);
//         }
        
        vector<int> visited(n, 0), lowTime(n, -1), insertionTime(n, -1);
        
        int timer = 0;
        vector<vector<int>> res;
        
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(graph, i, -1, visited, lowTime, insertionTime, timer, res);
            }            
        }        
        
        return res;
    }
};
