
// Question) 72. Edit Distance


// Implementation

// https://www.youtube.com/watch?v=fJaKO8FbDdo

// 1st Approach
// Recursive Approach
// Will give TLE
// Time Complexity : O(2!)
// Space Complexity : O(2!)

class Solution {
private:
    int solve(string word1, string word2, int ptr1, int ptr2){
       
        if(ptr1 == -1 && ptr2 == -1) return 0;
        if(ptr1 == -1) return ptr2+1;
        if(ptr2 == -1) return ptr1+1;
        
        // if matching
        if(word1[ptr1] == word2[ptr2]){
            return solve(word1, word2, ptr1-1, ptr2-1);    
        }       
        
        // deleting char, hypothetically deleting, it means just decrementing ptr1
        int deleteChar = 1 + solve(word1, word2, ptr1-1, ptr2);
        
        // inserting char, hypothetically inserting, it means just decrementing ptr2
        int insertChar = 1 + solve(word1, word2, ptr1, ptr2-1);
        
        // replacing char, hypothetically replacing, it means just decrementing ptr1 & ptr2
        int replaceChar = 1 + solve(word1, word2, ptr1-1, ptr2-1);
        
        return min(deleteChar, min(insertChar, replaceChar));
    }
    
public:
    int minDistance(string word1, string word2) {
        // Assuming 0 based indexing
        return solve(word1, word2, word1.size()-1, word2.size()-1);
    }
};



// 2nd Approach
// Recursive DP Approach / Memoization
// Time Complexity : O(M * N)
// Space Complexity : O(M * N + M * N) => O(M * N), bcz of recursion stack trace

class Solution {
private:
    int solve(string word1, string word2, int ptr1, int ptr2, vector<vector<int>> &memo){
       
        if(ptr1 == 0 && ptr2 == 0) return 0;
        if(ptr1 == 0) return ptr2;
        if(ptr2 == 0) return ptr1;
        
        if(memo[ptr1][ptr2] != -1) return memo[ptr1][ptr2];
        
        // if matching
        if(word1[ptr1-1] == word2[ptr2-1]){
            return memo[ptr1][ptr2] = solve(word1, word2, ptr1-1, ptr2-1, memo);    
        }       
        
        // deleting char, hypothetically deleting, it means just decrementing ptr1
        int deleteChar = 1 + solve(word1, word2, ptr1-1, ptr2, memo);
        
        // inserting char, hypothetically inserting, it means just decrementing ptr2
        int insertChar = 1 + solve(word1, word2, ptr1, ptr2-1, memo);
        
        // replacing char, hypothetically replacing, it means just decrementing ptr1 & ptr2
        int replaceChar = 1 + solve(word1, word2, ptr1-1, ptr2-1, memo);
        
        return memo[ptr1][ptr2] = min(deleteChar, min(insertChar, replaceChar));
    }
    
public:
    int minDistance(string word1, string word2) {
        // Assuming 1 based indexing
        vector<vector<int>> memo(word1.size()+1, vector<int> (word2.size()+1, -1));
        return solve(word1, word2, word1.size(), word2.size(), memo);
    }
};



// 3rd Approach
// Iterative DP Approach
// Time Complexity : O(M * N)
// Space Complexity : O(M * N)

class Solution {    
public:
    int minDistance(string word1, string word2) {
        // Assuming 1 based indexing
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        
        for(int i = 0; i <= n; i++){
            dp[i][0] = i;
        }
        
        for(int j = 0; j <= m; j++){
            dp[0][j] = j;
        }
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                // if matching
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];    
                }
                else{
                    // deleting char, hypothetically deleting, it means just decrementing ptr1
                    int deleteChar = 1 + dp[i-1][j];

                    // inserting char, hypothetically inserting, it means just decrementing ptr2
                    int insertChar = 1 + dp[i][j-1];

                    // replacing char, hypothetically replacing, it means just decrementing ptr1 & ptr2
                    int replaceChar = 1 + dp[i-1][j-1];

                    dp[i][j] = min(deleteChar, min(insertChar, replaceChar));    
                }                
            }
        }
        
        return dp[n][m];
    }
};



// 4th Approach
// Space Optimization in DP Approach
// Time Complexity : O(M*N)
// Space Complexity : O(M)

class Solution {    
public:
    int minDistance(string word1, string word2) {
        // Assuming 1 based indexing
        int n = word1.size(), m = word2.size();
        vector<int> prev(m+1), cur(m+1, 0);
        
        for(int j = 0; j <= m; j++){
            prev[j] = j;
        }
        
        for(int i = 1; i <= n; i++){
            cur[0] = i;
            for(int j = 1; j <= m; j++){
                // if matching
                if(word1[i-1] == word2[j-1]){
                    cur[j] = prev[j-1];    
                }
                else{
                    // deleting char, hypothetically deleting, it means just decrementing ptr1
                    int deleteChar = 1 + prev[j];

                    // inserting char, hypothetically inserting, it means just decrementing ptr2
                    int insertChar = 1 + cur[j-1];

                    // replacing char, hypothetically replacing, it means just decrementing ptr1 & ptr2
                    int replaceChar = 1 + prev[j-1];

                    cur[j] = min(deleteChar, min(insertChar, replaceChar));    
                }        
            }
            
            prev = cur;
        }
        
        return prev[m];
    }
};
