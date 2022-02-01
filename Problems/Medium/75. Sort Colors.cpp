
// Question) 75. Sort Colors


// Implementation

// Using the inbuilt sorting function
// Naive Approach
// Time Complexity = O(NLogN)
// Space Complexity = O(1)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }
};
