
// Question) 239. Sliding Window Maximum



// Implementation

// Naive Approach
// TLE will come
// Time Complexity = O(N*K), Space Complexity = O(1), we are considering output vector for space
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        for(int itr = 0; itr <= nums.size()-k; itr++){
            int maxWindowValue = INT_MIN;
            for(int jtr = itr; jtr < itr+k; jtr++){
                maxWindowValue = max(maxWindowValue, nums[jtr]);
            }
            res.push_back(maxWindowValue);
        }
        return res;
    }
};
