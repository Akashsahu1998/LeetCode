
// Question) 54. Spiral Matrix


// Implementation

// Using Trick of 4 variables
// https://www.youtube.com/watch?v=1ZGJzvkcLsA&t=184s
// Time Complexity = O(N)
// Space Complexity = O(1)

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int rows = matrix.size(), cols = matrix[0].size(), direction = 0;
        int top = 0, down = rows-1, left = 0, right = cols-1;
        
        // both while condition we can use
        while(res.size() < rows*cols){
        // while(top <= down && left <= right){
            if(direction == 0){
                for(int i = left; i <= right; i++){
                    res.push_back(matrix[top][i]);
                }
                
                top++;
            }            
            else if(direction == 1){
                for(int i = top; i <= down; i++){
                    res.push_back(matrix[i][right]);
                }
                
                right--;
            }
            else if(direction == 2){
                for(int i = right; i >= left; i--){
                    res.push_back(matrix[down][i]);
                }
                
                down--;
            }
            else if(direction == 3){
                for(int i = down; i >= top; i--){
                    res.push_back(matrix[i][left]);
                }
                
                left++;
            }
            
            direction = (direction+1) % 4;
        }
        
        return res;
    }
};
