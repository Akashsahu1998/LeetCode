
// Question) 62. Unique Paths


// Implementation

// Using DP
// Time Complexity: O(N*M)
// Space Complexity: O(N*M)

class Solution {
private:
    int solve(int m, int n, int left, int right, vector<vector<int>> &dp){
        if(left >= m || right >= n) return 0;        
        if(left == m-1 && right == n-1) return 1;
        if(dp[left][right]) return dp[left][right];
        return dp[left][right] = (solve(m, n, left+1, right, dp) + solve(m, n, left, right+1, dp));
    }
    
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));
        return solve(m, n, 0, 0, dp);
    }
};
