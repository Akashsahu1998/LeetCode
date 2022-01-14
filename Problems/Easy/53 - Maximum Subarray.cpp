
// Question) 53. Maximum Subarray


// Implementation

// 1st Approach
// Using DP & Memoization
// Time Complexity = O(N), Space Complexity = O(N)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        // dp will contains the maximum subarray value for every current index
        vector<int> dp(nums.size());
        
        // putting 0th index value into dp, and starting comparing from 1st index in the loop
        dp[0] = nums[0];
        int maxAns = dp[0];
        
        // starting from 1st bcz, 0th index value is already into the dp
        for(int itr = 1; itr < nums.size(); itr++){
			            
            // if our previous value in dp is more than 0, then only we will add it with current value of nums, otherwise just put a current value into dp for current index
            dp[itr] = (dp[itr-1] > 0) ? dp[itr-1] + nums[itr] : nums[itr];            
            
            // calculating the max at each index from dp
            maxAns = max(maxAns, dp[itr]);
        }
        return maxAns;
    }
};


// 2nd Approach
// Using Kadane Algorithm
// Time Complexity = O(N), Space Complexity = O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int curMax = 0, maxAns = INT_MIN;
                
        for(int itr = 0; itr < nums.size(); itr++){
            
            // if our curMax value is more than 0, then only we will add it with current value of nums, otherwise just put a current value into curMax for current index
            curMax = (curMax > 0) ? curMax + nums[itr] : nums[itr];
            
            // calculating the max at each index from curMax
            maxAns = max(maxAns, curMax);
        }
        
        return maxAns;
    }
};
