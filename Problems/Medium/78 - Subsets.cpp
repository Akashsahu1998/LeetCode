
// Question) 78. Subsets


// Implementation


// 1st Approach
// Recursive Approach
// Time Complexity: O(2^N)
// Space Complexity: O(2^N)
class Solution {
private: 
    void generateSubsets(vector<int>& nums, vector<vector<int>> &res, vector<int> &temp, int index){
        res.push_back(temp);
        
        for(int i = index; i < nums.size(); i++){
            temp.push_back(nums[i]);
            generateSubsets(nums, res, temp, i+1);   
            temp.pop_back();
        }        
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp; 
        generateSubsets(nums, res, temp, 0);
        
        return res;
    }
};


// 2nd Approach
// Recursive Approach
// Time Complexity: O(2^N)
// Space Complexity: O(2^N)
class Solution {
private: 
    void generateSubsets(vector<int>& nums, vector<vector<int>> &res, vector<int> &temp, int index){
        if(index == nums.size()){
            res.push_back(temp);
            return;
        }
        
        // pick
        temp.push_back(nums[index]);
        generateSubsets(nums, res, temp, index+1);
        
        // backtrack
        temp.pop_back();
        
        // not pick
        generateSubsets(nums, res, temp, index+1);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        generateSubsets(nums, res, temp, 0);
        
        return res;
    }
};


// 3rd Approach
// Iterative Approach
// Time Complexity: O(N * 2^N)
// Space Complexity: O(2^N)
 class Solution {
 public:
     vector<vector<int>> subsets(vector<int>& nums) {
         vector<vector<int>> res;
         res.push_back({});
        
         for(int i = 0; i < nums.size(); i++){
             int resSize = res.size();
             for(int j = 0; j < resSize; j++){
                 vector<int> temp = res[j];
                 temp.push_back(nums[i]);
                 res.push_back(temp);
             }
         }        
         return res;
     }
 };
