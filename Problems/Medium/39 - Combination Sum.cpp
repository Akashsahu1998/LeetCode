
// Question) 39. Combination Sum


// Implementation

// Using Recursion & Backtracking
// Time Complexity = O(2^T * K) Where K is the time taken to add the ans vector into the res vector
// Space Complexity = O(K * X), Where K is the size of ans, and X is the number of combinations

class Solution {
private:
    void solve(int index, int target, vector<int> candidates, vector<int> ans, vector<vector<int>> &res){
        if(index == candidates.size()){
            if(target == 0){
                res.push_back(ans);             
            }
            return;
        }
        
        if(candidates[index] <= target){
            ans.push_back(candidates[index]);
            solve(index, target-candidates[index], candidates, ans, res);
            ans.pop_back();
        }
        solve(index+1, target, candidates, ans, res);        
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ans;
        solve(0, target, candidates, ans, res);
        return res;
    }
};
