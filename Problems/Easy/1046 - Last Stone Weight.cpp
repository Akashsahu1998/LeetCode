
// Question) 1046. Last Stone Weight


// Implementation

// Using Max Heap (Priority Queue)
// Time Complexity : O(NlogN)
// Space Complexity : O(N)

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        
        while(!pq.empty()){
            int a = pq.top();
            pq.pop();
            if(pq.empty()){
                return a;
            }
            int b = pq.top();
            pq.pop();
            
            if(a != b){
                pq.push(a-b);   
            }            
        }
        return 0;
    }
};
