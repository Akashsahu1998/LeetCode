
// Question) 221. Maximal Square


// Implementation

// 1st Approach
// Using DP
// Time Complexity = O(M*N)
// Time Complexity = O(M*N), where M = total rows, N = total cols
// We can do inplace as well, if it was int not char, otherwise it requires lots of operation

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int rows = matrix.size(), cols = matrix[0].size(), largestSquare = 0;
        
        // taking +1 more size, bcz to avoid corner cases
        vector<vector<int>> dp(rows+1, vector<int>(cols+1, 0));
        
        for(int i = 1; i <= rows; i++){
            for(int j = 1; j <= cols; j++){
                
                // its current matrix is cell is not 1, then don't touch it, let it be 0
                if(matrix[i-1][j-1] == '1'){
                    // here we have to check three places to calculate the square
                    // up, left-up, left
                    dp[i][j] = 1 + min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
                    
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
        // will take care of previous row        
        vector<int> prev(cols+1, 0);
        
        for(int i = 1; i <= rows; i++){
            
            // will take care of current row
            // taking +1 more size, bcz to avoid corner cases
            vector<int> curr(cols+1, 0);
            
            for(int j = 1; j <= cols; j++){
                
                // its current matrix is cell is not 1, then don't touch it, let it be 0
                if(matrix[i-1][j-1] == '1'){
                    // here we have to check three places to calculate the square
                    // up, left-up, left
                    // we can get up from prev, left-up from prev, and left from cur
                    curr[j] = 1 + min(prev[j], min(prev[j-1], curr[j-1]));
                    
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
