
// Question) 300. Longest Increasing Subsequence


// Implementation


// Naive Approach
// Using DP
// Time Complexity : O(N^2)
// Space Complexity : O(N)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        // creating dp with value 1 in all index, bcz all element will have their own size as 1 atleast
        vector<int> dp(nums.size(), 1);
        
        // intializing with 1 bcz atleast 1 length it will have
        int longestLength = 1;
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j]+1);
                    longestLength = max(longestLength, dp[i]);
                }
            }
        }
        
        return longestLength;
    }
};
