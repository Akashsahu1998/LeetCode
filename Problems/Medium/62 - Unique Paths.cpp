
// Question) 62. Unique Paths


// Implementation

// https://www.youtube.com/watch?v=sdE0A2Oxofw
// https://www.youtube.com/watch?v=t_f0nwwdg5o

// 1st Approach
// Recursive Approach
// Will give TLE
// Time Complexity : O(2!)
// Space Complexity : O(2!)

class Solution {
private:
    int solve(int m, int n, int left, int up){
        if(left == -1 || up == -1) return 0;
        if(left == 0 && up == 0) return 1;
        
        int leftSide = solve(m, n, left-1, up);
        int upSide = solve(m, n, left, up-1);
        
        return leftSide + upSide;
    }
    
public:
    int uniquePaths(int m, int n) {
        return solve(m, n, m-1, n-1);
    }
};


// 2nd Approach
// Memoization Approach
// Time Complexity : O(M * N)
// Space Complexity : O((M * N) + (M * N)) => O(M * N), bcz of recursion stack trace

class Solution {
private:
    int solve(int m, int n, int left, int up, vector<vector<int>> &memo){
        if(left == -1 || up == -1) return 0;
        if(left == 0 && up == 0) return 1;
        
        if(memo[left][up] != -1) return memo[left][up];
        
        int leftSide = solve(m, n, left-1, up, memo);
        int upSide = solve(m, n, left, up-1, memo);
        
        return memo[left][up] = leftSide + upSide;
    }
    
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int> (n, -1));
        return solve(m, n, m-1, n-1, memo);
    }
};



// 3rd Approach
// DP Approach / Tabulation
// Time Complexity : O(M * N)
// Space Complexity : O(M * N)

class Solution {    
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    dp[i][j] = 1;
                }
                else{                    
                    int leftSide = 0;
                    if(i-1 >= 0){
                        leftSide = dp[i-1][j];
                    }
                    
                    int upSide = 0;
                    if(j-1 >= 0){
                        upSide = dp[i][j-1];
                    }                        
                    
                    dp[i][j] = leftSide + upSide;
                }
            }
        }
        
        return dp[m-1][n-1];
    }
};


// 4th Approach
// Space Optimization in DP Approach
// Time Complexity : O(M*N)
// Space Complexity : O(N)

class Solution {    
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 0);
        
        for(int i = 0; i < m; i++){
            
            vector<int> cur(n, 0);
            
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    cur[j] = 1;
                }
                else{                    
                    int leftSide = 0;
                    if(i-1 >= 0){
                        leftSide = prev[j];
                    }
                    
                    int upSide = 0;
                    if(j-1 >= 0){
                        upSide = cur[j-1];
                    }                        
                    
                    cur[j] = leftSide + upSide;
                }
            }
            prev = cur;
        }
        
        return prev[n-1];
    }
};



// 5th Approach
// Linear Solution
// Time Complexity : O(M)
// Space Complexity : O(1)
class Solution {    
public:
    int uniquePaths(int m, int n) {
        int formulaValue = m + n - 2;
        int run = m-1;
        
        // NcR formula
        
        double sum = 1;
        for(int i = 1; i <= run; i++){
            sum = sum * (formulaValue - run + i) / i;
        }
        
        return (int)sum;
    }
};
