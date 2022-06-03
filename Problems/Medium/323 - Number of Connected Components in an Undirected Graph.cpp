
// Question) 323. Number of Connected Components in an Undirected Graph


// Implementation

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
        vector<int> parent(n), rank(n);
        
        for(int i = 0; i < n; i++){
            parent[i] = i;
            rank[i] = 0;
        }
        
        int countComponents = n;
        for(int i = 0; i < edges.size(); i++){
            int x = findParent(parent, edges[i][0]);
            int y = findParent(parent, edges[i][1]);
            
            if(x != y){
                if(rank[x] > rank[y]){
                    parent[y] = x;
                }
                else if(rank[x] < rank[y]){
                    parent[x] = y;
                }
                else{
                    parent[y] = x;
                    rank[x]++;
                }                
                
                countComponents--;
            }
        }
        
        return countComponents;
    }
};
