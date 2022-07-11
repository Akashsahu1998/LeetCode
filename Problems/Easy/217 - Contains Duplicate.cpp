
// Question) 217. Contains Duplicate


// Implementation

// Using Unordered Map
// Time Complexity = O(N)
// Space Complexity = O(N)

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(auto num : nums){
            freq[num]++;
        }
        
        for(auto frq : freq){
            if(frq.second > 1){
                return true;
            }
        }
        
        return false;
    }
};
