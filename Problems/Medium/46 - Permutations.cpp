
// Question) 46. Permutations


// Implementation

// Time Complexity = O(N*(N!)), Space Complexity = O(N!)
class Solution {
public:
    void permuteArray(vector<vector<int>> &res, vector<int> nums, int low) {
        if(low == nums.size()) res.push_back(nums);
        else{
            for(int itr = low; itr < nums.size(); itr++){
                swap(nums[itr], nums[low]);
                permuteArray(res, nums, low+1);
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        permuteArray(res, nums, 0);
        return res;
    }
};
