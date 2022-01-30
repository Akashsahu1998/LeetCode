
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
