
// Question) 300. Longest Increasing Subsequence


// Implementation


// Naive Approach using DP
// Time Complexity = O(N^2), Space Complexity = O(N)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dpArr(nums.size());
        fill(dpArr.begin(), dpArr.end(), 1);
        int res = 1;
        for(int itr = 1; itr < nums.size(); itr++){
            for(int jtr = 0; jtr < itr; jtr++){
                if(nums[jtr] < nums[itr]) dpArr[itr] = max(dpArr[itr], dpArr[jtr]+1);
            }
            res = max(res, dpArr[itr]);
        }        
        return res;
    }
};


// Efficient Approach using binary search
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

