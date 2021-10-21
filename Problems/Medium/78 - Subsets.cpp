
// Question) 78. Subsets


// Implementation

// Time Complexity = O(N*(2^N)), Space Complexity = O(O(N*(2^N))) where H is the height of the Binary Tree
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back({});
        for(int itr = 0; itr < nums.size(); itr++){
            int resSize = res.size();
            for(int jtr = 0; jtr < resSize; jtr++){
                vector<int> temp = res[jtr];
                temp.push_back(nums[itr]);
                res.push_back(temp);
            }
        }
        return res;
    }
};
