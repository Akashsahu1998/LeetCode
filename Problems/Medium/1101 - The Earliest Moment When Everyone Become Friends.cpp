
// Question) 1101. The Earliest Moment When Everyone Become Friends


// Implementation

// Using Disjoint Set Union
// Time Complexity = O(N + MlogM + M*a(M))
// First of all, we sort the logs in the order of timestamp. The time complexity of sorting is O(MlogM).
// Then we created a Union-Find data structure, which takes O(N) time to initialize the parent array.
// Then we iterate through the sorted logs which are total M. At each iteration, we invoke the union(a, b) function which tooks a(M) Time. so the time complexity is O(M*a(M)),
// where a is the Inverse Ackermann Function and M will never go higher than 4 in the universe.

// Space Complexity = O(N)
// where M is the number of logs and N is the number of people

class Solution {
private:
    int findParent(int node, vector<int> &parent){
        if(parent[node] == node) return node;
        
        return parent[node] = findParent(parent[node], parent);
    }
    
    bool unionFind(int source, int destination, vector<int> &parent){
        int sourceParent = findParent(source, parent);
        int destinationParent = findParent(destination, parent);
        
        if(sourceParent != destinationParent){
            parent[destinationParent] = sourceParent;
            return true;
        }
        
        return false;
    }

public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        if(logs.size() < n-1) return -1;
        
        // sorting on the basis of time
        sort(logs.begin(), logs.end());
        
        vector<int> parent(n);
        
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        
        int res = n;
        for(auto a : logs){
            int time = a[0];
            int source = a[1];
            int destination = a[2];
            
            if(unionFind(source, destination, parent)) {
                res--;
            }
            
            if(res == 1) return time;
        }
        
        return -1;
    }
};
