
// Question) 399. Evaluate Division


// Implementation

// Using DFS
// Time complexity: O((E + V) * M)
// Space complexity: O(V)
// Where E is the number of edges, V is the number of vertices, M is the number of queries
// https://www.youtube.com/watch?v=P9cPgMp6Wc8

class Solution {
private:
    void dfs(unordered_map<string, vector<pair<string, double>>> &graph, unordered_set<string> &st, string source, string destination, double &ans, double temp){
        
        if(st.find(source) != st.end()) return;
        
        st.insert(source);
        
        if(source == destination){
            ans = temp;
            return;
        }
        
        for(auto adjacentNode : graph[source]){
            dfs(graph, st, adjacentNode.first, destination, ans, temp * adjacentNode.second);
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
            unordered_set<string> st;
            if(graph.find(source) != graph.end() && graph.find(destination) != graph.end()){
                dfs(graph, st, source, destination, ans, temp);
            }
            
            res.push_back(ans);
        }
        
        return res;
    }
};
