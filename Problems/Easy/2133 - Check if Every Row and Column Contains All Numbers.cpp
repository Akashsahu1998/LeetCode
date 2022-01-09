
// Question) 2133. Check if Every Row and Column Contains All Numbers


// Implementation

// Using vectors
// Time Complexity = O(N^2), Space Complexity = O(N)
class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // row wise
        for(int itr = 0; itr < n; itr++){
            vector<int> vec(n+1, 0);
            for(int jtr = 0; jtr < n; jtr++){
                
                // if element is present then we are marking it as 1, if that element is coming again(marked as a 1) then we will return false;
                if(vec[matrix[itr][jtr]] == 0) vec[matrix[itr][jtr]] = 1;
                else return false;      // vec[matrix[itr][jtr]] is 1, then it means it's already present
            }
        }
        
        // column wise
        for(int itr = 0; itr < n; itr++){
            vector<int> vec(n+1, 0);
            for(int jtr = 0; jtr < n; jtr++){
                // if element is present then we are marking it as 1, if that element is coming again(marked as a 1) then we will return false;
                if(vec[matrix[jtr][itr]] == 0) vec[matrix[jtr][itr]] = 1;
                else return false;      // vec[matrix[jtr][itr]] is 1, then it means it's already present
            }
        }
        
        return true;
    }
};


// XOR Property
// a   b     a^b
// 0   0       0
// 0   1       1
// 1   0       1
// 1   1       0

// Time Complexity = O(N^2), Space Complexity = O(1)
class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        int row = 0, col = 0;
        for(int itr = 0; itr < n; itr++){            
            for(int jtr = 0; jtr < n; jtr++){
                // row wise
                row = row ^ (matrix[jtr][itr] ^ (jtr+1));
                
                // col wise
                col = col ^ (matrix[itr][jtr] ^ (jtr+1));                
            }
            
            // if any one of the row & col is 1, it means there are values which are coming same, according to the XOR property, so that's why they are 1, so returning false
            if(row || col) return false;
        }
        
        return true;
    }
};
