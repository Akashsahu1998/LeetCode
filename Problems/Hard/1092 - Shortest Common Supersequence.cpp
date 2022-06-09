
// Question) 1092. Shortest Common Supersequence


// Implementation

// Iterative DP Approach
// Time Complexity : O(M * N)
// Space Complexity : O(M * N)
// https://www.youtube.com/watch?v=xElxAuBcvsU&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=32

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        
        int m = str1.size(), n = str2.size();
        
        // taking dp
        vector<vector<int>> dp(m+1, vector<int> (n+1));
        
        // basically here row is pointing to str1, and col is pointing to str2
        
        // filling all row of 0th col
        for(int row = 0; row <= m; row++){
            dp[row][0] = 0;
        }
        
        // filling all col of 0th row
        for(int col = 0; col <= n; col++){
            dp[0][col] = 0;
        }
        
        // filling the dp table by using the LCS logic, ultimately we are finding the LCS
        for(int row = 1; row <= m; row++){
            for(int col = 1; col <= n; col++){
                
                // if matching so adding 1 into diagonal and piutting into dp
                if(str1[row-1] == str2[col-1]){
                    dp[row][col] = 1 + dp[row-1][col-1];
                }
                
                // if not matching so taking max value of up side and left side from dp
                else{
                    dp[row][col] = max(dp[row-1][col], dp[row][col-1]);
                }
            }
        }
        
        // store the result
        string res;
        
        // starting from end
        int row = m, col = n;
        while(row > 0 && col > 0){
            
            // move diagonally if both string are having same character
            // taking any character, and moving diagonally, thats why row-1 & col-1
            if(str1[row-1] == str2[col-1]){
                res += str1[row-1];
                row--;
                col--;
            }
            
            // move up if upper side(index) of dp is having big value then left side of dp
            // taking row-1 character from str1, and moving upper side
            else if(dp[row-1][col] > dp[row][col-1]){
                res += str1[row-1];
                row--;
            }
            
            // move left if left side(index) of dp is having big value then upper side of dp
            // taking col-1 character from str2, and moving left side
            else{
                res += str2[col-1];
                col--;
            }
        }
        
        // if row is not 0, so lets take all value from row index which is pointing to str1
        while(row > 0){
            res += str1[row-1];
            row--;
        }
        
        // if col is not 0, so lets take all value from col index which is pointing to str2
        while(col > 0){
            res += str2[col-1];
            col--;
        }
        
        // reverse the res in the last bcz we have travelled from end
        reverse(res.begin(), res.end());
        
        // return the result
        return res;
    }
};
