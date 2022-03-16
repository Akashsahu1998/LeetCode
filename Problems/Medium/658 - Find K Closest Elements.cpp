
// Question) 658. Find K Closest Elements


// Implementation

// using max heap
// Time Complexity : O(NLogN)
// Space Complexity : O(K)

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        // will store the abs dfrnc b/w x and the arr element in the first position, and arr element value into the second position
        // it will sort it on the basis of first in the pair
        priority_queue<pair<int, int>> pq;
        
        for(auto a : arr){
            pq.push({abs(a-x), a});
            
            // if pq size is more than k, then pop the element, so automatically it will pop the pair which is having more abs dfrnc
            if(pq.size() > k) pq.pop();
        }
        
        vector<int> res;
        
        while(pq.size() > 0){
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        sort(res.begin(), res.end());
        
        return res;
    }
};
