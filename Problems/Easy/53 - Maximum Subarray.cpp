
// Question) 53. Maximum Subarray


// Implementation


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
