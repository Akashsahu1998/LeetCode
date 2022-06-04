
// Question) 1202. Smallest String With Swaps


// Implementation

// 1st Approach
// Using DFS
// Time complexity: O(E + VlogV)
// Space complexity: O(E + V)

class Solution {
private:
    void dfs(vector<int> graph[], vector<int> &indices, vector<char> &characters, vector<int> &visited, string &s, int node){
        visited[node] = 1;
        
        indices.push_back(node);
        characters.push_back(s[node]);
        
        for(auto adjacentNode : graph[node]){
            if(!visited[adjacentNode]){
                dfs(graph, indices, characters, visited, s, adjacentNode);
            }
        }
    }
    
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        // create adjacency list
        vector<int> graph[s.size()];        
        for(auto pair : pairs){
            graph[pair[0]].push_back(pair[1]);
            graph[pair[1]].push_back(pair[0]);
        }
        
        // iterate over the string s and check for each non visited char
        vector<int> visited(s.size(), 0);
        for(int i = 0; i < s.size(); i++){
            
            if(!visited[i]){
                
                // create indices vector to store the index of the char
                vector<int> indices;
                
                // create characters vector to store the char on particular index
                vector<char> characters;
                
                // traverse dfs for all adjacent node of ith index
                dfs(graph, indices, characters, visited, s, i);
                
                // sort the indices and characters vector, bcz we are having the leverage of sorting
                sort(indices.begin(), indices.end());
                sort(characters.begin(), characters.end());
                
                // Iterate over indices and characters, and place the ith character at the ith index in the string as a smallestString.
                for(int i = 0; i < indices.size(); i++){
                    s[indices[i]] = characters[i];                    
                }
            }
        }
        
        return s;
    }
};
