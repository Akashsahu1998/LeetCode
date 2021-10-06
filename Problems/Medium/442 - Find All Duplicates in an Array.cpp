
// Question) 442. Find All Duplicates in an Array


// Implementation

// Naive Approach
// Time Complexity = O(N), Space Complexity = O(N)
// In this solution we are using extra space as a unordered map
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int> ump;
        vector<int> res;
        for(int itr = 0; itr < nums.size(); itr++) ump[nums[itr]]++;
        for(auto mp : ump){
            if(mp.second > 1) res.push_back(mp.first);
        }
        return res;
    }
};


// Efficient Approach
// Time Complexity = O(N), Space Complexity = O(1)
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for(int itr = 0; itr < nums.size(); itr++){
            if(nums[abs(nums[itr])-1] < 0) res.push_back(abs(nums[itr]));
            else nums[abs(nums[itr])-1] = -nums[abs(nums[itr])-1];
        }
        return res;
    }
};
