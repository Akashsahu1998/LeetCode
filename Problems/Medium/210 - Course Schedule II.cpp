
// Question) 210. Course Schedule II


// Implementation

// Using Cycle detection technique, Topological Sort and DFS
// Time Complexity = O(N+E)
// Space Complexity = (O(N+E) + O(N) + O(N) + O(N)) => O(N+E)
// Where N is the nunber of vertices in the graph and E is the number of edges

// did with the help of course schedule 1, its same, in this que only need to append nodes into res

// Idea : just check whether cycle is there in graph or not if there is cycle then return true, so we can return blank array as answer.
// taking 3 colors, 0,1,2, here 0 means not started, 1 means completed, 2 means in process
// if any time if we reach a node which is having value 2, it means that node is in process and we reached again so it means cycle is there, so we are returning true
// if the node is compeltely process so we will mark it as a 1, and will push that node into result array

class Solution {
private:
    bool dfs(vector<vector<int>> &graph, vector<int> &visited, vector<int> &res, int node){
    
    if(visited[node] == 2) return true;
    
    visited[node] = 2;
    
    for(auto adjacentNode : graph[node]){
        if(visited[adjacentNode] != 1){
            if(dfs(graph, visited, res, adjacentNode)){
                return true;
            }
        }
    }    
    
    visited[node] = 1;
    res.push_back(node);
    return false;
}
    
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> visited(numCourses), res;        
        vector<vector<int>> graph(numCourses);
        
        for(auto a : prerequisites){
            graph[a[0]].push_back(a[1]);
        }
        
        for(int i = 0; i < numCourses; i++){
            if(visited[i] == 0){
                if(dfs(graph, visited, res, i)){
                    return {};
                }
            }
        }
        
        return res;
    }
};
