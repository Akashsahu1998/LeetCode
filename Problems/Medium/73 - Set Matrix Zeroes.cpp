
// Question) 73. Set Matrix Zeroes


// Implementation

// Total 3 approaches mentioned in the video
// https://www.youtube.com/watch?v=M65xBewcqcI&t=629s
// Time Complexity = O(M*N)
// Space Complexity = O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int row = matrix.size(), col = matrix[0].size(), col0 = 1;
        
        for(int i = 0; i < row; i++){
            if(matrix[i][0] == 0) col0 = 0;
            for(int j = 1; j < col; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = row-1; i >= 0; i--){
            for(int j = col-1; j >= 1; j--){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
            if(col0 == 0) matrix[i][0] = 0;
        }
    }
};
