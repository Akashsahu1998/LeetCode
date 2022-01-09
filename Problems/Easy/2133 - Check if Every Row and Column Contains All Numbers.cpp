
// Question) 2133. Check if Every Row and Column Contains All Numbers


// Implementation

// Using vectors
// Time Complexity = O(N^2), Space Complexity = O(N)
class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int itr = 0; itr < n; itr++){
            vector<int> vec(n+1, 0);
            for(int jtr = 0; jtr < n; jtr++){
                if(vec[matrix[itr][jtr]] == 0) vec[matrix[itr][jtr]] = 1;
                else return false;
            }
        }
        
        for(int itr = 0; itr < n; itr++){
            vector<int> vec(n+1, 0);
            for(int jtr = 0; jtr < n; jtr++){
                if(vec[matrix[jtr][itr]] == 0) vec[matrix[jtr][itr]] = 1;
                else return false;
            }
        }
        
        return true;
    }
};
