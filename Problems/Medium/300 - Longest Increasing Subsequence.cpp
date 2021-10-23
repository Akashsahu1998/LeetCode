
// Question) 300. Longest Increasing Subsequence


// Implementation

// Time Complexity = O(N log(N)), Space Complexity = O(N)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> subsequence;
        for(int itr = 0; itr < nums.size(); itr++){
            auto index = lower_bound(subsequence.begin(), subsequence.end(), nums[itr]);
            if(index == subsequence.end()) subsequence.push_back(nums[itr]);
            else *index = nums[itr];
        }
        return subsequence.size();
    }
};

