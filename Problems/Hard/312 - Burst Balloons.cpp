
// Question) 312. Burst Balloons


// Implementation

// Tabulation
// Using DP
// Gap & Cut strategy
// Time Complexity = O(N^3), Space Complexity = O(N^2)
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));
        
        for(int gap = 0; gap < n; gap++){
            for(int itr = 0, jtr = gap; jtr < n; itr++, jtr++){
                
                // to hold the maximum possible value in the gap from itr to jtr
                int maxValue = INT_MIN;
                
                // running loop in the gap of itr to jtr
                for(int ktr = itr; ktr <= jtr; ktr++){
                    int left = (itr == ktr) ? 0 : dp[itr][ktr-1];
                    int right = (jtr == ktr) ? 0 : dp[ktr+1][jtr];
                    int val = ((itr == 0) ? 1 : nums[itr-1]) * (nums[ktr]) * ((jtr == n-1) ? 1 : nums[jtr+1]);
                    
                    int total = left + right + val;
                    maxValue = max(maxValue, total);
                }
                
                dp[itr][jtr] = maxValue;
            }
        }
                               
        // returning the last index of the first row, it will gonna contain the highest possible value
        return dp[0][n-1];                       
    }
};
