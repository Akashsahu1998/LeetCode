
// Question) 1143. Longest Common Subsequence


// Implementation

// 1st Approach
// Recursive Approach
// Will give TLE
// Time Complexity : O(2^n)
// Space Complexity : O(2^n)

class Solution {
private:
    int dfs(string &text1, string &text2, int index1, int index2){
        if(index1 < 0 || index2 < 0) return 0;
        
        if(text1[index1] == text2[index2]){
            return 1 + dfs(text1, text2, index1-1, index2-1);
        }
        
        return max(dfs(text1, text2, index1-1, index2), dfs(text1, text2, index1, index2-1));
    }
    
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        return dfs(text1, text2, m-1, n-1);
    }
};



// 2nd Approach
// Recursive DP Approach
// Time Complexity : O(M.N)
// Space Complexity : O(M.N + M.N) => O(M.N), bcz of stack trace
class Solution {
private:
    int dfs(string &text1, string &text2, int index1, int index2, vector<vector<int>> &dp){
        if(index1 < 0 || index2 < 0) return 0;
        
        if(dp[index1][index2] != -1) return dp[index1][index2];
        
        if(text1[index1] == text2[index2]){
            return dp[index1][index2] = 1 + dfs(text1, text2, index1-1, index2-1, dp);
        }
        
        return dp[index1][index2] = max(dfs(text1, text2, index1-1, index2, dp), dfs(text1, text2, index1, index2-1, dp));
    }
    
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return dfs(text1, text2, m-1, n-1, dp);
    }
};
