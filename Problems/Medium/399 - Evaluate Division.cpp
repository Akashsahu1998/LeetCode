
// Question) 399. Evaluate Division


// Implementation

// Using DFS
// Time complexity: O((E + V) * M)
// Space complexity: O(V)
// Where E is the number of edges, V is the number of vertices, M is the number of queries
// https://www.youtube.com/watch?v=P9cPgMp6Wc8

class Solution {
private:
    void dfs(unordered_map<string, vector<pair<string, double>>> &graph, unordered_set<string> &visited, string source, string destination, double &ans, double temp){
        
        // if source is already visited return back
        if(visited.find(source) != visited.end()) return;
        
        visited.insert(source);
        
        // it means we reached the destination from source, now we need to return back. before that we will put temp into ans, bcz ans is passed by reference and there we are storing the ans for each query
        if(source == destination){
            ans = temp;
            return;
        }
        
        // exploring all adjacent node of source
        for(auto adjacentNode : graph[source]){
            dfs(graph, visited, adjacentNode.first, destination, ans, temp * adjacentNode.second);
        }
    }
    
public:    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        // putting source and destination with its value into map
        unordered_map<string, vector<pair<string, double>>> graph;
        for(int i = 0; i < equations.size(); i++){
            graph[equations[i][0]].push_back({equations[i][1], values[i]});
            graph[equations[i][1]].push_back({equations[i][0], 1.0/values[i]});
        }
        
        // store the result
        vector<double> res;
        
        // iterating over the queries and solving each query
        for(int i = 0; i < queries.size(); i++){
            string source = queries[i][0];
            string destination = queries[i][1];
            
            double ans = -1.0, temp = 1.0;
            unordered_set<string> visited;
            
            // if source or destination any of them is not present into graph, then ans(-1) will come
            if(graph.find(source) != graph.end() && graph.find(destination) != graph.end()){
                dfs(graph, visited, source, destination, ans, temp);
            }
            
            res.push_back(ans);
        }
        
        return res;
    }
};
