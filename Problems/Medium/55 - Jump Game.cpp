
// Question) 55. Jump Game


// Implementation

// Time Complexity = O(N), Space Complexity = O(1)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxDist = 0;
        for(int itr = 0; itr < nums.size(); itr++){
            if(maxDist < itr) return false;
            maxDist = max(maxDist, itr + nums[itr]);
        }
        return true;
    }
};
