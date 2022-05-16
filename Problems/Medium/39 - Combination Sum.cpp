
// Question) 39. Combination Sum


// Implementation

// Using Recursion & Backtracking
// Time Complexity = O(2^T * K) Where K is the time taken to add the ans vector into the res vector
// Space Complexity = O(K * X), Where K is the size of ans, and X is the number of combinations

class Solution {
private:
    void findCombination(vector<int> &candidates, int target, vector<vector<int>> &res, vector<int> &temp, int index){
        if(index == candidates.size() || target == 0){
            if(target == 0){
                res.push_back(temp);
            }
            return;
        }
        
        if(candidates[index] <= target){
            temp.push_back(candidates[index]);
            findCombination(candidates, target - candidates[index], res, temp, index);
            temp.pop_back();
        }
        findCombination(candidates, target, res, temp, index+1);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        
        findCombination(candidates, target, res, temp, 0);
        return res;
    }
};
