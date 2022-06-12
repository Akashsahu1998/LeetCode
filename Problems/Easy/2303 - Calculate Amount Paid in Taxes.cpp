
// Question) 2303. Calculate Amount Paid in Taxes


// Implementation

// Linearly iterate and perform the operation
// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double ans = 0.0;
        if(income == 0) return ans;
        int prev = 0;
        
        for(int i = 0; i < brackets.size(); i++){
            int upper = brackets[i][0], percent = brackets[i][1];
            int current = min(income, upper-prev);
            ans += (double)(current * percent) / 100;
            income -= current;
            prev = upper;
        }
        
        return ans;
    }
};
