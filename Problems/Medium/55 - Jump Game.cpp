
// Question) 55. Jump Game


// Implementation

// Using Greedy Approach
// Time Complexity = O(N)
// Space Complexity = O(1)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(maxReach < i) return false;
            maxReach = max(maxReach, i+nums[i]);
        }
        
        return true;
    }
};
