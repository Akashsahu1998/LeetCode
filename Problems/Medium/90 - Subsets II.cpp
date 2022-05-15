
// Question) 90. Subsets II


// Implementation

// Recursive Approach
// Using Backtracking
// Time Complexity : O(NlogN) + O(2^N) + O(N)
// Space Complexity : O(2^N) + O(K), where K is the length of the subset on each step we are getting
    
class Solution {
private:
    void generateSubset(vector<int> nums, vector<int> &temp, vector<vector<int>> &res, int index){
        res.push_back(temp);
        
        for(int i = index; i < nums.size(); i++){
            if(i != index && nums[i] == nums[i-1]) continue;
            
            temp.push_back(nums[i]);
            generateSubset(nums, temp, res, i+1);
            temp.pop_back();
        }
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> res;
        vector<int> temp;
        
        generateSubset(nums, temp, res, 0);
        
        return res;
    }
};
