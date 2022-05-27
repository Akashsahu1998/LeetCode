
// Question) 973. K Closest Points to Origin


// Implementation

// 1st Approach
// Using Normal Sorting
// Time Complexity: O(NLogN)
// Space Complexity: O(1)
class Solution {
private:
    bool static comp(vector<int> &a, vector<int> &b){
        int temp1 = (a[0] * a[0]) + (a[1] * a[1]);
        int temp2 = (b[0] * b[0]) + (b[1] * b[1]);
        return temp1 < temp2;
    }
    
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), comp);
        
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};

// 2nd Approach
// Using Max Heap (Priority Queue)
// Time Complexity: O(NLogK)
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
