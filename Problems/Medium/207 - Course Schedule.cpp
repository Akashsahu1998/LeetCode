
// Question) 207. Course Schedule


// Implementation

// Using Cycle detection technique, DFS
// Time Complexity = O(N+E)
// Space Complexity = (O(N+E) + O(N) + O(N)) => O(N)
// Where N is the nunber of vertices in the graph and E is the number of edges
// https://www.youtube.com/watch?v=kXy0ABd1vwo

// Idea : just check whether cycle is there in graph or not
// taking 3 colors, 0,1,2, here 0 means not started, 1 means completed, 2 means in process
// if any time if we reach a node which is having value 2, it means that node is in process and we reached again so it means cycle is there.

class Solution {
private:
    bool isCycle(vector<vector<int>> &graph, vector<int> &visited, int node){
        
        // if node is already in process, then it means there is cycle that's why we reached to this processing node
        if(visited[node] == 2){
            return true;
        }
        
        visited[node] = 2;
        
        for(auto adjancentNode : graph[node]){
            if(visited[adjancentNode] != 1){
                if(isCycle(graph, visited, adjancentNode)){
                    return true;
                }
            }
        }
        
        visited[node] = 1;
        return false;
    }
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {        
        vector<vector<int>> graph(numCourses);
        
        for(auto a : prerequisites){
            graph[a[0]].push_back(a[1]);
        }
        
        vector<int> visited(numCourses);
        for(int i = 0; i < numCourses; i++){
            if(visited[i] == 0){
                if(isCycle(graph, visited, i)){
                    return false;
                }
            }
        }
        
        return true;
    }
};
