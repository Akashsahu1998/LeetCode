
// Question) 2128. Remove All Ones With Row and Column Flips


// Implementation

// Time Complexity : O(M * N)
// Space Complexity : O(1)

class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        // if any cell at first is having 1, then flip that column
        for(int col = 0; col < n; col++){
            
            // [row][col]
            if(grid[0][col] == 1){
                for(int row = 0; row < m; row++){
                    // [col][row]
                    grid[row][col] = !grid[row][col];
                }
            }
        }
        
        // if any row's sum is not equal to 0 or 1 then return false
        // starting row from 1, bcz there is no sense of checking 1st row, bcz if there is 1 then we have already flipped it with the help of above code
        for(int row = 1; row < m; row++){
            int sum = 0;
            for(int col = 0; col < n; col++){
                sum += grid[row][col];
            }
            
            // it means its not possible
            if(sum != 0 && sum != n){
                return false;
            }
        }        
        
        return true;
    }
};
