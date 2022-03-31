
// Question) 647. Palindromic Substrings


// Implementation

// 1st Approach
// Using DP, gap strategy
// Time Complexity: O(N^2)
// Space Complexity: O(1)
class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0, n = s.size();
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int gap = 0; gap < n; gap++){
            for(int itr = 0, jtr = gap; jtr < n; itr++, jtr++){
                if(gap == 0){
                    dp[itr][jtr] = 1;
                }
                else if(gap == 1){
                    if(s[itr] == s[jtr]) dp[itr][jtr] = 1;
                }
                else{
                    if(s[itr] == s[jtr] && dp[itr+1][jtr-1]) dp[itr][jtr] = 1;
                }
                
                if(dp[itr][jtr]) ans++;
            }
        }
        
        return ans;
    }
};
