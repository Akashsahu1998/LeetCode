
// Question) 40. Combination Sum II


// Implementation

// Using Recursion & Backtracking
// Time Complexity = O(2^N * K) Where K is the time taken to add the ans vector into the res vector
// Space Complexity = O(2^N * K * X), Where K is the size of ans, and X is the number of combinations, but space complexity will completely depend on the number of combination which are getting created, bcz at that time the recursion call will also make.

class Solution {
private:
    void findCombination(vector<int> &candidates, int target, vector<vector<int>> &res, vector<int> &temp, int index){
        if(target == 0){           
            res.push_back(temp);
            return;
        }
        
        for(int i = index; i < candidates.size(); i++){
            
            // if i is greater and current element & last element is equal then we don't need to pick that element, bcz that can lead us to duplicate element situation
            if(i > index && candidates[i] == candidates[i-1]) continue;
            
            // if target become less than 0, then there is no sense of checking other elements, bcz they will be obviously greater
            if(target < 0) break;
            
            temp.push_back(candidates[i]);
            findCombination(candidates, target - candidates[i], res, temp, i+1);
            temp.pop_back();
           
        }        
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> res;
        vector<int> temp;
        
        findCombination(candidates, target, res, temp, 0);
        
        return res;
    }
};
