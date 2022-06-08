
// Question) 62. Unique Paths


// Implementation

// 1st Approach
// Recursive Approach
// Will give TLE
// Time Complexity : O(2!)
// Space Complexity : O(2!)

class Solution {
private:
    int solve(int m, int n, int left, int up){
        if(left == -1 || up == -1) return 0;
        if(left == 0 && up == 0) return 1;
        
        int leftSide = solve(m, n, left-1, up);
        int upSide = solve(m, n, left, up-1);
        
        return leftSide + upSide;
    }
    
public:
    int uniquePaths(int m, int n) {
        return solve(m, n, m-1, n-1);
    }
};
