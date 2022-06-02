
// Question) 743. Network Delay Time


// Implementation

// Using Dijkstra Algorithm
// Time Complexity = O(N + ElogN)
// Space Complexity = (O(N+E) + O(N) + O(N)) => O(N+E)
// Where N is the nunber of vertices in the graph and E is the number of edges

// Dijkstra Algorithm ->
// https://www.youtube.com/watch?v=jbhuqIASjoM&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=18

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<pair<int, int>> graph[n+1];
        
        for(auto time : times){
            graph[time[0]].push_back({time[1], time[2]});
        }
        
        vector<int> distance(n+1, INT_MAX);        
        distance[k] = 0;
        
        // to create min heap we need to take pass these 3 parameters
        // data type, vector type, comparison
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({0, k});
        
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto adjacentNode : graph[node]){
                int destinationNode = adjacentNode.first;
                int weight = adjacentNode.second;
                
                if(dis + weight < distance[destinationNode]){
                    distance[destinationNode] = dis + weight;
                    pq.push({dis + weight, destinationNode});
                }
            }
        }
        
        int res = INT_MIN;
        for(int i = 1; i < distance.size(); i++){
            res = max(res, distance[i]);
        }
        
        return (res == INT_MAX) ? -1 : res;
    }
};
