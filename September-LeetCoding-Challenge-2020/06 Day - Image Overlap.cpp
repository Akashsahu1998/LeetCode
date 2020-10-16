class Solution {
public:
    int helper(vector<vector<int>> &A,vector<vector<int>> &B_padded,int xshift,int yshift) {
        int total = 0;
        for(int itr = 0; itr < A.size(); itr++) {
            for(int jtr = 0; jtr < A[0].size(); jtr++) {
                total += A[itr][jtr] * B_padded[itr + yshift][jtr + xshift];
            }
        }
        return total;
    }
    
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
    int n = A.size();
    
    vector<vector<int>> B_padded(3 * A.size() - 2, vector<int>(3 * A.size() - 2, 0));
    
    for(int itr = 0; itr < A.size(); itr++) {
        for(int jtr = 0; jtr < A.size(); jtr++) {
            B_padded[itr + n - 1][jtr + n - 1] = B[itr][jtr];
        }
    }
        
    int res = 0;
    for(int xshift = 0; xshift < (2 * A.size() - 1); xshift++) {
        for(int yshift = 0; yshift < (2 * n - 1); yshift++) {
            res = max(res, helper(A, B_padded, xshift, yshift));
        }
    }    
    return res;
    }
};
