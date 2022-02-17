
// Question) 48. Rotate Image


// Implementation

// Idea: Firstly transpose the matrix, after that just reverse the each row of the matrix
// Time Complexity = (O(N^2) + O(N^2)) => O(N^2)
// Space Complexity = O(1)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        // transpose the matrix
        for(int itr = 0; itr < matrix.size(); itr++){
            for(int jtr = 0; jtr < itr; jtr++){
                swap(matrix[itr][jtr], matrix[jtr][itr]);
            }
        }
        
        // just reverse the each row
        for(int itr = 0; itr < matrix.size(); itr++){
            reverse(matrix[itr].begin(), matrix[itr].end());
        }
    }
};
