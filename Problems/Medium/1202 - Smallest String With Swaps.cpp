
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


// 2nd Approach
// Using Disjoin Set Union (DSU)
// Time complexity: O((E + V) * a(V) + VlogV), where a is the Inverse Ackermann Function and V will never go higher than 4 in the universe.
// Space complexity: O(V)

class Solution {
private:
    int findParent(int node, vector<int> &parent){
        if(parent[node] == node) return node;
        
        return parent[node] = findParent(parent[node], parent);
    }
    
    void unionFind(int source, int destination, vector<int> &parent){
        int sourceParent = findParent(source, parent);
        int destinationParent = findParent(destination, parent);
        
        if(sourceParent != destinationParent){
            parent[destinationParent] = sourceParent;
        }
    }
    
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        // generate the parent vector
        vector<int> parent(s.size());
        for(int i = 0; i < s.size(); i++){
            parent[i] = i;
        }
        
        // iterating over the pair, and making union of source & destination
        for(auto pair : pairs){
            int source = pair[0];
            int destination = pair[1];
            
            unionFind(source, destination, parent);
        }
        
        // finding the parent of each vertices and creating the map of that root which contains the list of vertices for that particular root
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < s.size(); i++){
            int root = findParent(i, parent);
            mp[root].push_back(i);
        }
        
        for(auto m : mp){
            
            vector<int> list = m.second;
            
            // iterate over the list and put all the char's present into the particular index of list into characters array.            
            vector<char> characters;
            for(int i = 0; i < list.size(); i++){
                characters.push_back(s[list[i]]);
            }
            
            // sort the charactes, bcz we are having leverage of swapping
            sort(characters.begin(), characters.end());
            
            for(int i = 0; i < list.size(); i++){
                s[list[i]] = characters[i];
            }
        }
        
        return s;
    }
};
