
// Question) 973. K Closest Points to Origin


// Implementation

// 1st Approach
// Using Max Heap (Priority Queue)
// Time Complexity: O(NLogN)
// Space Complexity: O(N)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> pq;
        
        for(int i = 0; i < points.size(); i++){
            int temp = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);
            pq.push({temp, {points[i][0], points[i][1]}});
            
            if(pq.size() > k){
                pq.pop();
            }
        }
        
        vector<vector<int>> res;
        while(!pq.empty()){
            pair<int, int> p = pq.top().second;
            res.push_back({p.first, p.second});
            pq.pop();
        }
        
        return res;
    }
};
