
// Question) 22. Generate Parentheses


// Implementation

// Using Recursion & Backtracking
// Time Complexity = O(2^N)
// Space Complexity = O(1), not considering the ans vector, bcz its a part of output
class Solution {
private:
    void solve(int open, int close, string output, vector<string> &ans){
        
        // base case
        if(open == 0 && close == 0){
            ans.push_back(output);
            return;
        }
        
        // always takes open, until & unless its 0
        // inside this just append the open bracket and decrease open by 1
        if(open != 0){
            string openOutput = output + "(";
            solve(open-1, close, openOutput, ans);    
        }
        
        // take close when close is greater than open, bcz when we will use open, then only we can use close
        // inside this just append the close bracket and decrease close by 1
        if(close > open){
            string closeOutput = output + ")";
            solve(open, close-1, closeOutput, ans);
        }
    }

public:    
    vector<string> generateParenthesis(int n) {
        
        // to store ans
        vector<string> ans;
        
        // we will be having n open & close brackets
        int open = n, close = n;
        
        // we will store the combination into this
        string output = "";
        
        // helper function to solve the problem
        solve(open, close, output, ans);
        
        return ans;
    }
};
