
// Question) 169. Majority Element


// Implementation

// Using Moore's Voting Algorithm
// Time Complexity = O(N),
// Space Complexity = O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, majorityElement = 0;
        for(int itr = 0; itr < nums.size(); itr++){
            if(count == 0) majorityElement = nums[itr];
            
            if(majorityElement == nums[itr]) count++;
            else count -= 1;
        }
        return majorityElement;
    }
};
