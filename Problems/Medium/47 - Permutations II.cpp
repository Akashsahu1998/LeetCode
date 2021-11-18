
// Question) 47. Permutations II


// Implementation

// Time Complexity = O(N*(N!)), Space Complexity = O(N!)
class Solution {
public:    
    void permuteArray(vector<vector<int>> &res, vector<int> nums, int low) {
        if(low == nums.size()){
            res.push_back(nums);
        }
        else{
            unordered_set<int> us;
            for(int itr = low; itr < nums.size(); itr++){
                if(us.find(nums[itr]) != us.end()) continue;
                us.insert(nums[itr]);
                swap(nums[itr], nums[low]);
                permuteArray(res, nums, low+1);
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        permuteArray(res, nums, 0);
        return res;
    }
};
