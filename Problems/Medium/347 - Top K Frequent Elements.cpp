
// Question) 347. Top K Frequent Elements


// Implementation

// Using Multi Set (Min Heap) & Unordered Map
// Time Complexity = O(NLogK)
// Space Complexity = O(N)

// Idea: using map to get the frequency of the elements & multi set to get the min heap, so will get the maximum value

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> freq;
        
        for(auto num : nums){
            freq[num]++;
        }
        
        multiset<pair<int, int>> mset;
        for(auto mp : freq){
            mset.insert(make_pair(mp.second, mp.first));
            
            if(mset.size() > k){
                mset.erase(mset.begin());
            }
        }
        
        vector<int> res;        
        for(auto a : mset){
            res.push_back(a.second);
        }
        
        return res;
    }
};
