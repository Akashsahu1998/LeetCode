
// Question) 2150. Find All Lonely Numbers in the Array


// Implementation

// Using Unordered Map
// Time Complexity = O(N), Space Complexity = O(N)
class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        // map to get the frequency of elements present into nums
        unordered_map<int, int> mp;
        
        // creating frequency into map
        for(auto a : nums){
            mp[a]++;
        }
        
        // result vector
        vector<int> res;
        
        // iterating over the elements of nums
        for(auto a : nums){
            int small = a-1, big = a+1;
            
            // if current element freq is more than 1, or its +1 or -1, is present into map, then we will continue, otherwise will add it into the result array
            if(mp[a] > 1 || mp[small] || mp[big]) continue;
            else res.push_back(a);
        }
        return res;
    }
};
