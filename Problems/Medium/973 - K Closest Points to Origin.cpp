
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


// 3rd Approach
// Quick Select
// Time Complexity: O(NLogK)
// Space Complexity: O(1)
class Solution {
private:
    int generateValue(vector<int>& arr) {
        return arr[0]*arr[0] + arr[1]*arr[1];
    }
    
    int partition(vector<vector<int>>& points, int low, int high) {
        int pivot = generateValue(points[high]);
        
        for (int i = low; i < high; ++i) {
            if(generateValue(points[i]) < pivot){
                swap(points[i], points[low++]);
            }                
        }
        
        swap(points[high], points[low]);
        
        return low;
    }
    
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int low = 0, high = points.size() - 1;
        k--;
        while(true) {
            int pivotIndex = partition(points, low, high);
            
            if (pivotIndex < k) {
                low = pivotIndex + 1;
            } 
            else if(pivotIndex > k){
                high = pivotIndex - 1;
            }
            else break;
        }
        return vector<vector<int>>(points.begin(), points.begin() + k + 1);
    }
};
