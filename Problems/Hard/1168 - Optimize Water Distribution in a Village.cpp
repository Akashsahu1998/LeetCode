
// Question) 1168. Optimize Water Distribution in a Village


// Implementation

// Using Kruskal's Algo & Union Find
// Time complexity: O((N + M)log(N + M))
// Space complexity: O(N), bcz we are only taking parent vector as a extra space
// Where N be the number of houses, and M be the number of pipes from the input.
// https://www.youtube.com/watch?v=gc6ShDTldb4 // for concept understanding purpose, not code, bcz we have used another method, but concept is same,

// Idea : Creating a graph from point 0 to all given points, and then just finding the MST
// we can solve this problem through Prim's and Kruskal's + Union Find approach as well.

class Solution {
private:
    bool static comp(vector<int> &pipe1, vector<int> &pipe2){
        return pipe1[2] < pipe2[2];
    }
    
    int findParent(int node, vector<int> &parent){
        if(parent[node] == node) return node;
        return findParent(parent[node], parent);
    }
    
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        
        // will use parent in union find
        vector<int> parent(n+1, 0);
        
        for(int i = 0; i < wells.size(); i++){
            // i+1 bcz we are having parent size till n+1, so filling from index 1 to n+1
            parent[i+1] = i+1;
            
            // here also i+1 bcz we are creating one more graph from 0 to all nodes, and putting the wells[i] value as a cost
            pipes.push_back({0, i+1, wells[i]});
        }
        
        // sorting pipes by cost in ascending order, acc to kruskal's Algorithm
        sort(pipes.begin(), pipes.end(), comp);
        
        int i = 0, res = 0;
        while(n > 0){
            int parentOfSource = findParent(pipes[i][0], parent);
            int parentOfDestination = findParent(pipes[i][1], parent);
            
            // if they are equal then it can be a cycle, thats why taking not equal's to
            if(parentOfSource != parentOfDestination){
                res += pipes[i][2];
                parent[parentOfSource] = parentOfDestination;
                n--;
            }
            
            i++;
        }
        
        return res;
    }
};
