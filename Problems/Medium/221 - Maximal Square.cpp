
// Question) 221. Maximal Square


// Implementation

// 1st Approach
// Using DP
// Time Complexity = O(M*N)
// Space Complexity = O(M*N)

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int rows = matrix.size(), cols = matrix[0].size(), largestSquare = 0;
        vector<vector<int>> dp(rows+1, vector<int>(cols+1, 0));
        
        for(int i = 1; i <= rows; i++){
            for(int j = 1; j <= cols; j++){
                if(matrix[i-1][j-1] == '1'){                    
                    dp[i][j] = 1 + min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
                    largestSquare = max(largestSquare, dp[i][j]);
                }
            }   
        }
        
        return largestSquare * largestSquare;
    }
};
