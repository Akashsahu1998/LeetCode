
// Question) 221. Maximal Square


// Implementation

// Reference : https://www.youtube.com/watch?v=RElcqtFYTm0

// 1st Approach
// Using DP
// Time Complexity = O(M*N)
// Time Complexity = O(M*N), where M = total rows, N = total cols
// We can do inplace as well, if it was int not char, otherwise it requires lots of operation

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int rows = matrix.size(), cols = matrix[0].size(), largestSquare = 0;
        
           Intializing DP
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                
                // its current matrix is cell is not 1, then don't touch it, let it be 0
                if(matrix[i][j] == '1'){
                    // here we have to check three places to calculate the square
                    // up, left-up, left
                    
                    int up = (i-1 >= 0) ? dp[i-1][j] : 0;
                    int leftUp = (i-1 >= 0 && j-1 >= 0) ? dp[i-1][j-1] : 0;
                    int left = (j-1 >= 0) ? dp[i][j-1] : 0;
                    
                    dp[i][j] = 1 + min(up, min(leftUp, left));
                    
                    // keep track of maximal square
                    largestSquare = max(largestSquare, dp[i][j]);
                }
            }   
        }
        
        return largestSquare * largestSquare;
    }
};


// 2nd Approach
// Best Approach, Space Optimized
// Using DP
// Time Complexity = O(M*N), where M = total rows, N = total cols
// Space Complexity = O(N), here we are only using 1 array as prev
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int rows = matrix.size(), cols = matrix[0].size(), largestSquare = 0;
        
        // taking +1 more size, bcz to avoid corner cases
        vector<int> prev(cols, 0);
        
        for(int i = 0; i < rows; i++){
            
            // will take care of current row
            vector<int> curr(cols, 0);
            
            for(int j = 0; j < cols; j++){
                
                // its current matrix is cell is not 1, then don't touch it, let it be 0
                if(matrix[i][j] == '1'){
                    // here we have to check three places to calculate the square
                    // up, left-up, left
                    // we can get up from prev, left-up from prev, and left from cur
                    
                    int up = prev[j];
                    int leftUp = (j-1 >= 0) ? prev[j-1] : 0;
                    int left = (j-1 >= 0) ? curr[j-1] : 0;
                    
                    curr[j] = 1 + min(up, min(leftUp, left));
                    
                    // keep track of maximal square
                    largestSquare = max(largestSquare, curr[j]);
                }
            }
            
            // update the previous by curr, bcz in next time the curr arr will be used as prev
            prev = curr;
        }
        
        return largestSquare * largestSquare;
    }
};


// Algo Steps
// 1) On each cell, check 3 places, which can be responsible for square
