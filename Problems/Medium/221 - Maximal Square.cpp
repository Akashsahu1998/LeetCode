
// Question) 221. Maximal Square


// Implementation

// 1st Approach
// Using DP
// Time Complexity = O(M*N)
// Space Complexity = O(M*N), we are using extra space of 2-D vector
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int rows = matrix.size(), cols = matrix[0].size(), largestSquare = 0;
        
        // taking +1 more size, bcz to avoid corner cases
        vector<vector<int>> dp(rows+1, vector<int>(cols+1, 0));
        
        for(int i = 1; i <= rows; i++){
            for(int j = 1; j <= cols; j++){
                if(matrix[i-1][j-1] == '1'){
                    // here we have to check three places to calculate the square
                    // up, left, left-up
                    dp[i][j] = 1 + min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
                    
                    // keep track maximal square
                    largestSquare = max(largestSquare, dp[i][j]);
                }
            }   
        }
        
        return largestSquare * largestSquare;
    }
};
