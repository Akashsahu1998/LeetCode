
// Question) 1572. Matrix Diagonal Sum

// Implementation
// Time Complexity = O(n^2)


class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size()-1, sum = 0;
        
        for(int itr1 = 0; itr1 < mat.size(); itr1++){            
            for(int itr2 = 0; itr2 < mat.size(); itr2++){
                if((itr2 == itr1) || (itr2 == n)) sum += mat[itr1][itr2];
            }
            n--;
        }
        return sum;
    }
};

