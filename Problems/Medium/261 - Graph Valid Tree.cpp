
// Question) 261. Graph Valid Tree


// Implementation

// Using Union Find
// Time Complexity = O(N * a(N)), where a is the Inverse Ackermann Function and N will never go higher than 4 in the universe.
// Space Complexity = O(N)

class Solution {
private:
    int findParent(vector<int> &parent, int node){
        if(parent[node] == node) return node;
        
        return findParent(parent, parent[node]);
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(n-1 != edges.size()) return false;
        
        vector<int> parent(n);
        
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        
        for(int i = 0; i < edges.size(); i++){
            int x = findParent(parent, edges[i][0]);
            int y = findParent(parent, edges[i][1]);
            
            if(x == y) return false;
            
            parent[x] = y;
        }
        
        return true;
    }
};
