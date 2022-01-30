
// Question) 2154. Keep Multiplying Found Values by Two


// Implementation

// Naive Approach
// Using Sorting
// Time Complexity = O(NLogN)
// Space Complexity = O(1)

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());
        for(int itr = 0; itr < nums.size(); itr++){
            if(original == nums[itr]) original *= 2;
        }
        return original;
    }
};


// Efficient Approach
// Using Unordered Set
// Time Complexity = O(N)
// Space Complexity = O(N)

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> st;
        for(int a : nums){
            st.insert(a);
        }
        
        for(int a : nums){
            if(st.find(original) != st.end()) original *= 2;
        }
        
        return original;
    }
};
