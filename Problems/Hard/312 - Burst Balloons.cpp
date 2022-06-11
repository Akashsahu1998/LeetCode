
// Question) 312. Burst Balloons


// Implementation

// Using DP / Tabulation
// Gap & Cut strategy
// Time Complexity = O(N^3)
// Space Complexity = O(N^2)
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> dp(n, vector<int>(n));
        
        for(int gap = 0; gap < n; gap++){
            for(int i = 0, j = gap; j < n; i++, j++){
                
                // to hold the maximum possible value in the gap from i to j
                int maxBurstValue = INT_MIN;
                
                // running loop in the gap of i to j
                for(int k = i; k <= j; k++){
                    int left = (k == i) ? 0 : dp[i][k-1];
                    int right = (k == j) ? 0 : dp[k+1][j];
                    
                    // int multiplyValue = ((i == 0) ? 1 : nums[i-1]) * (nums[k]) * ((j == n-1) ? 1 : nums[j+1]);
                    int multiplyValue = nums[k];
                    if(i != 0){
                        multiplyValue *= nums[i-1];
                    }
                    
                    if(j != n-1){
                        multiplyValue *= nums[j+1];
                    }
                    
                    int total = left + right + multiplyValue;
                    maxBurstValue = max(maxBurstValue, total);
                }
                dp[i][j] = maxBurstValue;
            }
        }
        
        // returning the last index of the first row, it will gonna contain the highest possible value
        return dp[0][n-1];
    }
};
