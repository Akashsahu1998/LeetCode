
// Question) 45. Jump Game II


// Implementation

// Greedy Based Approach
// Time Complexity = O(N)
// Space Complexity = O(1)

class Solution {
public:    
    int jump(vector<int>& nums) {
        int curEnd = 0, maxReachable = 0, jump = 0;
        for(int itr = 0; itr < nums.size()-1; itr++){
            maxReachable = max(maxReachable, itr+nums[itr]);
            if(itr == curEnd){
                jump++;
                curEnd = maxReachable;
            }
        }
        return jump;
    }
};
