
// Question) 2140. Solving Questions With Brainpower


// Implementation

// Iterative Approach
// Using DP & Memoization
// Time Complexity = O(N), Space Complexity = O(N)
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n+1, 0);
        
        for(int itr = n-1; itr >= 0; itr--){
            int points = questions[itr][0], jumps = questions[itr][1];
            
            // taking minimum index value bcz, jumps can cross n, so thats why whenever its crossing n, it will automatically take n as a minimum, so dp[n] means 0 will get added into points
            dp[itr] = max(dp[itr+1], points + dp[min(itr + jumps + 1, n)]);
        }
        
        return dp[0];
    }
};
