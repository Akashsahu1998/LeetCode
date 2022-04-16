
// Question) 74. Search a 2D Matrix


// Implementation

// Using Binary Search
// Time Complexity: O(log(M*N))
// Space Complexity: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), left = 0, right = m * n - 1;
        
        while(left <= right){
            int mid = left + ((right-left)/2);
            
            if(matrix[mid/n][mid%n] == target) return true;
            else if(matrix[mid/n][mid%n] > target) right = mid-1;
            else left = mid+1;
        }
        
        return false;
    }
};
