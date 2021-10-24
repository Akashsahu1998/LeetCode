
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


// Efficient Approach
// Time Complexity = O(N), Space Complexity = O(1)
class Solution {
public:
    // Efficient Approach
    bool increasingTriplet(vector<int>& nums) {
        int a = INT_MAX, b = INT_MAX;
        for(auto itr : nums){
            if(itr <= a) a = itr;
            else if(itr <= b) b = itr;
            else return true;
        }
        return false;
    }
};
