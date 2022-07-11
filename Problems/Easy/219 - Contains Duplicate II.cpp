
// Question) 219. Contains Duplicate II


// Implementation

// Using Unordered Set
// Time Complexity = O(N),
// Space Complexity = O(min(N, K))

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> st;
        for(int i = 0; i < nums.size(); i++){
            
            // if found return true
            if(st.find(nums[i]) != st.end()) return true;
            
            // otherwise insert into set
            st.insert(nums[i]);
            
            // if set size is greater than k, then remove (i-k)th element
            if(st.size() > k){
                st.erase(nums[i-k]);
            }
        }
        
        // if didn't found return false
        return false;
    }
};

// Algo steps
// 1) Use Unordered Set
// 2) check if nums[i] is present into set, return true
// 3) otherwise insert into set, and check if size is greater than k, then remove i-k element
