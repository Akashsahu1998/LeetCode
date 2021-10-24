
// Question) 334. Increasing Triplet Subsequence


// Implementation


// Naive Approach using Binary Search
// Time Complexity = O(Nlog(N)), Space Complexity = O(1)
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> subsequence;
        for(int itr = 0; itr < nums.size(); itr++){
            auto index = lower_bound(subsequence.begin(), subsequence.end(), nums[itr]);
            if(index == subsequence.end()) subsequence.push_back(nums[itr]);
            else *index = nums[itr];
            if(subsequence.size() == 3) return true;
        }
        if(subsequence.size() == 3) return true;        
        return false;
    }
};

